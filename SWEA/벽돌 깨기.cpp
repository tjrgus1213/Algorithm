#include<iostream>
#include<vector>
#include<stack>

using namespace std;

int function(vector<vector<int>> ary, int cnt);

int N, W, H;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;
	for (test_case = 1; test_case <= T; ++test_case)
	{
		cin >> N >> W >> H;
		vector<vector<int>> ary(H, vector<int>(W, 0));
		for (int i = 0; i < H; i++)
			for (int j = 0; j < W; j++)
				cin >> ary[i][j];

		cout << "#" << test_case << " " << function(ary, 0) << endl;

	}
	return 0;
}

int function(vector<vector<int>> ary, int cnt) {
	int min = 10000;
	if (cnt == N) {
		int brick_num = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (ary[i][j] != 0)
					brick_num++;
			}
		}
		return brick_num;
	}
	bool is = true;
	for (int i = 0; i < W; i++) {
		vector<vector<int>> temp_ary;
		temp_ary.assign(ary.begin(), ary.end());
		for (int j = 0; j < H; j++) {
			if (temp_ary[j][i] != 0) {
				is = false;
				stack<pair<int, int>> boom;
				boom.push(make_pair(j, i));
				while (!boom.empty()) {
					int a, b;
					a = boom.top().first;
					b = boom.top().second;
					boom.pop();
					for (int k = 1 - temp_ary[a][b]; k < temp_ary[a][b]; k++) {
						if (k + b < W && k + b > -1)
							boom.push(make_pair(a, k + b));
						if (k + a < H && k + a > -1)
							boom.push(make_pair(k + a, b));
					}
					temp_ary[a][b] = 0;
				}
				for (int i2 = 0; i2 < W; i2++) {
					int temp_pos = H - 1;
					for (int j2 = H - 1; j2 >= 0; j2--) {
						if (temp_ary[j2][i2] != 0) {
							temp_ary[temp_pos][i2] = temp_ary[j2][i2];
							temp_pos--;
						}
					}
					while (temp_pos >= 0) {
						temp_ary[temp_pos][i2] = 0;
						temp_pos--;
					}
				}

				int temp_num = function(temp_ary, cnt + 1);
				if (min > temp_num)
					min = temp_num;
				break;
			}
		}
	}
	if (is)
		return 0;
	return min;
}
