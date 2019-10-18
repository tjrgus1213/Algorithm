#include<iostream>
#include<algorithm>
#include<cstring>

using namespace std;
struct roll {
	int r, c, s;
};
int ary[50][50], tary[50][50], seq[6];
roll lst[6];
void rotate_ary(roll tempr);
int main()
{
	int N, M, K;
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> ary[i][j];
		}
	}
	for (int i = 0; i < K; i++) {
		cin >> lst[i].r >> lst[i].c >> lst[i].s;
		lst[i].r--;	lst[i].c--;
		seq[i] = i;
	}
	int tmin = 1000000000, sum;
	do {
		memcpy(tary, ary, sizeof(ary));

		for (int i = 0; i < K; i++) {
			rotate_ary(lst[seq[i]]);
		}
		for (int i = 0; i < N; i++) {
			sum = 0;
			for (int j = 0; j < M; j++)
				sum += tary[i][j];
			if (tmin > sum)
				tmin = sum;
		}
	} while (next_permutation(seq, seq + K));

	cout << tmin << endl;
	return 0;
}

void rotate_ary(roll tempr) {

	int ur = tempr.r - tempr.s, dr = tempr.r + tempr.s;
	int lc = tempr.c - tempr.s, rc = tempr.c + tempr.s;
	int temp = tary[ur][lc];
	for (int i = ur; i < dr; i++) 
		tary[i][lc] = tary[i + 1][lc];
	for (int i = lc; i < rc; i++)
		tary[dr][i] = tary[dr][i + 1];
	for (int i = dr; i > ur; i--)
		tary[i][rc] = tary[i - 1][rc];
	for (int i = rc; i > lc + 1; i--)
		tary[ur][i] = tary[ur][i - 1];
	tary[ur][lc + 1] = temp;

	if (tempr.s > 1) {
		tempr.s--;
		rotate_ary(tempr);
	}
}