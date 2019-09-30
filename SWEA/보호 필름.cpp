#include<iostream>
#include<vector>

using namespace std;

int D, W, K;
int min_depth;
int function(int row, int state, int ary[][20], int depth);
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	int i, j;
	int ary[13][20];

	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> D >> W >> K;
		for (i = 0; i < D; i++)
			for (j = 0; j < W; j++)
				cin >> ary[i][j];

		int pre, cnt, max_cnt;
		for (j = 0; j < W; j++) {
			pre = ary[0][j];
			cnt = 1;
			max_cnt = 1;
			for (i = 1; i < D; i++) {
				if (ary[i][j] == pre)
					cnt++;
				else {
					if (max_cnt < cnt)
						max_cnt = cnt;
					cnt = 1;
				}
				pre = ary[i][j];
			}
			if (max_cnt < cnt)
				max_cnt = cnt;
			if (max_cnt < K)
				break;
		}
		if (j == W) {
			cout << "#" << test_case << " 0\n";
			continue;
		}

		min_depth = D;
		for (j = 0; j < D; j++) {
			function(j, 0, ary, 1);
			function(j, 1, ary, 1);
		}
		cout << "#" << test_case << " ";
		cout << min_depth << endl;
	}
	system("pause");
	return 0;
}

int function(int row, int state, int ary[][20], int depth) {
	int tary[13][20];
	int i, j;

	if (depth >= min_depth)
		return min_depth;

	for (i = 0; i < D; i++) {
		for (j = 0; j < W; j++) {
			if (i == row)
				tary[i][j] = state;
			else
				tary[i][j] = ary[i][j];
		}
	}

	int pre, cnt, max_cnt;
	for (j = 0; j < W; j++) {
		pre = tary[0][j];
		cnt = 1;
		max_cnt = 1;
		for (i = 1; i < D; i++) {
			if (tary[i][j] == pre)
				cnt++;
			else {
				if (max_cnt < cnt)
					max_cnt = cnt;
				cnt = 1;
			}
			pre = tary[i][j];
		}
		if (max_cnt < cnt)
			max_cnt = cnt;
		if (max_cnt < K)
			break;
	}

	if (j == W) {
		if (min_depth > depth)
			min_depth = depth;
		return depth;
	}

	else {
		for (i = row + 1; i < D; i++) {
			function(i, 0, tary, depth + 1);
			function(i, 1, tary, depth + 1);
		}
	}
	return D;
}