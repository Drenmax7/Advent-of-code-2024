#include "j15.hpp"

void Jour15::solution(vector<string>& reponse) {

	cout << "Jour 15 :" << endl;
	
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

string Jour15::part1() {
	vector<string> instance = readLinesFromFile("instance/j15.txt");
	string retourFonction;
	long long resultat = 0;

	int finCarte = 0;
	for (int i = 0; i < instance.size(); i++) {
		if (instance[i] == "") {
			finCarte = i;
			break;
		}
	}

	vector<string> carte(instance.begin(), instance.begin()+finCarte);
	vector<string> vecInstruction(instance.begin() + finCarte + 1, instance.end());
	string instruction = "";
	for (string ligne : vecInstruction) {
		instruction += ligne;
	}

	vector<int> posRobot;
	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			if (instance[i][j] == '@') {
				posRobot = { i,j };
			}
		}
	}

	vector<int> direction;
	for (char fleche : instruction) {
		if (fleche == '^') direction = { -1,0 };
		if (fleche == '<') direction = { 0,-1 };
		if (fleche == '>') direction = { 0,1 };
		if (fleche == 'v') direction = { 1,0 };

		//verifie si le deplacement est possible
		int checkY = posRobot[0] + direction[0];
		int checkX = posRobot[1] + direction[1];
		while (carte[checkY][checkX] == 'O') {
			checkY += direction[0];
			checkX += direction[1];
		}

		//si le deplacement n'est pas possible on passe au suivant
		if (carte[checkY][checkX] == '#') continue;

		//si la case sur laquelle va sur le robot contient une caisse
		if (carte[posRobot[0] + direction[0]][posRobot[1] + direction[1]] == 'O') {
			//pousse toute la rangé de caisse
			carte[checkY][checkX] = 'O';
		}

		//deplace le robot
		carte[posRobot[0]][posRobot[1]] = '.';
		posRobot[0] += direction[0];
		posRobot[1] += direction[1];
		carte[posRobot[0]][posRobot[1]] = '@';
	}

	for (int i = 0; i < carte.size(); i++) {
		for (int j = 0; j < carte[0].size(); j++) {
			if (carte[i][j] == 'O') {
				resultat += i * 100 + j;
			}
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour15::part2() {
	vector<string> instance = readLinesFromFile("instance/j15.txt");
	string retourFonction;
	long long resultat = 0;

	int finCarte = 0;
	for (int i = 0; i < instance.size(); i++) {
		if (instance[i] == "") {
			finCarte = i;
			break;
		}
	}

	vector<string> carteOld(instance.begin(), instance.begin() + finCarte);
	vector<string> carte;
	for (string ligne : carteOld) {
		string newLigne = "";
		for (char car : ligne) {
			if (car == '.') {
				newLigne += "..";
			}
			if (car == '#') {
				newLigne += "##";
			}
			if (car == '@') {
				newLigne += "@.";
			}
			if (car == 'O') {
				newLigne += "[]";
			}
		}
		carte.push_back(newLigne);
	}

	vector<string> vecInstruction(instance.begin() + finCarte + 1, instance.end());
	string instruction = "";
	for (string ligne : vecInstruction) {
		instruction += ligne;
	}

	vector<int> posRobot;
	for (int i = 0; i < carte.size(); i++) {
		for (int j = 0; j < carte[0].size(); j++) {
			if (carte[i][j] == '@') {
				posRobot = { i,j };
			}
		}
	}

	vector<vector<caisse*>> caisses(carte.size(), vector<caisse*>(carte[0].size(), nullptr));
	for (int i = 0; i < carte.size(); i++) {
		for (int j = 0; j < carte[0].size(); j++) {
			if (carte[i][j] == '[') {
				new caisse(carte, caisses, { i,j });
			}
		}
	}

	vector<int> direction;
	for (char fleche : instruction) {
		if (fleche == '^') direction = { -1,0 };
		if (fleche == '<') direction = { 0,-1 };
		if (fleche == '>') direction = { 0,1 };
		if (fleche == 'v') direction = { 1,0 };

		int checkY = posRobot[0] + direction[0];
		int checkX = posRobot[1] + direction[1];

		if (carte[checkY][checkX] == '#') {
			continue;
		}

		if (caisses[checkY][checkX] != nullptr) {
			if (!caisses[checkY][checkX]->tryPush(direction)) {
				continue;
			}

			caisses[checkY][checkX]->push(direction);
		}

		carte[posRobot[0]][posRobot[1]] = '.';
		posRobot[0] += direction[0];
		posRobot[1] += direction[1];
		carte[posRobot[0]][posRobot[1]] = '@';

		/*cout << "fleche " << fleche << endl;
		for (string ligne : carte) {
			cout << ligne << endl;
		}
		cout << endl << endl;*/
	}

	for (int i = 0; i < carte.size(); i++) {
		for (int j = 0; j < carte[0].size(); j++) {
			if (carte[i][j] == '[') {
				resultat += i * 100 + j;
			}
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}