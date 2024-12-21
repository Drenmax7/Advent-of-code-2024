#include "j1.hpp"

void Jour1::solution(vector<string>& reponse) {

	cout << "Jour 1 :" << endl;
	
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

string Jour1::part1() {
	vector<string> instance = readLinesFromFile("instance/j1.txt");
	string resultat;
	long long score = 0;

	vector<int> liste1(instance.size());
	vector<int> liste2(instance.size());

	for (int i = 0; i < instance.size(); i++) {
		istringstream iss(instance[i]);
		iss >> liste1[i] >> liste2[i];
	}

	sort(liste1.begin(), liste1.end());
	sort(liste2.begin(), liste2.end());

	for (int i = 0; i < liste1.size(); i++) {
		score += abs(liste1[i] - liste2[i]);
	}

	resultat = to_string(score);
	return resultat;
}

string Jour1::part2() {
	vector<string> instance = readLinesFromFile("instance/j1.txt");
	string resultat;
	long long score = 0;

	vector<int> liste1(instance.size());
	vector<int> liste2(instance.size());

	for (int i = 0; i < instance.size(); i++) {
		istringstream iss(instance[i]);
		iss >> liste1[i] >> liste2[i];
	}

	sort(liste1.begin(), liste1.end());
	sort(liste2.begin(), liste2.end());

	for (int i = 0; i < liste1.size(); i++) {
		int montant = (int)count(liste2.begin(), liste2.end(), liste1[i]);
		score += liste1[i] * montant;
	}

	resultat = to_string(score);
	return resultat;
}