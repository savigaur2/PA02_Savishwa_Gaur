#include <iostream>
#include <filesystem>
#include <string>

using namespace std;
namespace fs = std::filesystem;

static int fileCount = 0, directoryCount = 0, finalSize = 0;

bool filecnt(const fs::path&, int);

int main () {
    
    // Read in directory path
    string dir;
    cout << "Enter a path of a directory in a Unix file system" << endl;
    cin >> dir;

    fs::path filePath(dir);

    if (filecnt(filePath, 0)) {
        cout << "The total number of directories in directory " << dir << " is:" << directoryCount << endl;
        cout << "The total number of files in directory " << dir << " is:" << fileCount << endl;
        cout << "The total number of bytes occupied by all files in  directory " << dir << " is:" << finalSize << endl;
    }
    else {
        cout << "The following directory cannot be found: " << dir;
    }
    
    return 0;
}

bool filecnt (const fs::path& filePath, int directoryNest) {

    bool validFlag = false;

    if (fs::exists(filePath) && fs::is_directory(filePath)) {
        validFlag = true;
        for (const auto& x : fs::directory_iterator(filePath)) {
            if (fs::is_directory(x.status())) {
                directoryCount++;
                filecnt(x, directoryNest + 1);
            }
            else if (fs::is_regular_file(x.status())) {
                fileCount ++;
                finalSize += fs::file_size(x);
            }
        }
    }

    return validFlag;
}
