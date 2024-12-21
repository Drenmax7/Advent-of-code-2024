#include "dijkstra.hpp"

int dijkstra(vector<string>& carte, char wall, vector<int> start, vector<int> end, bool noPath) {
	vector<vector<int>> path;
	return dijkstra(carte, wall, start, end, path, noPath);
}

int dijkstra(vector<string>& carte, char wall, vector<int> start, vector<int> end, vector<vector<int>>& path, bool noPath) {
	vector<vector<vector<vector<int>>>> chemins(carte.size(),
		vector<vector<vector<int>>>(carte[0].size(),
			vector<vector<int>>()));

	if (noPath) {
		chemins[start[0]][start[1]].push_back({{0}});
	}
	else {
		chemins[start[0]][start[1]].push_back({ start });
	}

	vector<vector<int>> enAttente = { start };

	bool fini = false;
	int iteration = 0;
	while (!fini && iteration < enAttente.size()) {
		vector<int> checkPoint = enAttente[iteration];
		//carte[checkPoint[0]][checkPoint[1]] = 'O';

		for (int i = -1; i <= 1; i++) {
			for (int j = -1; j <= 1; j++) {
				if (i == 0 && j == 0 || i != 0 && j != 0) {
					continue;
				}

				if (checkPoint[0]+i >= 0 && checkPoint[0]+i < carte.size() && checkPoint[1]+j >= 0 && checkPoint[1]+j < carte[0].size()) {
					if (carte[checkPoint[0] + i][checkPoint[1] + j] == wall) {
						continue;
					}

					if (chemins[checkPoint[0] + i][checkPoint[1] + j].empty()) {
						enAttente.push_back({ checkPoint[0] + i,checkPoint[1] + j});
						chemins[checkPoint[0] + i][checkPoint[1] + j] = chemins[checkPoint[0]][checkPoint[1]];
						if (noPath) {
							chemins[checkPoint[0] + i][checkPoint[1] + j][0][0]++;
						}
						else {
							chemins[checkPoint[0] + i][checkPoint[1] + j].push_back({ checkPoint[0] + i, checkPoint[1] + j });
						}
					}

					if (end[0] == checkPoint[0] + i && end[1] == checkPoint[1] + j) {
						fini = true;
					}
				}
			}
		}

		iteration++;
	}

	if (fini) {
		if (noPath) {
			return chemins[end[0]][end[1]][0][0];
		}
		else {
			path = chemins[end[0]][end[1]];
			return (int)path.size() - 1;
		}
	}
	else {
		return -1;
	}

}