#include <string>
#include <vector>
#include <queue>

using namespace std;

struct robot_struct {
	robot_struct(int tx, int ty, int tdir, int ttime) : x(tx), y(ty), dir(tdir), time(ttime) {}
	robot_struct() {}
	int x, y, dir, time;
};
bool isvisit[100][100][2];

int solution(vector<vector<int>> board) {
	int answer = 0, N = board.size() - 1;
	int plusx[4] = { 0, 0, 1, -1 };
	int plusy[4] = { 1, -1, 0, 0 };
	bool isvisit[101][101][2];
	queue<robot_struct> q;
	robot_struct robot(0, 0, 0, 0);

	for (int i = 0; i < 100; i++)
		for (int j = 0; j < 100; j++)
			isvisit[i][j][0] = isvisit[i][j][1] = false;

	q.push(robot);
	robot_struct tr;
	while (!q.empty()) {
		tr = q.front();
		q.pop();

		if (isvisit[tr.y][tr.x][tr.dir])
			continue;

		if ((tr.dir == 0 && tr.x + 1 == N && tr.y == N) || (tr.dir == 1 && tr.x == N && tr.y + 1 == N)) {
			answer = tr.time;
			break;
		}
		isvisit[tr.y][tr.x][tr.dir] = true;

		for (int i = 0; i < 4; i++) {
			int ty = tr.y + plusy[i];
			int tx = tr.x + plusx[i];

			if(tx < 0 || tx > N || ty < 0 || ty > N)
				continue;


			if (tr.dir == 0 && tx + 1 <= N && board[ty][tx] == 0 && board[ty][tx + 1] == 0) 
				q.push(robot_struct(tx, ty, tr.dir, tr.time + 1));
			else if (tr.dir == 1 && ty + 1 <= N && board[ty][tx] == 0 && board[ty + 1][tx] == 0)
				q.push(robot_struct(tx, ty, tr.dir, tr.time + 1));
		}

		if (tr.dir == 0) {
			if (tr.x + 1 <= N && tr.y + 1 <= N) {
				if (board[tr.y + 1][tr.x] == 0 && board[tr.y + 1][tr.x + 1] == 0) {
					q.push(robot_struct(tr.x, tr.y, 1, tr.time + 1));
					q.push(robot_struct(tr.x + 1, tr.y, 1, tr.time + 1));
				}
			}
			if (tr.x + 1 <= N && tr.y - 1 >= 0) {
				if (board[tr.y - 1][tr.x] == 0 && board[tr.y - 1][tr.x + 1] == 0) {
					q.push(robot_struct(tr.x, tr.y - 1, 1, tr.time + 1));
					q.push(robot_struct(tr.x + 1, tr.y - 1, 1, tr.time + 1));
				}
			}
		}
		else {
			if (tr.x + 1 <= N && tr.y + 1 <= N) {
				if (board[tr.y][tr.x + 1] == 0 && board[tr.y + 1][tr.x + 1] == 0) {
					q.push(robot_struct(tr.x, tr.y, 0, tr.time + 1));
					q.push(robot_struct(tr.x, tr.y + 1, 0, tr.time + 1));
				}
			}
			if (tr.x - 1 >= 0 && tr.y + 1 <= N) {
				if (board[tr.y][tr.x - 1] == 0 && board[tr.y + 1][tr.x - 1] == 0) {
					q.push(robot_struct(tr.x - 1, tr.y, 0, tr.time + 1));
					q.push(robot_struct(tr.x - 1, tr.y + 1, 0, tr.time + 1));
				}
			}
		}

	}

	return answer;
}