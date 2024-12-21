#ifndef JOUR14
#define JOUR14

#include "parseur.hpp"

#include <vector>
#include <chrono>

using namespace std;

class Jour14 {
public:
    static void solution(vector<string>& reponse);
    static string part1();
    static string part2();

    static bool verifSapin(vector<vector<bool>> visualisation);
};


#endif
