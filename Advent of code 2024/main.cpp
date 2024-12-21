#include "main.hpp"

int main()
{
	cout << "Advent of code 2024\n" << endl;

	auto start1 = chrono::high_resolution_clock::now();

	int debut = 20;
	int fin = 25;

    //a opti : 
    // 6-2 4s
    // 7-2 2s
    // 12-2 12s
    // 14-2 10s

	vector<string> reponse(0);

	switch (debut)
	{
    case 1: {
        Jour1::solution(reponse);
        if (1 >= fin) break;
    }
    case 2: {
        Jour2::solution(reponse);
        if (2 >= fin) break;
    }
    case 3: {
        Jour3::solution(reponse);
        if (3 >= fin) break;
    }
    case 4: {
        Jour4::solution(reponse);
        if (4 >= fin) break;
    }
    case 5: {
        Jour5::solution(reponse);
        if (5 >= fin) break;
    }
    case 6: {
        Jour6::solution(reponse);
        if (6 >= fin) break;
    }
    case 7: {
        Jour7::solution(reponse);
        if (7 >= fin) break;
    }
    case 8: {
        Jour8::solution(reponse);
        if (8 >= fin) break;
    }
    case 9: {
        Jour9::solution(reponse);
        if (9 >= fin) break;
    }
    case 10: {
        Jour10::solution(reponse);
        if (10 >= fin) break;
    }
    case 11: {
        Jour11::solution(reponse);
        if (11 >= fin) break;
    }
    case 12: {
        Jour12::solution(reponse);
        if (12 >= fin) break;
    }
    case 13: {
        Jour13::solution(reponse);
        if (13 >= fin) break;
    }
    case 14: {
        Jour14::solution(reponse);
        if (14 >= fin) break;
    }
    case 15: {
        Jour15::solution(reponse);
        if (15 >= fin) break;
    }
    case 16: {
        Jour16::solution(reponse);
        if (16 >= fin) break;
    }
    case 17: {
        Jour17::solution(reponse);
        if (17 >= fin) break;
    }
    case 18: {
        Jour18::solution(reponse);
        if (18 >= fin) break;
    }
    case 19: {
        Jour19::solution(reponse);
        if (19 >= fin) break;
    }
    case 20: {
        Jour20::solution(reponse);
        if (20 >= fin) break;
    }
    case 21: {
        Jour21::solution(reponse);
        if (21 >= fin) break;
    }
    case 22: {
        Jour22::solution(reponse);
        if (22 >= fin) break;
    }
    case 23: {
        Jour23::solution(reponse);
        if (23 >= fin) break;
    }
    case 24: {
        Jour24::solution(reponse);
        if (24 >= fin) break;
    }
    case 25: {
        Jour25::solution(reponse);
        if (25 >= fin) break;
    }

	default:
		break;
	}

	auto end1 = chrono::high_resolution_clock::now();
	auto duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

	cout << "\nTotal : " << duration1 << " ms" << endl;

	return 0;
}
