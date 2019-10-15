#include<iostream>
using namespace std;

int pr[4] = { -1, 1, 0, 0 };
int pc[4] = { 0, 0, -1, 1 };

int main()
{
	int map[50][50];
	int tempmap[50][50] = { 0, };
	int R, C, T;
	pair<int, int> aircon;
	cin >> R >> C >> T;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> map[i][j];
			if (map[i][j] == -1) {
				aircon.first = i;
				aircon.second = j;
			}
		}
	}

	int i, j, x, tsum;
	while (T > 0) {
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				tsum = map[i][j];
				if (map[i][j] >= 5) {
					for (x = 0; x < 4; x++) {
						if (i + pr[x] < 0 || i + pr[x] >= R || j + pc[x] < 0 || j + pc[x] >= C)
							continue;
						if (map[i + pr[x]][j + pc[x]] == -1)
							continue;
						tempmap[i + pr[x]][j + pc[x]] += map[i][j] / 5;
						tsum -= map[i][j] / 5;
					}
				}
				tempmap[i][j] += tsum;
			}
		}

		for (i = aircon.first; i < R - 1; i++)
			tempmap[i][0] = tempmap[i + 1][0];
		for (i = 0; i < C - 1; i++)
			tempmap[R - 1][i] = tempmap[R - 1][i + 1];
		for (i = R - 1; i > aircon.first; i--)
			tempmap[i][C - 1] = tempmap[i - 1][C - 1];
		for (i = C - 1; i > aircon.second + 1; i--) 
			tempmap[aircon.first][i] = tempmap[aircon.first][i - 1];
		tempmap[aircon.first][i] = 0;


		for (i = aircon.first - 1; i > 0; i--)
			tempmap[i][0] = tempmap[i - 1][0];
		for (i = 0; i < C - 1; i++)
			tempmap[0][i] = tempmap[0][i + 1];
		for (i = 0; i < aircon.first - 1; i++)
			tempmap[i][C - 1] = tempmap[i + 1][C - 1];
		for (i = C - 1; i > aircon.second + 1; i--)
			tempmap[aircon.first - 1][i] = tempmap[aircon.first - 1][i - 1];
		tempmap[aircon.first - 1][i] = 0;

		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				map[i][j] = tempmap[i][j];
				tempmap[i][j] = 0;
			}
		}
		map[aircon.first][aircon.second] = -1;
		map[aircon.first - 1][aircon.second] = -1;

		T--;
	}

	int total = 2;
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			total += map[i][j];
	cout << total << endl;
	return 0;
}