#include "j10.hpp"

void Jour10::solution(vector<string>& reponse) {

	cout << "Jour 10 :" << endl;
	
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

string Jour10::part1() {
	vector<string> instance = readLinesFromFile("instance/j10.txt");
	string retourFonction;
	long long resultat = 0;

	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			vector<vector<int>> vu;
			if (instance[i][j] == '0') {
				resultat += scoreChemin(i, j, instance, vu);
			}
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

int Jour10::scoreChemin(int i, int j, vector<string> map, vector<vector<int>>& vu) {
	int valeur = map[i][j] - '0';

	if (valeur == 9) {
		bool present = false;
		for (int k = 0; k < vu.size(); k++) {
			if (vu[k][0] == i && vu[k][1] == j) {
				present = true;
			}
		}


		if (!present) {
			vu.push_back({ i,j });
			return 1;
		}
		else {
			return 0;
		}
	}

	int score = 0;
	for (int di = -1; di <= 1; di++) {
		for (int dj = -1; dj <= 1; dj++) {
			if (di == 0 && dj == 0 || di != 0 && dj != 0) {
				continue;
			}

			if (i + di < 0 || i + di >= map.size() || j + dj < 0 || j + dj >= map[0].size()) {
				continue;
			}

			if (map[i + di][j + dj] - '0' == valeur + 1) {
				score += scoreChemin(i + di, j + dj, map, vu);
			}
		}
	}

	return score;
}

string Jour10::part2() {
	vector<string> instance = readLinesFromFile("instance/j10.txt");
	string retourFonction;
	long long resultat = 0;

	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			if (instance[i][j] == '0') {
				resultat += scoreChemin2(i, j, instance);
			}
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

int Jour10::scoreChemin2(int i, int j, vector<string> map) {
	int valeur = map[i][j] - '0';

	if (valeur == 9) {
		return 1;
	}

	int score = 0;
	for (int di = -1; di <= 1; di++) {
		for (int dj = -1; dj <= 1; dj++) {
			if (di == 0 && dj == 0 || di != 0 && dj != 0) {
				continue;
			}

			if (i + di < 0 || i + di >= map.size() || j + dj < 0 || j + dj >= map[0].size()) {
				continue;
			}

			if (map[i + di][j + dj] - '0' == valeur + 1) {
				score += scoreChemin2(i + di, j + dj, map);
			}
		}
	}

	return score;
}