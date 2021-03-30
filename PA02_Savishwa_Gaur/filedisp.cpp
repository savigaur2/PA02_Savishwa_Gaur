 #include <iostream>
 #include <string>
 #include <map>

using namespace std;

bool eval(string, map<int, string>);

int main (int argc, char **argv) {
    const string option = argv[1];
    map<int, string> fullInput;

    string lineInput;
    int index = 0;

    while (getline(cin,lineInput)) {
        lineInput += '\n';
        fullInput[index] = lineInput;
        index++;
    }

    if (!eval(option, fullInput)) {
        cout << "Nothing found in input string" << endl;
    }

    return 0;
}

bool eval (string option, map<int, string> fullInput) {
    bool validFlag = false;
    for (int i = 0; i < fullInput.size(); i++) {
        if (option.compare("-f") == 0) {
            if (fullInput[i].find("files") != -1) {
                cout << fullInput[i];
                validFlag = true;
                return validFlag;
            }
        }
        else if (option.compare("-d") == 0) {
            if (fullInput[i].find("directories") != -1) {
                cout << fullInput[i];
                validFlag = true;
                return validFlag;
            }
        }
        else if (option.compare("-b") == 0) {
            if (fullInput[i].find("bytes") != -1) {
                cout << fullInput[i];
                validFlag = true;
                return validFlag;
            }
        }
        else {
            cout << "Invalid option: " << option << endl;
            return validFlag;
        }
    }

    return validFlag;
}
