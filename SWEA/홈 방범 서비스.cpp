#include<iostream>
#include<vector>
using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	int ary[20][20];
	int cost[22];
	int profit[22];
	int N, M, i, j, a, b, k;
	for (i = 1; i < 22; i++)
		cost[i] = i * i + (i - 1) * (i - 1);

	for (test_case = 1; test_case <= T; ++test_case)
	{
		vector<pair<int, int>> house;
		cin >> N >> M;

		for (int i = 1; i < N + 2; i++) {
			profit[i] = cost[i] / M;
			if (cost[i] % M != 0)
				profit[i]++;
		}

		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				cin >> ary[i][j];
				if (ary[i][j] == 1)
					house.push_back(make_pair(i, j));
			}
		}

		int max_house = 0;
		int range = 1;
		int temp_house;
		int max_range;
		while(range <= N + 1) {
			for (i = 0; i < N; i++) {
				for (j = 0; j < N; j++) {
					temp_house = 0;
					for (k = 0; k < house.size(); k++) {
						if (abs(house[k].first - i) + abs(house[k].second - j) < range)
							temp_house++;
					}
					if (temp_house >= profit[range]) {
						if (max_house < temp_house)
							max_house = temp_house;
					}
				}
			}
			range++;
		}
		cout << "#" << test_case << " ";
		cout << max_house << endl;
	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}