#include "j2.hpp"

void Jour2::solution(vector<string>& reponse) {

	cout << "Jour 2 :" << endl;
	
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

string Jour2::part1() {
	vector<string> instance = readLinesFromFile("instance/j2.txt");
	string retourFonction;
	long long resultat = 0;


	vector<vector<int>> levels(instance.size());

	for (int i = 0; i < instance.size(); i++) {
		istringstream stream(instance[i]);
		int number;
		while (stream >> number) {
			levels[i].push_back(number);
		}
	}

	for (int i = 0; i < levels.size(); i++) {
		int premier = levels[i][0];
		bool croissant = true;
		for (int j = 1; j < levels[i].size(); j++) {
			if (levels[i][j] >= premier) {
				premier = levels[i][j];
			}
			else {
				croissant = false;
			}
		}

		premier = levels[i][0];
		bool decroissant = true;
		for (int j = 1; j < levels[i].size(); j++) {
			if (levels[i][j] <= premier) {
				premier = levels[i][j];
			}
			else {
				decroissant = false;
			}
		}

		bool smooth = true;
		for (int j = 1; j < levels[i].size(); j++) {
			int difference = abs(levels[i][j] - levels[i][j - 1]);
			if (difference < 1 || difference > 3) {
				smooth = false;
			}
		}

		if ((croissant || decroissant) && smooth) {
			resultat++;
		}
	}


	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour2::part2() {
	vector<string> instance = readLinesFromFile("instance/j2.txt");
	string retourFonction;
	long long resultat = 0;


	vector<vector<int>> levels(instance.size());

	for (int i = 0; i < instance.size(); i++) {
		istringstream stream(instance[i]);
		int number;
		while (stream >> number) {
			levels[i].push_back(number);
		}
	}

	for (int i = 0; i < levels.size(); i++) {
		bool valide = false;

		for (int k = 0; k < levels[i].size(); k++) {
			vector<int> tentative = levels[i];
			tentative.erase(tentative.begin() + k);

			int premier = tentative[0];
			bool croissant = true;
			for (int j = 1; j < tentative.size(); j++) {
				if (tentative[j] >= premier) {
					premier = tentative[j];
				}
				else {
					croissant = false;
				}
			}

			premier = tentative[0];
			bool decroissant = true;
			for (int j = 1; j < tentative.size(); j++) {
				if (tentative[j] <= premier) {
					premier = tentative[j];
				}
				else {
					decroissant = false;
				}
			}

			bool smooth = true;
			for (int j = 1; j < tentative.size(); j++) {
				int difference = abs(tentative[j] - tentative[j - 1]);
				if (difference < 1 || difference > 3) {
					smooth = false;
				}
			}

			if ((croissant || decroissant) && smooth) {
				valide = true;
			}
		}

		if (valide) resultat++;
	}


	retourFonction = to_string(resultat);
	return retourFonction;
}