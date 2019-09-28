#include<iostream>
#include<vector>
#include<iomanip>

using namespace std;

int plusx[5] = { 0, -1, 1, 0, 0 };
int plusy[5] = { 0, 0, 0, -1, 1 };
int back[5] = { 0, 2, 1, 4, 3 };

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, M, K;
		int ary[100][100];
		vector<pair<int, int>> cell;
		vector<int> dir;
		vector<int> numOfcell;
		cin >> N >> M >> K;
		int i, j;
		int a, b;
		int temp;
		for (i = 0; i < K; i++) {
			cin >> a >> b;
			cell.push_back(make_pair(a, b));
			cin >> a;
			numOfcell.push_back(a);
			cin >> j;
			dir.push_back(j);
		}

		while (M > 0) {
			for (i = 0; i < N; i++)
				for (j = 0; j < N; j++)
					ary[i][j] = -1;

			vector<int> tempcell = numOfcell;
			for (i = 0; i < K; i++) {
				if (numOfcell[i] == 0)
					continue;

				cell[i].first += plusx[dir[i]];
				cell[i].second += plusy[dir[i]];
				if (cell[i].first == 0 || cell[i].second == 0 || cell[i].first == N - 1 || cell[i].second == N - 1) {
					dir[i] = back[dir[i]];
					numOfcell[i] /= 2;
				}

				if (ary[cell[i].first][cell[i].second] != -1) {
					temp = ary[cell[i].first][cell[i].second];
					if (tempcell[i] >= tempcell[temp]) {
						numOfcell[i] += numOfcell[temp];
						numOfcell[temp] = 0;
						ary[cell[i].first][cell[i].second] = i;
					}
					else {
						numOfcell[temp] += numOfcell[i];
						numOfcell[i] = 0;
					}
				}
				else
					ary[cell[i].first][cell[i].second] = i;
			}
			M--;
		}
		int sum = 0;
		for (i = 0; i < K; i++) {
			if (numOfcell[i] > 0)
				sum += numOfcell[i];
		}
		cout << "#" << test_case << " ";
		cout << sum << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}