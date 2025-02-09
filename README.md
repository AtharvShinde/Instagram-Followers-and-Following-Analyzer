
# Instagram Followers and Following Comparator

This project allows you to compare your Instagram followers and following lists using JSON data downloaded from Instagram. It identifies mutual followers and people you follow who don't follow you back.





## How to Download Instagram Followers and Following Data

- Go to Instagram Settings

- Navigate to Account Center → Your Information and Permissions

- Click on Download Your Information → Download or Transfer Information

- Select Some of Your Information

- In the Connections section, check the checkboxes for Followers and Following

- Click Next → Download to Device

- After some time, you will receive a ZIP file. Extract it and then move check_followers.cpp file inside the extracted ZIP folder where followers_1.json and following.json exist.


## Clone This Repository

Clone the project

```bash
    git clone https://github.com/AtharvShinde/Instagram-Followers-and-Following-Comparator
```
Then, copy check_followers.cpp into the extracted ZIP folder where followers_1.json and following.json are located.

##  Installation of nlohmann/json

### Linux (Ubuntu/Debian) 

```bash
    sudo apt update
    sudo apt install g++ nlohmann-json3-dev
```

### macOS

```bash
    brew install gcc nlohmann-json
```

### Windows

#### Using MSYS2:
```bash
    pacman -S mingw-w64-x86_64-gcc mingw-w64-x86_64-nlohmann-json
```
#### Using vcpkg:

```bash
    vcpkg install nlohmann-json
```

## How to Compile and Run

After placing the JSON files in the correct directory, compile and run the program using the following commands:

### Linux/macOS

```bash
    g++ check_followers.cpp -o check_followers -std=c++11
    ./check_followers
```
### Windows (MSYS2 or MinGW)

```bash
    g++ check_followers.cpp -o check_followers.exe -std=c++11
    check_followers.exe
```

This will display the mutual followers and those who don't follow you back, along with their counts.
## Contributing
Feel free to fork the repository and submit pull requests to improve this project.

## License

This project is licensed under the MIT License.

