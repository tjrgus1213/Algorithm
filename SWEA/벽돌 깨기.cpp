#include<iostream>
#include<cstring>
using namespace std;

int N, W, H, tmax = 0;
int ary[15][12][5];
int pr[4] = { -1, 1, 0, 0 };
int pc[4] = { 0, 0, -1, 1 };

int bomb(int layer, int r, int c);
void func(int cnt, int brick);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		tmax = 0;
		cin >> N >> W >> H;

		int br = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				cin >> ary[i][j][0];
				if (ary[i][j][0] > 0)
					br++;
			}
		}

		func(0, 0);
		br -= tmax;
		cout << "#" << test_case << " ";
		cout << br << endl;
	}
	return 0;
}

void func(int cnt, int brick) {
	int tbrick;
	for (int i = 0; i < W; i++) {
		for (int a = 0; a < H; a++)
			for (int b = 0; b < W; b++)
				ary[a][b][cnt + 1] = ary[a][b][cnt];
	
		tbrick = brick;
		for (int j = 0; j < H; j++) {
			if (ary[j][i][cnt + 1] != 0) {
				tbrick += bomb(cnt + 1, j, i);
				break;
			}
		}

		for (int i2 = 0; i2 < W; i2++) {
			int temp_pos = H - 1;
			for (int j2 = H - 1; j2 >= 0; j2--) {
				if (ary[j2][i2][cnt + 1] != 0) {
					ary[temp_pos][i2][cnt + 1] = ary[j2][i2][cnt + 1];
					temp_pos--;
				}
			}
			while (temp_pos >= 0) {
				ary[temp_pos][i2][cnt + 1] = 0;
				temp_pos--;
			}
		}

		if(cnt < N - 1)
			func(cnt + 1, tbrick);
		else {
			if (tmax < tbrick) {
				tmax = tbrick;
			}
		}

	}
}

int bomb(int layer, int r, int c) {
	int s = ary[r][c][layer];
	ary[r][c][layer] = 0;
	int cnt = 1;
	for (int i = 1; i < s; i++) {
		for (int j = 0; j < 4; j++) {
			if (r + pr[j] * i < 0 || r + pr[j] * i >= H || c + pc[j] * i < 0 || c + pc[j] * i >= W)
				continue;
			if (ary[r + pr[j] * i][c + pc[j] * i][layer] != 0)
				cnt += bomb(layer, r + pr[j] * i, c + pc[j] * i);
		}
	}
	return cnt;
}