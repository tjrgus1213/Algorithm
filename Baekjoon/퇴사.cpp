#include<iostream>

using namespace std;

int N, M;
int ary[500][500];
int shape[10][3][2] = { {{1, 0}, {2, 0}, {3, 0}}, {{1, 0}, {0, 1}, {1, 1}}, {{1, 0}, {2, 0}, {2, 1}}, {{1, 0}, {2, 0}, {2, -1}}, {{1, 0}, {1, 1}, {2, 1}}, {{1, 0}, {1, -1}, {2, -1}},
{ {0 ,1}, {1, 1}, {0, 2}}, {{0, 1}, {-1, 1}, {0, 2} }, {{0, 1}, {1, 1}, {2, 1}}, {{0, -1}, {1, -1}, {2, -1}} };

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			cin >> ary[i][j];

	int max = 0;
	int temp = 0;
	int r, c;
	int i, j, a, b;
	for (i = 0; i < N; i++) {
		for (j = 0; j < M; j++) {
			for (a = 0; a < 10; a++) {
				temp = ary[i][j];
				for (b = 0; b < 3; b++) {
					r = i + shape[a][b][0];
					c = j + shape[a][b][1];
					if (r < 0 || r >= N || c < 0 || c >= M)
						break;
					temp += ary[r][c];
				}
				if (b == 3 && max < temp)	max = temp;

				temp = ary[i][j];
				for (b = 0; b < 3; b++) {
					r = i + shape[a][b][1];
					c = j + shape[a][b][0];
					if (r < 0 || r >= N || c < 0 || c >= M)
						break;
					temp += ary[r][c];
				}
				if (b == 3 && max < temp)	max = temp;
			}
		}
	}
	cout << max << endl;
	return 0;
}