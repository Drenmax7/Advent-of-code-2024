#include "j21.hpp"

void Jour21::solution(vector<string>& reponse) {

	cout << "Jour 21 :" << endl;
	
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

string Jour21::part1() {
	vector<string> instance = readLinesFromFile("instance/j21.txt");
	string retourFonction = "";
	long long resultat = 0;

	for (string code : instance) {
		vector<string> chemins = convertNumericalToRobot(code);
		supprimeTordu(chemins);

		vector<string> cheminsT1;
		for (string path : chemins) {
			vector<string> someCheminsT1 = convertRobotToRobot(path);

			cheminsT1.insert(cheminsT1.end(), someCheminsT1.begin(),someCheminsT1.end());
		}
		supprimeLong(cheminsT1);
		supprimeTordu(cheminsT1);
		
		vector<string> cheminsT2;
		for (string path : cheminsT1) {
			vector<string> someCheminsT2 = convertRobotToRobot(path);

			cheminsT2.insert(cheminsT2.end(), someCheminsT2.begin(), someCheminsT2.end());
		}
		supprimeLong(cheminsT2);

		resultat += cheminsT2[0].size() * stoi(code.substr(0, 3)); 
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour21::part2() {
	vector<string> instance = readLinesFromFile("instance/j21.txt");
	string retourFonction = "";
	long long resultat = 0;

	for (string code : instance) {
		vector<string> chemins = convertNumericalToRobot(code);
		supprimeTordu(chemins);

		vector<string> cheminsT1;
		for (string path : chemins) {
			vector<string> someCheminsT1 = convertRobotToRobot(path);

			cheminsT1.insert(cheminsT1.end(), someCheminsT1.begin(), someCheminsT1.end());
		}
		supprimeLong(cheminsT1);
		supprimeTordu(cheminsT1);

		vector<string> cheminsT2;
		for (string path : cheminsT1) {
			vector<string> someCheminsT2 = convertRobotToRobot(path);

			cheminsT2.insert(cheminsT2.end(), someCheminsT2.begin(), someCheminsT2.end());
		}
		supprimeLong(cheminsT2);

		resultat += cheminsT2[0].size() * stoi(code.substr(0, 3));
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

int Jour21::scoreDroiture(const string& chemin) {
	int score = 0;
	for (int i = 1; i < chemin.size(); i++) {
		if (chemin[i] == chemin[i - 1]) {
			score++;
		}
	}
	return score;
}

void Jour21::supprimeTordu(vector<string>& chemins) {
	map<string,int> scores;
	for (int i = 0; i < chemins.size(); i++) {
		scores[chemins[i]] = scoreDroiture(chemins[i]);
	}

	auto it = max_element(chemins.begin(), chemins.end(), 
		[&](const string& a, const string& b) { return scores[a] < scores[b]; });
	int scoreMax = scores[(*it)];

	vector<string> correct;
	for (int i = 0; i < chemins.size(); i++) {
		if (scores[chemins[i]] == scoreMax) {
			correct.push_back(chemins[i]);
		}
	}
	chemins = move(correct);
}

void Jour21::supprimeLong(vector<string>& chemins) {
	auto it = min_element(chemins.begin(), chemins.end(), 
		[&](const string& a, const string& b) { return a.size() < b.size(); });

	int tailleMin = (*it).size();

	vector<string> correct;
	for (int i = 0; i < chemins.size(); i++) {
		if (chemins[i].size() == tailleMin) {
			correct.push_back(chemins[i]);
		}
	}
	chemins = move(correct);
}

vector<string> Jour21::permutation(vector<int> start, vector<int> end, vector<int> gap) {
	vector<string> perm;

	if (end[0] - start[0] > 0) {
		vector<int> newStart = { start[0] + 1, start[1] };

		if (newStart != gap) {
			vector<string> result = permutation(newStart, end, gap);
			for (string k : result) {
				perm.push_back('v' + k);
			}
		}
	}

	if (end[0] - start[0] < 0) {
		vector<int> newStart = { start[0] - 1, start[1] };

		if (newStart != gap) {
			vector<string> result = permutation(newStart, end, gap);
			for (string k : result) {
				perm.push_back('^' + k);
			}
		}
	}

	if (end[1] - start[1] > 0) {
		vector<int> newStart = { start[0], start[1] +1};

		if (newStart != gap) {
			vector<string> result = permutation(newStart, end, gap);
			for (string k : result) {
				perm.push_back('>' + k);
			}
		}
	}

	if (end[1] - start[1] < 0) {
		vector<int> newStart = { start[0], start[1] - 1 };

		if (newStart != gap) {
			vector<string> result = permutation(newStart, end, gap);
			for (string k : result) {
				perm.push_back('<' + k);
			}
		}
	}

	if (start == end) {
		perm.push_back("");
	}

	return perm;
}

vector<string> Jour21::convertNumericalToRobot(string code) {
	vector<int> start, end;
	vector<string> chemins = { "" };

	start = getCoNumerical('A');

	for (int i = 0; i < code.size(); i++) {
		end = getCoNumerical(code[i]);
		vector<string> perm = permutation(start, end, {3,0});

		vector<string> tempChemin;
		for (string past : chemins) {
			for (string present : perm) {
				tempChemin.push_back(past + present + 'A');
			}
		}
		chemins = move(tempChemin);

		start = end;
	}

	return chemins;
}

vector<string> Jour21::convertRobotToRobot(string code) {
	vector<int> start, end;
	vector<string> chemins = { "" };

	start = getCoDirectionnal('A');

	for (int i = 0; i < code.size(); i++) {
		end = getCoDirectionnal(code[i]);
		vector<string> perm = permutation(start, end, {0,0});

		vector<string> tempChemin;
		for (string past : chemins) {
			for (string present : perm) {
				tempChemin.push_back(past + present + 'A');
			}
		}
		chemins = move(tempChemin);

		start = end;
	}

	return chemins;
}

/*
	+---+---+
	| ^ | A |
+---+---+---+
| < | v | > |
+---+---+---+
*/
vector<int> Jour21::getCoDirectionnal(char symbole) {
	switch (symbole)
	{
	case '<':
		return { 1,0 };
	case '>':
		return { 1,2 };
	case '^':
		return { 0,1 };
	case 'v':
		return { 1,1 };
	case 'A':
		return { 0,2 };
	}
}

/*
+---+---+---+
| 7 | 8 | 9 |
+---+---+---+
| 4 | 5 | 6 |
+---+---+---+
| 1 | 2 | 3 |
+---+---+---+
	| 0 | A |
	+---+---+
*/
vector<int> Jour21::getCoNumerical(char symbole) {
	switch (symbole)
	{
	case '7':
		return { 0,0 };
	case '8':
		return { 0,1 };
	case '9':
		return { 0,2 };
	case '4':
		return { 1,0 };
	case '5':
		return { 1,1 };
	case '6':
		return { 1,2 };
	case '1':
		return { 2,0 };
	case '2':
		return { 2,1 };
	case '3':
		return { 2,2 };
	case '0':
		return { 3,1 };
	case 'A':
		return { 3,2 };
	}
}