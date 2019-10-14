#include<iostream>
#include<queue>

using namespace std;
struct sharkway {
	pair<int, int> pos;
	int len;
	sharkway(pair<int, int> p, int l) : pos(p), len(l) {}
};
int main()
{
	int N, sharksize = 2, eat = 0;
	int map[20][20];
	int route[20][20] = { 0, };
	int px[4] = { -1, 0, 0, 1 };
	int py[4] = { 0, -1, 1, 0 };
	pair<int, int> shark;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark.first = i;
				shark.second = j;
				map[i][j] = 0;
			}
		}
	}

	queue<sharkway> q;
	int r, c, l;
	int minlen, total = 0;
	while (true) {
		minlen = 1000;
		q.push(sharkway(shark, 0));
		while (!q.empty()) {
			l = q.front().len;
			if (l > minlen) {
				q.pop();
				continue;
			}
			if (map[q.front().pos.first][q.front().pos.second] > 0 && map[q.front().pos.first][q.front().pos.second] < sharksize) {
				if (minlen > l) {
					minlen = l;
					shark.first = q.front().pos.first;
					shark.second = q.front().pos.second;
				}
				else if(minlen == l) {
					if (shark.first > q.front().pos.first) {
						shark.first = q.front().pos.first;
						shark.second = q.front().pos.second;
					}
					else if (shark.first == q.front().pos.first && shark.second > q.front().pos.second)
						shark.second = q.front().pos.second;
				}
			}
			else {
				for (int i = 0; i < 4; i++) {
					r = q.front().pos.first + px[i];
					c = q.front().pos.second + py[i];
					if (r < 0 || r >= N || c < 0 || c >= N)
						continue;
					if (map[r][c] > sharksize)
						continue;
					if (route[r][c] == 1)
						continue;
					route[r][c] = 1;
					q.push(sharkway(make_pair(r, c), l + 1));
				}
			}
			q.pop();
		}

		for (int i = 0; i < N; i++)
			for (int j = 0; j < N; j++)
				route[i][j] = 0;

		if (minlen == 1000) {
			break;
		}
		else {
			total += minlen;
			map[shark.first][shark.second] = 0;
			eat++;
			if (eat == sharksize) {
				eat = 0;
				sharksize++;
			}
		}
	}
	cout << total << endl;
	return 0;
}