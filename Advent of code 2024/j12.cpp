#include "j12.hpp"

void Jour12::solution(vector<string>& reponse) {

	cout << "Jour 12 :" << endl;
	
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

string Jour12::part1() {
	vector<string> instance = readLinesFromFile("instance/j12.txt");
	string retourFonction;
	long long resultat = 0;

	vector<vector<vector<int>>> classes;
	map<int, int> correspondance;

	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			int classeCase;
			int classeUp = -1;
			if (i - 1 >= 0 && instance[i-1][j] == instance[i][j]) {
				classeUp = correspondance[(i-1)*(int)instance[0].size()+j];
			}

			int classeLeft = -1;
			if (j - 1 >= 0 && instance[i][j - 1] == instance[i][j]) {
				classeLeft = correspondance[(i) * (int)instance[0].size() + j -1];
			}

			//meme classe que case au dessus
			if (classeLeft == -1 && classeUp != -1) {
				classeCase = classeUp;
				classes[classeCase].push_back({ i,j });
			}

			//meme classe que case de gauche
			if (classeLeft != -1 && classeUp == -1) {
				classeCase = classeLeft;
				classes[classeCase].push_back({ i,j });
			}

			//nouvelle classe
			if (classeLeft == -1 && classeUp == -1) {
				vector<vector<int>> listeClasse;
				listeClasse.push_back({ i,j });
				classes.push_back(listeClasse);

				classeCase = (int)classes.size()-1;
			}

			//case de gauche et haut de meme classe
			if (classeLeft != -1 && classeUp != -1) {
				classeCase = classeLeft;
				classes[classeCase].push_back({ i,j });

				//les deux cases n'ont pas le meme id et doivent etre fusionné
				if (classeLeft != classeUp) {
					for (int k = 0; k < classes[classeUp].size(); k++) {
						vector<int> coordonnes = classes[classeUp][k];
						classes[classeLeft].push_back(coordonnes);

						int y = coordonnes[0];
						int x = coordonnes[1];
						correspondance[y * (int)instance[0].size() + x] = classeLeft;
					}

					classes[classeUp].clear();
				}
			}

			correspondance[i * (int)instance[0].size() + j] = classeCase;
		}
	}

	for (int numClasse = 0; numClasse < classes.size(); numClasse++) {
		int perimetre = 0;
		for (vector<int> coordonnes : classes[numClasse]) {
			int i = coordonnes[0];
			int j = coordonnes[1];

			for (int di = -1; di <= 1; di++) {
				for (int dj = -1; dj <= 1; dj++) {
					if (di == 0 && dj == 0 || di != 0 && dj != 0) {
						continue;
					}

					if (i + di < 0 || i + di >= instance.size() || j + dj < 0 || j + dj >= instance[0].size()) {
						perimetre++;
					}

					else if (instance[i][j] != instance[i + di][j + dj]) {
						perimetre++;
					}
				}
			}
		}

		resultat += perimetre * classes[numClasse].size();
	}

	retourFonction = to_string(resultat);
	return retourFonction;
}

string Jour12::part2() {
	vector<string> instance = readLinesFromFile("instance/j12.txt");
	string retourFonction;
	long long resultat = 0;

	vector<vector<vector<int>>> classes;
	map<int, int> correspondance;

	for (int i = 0; i < instance.size(); i++) {
		for (int j = 0; j < instance[0].size(); j++) {
			int classeCase;
			int classeUp = -1;
			if (i - 1 >= 0 && instance[i - 1][j] == instance[i][j]) {
				classeUp = correspondance[(i - 1) * (int)instance[0].size() + j];
			}

			int classeLeft = -1;
			if (j - 1 >= 0 && instance[i][j - 1] == instance[i][j]) {
				classeLeft = correspondance[i*(int)instance[0].size() + j - 1];
			}

			//meme classe que case au dessus
			if (classeLeft == -1 && classeUp != -1) {
				classeCase = classeUp;
				classes[classeCase].push_back({ i,j });
			}

			//meme classe que case de gauche
			if (classeLeft != -1 && classeUp == -1) {
				classeCase = classeLeft;
				classes[classeCase].push_back({ i,j });
			}

			//nouvelle classe
			if (classeLeft == -1 && classeUp == -1) {
				vector<vector<int>> listeClasse;
				listeClasse.push_back({ i,j });
				classes.push_back(listeClasse);

				classeCase = (int)classes.size() - 1;
			}

			//case de gauche et haut de meme classe
			if (classeLeft != -1 && classeUp != -1) {
				classeCase = classeLeft;
				classes[classeCase].push_back({ i,j });

				//les deux cases n'ont pas le meme id et doivent etre fusionné
				if (classeLeft != classeUp) {
					for (int k = 0; k < classes[classeUp].size(); k++) {
						vector<int> coordonnes = classes[classeUp][k];
						classes[classeLeft].push_back(coordonnes);

						int y = coordonnes[0];
						int x = coordonnes[1];
						correspondance[y * (int)instance[0].size() + x] = classeLeft;
					}

					classes[classeUp].clear();
				}
			}

			correspondance[i * (int)instance[0].size() + j] = classeCase;
		}
	}

	for (int numClasse = 0; numClasse < classes.size(); numClasse++) {
		int cote = 0;

		bool coteHaut = false;
		bool coteBas = false;

		for (int i = 0; i < instance.size(); i++) {
			for (int j = 0; j < instance[0].size(); j++) {

				if (correspondance[i * (int)instance[0].size() + j] != numClasse) {
					coteHaut = false;
					coteBas = false;
					continue;
				}

				if (i + 1 < instance.size()) {
					if (correspondance[(i + 1) * (int)instance[0].size() + j] != numClasse) {
						if (!coteBas) {
							cote++;
						}
						coteBas = true;
					}
					else {
						coteBas = false;
					}
				}
				else {
					if (!coteBas) {
						cote++;
					}
					coteBas = true;
				}

				if (i - 1 >= 0) {
					if (correspondance[(i - 1) * (int)instance[0].size() + j] != numClasse) {
						if (!coteHaut) {
							cote++;
						}
						coteHaut = true;
					}
					else {
						coteHaut = false;
					}
				}
				else {
					if (!coteHaut) {
						cote++;
					}
					coteHaut = true;
				}

			}
		}

		bool coteGauche = false;
		bool coteDroit = false;

		for (int j = 0; j < instance[0].size(); j++) {
			for (int i = 0; i < instance.size(); i++) {

				if (correspondance[i * (int)instance[0].size() + j] != numClasse) {
					coteGauche = false;
					coteDroit = false;
					continue;
				}

				if (j + 1 < (int)instance[0].size()) {
					if (correspondance[(i) * (int)instance[0].size() + j+1] != numClasse) {
						if (!coteDroit) {
							cote++;
						}
						coteDroit = true;
					}
					else {
						coteDroit = false;
					}
				}
				else {
					if (!coteDroit) {
						cote++;
					}
					coteDroit = true;
				}

				if (j - 1 >= 0) {
					if (correspondance[(i) * (int)instance[0].size() + j-1] != numClasse) {
						if (!coteGauche) {
							cote++;
						}
						coteGauche = true;
					}
					else {
						coteGauche = false;
					}
				}
				else {
					if (!coteGauche) {
						cote++;
					}
					coteGauche = true;
				}

			}
		}
		//cout << numClasse << " " << cote << endl;

		resultat += cote * classes[numClasse].size();
	}
		/*for (int i = 0; i < instance.size(); i++) {
			for (int j = 0; j < instance[0].size(); j++) {
				cout << instance[i][j] << " " << correspondance[i * instance[0].size() + j] << "\t";
			}
			cout << endl;
		}*/

	retourFonction = to_string(resultat);
	return retourFonction;
}