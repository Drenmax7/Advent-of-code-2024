#include "j6.hpp"

void Jour6::solution(vector<string>& reponse) {

	cout << "Jour 6 :" << endl;
	
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


int Jour6::simulePassage(vector<string>& instance, vector<vector<bool>>& chemin, bool checkBoucle) {
	int resultat = 0;

	vector<int> direction = { -1,0 };
	vector<int> position(2);

	vector<vector<vector<int>>> historiqueDirectionParPosition(instance.size() * instance[0].size());

	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			if (instance[i][j] == '^') {
				position[0] = i;
				position[1] = j;
			}
		}
	}
	chemin[position[0]][position[1]] = 1;
	int indice = position[0] * (int)instance.size() + position[1];
	historiqueDirectionParPosition[indice].push_back(direction);

	bool boucle = false;
	while (true) {
		//the guard has reach his final step
		if (position[0] + direction[0] < 0 || position[0] + direction[0] >= instance.size() ||
			position[1] + direction[1] < 0 || position[1] + direction[1] >= instance[0].size()) {
			break;
		}

		position[0] += direction[0];
		position[1] += direction[1];

		while (instance[position[0]][position[1]] == '#') {
			position[0] -= direction[0];
			position[1] -= direction[1];

			//turn right
			int temp = direction[0];
			direction[0] = direction[1];
			direction[1] = -temp;

			position[0] += direction[0];
			position[1] += direction[1];
		}

		if (checkBoucle) {
			int indice = position[0] * (int)instance.size() + position[1];

			for (int i = 0; i < historiqueDirectionParPosition[indice].size(); i++) {
				if (direction == historiqueDirectionParPosition[indice][i]) {
					boucle = true;
					break;
				}
			}
		}
		if (boucle) break;

		chemin[position[0]][position[1]] = 1;
		int indice = position[0] * (int)instance.size() + position[1];
		historiqueDirectionParPosition[indice].push_back(direction);
	}

	for (int i = 0; i < chemin.size(); i++) {
		for (int j = 0; j < chemin[0].size(); j++) {
			resultat += chemin[i][j];
		}
	}

	if (boucle) {
		return -1;
	}
	else {
		return resultat;
	}
}


string Jour6::part1() {
	vector<string> instance = readLinesFromFile("instance/j6.txt");
	string retourFonction;
	long long resultat = 0;

	vector<vector<bool>> chemin(instance.size(), vector<bool>(instance[0].size(), 0));
	resultat = simulePassage(instance, chemin, 0);

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour6::part2() {
	vector<string> instance = readLinesFromFile("instance/j6.txt");
	string retourFonction;
	long long resultat = 0;

	vector<vector<bool>> chemin(instance.size(), vector<bool>(instance[0].size(), 0));
	simulePassage(instance, chemin, 0);

	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			if (chemin[i][j] == 1 && instance[i][j] == '.') {
				instance[i][j] = '#';

				vector<vector<bool>> chemin2(instance.size(), vector<bool>(instance[0].size(), 0));
				bool boucle = simulePassage(instance, chemin2, 1) == -1;
				if (boucle) {
					resultat++;
				}

				instance[i][j] = '.';
			}
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}