#include <iostream>
#include <fstream>
#include <set>
#include <nlohmann/json.hpp>
#include <iomanip>

using json = nlohmann::json;
using namespace std;

set<string> extractUsernames(const json& data, const string& key) {
    set<string> usernames;
    if (data.contains(key)) {
        for (const auto& entry : data[key]) {
            if (!entry["string_list_data"].empty()) {
                usernames.insert(entry["string_list_data"][0]["value"]);
            }
        }
    } else {
        for (const auto& entry : data) {
            if (!entry["string_list_data"].empty()) {
                usernames.insert(entry["string_list_data"][0]["value"]);
            }
        }
    }
    return usernames;
}

void printSectionHeader(const string& title) {
    cout << "\n===============================" << endl;
    cout << "  " << title << endl;
    cout << "===============================" << endl;
}

set<string> extractPendingRequests(const json& data) {
    set<string> pendingRequests;
    for (const auto& entry : data["relationships_follow_requests_sent"]) {
        if (!entry["string_list_data"].empty()) {
            pendingRequests.insert(entry["string_list_data"][0]["value"]);
        }
    }
    return pendingRequests;
}

int main() {
    ifstream followersFile("followers_1.json");
    ifstream followingFile("following.json");
    ifstream pendingRequestsFile("pending_follow_requests.json");
    
    if (!followersFile.is_open() || !followingFile.is_open() || !pendingRequestsFile.is_open()) {
        cerr << "\n[ERROR] Unable to open JSON files!" << endl;
        return 1;
    }
    
    json followersJson, followingJson, pendingRequestsJson;
    followersFile >> followersJson;
    followingFile >> followingJson;
    pendingRequestsFile >> pendingRequestsJson;
    
    set<string> followers = extractUsernames(followersJson, "");
    set<string> following = extractUsernames(followingJson, "relationships_following");
    set<string> pendingRequests = extractPendingRequests(pendingRequestsJson);
    
    set<string> mutualFollowers;
    set<string> notFollowingBack;
    
    printSectionHeader("Mutual Followers");
    for (const auto& user : followers) {
        if (following.find(user) != following.end()) {
            cout << "  - " << user << endl;
            mutualFollowers.insert(user);
        }
    }
    cout << "\n[Total Mutual Followers]: " << mutualFollowers.size() << "\n" << endl;
    
    printSectionHeader("People You Follow but Don't Follow You Back");
    for (const auto& user : following) {
        if (followers.find(user) == followers.end()) {
            cout << "  - " << user << endl;
            notFollowingBack.insert(user);
        }
    }
    cout << "\n[Total Not Following Back]: " << notFollowingBack.size() << "\n" << endl;
    
    printSectionHeader("Pending Follow Requests");
    for (const auto& user : pendingRequests) {
        cout << "  - " << user << endl;
    }
    cout << "\n[Total Pending Follow Requests]: " << pendingRequests.size() << "\n" << endl;
    
    return 0;
}
