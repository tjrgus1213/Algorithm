#include <string>
#include <vector>
#include <queue>

using namespace std;

int M, N;

void rotate_key(queue<pair<int, int>> &q) {
	int size = q.size();
	int x, y;
	for (int i = 0; i < size; i++) {
		x = q.front().first;
		y = q.front().second;
		q.push(make_pair(y, N - x - 1));
		q.pop();
	}
}

bool solution(vector<vector<int>> key, vector<vector<int>> lock) {
	bool answer = false;
	M = key.size();
	N = lock.size();
	int lock_hole = 0;
	int key_block = 0;

	queue<pair<int, int>> q;

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			if (lock[i][j] == 0)
				lock_hole++;

	for (int i = 0; i < M; i++) {
		for (int j = 0; j < M; j++) {
			if (key[i][j] == 1) {
				key_block++;
				q.push(make_pair(i, j));
			}
		}
	}
	int a, b, temp;
	bool is;
	for (int r = 0; r < 4; r++) {
		rotate_key(q);
		for (int i = 1 - N; i < N; i++) {
			for (int j = 1 - N; j < N; j++) {
				temp = 0;
				is = true;
				for (int x = 0; x < key_block; x++) {
					a = q.front().first;
					b = q.front().second;
					q.pop();
					q.push(make_pair(a, b));
					if (a + i < N && b + j < N && a + i >= 0 && b + j >= 0) {
						if (lock[a + i][b + j] == 0) {
							temp++;
						}
						else {
							is = false;
						}
					}
				}
				if (temp == lock_hole && is) {
					return true;
				}
			}
		}
	}
	return answer;
}