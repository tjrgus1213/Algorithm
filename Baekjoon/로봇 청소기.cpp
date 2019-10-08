#include<iostream>

using namespace std;

int plusx[4] = { -1, 0, 1, 0 };
int plusy[4] = { 0, 1, 0, -1 };

int main()
{
	int N, M;
	int r, c, dir;
	int map[50][50];
	int i, j;
	cin >> N >> M;
	cin >> r >> c >> dir;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> map[i][j];

	int tempdir, cnt = 0;
	bool iswall = false;
	while (true) {
		if (map[r][c] == 0) {
			cnt++;
			map[r][c] = 2;
		}
		for (i = 1; i <= 4; i++) {
			tempdir = dir - i;
			if (tempdir < 0)
				tempdir += 4;
			if (map[r + plusx[tempdir]][c + plusy[tempdir]] == 0)
				break;
		}
		if (i != 5) {
			r = r + plusx[tempdir];
			c = c + plusy[tempdir];
			dir = tempdir;
		}
		else {
			tempdir = dir + 2;
			tempdir %= 4;
			if (map[r + plusx[tempdir]][c + plusy[tempdir]] == 1) {
				iswall = true;
			}
			else {
				r += plusx[tempdir];
				c += plusy[tempdir];
			}
		}

		if (iswall)
			break;
	}

	cout << cnt << endl;
	return 0;
}