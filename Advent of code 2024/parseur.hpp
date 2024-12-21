#ifndef PARSEUR
#define PARSEUR

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>

using namespace std;

vector<string> readLinesFromFile(const string& fileName);

vector<string> split(const string& str, const string& delimiter);

#endif