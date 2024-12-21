#ifndef JOUR7
#define JOUR7

#include "parseur.hpp"

#include <vector>
#include <chrono>

using namespace std;

class Jour7 {
public:
    static void solution(vector<string>& reponse);
    static string part1();
    static string part2();

    static bool resoud(long long valeur, vector<long long>& operandes);
    static bool resoud2(long long valeur, vector<long long>& operandes, vector<string>& ordre);
};


#endif
