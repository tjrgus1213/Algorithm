#include<iostream>
#include<deque>

using namespace std;

int plusx[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int plusy[8] = {-1, 0, 1, -1, 1, -1, 0, 1};

struct tree {
	deque<int> lt;
};

int main()
{
	int N, M, K;
	int map[11][11];
	int nut[11][11];
	cin >> N >> M >> K;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			cin >> nut[i][j];
			map[i][j] = 5;
		}
	}
	tree treelist[11][11];
	int i, j, r, c;
	for (i = 0; i < M; i++) {
		cin >> r >> c >> j;
		treelist[r][c].lt.push_back(j);
	}

	deque<int>::iterator it;
	int size;

	while (K > 0) {
		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				size = treelist[i][j].lt.size();
				for (it = treelist[i][j].lt.begin(); it != treelist[i][j].lt.end(); ++it) {
					if ((*it) <= map[i][j]) {
						map[i][j] -= (*it);
						(*it)++;
						size--;
					}
					else {
						for (r = 0; r < size; r++) {
							map[i][j] += treelist[i][j].lt.back() / 2;
							treelist[i][j].lt.pop_back();
						}
						break;
					}
				}
			}
		}

		for (i = 1; i <= N; i++) {
			for (j = 1; j <= N; j++) {
				for (it = treelist[i][j].lt.begin(); it != treelist[i][j].lt.end(); ++it) {
					if ((*it) % 5 == 0) {
						for (r = 0; r < 8; r++) {
							if (i + plusx[r] > 0 && i + plusx[r] <= N && j + plusy[r] > 0 && j + plusy[r] <= N) {
								treelist[i + plusx[r]][j + plusy[r]].lt.push_front(1);
							}
						}
					}
				}
				map[i][j] += nut[i][j];
			}
		}
		K--;
	}

	r = 0;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			r += treelist[i][j].lt.size();
		}
	}
	cout << r << endl;
	return 0;
}