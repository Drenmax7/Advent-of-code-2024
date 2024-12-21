#include "j19.hpp"

void Jour19::solution(vector<string>& reponse) {

	cout << "Jour 19 :" << endl;
	
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

string Jour19::part1() {
	vector<string> instance = readLinesFromFile("instance/j19.txt");
	string retourFonction = "";
	long long resultat = 0;

	vector<string> patern = split(instance[0],", ");
	vector<string> objectifs(instance.begin() + 2, instance.end());

	map<string, long long> objectifPossible;
	for (string obj : objectifs) {
		if (comptePossibilite(patern, obj, objectifPossible) > 0) {
			resultat++;
		}
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour19::part2() {
	vector<string> instance = readLinesFromFile("instance/j19.txt");
	string retourFonction = "";
	long long resultat = 0;

	vector<string> patern = split(instance[0], ", ");
	vector<string> objectifs(instance.begin() + 2, instance.end());

	map<string, long long> objectifPossible;
	for (string obj : objectifs) {
		resultat += comptePossibilite(patern, obj, objectifPossible);
	}


	retourFonction = to_string(resultat);
	return retourFonction;
}

long long Jour19::comptePossibilite(vector<string>& patern, string objectif, map<string, long long>& objectifPossible) {
	long long compte = 0;

	for (string pat : patern) {
		int taillePat = (int)pat.size();

		if (taillePat < objectif.size()) {
			if (pat != objectif.substr(0,taillePat)) {
				//si le debut de l'objectif ne correspond pas au patern
				continue;
			}

			if (objectifPossible.count(objectif.substr(taillePat)) > 0) {
				compte += objectifPossible[objectif.substr(taillePat)];
			}
			else {
				long long nbPossible = comptePossibilite(patern, objectif.substr(taillePat), objectifPossible);
				objectifPossible[objectif.substr(taillePat)] = nbPossible;
				//si ce qu'il reste de l'objectif peut etre couvert par d'autres patern
				if (nbPossible) {
					compte += nbPossible;
				}
				else {
					//si ce qu'il reste de l'objectif ne peut pas etre couvert par d'autres patern
					continue;
				}
			}
		}
		else if(taillePat == objectif.size()) {
			if (pat == objectif) {
				//si le patern est identique a l'objectif
				compte++;
			}
			else {
				//si le patern est different de l'objectif
				continue;
			}
		}
		else {
			//si le patern est trop grand pour couvrir un bout de l'objectif
			continue;
		}

	}

	return compte;
}
