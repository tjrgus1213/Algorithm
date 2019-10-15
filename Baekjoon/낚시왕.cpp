#include<iostream>
#include<vector>
#include<cstring>

using namespace std;

struct shark {
	int r, c;
	int dir, speed, size;
};

int pr[5] = { 0, -1, 1, 0, 0 };
int pc[5] = { 0, 0, 0, 1, -1 };

int main()
{
	int map[100][100] = { 0, };
	int R, C, M, tR, tC;
	cin >> R >> C >> M;
	vector<shark> sharklist;
	shark ts;
	sharklist.push_back(ts);

	tR = 2 * (R - 1);
	tC = 2 * (C - 1);
	for (int i = 1; i <= M; i++) {
		cin >> ts.r >> ts.c >> ts.speed >> ts.dir >> ts.size;
		ts.r--;
		ts.c--;
		if (ts.speed >= tR) {
			if (ts.dir == 1 || ts.dir == 2)
				ts.speed %= tR;
			else
				ts.speed %= tC;
		}
		sharklist.push_back(ts);
		map[ts.r][ts.c] = i;
	}

	int cnt = 0;
	for (int i = 0; i < C; i++) {
		for (int j = 0; j < R; j++) {
			if (map[j][i] != 0) {
				cnt += sharklist[map[j][i]].size;
				sharklist[map[j][i]].size = 0;
				break;
			}
		}

		memset(map, 0, sizeof(map));

		for (int j = 1; j <= M; j++) {
			if (sharklist[j].size == 0)
				continue;

			for (int a = 0; a < sharklist[j].speed; a++) {
				sharklist[j].r += pr[sharklist[j].dir];
				sharklist[j].c += pc[sharklist[j].dir];
				if (sharklist[j].r < 0) {
					sharklist[j].dir++;
					sharklist[j].r = 1;
				}
				else if (sharklist[j].r >= R) {
					sharklist[j].dir--;
					sharklist[j].r = R - 2;
				}
				else if (sharklist[j].c < 0) {
					sharklist[j].dir--;
					sharklist[j].c = 1;
				}
				else if (sharklist[j].c >= C) {
					sharklist[j].dir++;
					sharklist[j].c = C - 2;
				}
			}

			if (map[sharklist[j].r][sharklist[j].c] == 0) {
				map[sharklist[j].r][sharklist[j].c] = j;
			}
			else {
				int temp = map[sharklist[j].r][sharklist[j].c];
				if (sharklist[j].size > sharklist[temp].size) {
					map[sharklist[j].r][sharklist[j].c] = j;
					sharklist[temp].size = 0;
				}
				else {
					sharklist[j].size = 0;
				}
			}
		}
	}
	cout << cnt << endl;
	return 0;
}