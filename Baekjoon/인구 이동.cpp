#include<iostream>

using namespace std;

int main()
{
	int map[50][50];
	int con[50][50] = { 0, };
	int N, L, R;
	int i, j;
	cin >> N >> L >> R;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> map[i][j];

	bool is = true;
	int sum = 0, cnt = 0;
	int uni[2500][2], uni_cnt = 0, back;
	while (is) {
		is = false;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (con[i][j] == 0) {
					int r, c, t;
					uni_cnt = 0;
					back = 1;
					uni[uni_cnt][0] = i;
					uni[uni_cnt][1] = j;
					con[i][j] = 1;
					sum = 0;
					while (uni_cnt != back) {
						r = uni[uni_cnt][0];
						c = uni[uni_cnt][1];
						uni_cnt++;
						sum += map[r][c];
						if (r + 1 < N && con[r + 1][c] == 0) {
							t = abs(map[r + 1][c] - map[r][c]);
							if (t >= L && t <= R) {
								uni[back][0] = r + 1;
								uni[back][1] = c;
								back++;
								con[r + 1][c] = 1;
							}
						}
						if (r - 1 >= 0 && con[r - 1][c] == 0) {
							t = abs(map[r - 1][c] - map[r][c]);
							if (t >= L && t <= R) {
								uni[back][0] = r - 1;
								uni[back][1] = c;
								back++;
								con[r - 1][c] = 1;
							}
						}
						if (c - 1 >= 0 && con[r][c - 1] == 0) {
							t = abs(map[r][c - 1] - map[r][c]);
							if (t >= L && t <= R) {
								uni[back][0] = r;
								uni[back][1] = c - 1;
								back++;
								con[r][c - 1] = 1;
							}
						}
						if (c + 1 < N && con[r][c + 1] == 0) {
							t = abs(map[r][c + 1] - map[r][c]);
							if (t >= L && t <= R) {
								uni[back][0] = r;
								uni[back][1] = c + 1;
								back++;
								con[r][c + 1] = 1;
							}
						}
					}

					if (back > 1) {
						is = true;
						sum /= back;
						for (uni_cnt = 0; uni_cnt < back; uni_cnt++) {
							r = uni[uni_cnt][0];
							c = uni[uni_cnt][1];
							map[r][c] = sum;
						}
					}
				}
			}
		}

		for (int a = 0; a < N; a++)
			for (int b = 0; b < N; b++)
				con[a][b] = 0;

		if (is)
			cnt++;
	}

	cout << cnt << endl;
	return 0;
}