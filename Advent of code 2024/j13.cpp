#include "j13.hpp"

void Jour13::solution(vector<string>& reponse) {

	cout << "Jour 13 :" << endl;
	
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

string Jour13::part1() {
	vector<string> instance = readLinesFromFile("instance/j13.txt");
	string retourFonction;
	long long resultat = 0;

	vector<vector<string>> machines;
	vector<string> machine;
	for (string ligne : instance) {
		if (ligne == "") {
			machines.push_back(machine);
			machine.clear();
		}
		else {
			machine.push_back(ligne);
		}
	}
	machines.push_back(machine);


	for (vector<string> machine : machines) {
		string a = machine[0];
		string b = machine[1];
		string obj = machine[2];

		a = split(a, ":")[1];
		b = split(b, ":")[1];
		obj = split(obj, ":")[1];

		vector<string> leftRightA = split(a, ",");
		vector<string> leftRightB = split(b, ",");
		vector<string> leftRightObj = split(obj, ",");

		string leftA = leftRightA[0];
		string rightA = leftRightA[1];
		string leftB = leftRightB[0];
		string rightB = leftRightB[1];
		string leftObj = leftRightObj[0];
		string rightObj = leftRightObj[1];

		int intLeftA = stoi(split(leftA, "+")[1]);
		int intRightA = stoi(split(rightA, "+")[1]);
		int intLeftB = stoi(split(leftB, "+")[1]);
		int intRightB = stoi(split(rightB, "+")[1]);
		int intLeftObj = stoi(split(leftObj, "=")[1]);
		int intRightObj = stoi(split(rightObj, "=")[1]);

		vector<int> buttonA = {intLeftA,intRightA};
		vector<int> buttonB = { intLeftB,intRightB };
		vector<int> buttonObj = { intLeftObj,intRightObj };


		resultat += minButtonPress(intLeftA, intRightA, intLeftB, intRightB, intLeftObj, intRightObj);

	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

int Jour13::minButtonPress(int xA, int yA, int xB, int yB, int xObj, int yObj) {
	for (int aPress = 0; aPress <= 100; aPress++) {
		for (int bPress = 0; bPress <= 100; bPress++) {
			int actuelX = aPress * xA + bPress * xB;
			int actuelY = aPress * yA + bPress * yB;

			if (actuelX == xObj && actuelY == yObj) {
				//cout << "a : " << aPress << ", b : " << bPress << endl;
				return 3 * aPress + bPress;
			}
		}
	}

	//cout << "0" << endl;
	return 0;
}

string Jour13::part2() {
	vector<string> instance = readLinesFromFile("instance/j13.txt");
	string retourFonction;
	long long resultat = 0;

	vector<vector<string>> machines;
	vector<string> machine;
	for (string ligne : instance) {
		if (ligne == "") {
			machines.push_back(machine);
			machine.clear();
		}
		else {
			machine.push_back(ligne);
		}
	}
	machines.push_back(machine);


	for (vector<string> machine : machines) {
		string a = machine[0];
		string b = machine[1];
		string obj = machine[2];

		a = split(a, ":")[1];
		b = split(b, ":")[1];
		obj = split(obj, ":")[1];

		vector<string> leftRightA = split(a, ",");
		vector<string> leftRightB = split(b, ",");
		vector<string> leftRightObj = split(obj, ",");

		string leftA = leftRightA[0];
		string rightA = leftRightA[1];
		string leftB = leftRightB[0];
		string rightB = leftRightB[1];
		string leftObj = leftRightObj[0];
		string rightObj = leftRightObj[1];

		long long intLeftA = stoi(split(leftA, "+")[1]);
		long long intRightA = stoi(split(rightA, "+")[1]);
		long long intLeftB = stoi(split(leftB, "+")[1]);
		long long intRightB = stoi(split(rightB, "+")[1]);
		long long intLeftObj = stoi(split(leftObj, "=")[1]) +10000000000000;
		long long intRightObj = stoi(split(rightObj, "=")[1]) +10000000000000;

		vector<vector<long long>> matrice = { {intLeftA, intLeftB},{intRightA, intRightB} };
		vector<long long> vobj = { intLeftObj,intRightObj };

		double det = (double)(matrice[0][0] * matrice[1][1] - matrice[0][1] * matrice[1][0]);
		if (det == 0) {
			cout << "vecteur colineaire" << endl;
			continue;
		}

		vector<vector<double>> inverse = { {matrice[1][1] / det, -matrice[0][1] / det}, {-matrice[1][0] / det, matrice[0][0] / det} };
		vector<long double> solution = { inverse[0][0] * vobj[0] + inverse[0][1] * vobj[1],inverse[1][0] * vobj[0] + inverse[1][1] * vobj[1] };

		if (0 <= solution[0] && 0 <= solution[1]) {
			//printf("a %f1000.0, b %f1000.0",solution[0], solution[1]);
			//cout << (long long)solution[0] * 3 + (long long)solution[1] << endl;
			if (abs(solution[0] - round(solution[0])) < 0.001 && abs(solution[1] - round(solution[1])) < 0.001) {
				if (round(solution[0]) * intLeftA + round(solution[1]) * intLeftB != intLeftObj ||
					round(solution[0]) * intRightA + round(solution[1]) * intRightB != intRightObj) {
					cout << "erreur" << endl;
				}
				resultat += (long long)(round(solution[0]) * 3 + round(solution[1]));
			}
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}