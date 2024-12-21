#ifndef JOUR6
#define JOUR6

#include "parseur.hpp"

#include <vector>
#include <chrono>

using namespace std;

class Jour6 {
public:
    static void solution(vector<string>& reponse);
    static string part1();
    static string part2();

    static int simulePassage(vector<string>& instance, vector<vector<bool>>& chemin, bool checkBoucle);
};


#endif
