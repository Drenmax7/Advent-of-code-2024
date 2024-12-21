#ifndef JOUR17
#define JOUR17

#include "parseur.hpp"

#include <vector>
#include <chrono>
#include <math.h>

using namespace std;

class Jour17 {
public:
    static void solution(vector<string>& reponse);
    static string part1();
    static string part2();

    class Processeur {
    public:
        static long long a;
        static long long b;
        static long long c;

        static int pointer;

        static vector<int> instructionList;
        static vector<int> output;

        static void inline start() {
            pointer = 0;
            output.clear();

            while (pointer < instructionList.size()) {
                int instruction = instructionList[pointer];
                int operand = instructionList[pointer+1];

                pointer += 2;

                switch (instruction)
                {
                case 0:
                    adv(operand);
                    break;
                case 1:
                    bxl(operand);
                    break;
                case 2:
                    bst(operand);
                    break;
                case 3:
                    jnz(operand);
                    break;
                case 4:
                    bxc(operand);
                    break;
                case 5:
                    out(operand);
                    break;
                case 6:
                    bdv(operand);
                    break;
                case 7:
                    cdv(operand);
                    break;
                default:
                    break;
                }
            }
        }

        static long long inline combo(int operand) {
            switch (operand) {
            case 0:
                return operand;
            case 1:
                return operand;
            case 2:
                return operand;
            case 3:
                return operand;
            case 4:
                return a;
            case 5:
                return b;
            case 6:
                return c;
            default:
                cout << operand << " is not a valide operand";
            }
        }

        //division store in a
        static void inline adv(int operand) {
            //cout << "division store in a " << a << " " << combo(operand) << endl;
            long long result = a / (long long)pow(2, combo(operand));
            a = result;
        }

        //bitwise xor
        static void inline bxl(int operand) {
            //cout << "bitwise xor b " << b << " " << operand << endl;
            long long result = b ^ operand;
            b = result;
        }

        //modulo 8
        static void inline bst(int operand) {
            //cout << "modulo 8 in b " << combo(operand) << endl;
            long long result = combo(operand) % 8;
            b = result;
        }

        //jump if a
        static void inline jnz(int operand) {
            //cout << "jump to if a " << a << " " << operand << endl;
            if (a) {
                pointer = operand;
            }
        }

        //bitwise xor b c
        static void inline bxc(int operand) {
            //cout << "bitwise xor b et c " << b << " " << c << endl;
            long long result = b ^ c;
            b = result;
        }

        //print
        static void inline out(int operand) {
            //cout << "print " << combo(operand) % 8 << endl;
            long long result = combo(operand) % 8;
            output.push_back((int)result);
        }


        //division store in b
        static void inline bdv(int operand) {
            //cout << "division store in b " << a << " " << combo(operand) << endl;
            long long result = a / (long long)pow(2, combo(operand));
            b = result;
        }

        //division store in c
        static void inline cdv(int operand) {
            //cout << "division store in c " << a << " " << combo(operand) << endl;
            long long result = a / (long long)pow(2, combo(operand));
            c = result;
        }
    };
};

/*
b = a % 8
b = b ^ 1
c = a / 2**b
b = b ^ 5
b = b ^ c
a = a / 8
print(b)
goto 0

b = a % 8
b = b ^ 1
c = a / 2**b
b = b ^ 5
b = b ^ c
a = a / 8

117440 / 8 % 8 = 0
117440 /8^2 % 8 = 3
117440 / 8^3 % 8 = 5
117440 / 8^4 % 8 = 4
117440 / 8^5 % 8 = 3
117440 / 8^6 % 8 = 0


*/


#endif
