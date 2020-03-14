#include <iostream>
#include <string>
#include <vector>
#include <memory.h>

using namespace std;

bool check[100][100];
int pr[4] = { 0, 0, -1, 1 };
int pc[4] = { 1, -1, 0, 0 };
int M, N;
string answer;

bool canRemove(vector<string> &board, pair<int, int> p1, pair<int, int> p2) {
	char ch = board[p1.first][p1.second];
	for (int i = 0; i < M; i++)
		for (int j = 0; j < N; j++)
			check[i][j] = false;
	for (int i = 0; i < 4; i++) {
		int r = p1.first;
		int c = p1.second;
		while (board[r][c] == '.' || board[r][c] == ch) {
			check[r][c] = true;
			r += pr[i];
			c += pc[i];
			if (r < 0 || r >= M || c < 0 || c >= N)
				break;
		}
	}
	for (int i = 0; i < 4; i++) {
		int r = p2.first;
		int c = p2.second;
		while (board[r][c] == '.' || board[r][c] == ch) {
			if (check[r][c])
				return true;
			r += pr[i];
			c += pc[i];
			if (r < 0 || r >= M || c < 0 || c >= N)
				break;
		}
	}
	return false;
}

void removeBlock(vector<vector<pair<int, int>>> &blocks, vector<string> &board, int removed) {
	for (int i = 0; i < 26; i++) {
		if (blocks[i].size() == 0 || board[blocks[i][0].first][blocks[i][0].second] == '.')
			continue;
		if (canRemove(board, blocks[i][0], blocks[i][1])) {
			board[blocks[i][0].first][blocks[i][0].second] = '.';
			board[blocks[i][1].first][blocks[i][1].second] = '.';
			answer.push_back('A' + i);
			removeBlock(blocks, board, removed + 1);
			return;
		}
	}
}

string solution(int m, int n, vector<string> board) {
	vector<vector<pair<int, int>>> blocks(26);
	answer = "";
	M = m;
	N = n;
	int cnt = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (board[i][j] >= 'A' && board[i][j] <= 'Z') {
				blocks[board[i][j] - 'A'].push_back(make_pair(i, j));
				cnt++;
			}
		}
	}
	removeBlock(blocks, board, 0);
	if (answer.size() != cnt / 2)
		return "IMPOSSIBLE";
	return answer;
}