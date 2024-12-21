#include "j14.hpp"

void Jour14::solution(vector<string>& reponse) {

	cout << "Jour 14 :" << endl;
	
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

string Jour14::part1() {
	vector<string> instance = readLinesFromFile("instance/j14.txt");
	string retourFonction;
	long long resultat = 0;

	long long time = 100;
	long long mapWidth = 101;
	long long mapHeight = 103;

	vector<int> quadrant(4, 0);
	for (int i = 0; i < instance.size(); i++) {
		vector<string> posVec = split(instance[i], " ");
		string sPos = posVec[0];
		sPos = sPos.substr(2);
		vector<string> vPos = split(sPos, ",");
		vector<long long> pos = { stoll(vPos[0]) ,stoll(vPos[1]) };

		string sVec = posVec[1];
		sVec = sVec.substr(2);
		vector<string> vVec = split(sVec, ",");
		vector<long long> vec = { stoll(vVec[0]) ,stoll(vVec[1]) };

		pos[0] = (pos[0] + time * vec[0]) % mapWidth;
		if (pos[0] < 0) {
			pos[0] += mapWidth;
		}

		pos[1] = (pos[1] + time * vec[1]) % mapHeight;
		if (pos[1] < 0) {
			pos[1] += mapHeight;
		}

		if (pos[0] < mapWidth / 2 && pos[1] < mapHeight / 2) {
			quadrant[0]++;
		}
		if (pos[0] < mapWidth / 2 && pos[1] > mapHeight / 2) {
			quadrant[1]++;
		}
		if (pos[0] > mapWidth / 2 && pos[1] < mapHeight / 2) {
			quadrant[2]++;
		}
		if (pos[0] > mapWidth / 2 && pos[1] > mapHeight / 2) {
			quadrant[3]++;
		}
	}
	resultat += quadrant[0] * quadrant[1] * quadrant[2] * quadrant[3];

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour14::part2() {
	vector<string> instance = readLinesFromFile("instance/j14.txt");
	std::ofstream file("j14-2/images.txt");

	string retourFonction;
	long long resultat = 0;

	long long mapWidth = 101;
	long long mapHeight = 103;

	for (int time = 0; time < 100000; time++) {

		vector<vector<bool>> visualisation(mapHeight, vector<bool>(mapWidth,false));
		for (int i = 0; i < instance.size(); i++) {
			vector<string> posVec = split(instance[i], " ");
			string sPos = posVec[0];
			sPos = sPos.substr(2);
			vector<string> vPos = split(sPos, ",");
			vector<long long> pos = { stoll(vPos[0]) ,stoll(vPos[1]) };

			string sVec = posVec[1];
			sVec = sVec.substr(2);
			vector<string> vVec = split(sVec, ",");
			vector<long long> vec = { stoll(vVec[0]) ,stoll(vVec[1]) };

			pos[0] = (pos[0] + time * vec[0]) % mapWidth;
			if (pos[0] < 0) {
				pos[0] += mapWidth;
			}

			pos[1] = (pos[1] + time * vec[1]) % mapHeight;
			if (pos[1] < 0) {
				pos[1] += mapHeight;
			}

			visualisation[pos[1]][pos[0]] = true;
		}

		if (verifSapin(visualisation)) {
			for (vector<bool> ligne : visualisation) {
				for (bool value : ligne) {
					file << (value ? '1' : '0'); // Écrire 1 pour true et 0 pour false
				}
				file << '\t'; // Nouvelle ligne pour chaque rangée
			}
			file << "\n";

			resultat = time;
			break;
		}
	}

	file.close();
	retourFonction = to_string(resultat);
	return retourFonction;
}

bool Jour14::verifSapin(vector<vector<bool>> visualisation) {
	int compte = 0;
	for (int i = 0; i < visualisation.size(); i++) {
		for (int j = 0; j < visualisation[0].size(); j++) {
			if (visualisation[i][j]) {
				compte++;
			}
			else {
				compte = 0;
			}

			if (compte >= 10) {
				return true;
			}
		}
	}

	return false;
}