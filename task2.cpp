#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <filesystem>

namespace fs = std::filesystem;
using namespace std;
using namespace fs;

void listDirectory(const path& directory) {
    for (const auto& entry : directory_iterator(directory)) {
        cout << entry.path().filename() << endl;
    }
}

void viewFile(const path& filename) {
    ifstream file(filename);
    if (file.is_open()) {
        string line;
        while (getline(file, line)) {
            cout << line << endl;
        }
        file.close();
    } else {
        cerr << "Unable to open file: " << filename << endl;
    }
}

void createDirectory(const path& directory) {
    if (create_directory(directory)) {
        cout << "Directory created: " << directory << endl;
    } else {
        cerr << "Failed to create directory: " << directory << endl;
    }
}

void copyFile(const path& source, const path& destination) {
    if (exists(source)) {
        copy_file(source, destination, copy_options::overwrite_existing);
        cout << "File copied: " << source << " -> " << destination << endl;
    } else {
        cerr << "Source file does not exist: " << source << endl;
    }
}

void moveFile(const path& source, const path& destination) {
    if (exists(source)) {
        rename(source, destination);
        cout << "File moved: " << source << " -> " << destination << endl;
    } else {
        cerr << "Source file does not exist: " << source << endl;
    }
}

int main() {
    string command, arg1, arg2;

    while (true) {
        cout << "Enter a command (list, view, create_dir, copy, move, exit): ";
        cin >> command;

        if (command == "exit") {
            break;
        } else if (command == "list") {
            cout << "Enter directory path: ";
            cin >> arg1;
            listDirectory(arg1);
        } else if (command == "view") {
            cout << "Enter file path: ";
            cin >> arg1;
            viewFile(arg1);
        } else if (command == "create_dir") {
            cout << "Enter directory path: ";
            cin >> arg1;
            createDirectory(arg1);
        } else if (command == "copy") {
            cout << "Enter source file path: ";
            cin >> arg1;
            cout << "Enter destination file path: ";
            cin >> arg2;
            copyFile(arg1, arg2);
        } else if (command == "move") {
            cout << "Enter source file path: ";
            cin >> arg1;
            cout << "Enter destination file path: ";
            cin >> arg2;
            moveFile(arg1, arg2);
        } else {
            cout << "Invalid command. Please try again." << endl;
        }
    }

    return 0;
}
