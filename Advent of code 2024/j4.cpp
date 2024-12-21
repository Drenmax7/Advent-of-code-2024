#include "j4.hpp"

void Jour4::solution(vector<string>& reponse) {

	cout << "Jour 4 :" << endl;
	
	auto start1 = chrono::high_resolution_clock::now();
	string result1 = part1();
	auto end1 = chrono::high_resolution_clock::now();
	auto duration1 = chrono::duration_cast<chrono::milliseconds>(end1 - start1).count();

    cout << "\tPartie 1 : " << result1 << " (temps : " << duration1 << " ms)" << endl;

	reponse.push_back(result1);


	auto start2 = chrono::high_resolution_clock::now();
	string result2 = part2();
	auto end2 = chrono::high_resolution_clock::now();
	auto duration2 = chrono::duration_cast<chrono::milliseconds>(end2 - start2).count();

    cout << "\tPartie 2 : " << result2 << " (temps : " << duration2 << " ms)" << endl;

	reponse.push_back(result2);
}

string Jour4::part1() {
	vector<string> instance = readLinesFromFile("instance/j4.txt");
	string retourFonction;
	long long resultat = 0;

	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			for (int k = -1; k <= 1; k++) {
				for (int l = -1; l <= 1; l++) {
					//si pas de direction on passe
					if (k == 0 && l == 0) continue;
					//si la coordonnées x depasse les bordures
					if (i + k * 3 >= instance.size() || i + k * 3 < 0) continue;
					//si la coordonnées y depasse les bordures
					if (j + l * 3 >= instance[0].size() || j + l * 3 < 0) continue;

					string mot = "";
					for (int m = 0; m <= 3; m++) {
						mot += instance[i + k * m][j + l * m];
					}

					if (mot == "XMAS") resultat++;
				}
			}

		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour4::part2() {
	vector<string> instance = readLinesFromFile("instance/j4.txt");
	string retourFonction;
	long long resultat = 0;

	for (int i = 1; i < instance.size() - 1; i++) {
		for (int j = 1; j < instance[0].size() - 1; j++) {
			if (instance[i][j] == 'A') {
				string mot1 = "";
				mot1 += instance[i - 1][j - 1];
				mot1 += instance[i + 1][j + 1];

				string mot2 = "";
				mot2 += instance[i + 1][j - 1];
				mot2 += instance[i - 1][j + 1];

				if ((mot1 == "MS" || mot1 == "SM") && (mot2 == "MS" || mot2 == "SM")) {
					resultat++;
				}
			}

		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}