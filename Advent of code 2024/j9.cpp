#include "j9.hpp"

void Jour9::solution(vector<string>& reponse) {

	cout << "Jour 9 :" << endl;
	
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

string Jour9::part1() {
	vector<string> instance = readLinesFromFile("instance/j9.txt");
	string retourFonction;
	long long resultat = 0;

	string compresse = instance[0];
	vector<int> decompresse(0);
	
	int id = 0;

	for (int i = 0; i < compresse.size()/2*2; i += 2) {
		int caractere = compresse[i] - '0';
		for (int j = 0; j < caractere; j++) {
			decompresse.push_back(id);
		}

		caractere = compresse[i+1] - '0';
		for (int j = 0; j < caractere; j++) {
			decompresse.push_back(-1);
		}

		id++;
	}

	if (compresse.size() % 2 == 1) {
		int last = compresse[compresse.size()-1] - '0';
		for (int j = 0; j < last; j++) {
			decompresse.push_back(id);
		}
	}

	int premierVide = 0;
	int dernierPlein = (int)decompresse.size() - 1;

	while (premierVide < dernierPlein) {
		while (decompresse[premierVide] != -1) {
			premierVide++;
		}

		while (decompresse[dernierPlein] == -1) {
			dernierPlein--;
		}

		if (premierVide < dernierPlein) {
			decompresse[premierVide] = decompresse[dernierPlein];
			decompresse[dernierPlein] = -1;
		}
	}


	for (int i = 0; i < decompresse.size(); i++) {
		int id = decompresse[i];
		if (id != -1) {
			resultat += id * i;
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour9::part2() {
	vector<string> instance = readLinesFromFile("instance/j9.txt");
	string retourFonction;
	long long resultat = 0;

	string compresse = instance[0];
	vector<int> decompresse(0);

	int id = 0;

	for (int i = 0; i < compresse.size() / 2 * 2; i += 2) {
		int caractere = compresse[i] - '0';
		for (int j = 0; j < caractere; j++) {
			decompresse.push_back(id);
		}

		caractere = compresse[i + 1] - '0';
		for (int j = 0; j < caractere; j++) {
			decompresse.push_back(-1);
		}

		id++;
	}

	if (compresse.size() % 2 == 1) {
		int last = compresse[compresse.size() - 1] - '0';
		for (int j = 0; j < last; j++) {
			decompresse.push_back(id);
		}

		id++;
	}

	vector<vector<int>> listePlein(id,vector<int>({-1,0}));

	for (int i = 0; i < decompresse.size(); i++) {
		id = decompresse[i];
		if (id != -1) {
			if (listePlein[id][0] == -1) {
				listePlein[id][0] = i;
			}
			listePlein[id][1]++;
		}
	}

	for (int i = (int)listePlein.size()-1; i >= 0; i--) {
		int tailleBloc = listePlein[i][1];
		int depart = listePlein[i][0];

		int longueur = 0;
		for (int j = 0; j < depart; j++) {
			if (decompresse[j] == -1) {
				longueur++;
			}
			else {
				longueur = 0;
			}

			if (longueur == tailleBloc) {
				for (int k = j + 1 - longueur; k <= j; k++) {
					decompresse[k] = i;
				}
				for (int k = depart; k < depart + tailleBloc; k++) {
					decompresse[k] = -1;
				}

				break;
			}
		}
	}

	for (int i = 0; i < decompresse.size(); i++) {
		int id = decompresse[i];
		if (id != -1) {
			resultat += id * i;
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}