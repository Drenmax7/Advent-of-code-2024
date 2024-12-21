#include "j22.hpp"

void Jour22::solution(vector<string>& reponse) {

	cout << "Jour 22 :" << endl;
	
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

string Jour22::part1() {
	vector<string> instance = readLinesFromFile("instance/j22.txt");
	string retourFonction = "";
	long long resultat = 0;



	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour22::part2() {
	vector<string> instance = readLinesFromFile("instance/j22.txt");
	string retourFonction = "";
	long long resultat = 0;



	retourFonction = to_string(resultat);
	return retourFonction;
}