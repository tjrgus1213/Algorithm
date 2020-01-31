#include <string>
#include <vector>

using namespace std;

bool ver[104][104];
bool hor[104][104];

vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
	vector<vector<int>> answer;

	for (int i = 0; i < 104; i++)
		for (int j = 0; j < 104; j++)
			ver[i][j] = hor[i][j] = false;


	int x, y, type, isbuild;
	for (int i = 0; i < build_frame.size(); i++) {
		x = build_frame[i][0] + 2;
		y = build_frame[i][1] + 2;
		type = build_frame[i][2];
		isbuild = build_frame[i][3];

		if (isbuild == 1) {
			if (type == 0) {
				if (y == 2 || ver[x][y - 1] || hor[x - 1][y] || hor[x][y])
					ver[x][y] = true;
			}
			else {
				if (ver[x][y - 1] || ver[x + 1][y - 1] || (hor[x - 1][y] && hor[x + 1][y]))
					hor[x][y] = true;
			}
		}
		else {
			if (type == 0) {
				ver[x][y] = false;
				if (ver[x][y + 1] && !hor[x - 1][y + 1] && !hor[x][y + 1])
					ver[x][y] = true;
				else if (hor[x][y + 1] && (!hor[x + 1][y + 1] || !hor[x - 1][y + 1]) && !ver[x + 1][y])
					ver[x][y] = true;
				else if (hor[x - 1][y + 1] && (!hor[x][y + 1] || !hor[x - 2][y + 1]) && !ver[x - 1][y])
					ver[x][y] = true;
			}
			else {
				hor[x][y] = false;
				if (ver[x][y] && !ver[x][y - 1] && !hor[x - 1][y])
					hor[x][y] = true;
				else if (ver[x + 1][y] && !ver[x + 1][y - 1] && !hor[x + 1][y])
					hor[x][y] = true;
				else if (hor[x - 1][y] && !ver[x][y - 1] && !ver[x - 1][y - 1])
					hor[x][y] = true;
				else if (hor[x + 1][y] && !ver[x + 1][y - 1] && !ver[x + 2][y - 1])
					hor[x][y] = true;
			}
		}
	}

	for (int i = 2; i < 104; i++) {
		for (int j = 2; j < 104; j++) {
			if (ver[i][j])
				answer.push_back({ i - 2, j - 2, 0 });
			if (hor[i][j])
				answer.push_back({ i - 2, j - 2, 1 });
		}
	}
	return answer;
}