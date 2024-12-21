#include "j17.hpp"

long long Jour17::Processeur::a;
long long Jour17::Processeur::b;
long long Jour17::Processeur::c;
int Jour17::Processeur::pointer;
vector<int> Jour17::Processeur::instructionList;
vector<int> Jour17::Processeur::output;

void Jour17::solution(vector<string>& reponse) {

	cout << "Jour 17 :" << endl;
	
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

string Jour17::part1() {
	vector<string> instance = readLinesFromFile("instance/j17.txt");
	string retourFonction = "";
	long long resultat = 0;

	string sa = instance[0];
	string sb = instance[1];
	string sc = instance[2];

	sa = split(sa, ": ")[1];
	sb = split(sb, ": ")[1];
	sc = split(sc, ": ")[1];

	Processeur::a = stoi(sa);
	Processeur::a = 164541160582784;
	Processeur::b = stoi(sb);
	Processeur::c = stoi(sc);

	string pro = instance[4];
	pro = split(pro, ": ")[1];
	vector<string> vPro = split(pro, ",");
	for (string inst : vPro) {
		Processeur::instructionList.push_back(stoi(inst));
	}

	Processeur::start();

	retourFonction = to_string(Processeur::output[0]);
	for (int i = 1; i < Processeur::output.size(); i++) {
		retourFonction += "," + to_string(Processeur::output[i]);
	}

	return retourFonction;
}

string Jour17::part2() {
	vector<string> instance = readLinesFromFile("instance/j17.txt");
	string retourFonction;
	long long resultat = 0;

	string sa = instance[0];
	string sb = instance[1];
	string sc = instance[2];

	sa = split(sa, ": ")[1];
	sb = split(sb, ": ")[1];
	sc = split(sc, ": ")[1];

	long long a = stoi(sa);
	long long b = stoi(sb);
	long long c = stoi(sc);

	string pro = instance[4];
	pro = split(pro, ": ")[1];
	vector<string> vPro = split(pro, ",");

	Processeur::instructionList.clear();
	for (string inst : vPro) {
		Processeur::instructionList.push_back(stoi(inst));
	}

	vector<int> exploration(Processeur::instructionList.size(), 0);
	a = 0;
	for (int j = (int)Processeur::instructionList.size() - 1; j >= 0; j--) {
		a *= 8;

		bool trouve = false;
		for (int i = exploration[j]; i < 8; i++) {
			Processeur::a = a + i;
			Processeur::b = stoi(sb);
			Processeur::c = stoi(sc);

			Processeur::start();

			if (Processeur::output[0] == Processeur::instructionList[j]) {
				a = a + i;
				trouve = true;
				exploration[j] = i+1;
				break;
			}
		}

		if (!trouve) {
			exploration[j] = 0;
			a /= 64;
			j += 2;
			continue;
		}
	}

	resultat = a;

	retourFonction = to_string(resultat);
	return retourFonction;
}

