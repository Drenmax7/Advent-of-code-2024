#ifndef DIJKSTRA
#define DIJKSTRA

#include <vector>
#include <string>
#include <iostream>

using namespace std;

int dijkstra(vector<string>& carte, char wall, vector<int> start, vector<int> end, bool noPath = false);
int dijkstra(vector<string>& carte, char wall, vector<int> start, vector<int> end, vector<vector<int>>& path, bool noPath = false);


#endif
