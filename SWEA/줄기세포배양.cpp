#include<iostream>
#include<vector>
#include<queue>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;

	cin >> T;
	vector<pair<int, int>> plus = { make_pair(-1, 0), make_pair(1, 0), make_pair(0, -1), make_pair(0, 1) };
	for (test_case = 1; test_case <= T; ++test_case) {
		vector < vector<int>> ary(400, vector<int>(400, 0));
		vector < vector<int>> devide(400, vector<int>(400, 0));
		vector<queue<pair<int, int>>> sepo;
		for (int i = 0; i <= 10; i++) {
			queue<pair<int, int>> temp;
			sepo.push_back(temp);
		}
		const int posx = 200, posy = 200;
		int minx, miny; //
		minx = posx; miny = posy;
		int maxx, maxy; //
		int N, M, K;
		int cnt = 0;
		cin >> N >> M >> K;
		maxx = posx + N; maxy = posy + M; //
		for (int i = posx; i < posx + N; i++) {
			for (int j = posy; j < posy + M; j++) {
				cin >> ary[i][j];
				sepo[ary[i][j]].push(make_pair(i, j));
			}
		}

		int jugi = 1;
		while (jugi <= K) {
			for (int i = 10; i > 0; i--) {
				if (jugi % (i + 1) != 0)
					continue;

				int size = sepo[i].size();
				for (int j = 0; j < size; j++) {
					if (sepo[i].empty())
						break;
					int x = sepo[i].front().first;
					int y = sepo[i].front().second;
					sepo[i].pop();
					devide[x][y] = jugi;
					for (int k = 0; k < 4; k++) {
						int tempx = x + plus[k].first;
						int tempy = y + plus[k].second;
						if (ary[tempx][tempy] == 0) {
							ary[tempx][tempy] = i;
							sepo[i].push(make_pair(tempx, tempy));

							if (tempx < minx)
								minx = tempx;
							else if (tempx == maxx)
								maxx = tempx + 1;
							if (tempy < miny)
								miny = tempy;
							else if (tempy == maxy)
								maxy = tempy + 1;
						}
					}
				}
			}
			jugi++;
		}

		for (int i = minx; i < maxx; i++) {
			for (int j = miny; j < maxy; j++) {
				if (ary[i][j] > 0) {
					if (devide[i][j] == 0 || K - devide[i][j] < ary[i][j] - 1) {
						cnt++;
					}
				}
			}
		}

		cout << "#" << test_case << " ";
		cout << cnt << endl;
	}
	return 0;
}
