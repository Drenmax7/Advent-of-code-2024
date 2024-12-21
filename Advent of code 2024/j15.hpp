#ifndef JOUR15
#define JOUR15

#include "parseur.hpp"

#include <vector>
#include <chrono>

using namespace std;

class Jour15 {
public:
    static void solution(vector<string>& reponse);
    static string part1();
    static string part2();

    class caisse {
    public:
        caisse(vector<string>& carte, vector<vector<caisse*>>& caisses, vector<int> coordonnees) : carte(carte), caisses(caisses) {
            this->co = coordonnees;
            caisses[co[0]][co[1]] = this;
            caisses[co[0]][co[1]+1] = this;
        };

        vector<string>& carte;
        vector<vector<caisse*>>& caisses;
        //co de la gauche de la caisse
        vector<int> co;

        bool tryPush(vector<int> direction) {
            int checkY = co[0] + direction[0];
            int checkX = co[1] + direction[1];

            bool gauche = true;
            //evite de s'appeler lui meme
            if (caisses[checkY][checkX] != this && caisses[checkY][checkX] != nullptr) {
                gauche = caisses[checkY][checkX]->tryPush(direction);
            }
            if (carte[checkY][checkX] == '#') {
                gauche = false;
            }

            bool droite = true;
            //evite d'appeler 2 fois la fonction de la meme caisse
            if (caisses[checkY][checkX + 1] != this && caisses[checkY][checkX + 1] != nullptr && caisses[checkY][checkX] != caisses[checkY][checkX + 1]) {
                droite = caisses[checkY][checkX+1]->tryPush(direction);
            }
            if (carte[checkY][checkX+1] == '#') {
                droite = false;
            }

            return gauche && droite;
        };

        void push(vector<int> direction) {
            int checkY = co[0] + direction[0];
            int checkX = co[1] + direction[1];

            if (caisses[checkY][checkX] != this && caisses[checkY][checkX] != nullptr) {
                caisses[checkY][checkX]->push(direction);
            }
            if (caisses[checkY][checkX+1] != this && caisses[checkY][checkX+1] != nullptr) {
                caisses[checkY][checkX+1]->push(direction);
            }

            caisses[co[0]][co[1]] = nullptr;
            caisses[co[0]][co[1] + 1] = nullptr;
            carte[co[0]][co[1]] = '.';
            carte[co[0]][co[1] + 1] = '.';

            caisses[checkY][checkX] = this;
            caisses[checkY][checkX + 1] = this;
            carte[checkY][checkX] = '[';
            carte[checkY][checkX + 1] = ']';

            co = { checkY,checkX };
        };
    };
};


#endif
