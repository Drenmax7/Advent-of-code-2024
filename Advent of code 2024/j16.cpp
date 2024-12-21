#include "j16.hpp"

void Jour16::solution(vector<string>& reponse) {

	cout << "Jour 16 :" << endl;
	
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

string Jour16::part1() {
	vector<string> instance = readLinesFromFile("instance/j16.txt");
	string retourFonction;
	long long resultat = 0;


	vector<int> start, end;
	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			if (instance[i][j] == 'S') {
				start = { i,j, 0, 0};
				instance[i][j] = '.';
			}
			if (instance[i][j] == 'E') {
				end = { i,j };
				instance[i][j] = '.';
			}
		}
	}

	vector<vector<int>> attente = { start };
	vector<vector<vector<unsigned int>>> vu(instance.size(),vector<vector<unsigned int>>(instance[0].size(), vector<unsigned int>(4,-1)));
	vector<vector<vector<int>>> chemins(1,vector<vector<int>>(1,start));

	vu[start[0]][start[1]][start[2]] = 0;

	vector<vector<vector<int>>> meilleurChemin;
	vector<vector<int>> cheminActuel;
	vector<int> checkPoint;
	unsigned int meilleurScore = -1;
	bool arrive = false;
	while (!attente.empty() && !arrive) {
		checkPoint = attente[attente.size()-1];
		attente.pop_back();

		cheminActuel = chemins[chemins.size() - 1];
		chemins.pop_back();

		int x, y, d;
		y = checkPoint[0];
		x = checkPoint[1];
		d = checkPoint[2];

		if ((unsigned int)checkPoint[3] > meilleurScore) {
			break;
		}

		if (y == end[0] && x == end[1]) {
			meilleurScore = checkPoint[3];
			meilleurChemin.push_back(cheminActuel);
		}
		

		vector<int> direction;
		switch (d) {
		case 0:
			direction = { 0,1 };
			break;
		case 1:
			direction = { -1,0 };
			break;
		case 2:
			direction = { 0,-1 };
			break;
		case 3:
			direction = { 1,0 };
			break;
		}


		for (int dDir = 1; dDir <= 3; dDir += 2) {
			if (vu[y][x][(d + dDir) % 4] > (unsigned int)checkPoint[3] + 1000) {
				vu[y][x][(d + dDir) % 4] = checkPoint[3] + 1000;
				insertTrie(attente, chemins, { y,x,(d + dDir) % 4, checkPoint[3] + 1000 }, cheminActuel);
			}
		}


		if (instance[y + direction[0]][x + direction[1]] == '.') {

			y += direction[0];
			x += direction[1];
			int compte = 1;

			while (instance[y + direction[1]][x + direction[0]] == '#' && instance[y - direction[1]][x - direction[0]] == '#' && instance[y + direction[0]][x + direction[1]] == '.') {
				y += direction[0];
				x += direction[1];
				compte++;
			}


			if (compte > 0 && vu[y][x][d] > (unsigned int)checkPoint[3] + compte) {
				vu[y][x][d] = checkPoint[3] + compte;
				vector<vector<int>> copieCheminActuel = cheminActuel;
				copieCheminActuel.push_back({ y,x });
				insertTrie(attente, chemins, { y,x,d, checkPoint[3] + compte }, copieCheminActuel);
			}
		}
	}

	/*for (vector<int> point : vraiChemin) {
		instance[point[0]][point[1]] = 'O';
	}

	for (string ligne : instance) {
		cout << ligne << endl;
	}*/

	resultat = meilleurScore;

	retourFonction = to_string(resultat);
	return retourFonction;
}

void Jour16::insertTrie(vector<vector<int>>& attente, vector<vector<vector<int>>>& chemins, vector<int> point, vector<vector<int>>& chemin) {
	auto it2 = chemins.begin();
	auto it = attente.begin();
	for (it = attente.begin(); it != attente.end(); it++) {
		if ((*it)[3] <= point[3]) {
			break;
		}
		it2++;
	}

	if (chemin.size() < 2) {
		chemin.push_back(point);
	}
	else {
		vector<int> a = chemin[chemin.size() - 2];
		vector<int> b = point;

		vector<int> direction;
		if (a[0] - b[0] > 0) {
			direction = { -1,0 };
		}
		else if (a[0] - b[0] < 0) {
			direction = { 1,0 };
		}
		else if (a[1] - b[1] > 0) {
			direction = { 0,-1 };
		}
		else if (a[1] - b[1] < 0) {
			direction = { 0,1 };
		}

		chemin.push_back(a);
		while (a[0] != b[0] || a[1] != b[1]) {
			a[0] += direction[0];
			a[1] += direction[1];
			chemin.push_back(a);
		}
	}

	attente.insert(it, point);
	chemins.insert(it2, chemin);

}

string Jour16::part2() {
	vector<string> instance = readLinesFromFile("instance/j16.txt");
	string retourFonction;
	long long resultat = 0;


	vector<int> start, end;
	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			if (instance[i][j] == 'S') {
				start = { i,j, 0, 0 };
				instance[i][j] = '.';
			}
			if (instance[i][j] == 'E') {
				end = { i,j };
				instance[i][j] = '.';
			}
		}
	}
	

	vector<vector<int>> attente = { start };
	vector<vector<vector<pair<unsigned int, vector<vector<int>>>>>> vu(instance.size(), vector<vector<pair<unsigned int, vector<vector<int>>>>>(instance[0].size(), vector<pair<unsigned int, vector<vector<int>>>>(4, pair<unsigned int, vector<vector<int>>>(-1, vector<vector<int>>()))));
	vector<vector<vector<int>>> chemins(1, vector<vector<int>>(1, start));

	vu[start[0]][start[1]][start[2]].first = 0;

	vector<vector<vector<int>>> meilleurChemin;
	vector<vector<int>> cheminActuel;
	vector<int> checkPoint;
	unsigned int meilleurScore = -1;
	while (!attente.empty()) {
		checkPoint = attente[attente.size() - 1];
		attente.pop_back();


		int x, y, d;
		y = checkPoint[0];
		x = checkPoint[1];
		d = checkPoint[2];

		/*cheminActuel = chemins[chemins.size() - 1];
		chemins.pop_back();*/
		cheminActuel = vu[y][x][d].second;

		if ((unsigned int)checkPoint[3] > meilleurScore) {
			break;
		}

		if (y == end[0] && x == end[1]) {
			meilleurScore = checkPoint[3];
			meilleurChemin.push_back(cheminActuel);
			for (vector<int> point : cheminActuel) {
				cout << point[0] << " " << point[1] << endl;
			}
			continue;
		}


		vector<int> direction;
		switch (d) {
		case 0:
			direction = { 0,1 };
			break;
		case 1:
			direction = { -1,0 };
			break;
		case 2:
			direction = { 0,-1 };
			break;
		case 3:
			direction = { 1,0 };
			break;
		}

		for (int dDir = 1; dDir <= 3; dDir += 2) {
			if (vu[y][x][(d + dDir) % 4].first > (unsigned int)checkPoint[3] + 1000) {
				vu[y][x][(d + dDir) % 4].first = checkPoint[3] + 1000;
				vu[y][x][(d + dDir) % 4].second = cheminActuel;
				vu[y][x][(d + dDir) % 4].second.push_back({ y,x });
				insertTrie(attente, chemins, { y,x,(d + dDir) % 4, checkPoint[3] + 1000 }, vu[y][x][(d + dDir) % 4].second);
			}
			else if (vu[y][x][(d + dDir) % 4].first == checkPoint[3] + 1000) {
				for (vector<int> point : cheminActuel) {
					bool present = false;
					for (vector<int> point2 : vu[y][x][(d + dDir) % 4].second) {
						if (point[0] == point2[0] && point[1] == point2[1]) {
							present = true;
						}
					}
					if (!present) {
						vu[y][x][(d + dDir) % 4].second.push_back(point);
					}
				}
			}

		}


		if (instance[y + direction[0]][x + direction[1]] == '.') {

			y += direction[0];
			x += direction[1];
			int compte = 1;

			while (instance[y + direction[1]][x + direction[0]] == '#' && instance[y - direction[1]][x - direction[0]] == '#' && instance[y + direction[0]][x + direction[1]] == '.') {
				y += direction[0];
				x += direction[1];
				compte++;
			}


			if (compte > 0 && vu[y][x][d].first > (unsigned int)checkPoint[3] + compte) {
				vu[y][x][d].first = checkPoint[3] + compte;
				vector<vector<int>> copieCheminActuel = cheminActuel;
				copieCheminActuel.push_back({ y,x });
				vu[y][x][d].second = copieCheminActuel;
				insertTrie(attente, chemins, { y,x,d, checkPoint[3] + compte }, copieCheminActuel);
			}
			else if (compte > 0 && vu[y][x][d].first == checkPoint[3] + compte) {
				for (vector<int> point : cheminActuel) {
					bool present = false;
					for (vector<int> point2 : vu[y][x][d].second) {
						if (point[0] == point2[0] && point[1] == point2[1]) {
							present = true;
						}
					}
					if (!present) {
						vu[y][x][d].second.push_back(point);
					}
				}
			}
		}
	}

	meilleurChemin.clear();
	for (int i = 0; i < 3; i++) {
		cout << vu[end[0]][end[1]][i].second.size() << endl;
		meilleurChemin.push_back(vu[end[0]][end[1]][i].second);
	}

	for (vector<vector<int>> chemin : meilleurChemin) {
		for (int i = 0; i < chemin.size(); i++) {
			vector<int> a = chemin[i];
			instance[a[0]][a[1]] = 'O';
		}
	}

	for (string ligne : instance) {
		cout << ligne << endl;
	}

	int compte = 0;
	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			if (instance[i][j] == 'O') {
				compte++;
			}
		}
	}
	resultat = compte;

	retourFonction = to_string(resultat);
	return retourFonction;
}