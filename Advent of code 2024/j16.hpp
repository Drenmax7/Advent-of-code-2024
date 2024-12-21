#ifndef JOUR16
#define JOUR16

#include "parseur.hpp"

#include <vector>
#include <chrono>

using namespace std;

class Jour16 {
public:
    static void solution(vector<string>& reponse);
    static string part1();
    static string part2();

    static void insertTrie(vector<vector<int>>& attente, vector<vector<vector<int>>>& chemins, vector<int> point, vector<vector<int>>& chemin);
};


#endif
