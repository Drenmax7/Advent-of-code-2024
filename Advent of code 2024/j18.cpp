#include "j18.hpp"
#include "dijkstra.hpp"

void Jour18::solution(vector<string>& reponse) {

	cout << "Jour 18 :" << endl;
	
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

string Jour18::part1() {
	vector<string> instance = readLinesFromFile("instance/j18.txt");
	string retourFonction;
	long long resultat = 0;

	vector<vector<int>> corrupted;

	for (int i = 0; i < instance.size(); i++) {
		vector<string> co = split(instance[i], ",");
		corrupted.push_back({ stoi(co[0]) ,stoi(co[1]) });
	}

	int taille = 71;
	vector<string> carte(taille, string(taille, '.'));

	int nbIteration = 1024;
	for (int i = 0; i < nbIteration; i++) {
		vector<int> co = corrupted[i];
		carte[co[1]][co[0]] = '#';
	}

	vector<int> start = { 0,0 };
	vector<int> end = { (int)carte[0].size()-1,(int)carte.size()-1};

	vector<vector<int>> path;

	resultat = dijkstra(carte, '#', start, end, path);

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour18::part2() {
	vector<string> instance = readLinesFromFile("instance/j18.txt");
	string retourFonction;
	long long resultat = 0;

	vector<vector<int>> corrupted;

	for (int i = 0; i < instance.size(); i++) {
		vector<string> co = split(instance[i], ",");
		corrupted.push_back({ stoi(co[0]) ,stoi(co[1]) });
	}

	int taille = 71;
	vector<string> carte(taille, string(taille, '.'));

	vector<int> start = { 0,0 };
	vector<int> end = { (int)carte[0].size() - 1,(int)carte.size() - 1 };
	vector<vector<int>> path;

	int borneMin = 0;
	int borneMax = (int)corrupted.size() -1;
	int milieu = (borneMax + borneMin) / 2;
	vector<int> co;
	while (milieu != borneMin) {
		vector<string> copieCarte = carte;
		for (int i = 0; i < milieu; i++) {
			co = corrupted[i];
			copieCarte[co[1]][co[0]] = '#';
		}

		int pathSize = dijkstra(copieCarte, '#', start, end, path);

		if (pathSize == -1) {
			borneMax = milieu;
		}
		else {
			borneMin = milieu;
		}

		milieu = (borneMax + borneMin) / 2;
	}

	co = corrupted[borneMin];
	retourFonction = to_string(co[0]) + "," + to_string(co[1]);
	return retourFonction;
}