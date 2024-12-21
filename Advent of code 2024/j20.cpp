#include "j20.hpp"

void Jour20::solution(vector<string>& reponse) {

	cout << "Jour 20 :" << endl;
	
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

string Jour20::part1() {
	vector<string> instance = readLinesFromFile("instance/j20.txt");
	string retourFonction = "";
	long long resultat = 0;

	vector<int> end, start;
	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			if (instance[i][j] == 'S') {
				start = { i,j };
			}
			if (instance[i][j] == 'E') {
				end = { i,j };
			}
		}
	}
	vector<vector<int>> path = { start };

	vector<int> direction = { 1,0 };
	bool fini = false;
	while (!fini) {
		vector<int> point = path.back();

		for (int i = 0; i < 4; i++) {
			int temp = direction[0];
			direction[0] = direction[1];
			direction[1] = -temp;

			if (point[0] + direction[0] < 0 || point[0] + direction[0] >= instance.size() || point[1] + direction[1] < 0 || point[1] + direction[1] >= instance[0].size()) {
				continue;
			}


			if (instance[point[0] + direction[0]][point[1] + direction[1]] == '#') {
				continue;
			}

			if (path.size() > 1 && point[0] + direction[0] == path[path.size() - 2][0] &&
				point[1] + direction[1] == path[path.size() - 2][1]) {
				continue;
			}

			if (point[0] + direction[0] == end[0] && point[1] + direction[1] == end[1]) {
				fini = true;
			}

			path.push_back({point[0] + direction[0], point[1] + direction[1]});
			break;
		}
	}

	for (int co = 0; co < path.size(); co++) {
		int i = path[co][0];
		int j = path[co][1];

		for (int k = 0; k < 4; k++) {
			int temp = direction[0];
			direction[0] = direction[1];
			direction[1] = -temp;

			//assure de ne pas sortir de la map
			if (i + direction[0]*2 < 0 || i + direction[0]*2 >= instance.size() || j + direction[1]*2 < 0 || j + direction[1]*2 >= instance[0].size()) {
				continue;
			}

			//assure que ce soit possible de sauter le mur
			if (instance[i + direction[0]][j + direction[1]] != '#' || instance[i + direction[0] * 2][j + direction[1] * 2] == '#') {
				continue;
			}

			int cmpr;
			//permet de trouver le point sur lequelle on atterit en sautant le mur
			for (cmpr = 0; cmpr < path.size(); cmpr++) {
				if (path[cmpr][0] == i + direction[0] * 2 && path[cmpr][1] == j + direction[1] * 2) {
					break;
				}
			}

			//si sauter le mur nous ramene avant
			if (cmpr < co) {
				continue;
			}

			int gain = cmpr - co - 2;
			if (gain >= 100) {
				resultat++;
			}
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour20::part2() {
	vector<string> instance = readLinesFromFile("instance/j20.txt");
	string retourFonction = "";
	long long resultat = 0;



	retourFonction = to_string(resultat);
	return retourFonction;
}