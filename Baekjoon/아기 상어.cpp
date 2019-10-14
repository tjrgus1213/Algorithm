#include<iostream>
#include<queue>

using namespace std;

int plusx[4] = { -1, 0, 0, 1 };
int plusy[4] = { 0, -1, 1, 0 };

struct sha {
	pair<int, int> pos;
	int cnt;
};

int main()
{
	int N;
	int map[20][20];
	int route[20][20] = { 0, };
	pair<int, int> shark;
	int sharksize = 2, eat = 0, totalmove = 0;;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 9) {
				shark = make_pair(i, j);
				map[i][j] = 0;
			}
		}
	}
	sha temp;
	bool is = true;
	pair<int, int> temppos;
	queue<sha> q;
	int tempcnt, r, c, tempr, tempc, len;
	while (is) {
		is = false;
		len = 1000;
		tempr = 1000; tempc = 1000;
		temp.pos = shark;
		temp.cnt = 0;
		q.push(temp);
		route[shark.first][shark.second] = 1;
		while (!q.empty()) {
			temppos = q.front().pos;
			tempcnt = q.front().cnt;
			q.pop();
			for (int i = 0; i < 4; i++) {
				r = temppos.first + plusx[i];
				c = temppos.second + plusy[i];
				if (r >= 0 && r < N && c >= 0 && c < N && route[r][c] == 0) {
					if (map[r][c] > 0 && map[r][c] < sharksize) {
						is = true;
						if (len >= tempcnt) {
							len = tempcnt;
							if (r < tempr) {
								tempr = r;
								tempc = c;
							}
							else if (r == tempr && c < tempc) {
								tempc = c;
							}
						}
					}
					else if (map[r][c] == 0 || map[r][c] == sharksize) {
						if (tempcnt < len) {
							route[r][c] = 1;
							temp.pos = make_pair(r, c);
							temp.cnt = tempcnt + 1;
							q.push(temp);
						}
					}
				}
			}
		}

		if (is) {
			while (!q.empty())
				q.pop();
			totalmove += len + 1;
			shark = make_pair(tempr, tempc);
			map[tempr][tempc] = 0;
			eat++;
			if (eat == sharksize) {
				eat = 0;
				sharksize++;
			}
			for (int i = 0; i < N; i++)
				for (int j = 0; j < N; j++)
					route[i][j] = 0;
		}
	}

	cout << totalmove << endl;
	return 0;
}