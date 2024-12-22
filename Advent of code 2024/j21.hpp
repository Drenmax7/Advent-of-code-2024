#ifndef JOUR21
#define JOUR21

#include "parseur.hpp"

#include <vector>
#include <map>
#include <chrono>
#include <map>


using namespace std;

class Jour21 {
public:
    static void solution(vector<string>& reponse);
    static string part1();
    static string part2();

    static vector<string> permutation(vector<int> start, vector<int> end, vector<int> gap);
    inline static vector<int> getCoNumerical(char symbole);
    inline static vector<int> getCoDirectionnal(char symbole);
    inline static vector<string> convertNumericalToRobot(string code);
    inline static vector<string> convertRobotToRobot(string code);

    inline static void supprimeLong(vector<string>& chemins);
    inline static void supprimeTordu(vector<string>& chemins);
    inline static int scoreDroiture(const string& chemin);
};


#endif
