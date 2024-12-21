#include "j8.hpp"

void Jour8::solution(vector<string>& reponse) {

	cout << "Jour 8 :" << endl;
	
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

string Jour8::part1() {
	vector<string> instance = readLinesFromFile("instance/j8.txt");
	string retourFonction;
	long long resultat = 0;

	vector<vector<bool>> antinode(instance.size(), vector<bool>(instance[0].size(), 0));
	map<char, vector<vector<int>>> antennesVu;

	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			char antenne = instance[i][j];
			if (antenne != '.') {
				if (antennesVu.count(antenne) == 0) {
					vector<vector<int>> liste(0);
					antennesVu[antenne] = liste;
				}

				for (int k = 0; k < antennesVu[antenne].size(); k++) {
					vector<int> autreAntenne = antennesVu[antenne][k];

					vector<int> antinode1(2);
					vector<int> antinode2(2);

					antinode1[0] = 2*autreAntenne[0] - i;
					antinode2[0] = 2*i - autreAntenne[0];

					antinode1[1] = 2*autreAntenne[1] - j;
					antinode2[1] = 2*j - autreAntenne[1];

					if (0 <= antinode1[0] && antinode1[0] < instance.size() && 0 <= antinode1[1] && antinode1[1] < instance[0].size()) {
						antinode[antinode1[0]][antinode1[1]] = 1;
					}

					if (0 <= antinode2[0] && antinode2[0] < instance.size() && 0 <= antinode2[1] && antinode2[1] < instance[0].size()) {
						antinode[antinode2[0]][antinode2[1]] = 1;
					}
				}

				vector<int> coAntenne(2);
				coAntenne[0] = i;
				coAntenne[1] = j;
				antennesVu[antenne].push_back(coAntenne);
			}
		}
	}

	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			if (antinode[i][j]) {
				resultat++;
			}
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour8::part2() {
	vector<string> instance = readLinesFromFile("instance/j8.txt");
	string retourFonction;
	long long resultat = 0;

	vector<vector<bool>> antinode(instance.size(), vector<bool>(instance[0].size(), 0));
	map<char, vector<vector<int>>> antennesVu;

	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			char antenne = instance[i][j];
			if (antenne != '.') {
				if (antennesVu.count(antenne) == 0) {
					vector<vector<int>> liste(0);
					antennesVu[antenne] = liste;
				}

				for (int k = 0; k < antennesVu[antenne].size(); k++) {
					vector<int> autreAntenne = antennesVu[antenne][k];

					vector<int> antinode1(2);
					vector<int> antinode2(2);
					int diffX, diffY;

					antinode1[0] = autreAntenne[0];
					antinode1[1] = autreAntenne[1];

					diffY = autreAntenne[0] - i;
					diffX = autreAntenne[1] - j;

					while (0 <= antinode1[0] && antinode1[0] < instance.size() && 0 <= antinode1[1] && antinode1[1] < instance[0].size()) {
						antinode[antinode1[0]][antinode1[1]] = 1;
						antinode1[0] += diffY;
						antinode1[1] += diffX;
					}


					antinode2[0] = i;
					antinode2[1] = j;

					diffY = i - autreAntenne[0];
					diffX = j - autreAntenne[1];


					while (0 <= antinode2[0] && antinode2[0] < instance.size() && 0 <= antinode2[1] && antinode2[1] < instance[0].size()) {
						antinode[antinode2[0]][antinode2[1]] = 1;
						antinode2[0] += diffY;
						antinode2[1] += diffX;
					}
				}

				vector<int> coAntenne(2);
				coAntenne[0] = i;
				coAntenne[1] = j;
				antennesVu[antenne].push_back(coAntenne);
			}
		}
	}

	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			if (antinode[i][j]) {
				resultat++;
			}
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}