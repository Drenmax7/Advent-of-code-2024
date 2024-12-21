#ifndef JOUR10
#define JOUR10

#include "parseur.hpp"

#include <vector>
#include <chrono>
#include <algorithm>

using namespace std;

class Jour10 {
public:
    static void solution(vector<string>& reponse);
    static string part1();
    static string part2();

    static int scoreChemin(int i, int j, vector<string> map, vector<vector<int>>& vu);
    static int scoreChemin2(int i, int j, vector<string> map);
};


#endif
