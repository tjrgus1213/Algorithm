#include<iostream>

using namespace std;

int main()
{
	int N, L;
	int map[100][100];
	cin >> N >> L;

	int i, j, k;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			cin >> map[i][j];

	int h, v;
	bool ish, isv;
	int cnt = 0;
	for (i = 0; i < N; i++) {
		h = -1;	v = -1;
		ish = false;	isv = false;
		for (j = 1; j < N; j++) {
			if (!ish) {
				if (abs(map[i][j - 1] - map[i][j]) == 1) {
					if (map[i][j - 1] > map[i][j]) {
						if (j + L <= N) {
							for (k = j; k < j + L; k++)
								if (map[i][k] != map[i][j])
									break;
							if (k == j + L)
								h = k - 1;
							else
								ish = true;
						}
						else
							ish = true;
					}
					else {
						if (h < j - L && j - L >= 0) {
							for (k = j - L; k < j; k++)
								if (map[i][k] != map[i][j - 1])
									break;
							if (k == j)
								h = k - 1;
							else
								ish = true;
						}
						else
							ish = true;
					}
				}
				else if (map[i][j - 1] != map[i][j]) {
					ish = true;
				}
			}

			if (!isv) {
				if (abs(map[j - 1][i] - map[j][i]) == 1) {
					if (map[j - 1][i] > map[j][i]) {
						if (j + L <= N) {
							for (k = j; k < j + L; k++)
								if (map[k][i] != map[j][i])
									break;
							if (k == j + L)
								v = k - 1;
							else
								isv = true;
						}
						else
							isv = true;
					}
					else {
						if (v < j - L && j - L >= 0) {
							for (k = j - L; k < j; k++)
								if (map[k][i] != map[j - 1][i])
									break;
							if (k == j)
								v = k - 1;
							else
								isv = true;
						}
						else
							isv = true;
					}
				}
				else if (map[j - 1][i] != map[j][i]) {
					isv = true;
				}
			}
		}
		if (!ish)
			cnt++;
		if (!isv) 
			cnt++;
	}

	cout << cnt << endl;
	system("pause");
	return 0;
}