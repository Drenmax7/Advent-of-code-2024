#include "j11.hpp"

void Jour11::solution(vector<string>& reponse) {

	cout << "Jour 11 :" << endl;
	
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

string Jour11::part1() {
	vector<string> instance = readLinesFromFile("instance/j11.txt");
	string retourFonction;
	long long resultat = 0;

	vector<string> stones = split(instance[0], " ");

	for (int blink = 0; blink < 25; blink++) {
		vector<string> newStones;
		for (int i = 0; i < stones.size(); i++) {
			string valeur = stones[i];

			if (valeur == "0") {
				newStones.push_back("1");
			}
			else if (valeur.size() % 2 == 0) {
				string left = valeur.substr(0, valeur.size() / 2);
				newStones.push_back(left);

				string right = valeur.substr(valeur.size() / 2);
				right = to_string(stoll(right));
				newStones.push_back(right);
			}
			else {
				newStones.push_back(to_string(stoll(valeur)*2024));

			}
		}
		stones = move(newStones);
	}

	resultat = stones.size();

	retourFonction = to_string(resultat);
	return retourFonction;
}



string Jour11::part2() {
	vector<string> instance = readLinesFromFile("instance/j11.txt");
	string retourFonction;
	long long resultat = 0;

	map<string, long long> stones;
	vector<string> stonesVec = split(instance[0], " ");
	for (int i = 0; i < stonesVec.size(); i++) {
		stones[stonesVec[i]]++;
	}

	for (int blink = 0; blink < 75; blink++) {
		map<string, long long> newStones;

		for (pair<string, long long> keyValue : stones) {
			string valeur = keyValue.first;

			if (valeur == "0") {
				newStones["1"] += keyValue.second;
			}
			else if (valeur.size() % 2 == 0) {
				string left = valeur.substr(0, valeur.size() / 2);
				newStones[left] += keyValue.second;

				string right = valeur.substr(valeur.size() / 2);
				right = to_string(stoll(right));
				newStones[right] += keyValue.second;
			}
			else {
				newStones[to_string(stoll(valeur) * 2024)] += keyValue.second;

			}
		}

		stones = move(newStones);
	}

	for (pair<string, long long> keyValue : stones) {
		if (keyValue.second < 0) cout << keyValue.second << endl;
		resultat += keyValue.second;
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}