#include<iostream>

using namespace std;

int N, M, R, C, L;
int ary[50][50];
int check[50][50];
int pipe[8][5] = { { 0, 0, 0, 0, 0 },{ 0, 1, 2, 3, -1 },{ 0, 1, -1, 0, 0 },{ 2, 3, -1, 0, 0 },{ 0, 3, -1, 0, 0 },
{ 1, 3, -1, 0, 0 },{ 1, 2, -1, 0, 0 },{ 0, 2, -1, 0, 0 } };
int plusx[4] = { -1, 1, 0, 0 };
int plusy[4] = { 0, 0, -1, 1 };
int find_way(int x, int y, int time);
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	int i, j;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> M >> R >> C >> L;
		for (i = 0; i < N; i++) {
			for (j = 0; j < M; j++) {
				cin >> ary[i][j];
				check[i][j] = 21;
			}
		}
		check[R][C] = 1;
		find_way(R, C, 1);

		int way = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				if (check[i][j] <= L)
					way++;

		cout << "#" << test_case << " ";
		cout << way << endl;
	}
	return 0;
}

int find_way(int x, int y, int time) {

	time++;
	int i = 0, j;
	int tempx, tempy;
	int a, b, c, d;
	bool is;
	while (pipe[ary[x][y]][i] != -1) {
		tempx = x + plusx[pipe[ary[x][y]][i]];
		tempy = y + plusy[pipe[ary[x][y]][i]];
		if (ary[tempx][tempy] != 0 && check[tempx][tempy] > time) {
			j = 0;
			is = false;
			a = plusx[pipe[ary[x][y]][i]];
			b = plusy[pipe[ary[x][y]][i]];
			while (pipe[ary[tempx][tempy]][j] != -1) {
				c = plusx[pipe[ary[tempx][tempy]][j]];
				d = plusy[pipe[ary[tempx][tempy]][j]];
				if (a + c == 0 && b + d == 0) {
					is = true;
					break;
				}
				j++;
			}
			if (is) {
				check[tempx][tempy] = time;
				if(time != L)
					find_way(tempx, tempy, time);
			}
		}
		i++;
	}
	return 0;
}