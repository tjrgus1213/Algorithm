#include<iostream>
#include<algorithm>

using namespace std;

int N, ary[20][20], tmin = 10000000;

void divide_sector(int r, int c, int d1, int d2);

int main() {
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> ary[i][j];

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int x = 1; x <= j; x++) {
				for (int y = 1; (y < N - i) && (y <= j); y++) {
					if (i + x + y >= N)
						continue;
					divide_sector(i, j, x, y);
				}
			}
		}
	}
	cout << tmin << endl;
	return 0;
}

void divide_sector(int r, int c, int d1, int d2) {
	int sector[5] = { 0 };
	for (int i = 0; i < N; i++) {
		if (i < r) {
			for (int j = 0; j < N; j++) {
				if (j <= c)
					sector[0] += ary[i][j];
				else
					sector[1] += ary[i][j];
			}
		}
		else if(i > r + d1 + d2) {
			for (int j = 0; j < N; j++) {
				if (j < c - d1 + d2)
					sector[2] += ary[i][j];
				else
					sector[3] += ary[i][j];
			}
		}
		else {
			for (int j = 0; j < N; j++) {
				if (i < r + d1 && j < r + c - i)
					sector[0] += ary[i][j];
				else if (i >= r + d1 && j < i + c - r - 2 * d1)
					sector[2] += ary[i][j];
				else if (i <= r + d2 && j > c + i - r)
					sector[1] += ary[i][j];
				else if (i > r + d2 && j > c - i + r + 2 * d2)
					sector[3] += ary[i][j];
				else
					sector[4] += ary[i][j];
			}
		}
	}
	int temp = max(sector[0], max(sector[1], max(sector[2], max(sector[3], sector[4])))) - min(sector[0], min(sector[1], min(sector[2], min(sector[3], sector[4]))));
	if (tmin > temp)
		tmin = temp;

	return;
}