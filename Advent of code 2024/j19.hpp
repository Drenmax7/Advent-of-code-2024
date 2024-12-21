#ifndef JOUR19
#define JOUR19

#include "parseur.hpp"

#include <vector>
#include <map>
#include <chrono>
#include <map>

using namespace std;

class Jour19 {
public:
    static void solution(vector<string>& reponse);
    static string part1();
    static string part2();
    

    static long long comptePossibilite(vector<string>& patern, string objectif, map<string,long long>& objectifPossible);
};


#endif
