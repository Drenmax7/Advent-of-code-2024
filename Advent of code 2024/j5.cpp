#include "j5.hpp"

void Jour5::solution(vector<string>& reponse) {

	cout << "Jour 5 :" << endl;
	
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

string Jour5::part1() {
	vector<string> instance = readLinesFromFile("instance/j5.txt");
	string retourFonction;
	long long resultat = 0;

	vector<string>::iterator separation = find(instance.begin(), instance.end(), "");
	vector<string> contrainteV(instance.begin(), separation);
	vector<string> instructions(separation + 1, instance.end());

	map<int, vector<int>> contrainte;
	for (string ligne : contrainteV) {
		vector<string> separe = split(ligne, "|");

		int key = stoi(separe[0]);
		int value = stoi(separe[1]);
		if (contrainte.find(key) == contrainte.end()) {
			vector<int> listeContrainte = { value };
			contrainte.insert({ key,listeContrainte });
		}
		else {
			contrainte[key].push_back(value);
		}
	}

	for (string ligne : instructions) {
		vector<string> listeInstruction = split(ligne, ",");
		vector<int> dejaVu;

		bool valide = true;
		for (string nombre : listeInstruction) {
			int page = stoi(nombre);

			if (contrainte.find(page) != contrainte.end()) {
				for (int pageApres : contrainte[page]) {
					bool present = find(dejaVu.begin(), dejaVu.end(), pageApres) != dejaVu.end();
					if (present) {
						valide = false;
						//cout << pageApres << " imprime avant " << page << endl;
						break;
					}
				}
			}
			if (!valide) {
				break;
			}

			dejaVu.push_back(page);
		}

		if (valide) {
			int milieu = (int)dejaVu.size() / 2;
			resultat += dejaVu[milieu];
		}

	}


	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour5::part2() {
	vector<string> instance = readLinesFromFile("instance/j5.txt");
	string retourFonction;
	long long resultat = 0;

	vector<string>::iterator separation = find(instance.begin(), instance.end(), "");
	vector<string> contrainteV(instance.begin(), separation);
	vector<string> instructions(separation + 1, instance.end());

	map<int, vector<int>> contrainte;
	for (string ligne : contrainteV) {
		vector<string> separe = split(ligne, "|");

		int key = stoi(separe[0]);
		int value = stoi(separe[1]);
		if (contrainte.find(key) == contrainte.end()) {
			vector<int> listeContrainte = { value };
			contrainte.insert({ key,listeContrainte });
		}
		else {
			contrainte[key].push_back(value);
		}
	}

	for (string ligne : instructions) {
		vector<string> listeInstruction = split(ligne, ",");
		vector<int> dejaVu;

		bool valide = true;
		for (string nombre : listeInstruction) {
			int page = stoi(nombre);

			if (contrainte.find(page) != contrainte.end()) {
				for (int pageApres : contrainte[page]) {
					bool present = find(dejaVu.begin(), dejaVu.end(), pageApres) != dejaVu.end();
					if (present) {
						valide = false;
						//cout << pageApres << " imprime avant " << page << endl;
					}
				}
			}

			dejaVu.push_back(page);
		}

		if (!valide) {
			vector<int> correct;

			while (!valide) {
				valide = true;
				for (int i = 0; i < dejaVu.size(); i++) {
					int page = dejaVu[i];

					if (contrainte.find(page) != contrainte.end()) {
						for (int pageApres : contrainte[page]) {
							bool present = find(dejaVu.begin(), dejaVu.begin() + i, pageApres) != (dejaVu.begin() + i);

							if (present) {
								valide = false;

								int j = 0;
								while (dejaVu[j] != pageApres) {
									j++;
								}
								swap(dejaVu[i], dejaVu[j]);
								break;
							}
						}
					}
					if (!valide) {
						break;
					}
				}
			}

			int milieu = (int)dejaVu.size() / 2;
			resultat += dejaVu[milieu];
		}
	}


	retourFonction = to_string(resultat);
	return retourFonction;
}