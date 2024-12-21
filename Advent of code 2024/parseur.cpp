#include "parseur.hpp"

vector<string> readLinesFromFile(const string& fileName) {
    vector<string> lines;
    ifstream file(fileName);
    string line;

    if (file.is_open()) {
        while (getline(file, line)) {
            lines.push_back(line);
        }
        file.close();
    }
    else {
        cerr << "Cannot open file: " << fileName << endl;
    }

    return lines;
}

vector<string> split(const string& str, const string& delimiter) {
    vector<string> result;
    size_t start = 0, end;

    while ((end = str.find(delimiter, start)) != string::npos) {
        result.push_back(str.substr(start, end - start));
        start = end + delimiter.length();
    }

    result.push_back(str.substr(start));
    return result;
}