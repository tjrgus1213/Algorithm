#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;

struct con {
	int r, c, len;
	con(int a, int b, int cc) : r(a), c(b), len(cc) {}
};
struct cmp {
	bool operator()(con a, con b) {
		return a.len > b.len;
	}
};

bool check(vector<int> &line, int r, int c) {
	int rroot = r, croot = c;
	while (rroot != line[rroot])
		rroot = line[rroot];
	while (croot != line[croot])
		croot = line[croot];

	if (rroot == croot)
		return false;

	line[croot] = rroot;
	return true;
}

int solution(vector<vector<int>> land, int height) {
	int answer = 0;
	const int N = land.size();
	int ary[300][300] = { 0, };
	int pr[4] = { 0, 0, -1, 1 };
	int pc[4] = { -1 ,1 , 0, 0 };
	queue<pair<int, int>> q;
	int ind = 1;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (ary[i][j] != 0)
				continue;
			ary[i][j] = ind;
			q.push(make_pair(i, j));
			while (!q.empty()) {
				for (int x = 0; x < 4; x++) {
					int r = q.front().first + pr[x];
					int c = q.front().second + pc[x];

					if (r < 0 || r >= N || c < 0 || c >= N || ary[r][c] != 0)
						continue;
					if (abs(land[q.front().first][q.front().second] - land[r][c]) <= height) {
						ary[r][c] = ind;
						q.push(make_pair(r, c));
					}
				}
				q.pop();
			}
			ind++;
		}
	}

	vector<vector<pair<int, int>>> line(ind);
	ind--;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			for (int x = 0; x < 4; x++) {
				int r = i + pr[x];
				int c = j + pc[x];

				if (r < 0 || r >= N || c < 0 || c >= N)
					continue;
				if (ary[i][j] != ary[r][c]) {
					int xx;
					for (xx = 0; xx < line[ary[i][j]].size(); xx++) {
						if (line[ary[i][j]][xx].first == ary[r][c]) {
							if (line[ary[i][j]][xx].second > abs(land[i][j] - land[r][c])) {
								line[ary[i][j]][xx].second = abs(land[i][j] - land[r][c]);
							}
							break;
						}
					}
					if (xx == line[ary[i][j]].size()) {
						line[ary[i][j]].push_back(make_pair(ary[r][c], abs(land[i][j] - land[r][c])));
					}
				}
			}
		}
	}

	priority_queue<con, vector<con>, cmp> pq;
	set<pair<int, int>> s;
	pair<set<pair<int, int>>::iterator, bool> ps;
	for (int i = 1; i < line.size(); i++) {
		for (int j = 0; j < line[i].size(); j++) {
			int tmin = min(line[i][j].first, i);
			int tmax = max(line[i][j].first, i);
			ps = s.insert(make_pair(tmin, tmax));
			if (ps.second)
				pq.push(con(tmin, tmax, line[i][j].second));
		}
	}

	vector<int> fline(ind + 1);
	for (int i = 0; i < fline.size(); i++)
		fline[i] = i;

	while (!pq.empty()) {
		if (check(fline, pq.top().r, pq.top().c)) {
			answer += pq.top().len;
		}
		pq.pop();
	}

	return answer;
}