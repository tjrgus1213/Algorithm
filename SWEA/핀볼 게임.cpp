#include<iostream>
#include<vector>
#include<map>

using namespace std;

vector<pair<int, int>> dir = { make_pair(0, -1), make_pair(0, 1), make_pair(-1, 0), make_pair(1, 0) };
map<int, vector<pair<int, int>>> wormhole;
int N;

int start_pinball(vector<vector<int>> &ary, int x, int y, pair<int, int> d);

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case)
	{
		int max_point = 0;
		cin >> N;
		wormhole.clear();
		vector<vector<int>> ary(N, vector<int>(N, 0));
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				cin >> ary[i][j];
				if (ary[i][j] > 5) {
					wormhole[ary[i][j]].push_back(make_pair(i, j));
				}
			}
		}
		int temp_point;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (ary[i][j] == 0) {
					for (int k = 0; k < 4; k++) {
						temp_point = start_pinball(ary, i, j, dir[k]);
						if (max_point < temp_point)
							max_point = temp_point;
					}
				}
			}
		}

		cout << "#" << test_case << " ";
		cout << max_point << endl;

	}
	return 0;//정상종료시 반드시 0을 리턴해야합니다.
}

int start_pinball(vector<vector<int>> &ary, int x, int y, pair<int, int> d) {
	int posx = x;
	int posy = y;
	int point = 0;
	do {
		switch (ary[posx][posy]) {
		case -1:
			break;
		case 0:
			break;
		case 1:
			point++;
			if (d.second == 1) {
				d.second = -1;
			}
			else if (d.second == -1) {
				d.second = 0;
				d.first = -1;
			}
			else if (d.first == 1) {
				d.second = 1;
				d.first = 0;
			}
			else {
				d.first = 1;
			}
			break;

		case 2:
			point++;
			if (d.second == 1) {
				d.second = -1;
			}
			else if (d.second == -1) {
				d.second = 0;
				d.first = 1;
			}
			else if (d.first == 1) {
				d.first = -1;
			}
			else {
				d.second = 1;
				d.first = 0;
			}
			break;

		case 3:
			point++;
			if (d.second == 1) {
				d.second = 0;
				d.first = 1;
			}
			else if (d.second == -1) {
				d.second = 1;
			}
			else if (d.first == 1) {
				d.first = -1;
			}
			else {
				d.second = -1;
				d.first = 0;
			}
			break;

		case 4:
			point++;
			if (d.second == 1) {
				d.second = 0;
				d.first = -1;
			}
			else if (d.second == -1) {
				d.second = 1;
			}
			else if (d.first == 1) {
				d.second = -1;
				d.first = 0;
			}
			else {
				d.first = 1;
			}
			break;

		case 5:
			point++;
			d.first *= -1;
			d.second *= -1;
			break;

		default:
			vector<pair<int, int>> tp = wormhole[ary[posx][posy]];
			if (posx == tp[0].first && posy == tp[0].second) {
				posx = tp[1].first;
				posy = tp[1].second;
			}
			else {
				posx = tp[0].first;
				posy = tp[0].second;
			}
		}
		posx += d.first;
		posy += d.second;

		if ((posx < 0 || posx >= N)) {
			d.first *= -1;
			posx += d.first;
			point++;
		}
		else if ((posy < 0 || posy >= N)) {
			d.second *= -1;
			posy += d.second;
			point++;
		}
	} while (!(posx == x && posy == y) && !(ary[posx][posy] == -1));
	return point;
}