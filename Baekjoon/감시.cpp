#include<iostream>

using namespace std;

int N, M, tmax = 0;
int cctv[8][2], numOfcctv = 0;

void func(int cam, int num, int ary[][8]);
int paint(int r, int c, int dir, int con, int map[][8]);

int main()
{
	int blank = 0;
	int map[8][8];
	cin >> N >> M;
	blank = N * M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
			if (map[i][j] != 0) {
				blank--;
				if (map[i][j] != 6) {
					cctv[numOfcctv][0] = i;
					cctv[numOfcctv][1] = j;
					numOfcctv++;
				}
			}
		}
	}

	func(0, 0, map);
	blank -= tmax;
	cout << blank << endl;
	return 0;
}

void func(int cam, int num, int ary[][8]) {
	if (cam == numOfcctv) {
		if (tmax < num) {
			tmax = num;
		}
		return;
	}

	int temp, tempary[8][8];
	switch (ary[cctv[cam][0]][cctv[cam][1]]) {
	case 1:
		for (int i = 0; i < 4; i++) {
			for (int r = 0; r < N; r++)
				for (int c = 0; c < M; c++)
					tempary[r][c] = ary[r][c];
			temp = num;
			temp += paint(cctv[cam][0], cctv[cam][1], i, -1, tempary);
			func(cam + 1, temp, tempary);
		}
		return;
	case 2:
		for (int i = 0; i < 2; i++) {
			for (int r = 0; r < N; r++)
				for (int c = 0; c < M; c++)
					tempary[r][c] = ary[r][c];
			temp = num;
			temp += paint(cctv[cam][0], cctv[cam][1], i, -1, tempary);
			temp += paint(cctv[cam][0], cctv[cam][1], i + 2, -1, tempary);
			func(cam + 1, temp, tempary);
		}
		return;
	case 3:
		for (int i = 0; i < 4; i++) {
			for (int r = 0; r < N; r++)
				for (int c = 0; c < M; c++)
					tempary[r][c] = ary[r][c];
			temp = num;
			temp += paint(cctv[cam][0], cctv[cam][1], i, -1, tempary);
			temp += paint(cctv[cam][0], cctv[cam][1], (i + 1) % 4, -1, tempary);
			func(cam + 1, temp, tempary);
		}
		return;
	case 4:
		for (int i = 0; i < 4; i++) {
			for (int r = 0; r < N; r++)
				for (int c = 0; c < M; c++)
					tempary[r][c] = ary[r][c];
			temp = num;
			temp += paint(cctv[cam][0], cctv[cam][1], i, -1, tempary);
			temp += paint(cctv[cam][0], cctv[cam][1], (i + 1) % 4, -1, tempary);
			temp += paint(cctv[cam][0], cctv[cam][1], (i + 2) % 4, -1, tempary);
			func(cam + 1, temp, tempary);
		}
		return;

	case 5:
		for (int r = 0; r < N; r++)
			for (int c = 0; c < M; c++)
				tempary[r][c] = ary[r][c];
		temp = num;
		temp += paint(cctv[cam][0], cctv[cam][1], 0, -1, tempary);
		temp += paint(cctv[cam][0], cctv[cam][1], 1, -1, tempary);
		temp += paint(cctv[cam][0], cctv[cam][1], 2, -1, tempary);
		temp += paint(cctv[cam][0], cctv[cam][1], 3, -1, tempary);
		func(cam + 1, temp, tempary);
		return;
	}
}

int paint(int r, int c, int dir, int con, int map[][8]) {
	int i, cnt = 0;
	switch (dir) {
	case 0: //up
		for (i = r - 1; i >= 0; i--) {
			if (map[i][c] == 6)
				break;
			else if (map[i][c] <= 0 && map[i][c] != con) {
				map[i][c] = con;
				cnt++;
			}
		}
		return cnt;

	case 1: // right
		for (i = c + 1; i < M; i++) {
			if (map[r][i] == 6)
				break;
			else if (map[r][i] <= 0 && map[r][i] != con) {
				map[r][i] = con;
				cnt++;
			}
		}
		return cnt;

	case 2: // down
		for (i = r + 1; i < N; i++) {
			if (map[i][c] == 6)
				break;
			else if (map[i][c] <= 0 && map[i][c] != con) {
				map[i][c] = con;
				cnt++;
			}
		}
		return cnt;

	case 3: // elft
		for (i = c - 1; i >= 0; i--) {
			if (map[r][i] == 6)
				break;
			else if (map[r][i] <= 0 && map[r][i] != con) {
				map[r][i] = con;
				cnt++;
			}
		}
		return cnt;
	}
	return 0;
}