#include<iostream>

using namespace std;

int N;
int plusx[4] = { -1, 1, 0, 0 };
int plusy[4] = { 0, 0, -1, 1 };

int func(int ary[][20], int cnt);
void move(int ary[][20], int dir);

int main()
{
	int ary[20][20];
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ary[i][j];

	cout << func(ary, 0) << endl;
	return 0;
}

int func(int ary[][20], int cnt) {
	if (cnt == 5) {
		int max = 0;
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				if (max < ary[i][j])
					max = ary[i][j];
		return max;
	}

	int temp_ary[20][20];
	int temp, max = 0;
	for (int i = 0; i < 4; i++) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				temp_ary[i][j] = ary[i][j];

		move(temp_ary, i);
		temp = func(temp_ary, cnt + 1);
		if (max < temp)
			max = temp;
	}
	return max;
}

void move(int ary[][20], int dir) {
	int i, j, k;
	int check[20][20] = { 0, };

	switch (dir) {
	case 0: // up
		for (i = 1; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (ary[i][j] != 0) {
					k = i - 1;
					while (k >= 0 && ary[k][j] == 0)	k--;
					k++;
					if (k != i) {
						ary[k][j] = ary[i][j];
						ary[i][j] = 0;
					}
					if (k > 0) {
						if (ary[k][j] == ary[k - 1][j] && check[k - 1][j] == 0) {
							check[k - 1][j] = 1;
							ary[k - 1][j] *= 2;
							ary[k][j] = 0;
						}
					}
				}
			}
		}
		return;

	case 1: // down
		for (i = N - 2; i >= 0; i--) {
			for (j = N - 1; j >= 0 ; j--) {
				if (ary[i][j] != 0) {
					k = i + 1;
					while (k < N && ary[k][j] == 0)	k++;
					k--;
					if (k != i) {
						ary[k][j] = ary[i][j];
						ary[i][j] = 0;
					}
					if (k < N - 1) {
						if (ary[k][j] == ary[k + 1][j] && check[k + 1][j] == 0) {
							check[k + 1][j] = 1;
							ary[k + 1][j] *= 2;
							ary[k][j] = 0;
						}
					}
				}
			}
		}
		return;

	case 2: // left
		for (i = 0; i < N; i++) {
			for (j = 1; j < N; j++) {
				if (ary[i][j] != 0) {
					k = j - 1;
					while (k >= 0 && ary[i][k] == 0)	k--;
					k++;
					if (k != j) {
						ary[i][k] = ary[i][j];
						ary[i][j] = 0;
					}
					if (k > 0) {
						if (ary[i][k] == ary[i][k - 1] && check[i][k - 1] == 0) {
							check[i][k - 1] = 1;
							ary[i][k - 1] *= 2;
							ary[i][k] = 0;
						}
					}
				}
			}
		}
		return;

	case 3: // right
		for (i = N - 1; i >= 0; i--) {
			for (j = N - 2; j >= 0; j--) {
				if (ary[i][j] != 0) {
					k = j + 1;
					while (k < N && ary[i][k] == 0)	k++;
					k--;
					if (k != j) {
						ary[i][k] = ary[i][j];
						ary[i][j] = 0;
					}
					if (k < N - 1) {
						if (ary[i][k] == ary[i][k+1] && check[i][k+1] == 0) {
							check[i][k+1] = 1;
							ary[i][k+1] *= 2;
							ary[i][k] = 0;
						}
					}
				}
			}
		}
		return;
	}
}