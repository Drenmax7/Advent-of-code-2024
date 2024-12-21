#ifndef JOUR13
#define JOUR13

#include "parseur.hpp"

#include <vector>
#include <chrono>
#include <math.h>

using namespace std;

class Jour13 {
public:
    static void solution(vector<string>& reponse);
    static string part1();
    static string part2();

    static int minButtonPress(int LeftA, int RightA, int LeftB, int RightB, int LeftObj, int RightObj);
};


#endif
