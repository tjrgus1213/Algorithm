#include <string>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct s {
	s() {}
	s(int p, int de) : w(0), pos(p), dep(de) {}
	s(unsigned int we, int p, int de) : w(we), pos(p), dep(de) {}
	unsigned int w;
	int pos;
	int dep;
};

int solution(int n, vector<int> weak, vector<int> dist) {
	int answer = 1000;
	queue<s> q;
	s ts;
	for (int i = 0; i < weak.size(); i++) {
		q.push(s(i, 1));
	}
	int start, end, who;
	while (!q.empty()) {
		ts = q.front();
		q.pop();
		who = dist.size() - ts.dep;
		start = weak[ts.pos];
		end = start + dist[who];

		if (ts.dep == 1 && dist[who] >= n) {
			answer = 1;
			break;
		}

		if (end >= n) {
			end %= n;
			for (int i = 0; i < weak.size(); i++) {
				if (((ts.w >> i) & 1) == 1)
					continue;
				if ((start <= weak[i] && weak[i] < n) || (0 <= weak[i] && weak[i] <= end))
					ts.w = (ts.w | (1 << i));
			}
			//start ~ N, 0 ~ end
		}
		else {
			for (int i = 0; i < weak.size(); i++) {
				if (((ts.w >> i) & 1) == 1)
					continue;
				if (start <= weak[i] && weak[i] <= end)
					ts.w = (ts.w | (1 << i));
			}
			//start ~ end
		}

		bool is = true;
		for (int i = 0; i < weak.size(); i++) {
			if (((ts.w >> i) & 1) == 0) {
				is = false;
				if (ts.dep < dist.size())
					q.push(s(ts.w, i, ts.dep + 1));
			}
		}
		if (is) {
			answer = ts.dep;
			break;
		}
	}

	if (answer == 1000)
		return -1;
	else
		return answer;
}