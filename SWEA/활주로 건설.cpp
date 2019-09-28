#include<iostream>

using namespace std;
int function(int* ary, int N, int X, int i);
int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	int h[20][20];
	for (test_case = 1; test_case <= T; ++test_case)
	{
		int N, X;
		cin >> N >> X;

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				cin >> h[i][j];

		int xtemp[20];
		int ytemp[20];
		int cnt = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				xtemp[j] = h[i][j];
				ytemp[j] = h[j][i];
			}
			cnt += function(xtemp, N, X, i);
			cnt += function(ytemp, N, X, i);
		}
		cout << "#" << test_case << " ";
		cout << cnt << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int function(int* ary, int N, int X, int i) {
	int is[20] = { 0, };
	for (int i = 1; i < N; i++) {
		if (ary[i] == ary[i - 1])
			continue;

		else if (ary[i] == ary[i - 1] + 1) {
			for (int j = 1; j <= X; j++) {
				if (i - j < 0 || ary[i - 1] != ary[i - j] || is[i - j] != 0) {
					return 0;
				}
			}
			for (int j = 1; j <= X; j++)
				is[i - j] = 1;
		}
		else if (ary[i] == ary[i - 1] - 1) {
			for (int j = 0; j < X; j++) {
				if (i + j >= N || ary[i] != ary[i + j] || is[i + j] != 0) {
					return 0;
				}
			}
			for (int j = 0; j < X; j++)
				is[i + j] = 1;
		}
		else
			return 0;
	}
	return 1;
}