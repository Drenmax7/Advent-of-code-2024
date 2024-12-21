#include "j3.hpp"

void Jour3::solution(vector<string>& reponse) {

	cout << "Jour 3 :" << endl;
	
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

string Jour3::part1() {
	vector<string> instance = readLinesFromFile("instance/j3.txt");
	string retourFonction;
	long long resultat = 0;

	string chaine = "";
	for (int i = 0; i < instance.size(); i++) {
		chaine += instance[i];
	}

	while (!chaine.empty()) {
		int debut = (int)chaine.find("mul(");
		if (debut == -1) break;

		int fin = (int)chaine.substr(debut).find(")");
		if (fin == -1) break;

		string mul = chaine.substr(debut, fin + 1);
		chaine = chaine.substr(debut + 1, chaine.length());

		int x;
		istringstream stream(mul.substr(4));
		stream >> x;

		int y;
		int posy = (int)mul.find(",");
		if (posy == -1) continue;
		istringstream stream2(mul.substr(posy + 1));
		stream2 >> y;

		string compare = "mul(" + to_string(x) + "," + to_string(y) + ")";

		//cout << (compare == mul) << endl;
		if (compare != mul) {
			continue;
		}

		resultat += x * y;

	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour3::part2() {
	vector<string> instance = readLinesFromFile("instance/j3.txt");
	string retourFonction;
	long long resultat = 0;

	string chaine = "";
	for (int i = 0; i < instance.size(); i++) {
		chaine += instance[i];
	}

	vector<string> parties = split(chaine, "don't()");
	string tempchaine = parties[0];
	for (int i = 1; i < parties.size(); i++) {
		int posDo = (int)parties[i].find("do()");
		if (posDo == -1) continue;
		tempchaine += parties[i].substr(posDo);
	}
	chaine = tempchaine;


	while (!chaine.empty()) {
		int debut = (int)chaine.find("mul(");
		if (debut == -1) break;

		int fin = (int)chaine.substr(debut).find(")");
		if (fin == -1) break;

		string mul = chaine.substr(debut, fin + 1);
		chaine = chaine.substr(debut + 1, chaine.length());

		int x;
		istringstream stream(mul.substr(4));
		stream >> x;

		int y;
		int posy = (int)mul.find(",");
		if (posy == -1) continue;
		istringstream stream2(mul.substr(posy + 1));
		stream2 >> y;

		string compare = "mul(" + to_string(x) + "," + to_string(y) + ")";

		//cout << (compare == mul) << endl;
		if (compare != mul) {
			continue;
		}

		resultat += x * y;

	}

	retourFonction = to_string(resultat);
	return retourFonction;
}