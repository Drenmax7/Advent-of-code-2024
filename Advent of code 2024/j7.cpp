#include "j7.hpp"

void Jour7::solution(vector<string>& reponse) {

	cout << "Jour 7 :" << endl;
	
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

string Jour7::part1() {
	vector<string> instance = readLinesFromFile("instance/j7.txt");
	string retourFonction;
	long long resultat = 0;

	for (int i = 0; i < instance.size(); i++) {
		vector<string> operation = split(instance[i], ": ");

		long long valeur = stoll(operation[0]);
		operation.erase(operation.begin());

		operation = split(operation[0], " ");

		vector<long long> operandes;
		for (int j = 0; j < operation.size(); j++) {
			operandes.push_back(stoll(operation[j]));
		}

		bool possible = resoud(valeur, operandes);

		if (possible) {
			resultat += valeur;
		}

	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

bool Jour7::resoud(long long valeur, vector<long long>& operandes) {
	if (operandes.size() == 1) {
		return operandes[0] == valeur;
	}

	vector<long long> copieOperandes(operandes.begin(), operandes.end() - 1);

	long long diff = valeur - operandes[operandes.size() - 1];
	bool plus = resoud(diff, copieOperandes);

	if (plus) return plus;

	bool mul = 0;
	if (valeur % operandes[operandes.size() - 1] == 0) {
		diff = valeur / operandes[operandes.size() - 1];
		mul = resoud(diff, copieOperandes);
	}

	return mul;
}


string Jour7::part2() {
	vector<string> instance = readLinesFromFile("instance/j7.txt");
	string retourFonction;
	long long resultat = 0;

	for (int i = 0; i < instance.size(); i++) {
		vector<string> operation = split(instance[i], ": ");

		long long valeur = stoll(operation[0]);
		operation.erase(operation.begin());

		operation = split(operation[0], " ");

		vector<long long> operandes;
		for (int j = 0; j < operation.size(); j++) {
			operandes.push_back(stoll(operation[j]));
		}

		vector<string> ordre;
		bool possible = resoud2(valeur, operandes, ordre);

		if (possible) {
			resultat += valeur;
		}

	}

	retourFonction = to_string(resultat);
	return retourFonction;
}


bool Jour7::resoud2(long long valeur, vector<long long>& operandes, vector<string>& ordre) {
	if (operandes.size() == 1) {
		return operandes[0] == valeur;
	}

	vector<long long> copieOperandes(operandes.begin() + 1, operandes.end());
	vector<string> copieOrdre(ordre);
	copieOrdre.push_back(".");

	long long calcul = operandes[0] + operandes[1];
	copieOperandes[0] = calcul;
	copieOrdre[copieOrdre.size() - 1] = "+";
	bool plus = resoud2(valeur, copieOperandes, copieOrdre);

	if (plus) {
		ordre = move(copieOrdre);
		return plus;
	}


	calcul = operandes[0] * operandes[1];
	copieOperandes[0] = calcul;
	copieOrdre[copieOrdre.size() - 1] = "*";
	bool mul = resoud2(valeur, copieOperandes, copieOrdre);

	if (mul) {
		ordre = move(copieOrdre);
		return mul;
	}


	calcul = stoll(to_string(operandes[0]) + to_string(operandes[1]));
	copieOperandes[0] = calcul;
	copieOrdre[copieOrdre.size() - 1] = "||";
	bool conc = resoud2(valeur, copieOperandes, copieOrdre);

	if (conc) {
		ordre = move(copieOrdre);
		return conc;
	}

	return false;
}

