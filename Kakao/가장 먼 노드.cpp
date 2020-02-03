#include <string>
#include <vector>
#include <map>
#include <queue>

using namespace std;

bool isvisit[20000] = { 0, };

int solution(int n, vector<vector<int>> edge) {
	int answer = 0;
	map<int, vector<int>> m;
	queue<int> q;
	for (int i = 0; i < edge.size(); i++) {
		m[edge[i][0]].push_back(edge[i][1]);
		m[edge[i][1]].push_back(edge[i][0]);
	}
	q.push(1);
	int size = 1, cnt = 0, num;
	isvisit[1] = true;
	while (!q.empty()) {
		num = q.front();
		q.pop();
		for (int i = 0; i < m[num].size(); i++) {
			if (!isvisit[m[num][i]]) {
				q.push(m[num][i]);
				isvisit[m[num][i]] = true;
			}
		}

		cnt++;
		if (size == cnt && !q.empty()) {
			size = q.size();
			cnt = 0;
		}
	}
	answer = size;
	return answer;
}