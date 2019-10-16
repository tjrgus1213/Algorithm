#include<iostream>
#include<cstring>
#include<vector>
#include<queue>

using namespace std;

struct v {
	int r, c, time;
	v(int row, int col, int t) : r(row), c(col), time(t) {};
};

int map[50][50];
int tempmap[50][50];
int pr[4] = { -1, 1, 0, 0 };
int pc[4] = { 0, 0, -1, 1 };
int N, M, tmin = 10000000, vac = 0;
vector<pair<int, int>> virus;
vector<pair<int, int>> active(10);

void solve(int pre, int cnt);

int main()
{
	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> map[i][j];
			if (map[i][j] == 2)
				virus.push_back(make_pair(i, j));
			else if (map[i][j] == 0)
				vac++;
		}
	}
	solve(-1, 0);
	if (tmin == 10000000)
		tmin = -1;
	cout << tmin << endl;
	return 0;
}

void solve(int pre, int cnt) {
	if (cnt < M) {
		for (int i = pre + 1; i < virus.size(); i++) {
			active[cnt] = virus[i];
			solve(i, cnt + 1);
		}
	}
	else {
		int i, r, c, t, tmax = 0, tvac = vac, tr, tc;
		queue<v> vis;
		memcpy(tempmap, map, sizeof(map));
		for (i = 0; i < M; i++) {
			vis.push(v(active[i].first, active[i].second, 0));
			tempmap[active[i].first][active[i].second] = 3;
		}

		while (!vis.empty()) {
			r = vis.front().r;
			c = vis.front().c;
			t = vis.front().time;
			vis.pop();
			for (i = 0; i < 4; i++) {
				tr = r + pr[i];
				tc = c + pc[i];
				if (tr < 0 || tr >= N || tc < 0 || tc >= N)
					continue;
				if (tempmap[tr][tc] == 1 || tempmap[tr][tc] == 3)
					continue;
				vis.push(v(tr, tc, t + 1));

				if (tempmap[tr][tc] == 0) {
					if (t + 1 > tmin)
						return;
					if (tmax < t + 1)
						tmax = t + 1;
					tvac--;
				}
				tempmap[tr][tc] = 3;
			}
		}
		if (tvac > 0)
			return;

		if (tmin > tmax)
			tmin = tmax;
	}
}