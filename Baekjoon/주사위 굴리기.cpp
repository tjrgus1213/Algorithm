#include<iostream>
using namespace std;

int plusx[5] = {0, 0, 0, -1, 1 };
int plusy[5] = {0, 1, -1, 0, 0 };
int face[6] = { 0, 0, 0, 0, 0, 0 }; // up, down, left, right, bottom, up
void roll(int dir);
int main()
{
	int N, M, r, c, K;
	int map[20][20];
	cin >> N >> M >> r >> c >> K;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> map[i][j];

	int dir;
	while (K > 0) {
		K--;
		cin >> dir;
		if (r + plusx[dir] < 0 || r + plusx[dir] == N || c + plusy[dir] < 0 || c + plusy[dir] == M)
			continue;
		r += plusx[dir];
		c += plusy[dir];
		roll(dir);
		if (map[r][c] == 0) {
			map[r][c] = face[4];
		}
		else {
			face[4] = map[r][c];
			map[r][c] = 0;
		}
		cout << face[5] << endl;
	}
	return 0;
}

void roll(int dir) {
	int temp;

	switch (dir) {
	case 1:
		temp = face[2];
		face[2] = face[4];
		face[4] = face[3];
		face[3] = face[5];
		face[5] = temp;
		break;

	case 2:
		temp = face[2];
		face[2] = face[5];
		face[5] = face[3];
		face[3] = face[4];
		face[4] = temp;
		break;

	case 3:
		temp = face[0];
		face[0] = face[5];
		face[5] = face[1];
		face[1] = face[4];
		face[4] = temp;
		break;

	case 4:
		temp = face[0];
		face[0] = face[4];
		face[4] = face[1];
		face[1] = face[5];
		face[5] = temp;
		break;
	default:
		break;
	}
}