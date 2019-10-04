#include<iostream>
#include<queue>
using namespace std;

int plusx[4] = { 0, 1, 0, -1 }; // 오른쪽, 아래, 왼쪽, 위
int plusy[4] = { 1, 0, -1, 0 };

int main()
{
	int N, numOfapple, move;
	int ary[101][101] = { 0, };
	int r, c, i;
	cin >> N >> numOfapple;
	for (i = 0; i < numOfapple; i++) {
		cin >> r >> c;
		ary[r][c] = 1;
	}
	cin >> move;

	ary[1][1] = 2;
	pair<int, int> snake = make_pair(1, 1);
	queue<pair<int, int>> q;
	q.push(snake);
	bool is = false;
	int time, cnt = 0, dir = 0;
	char turn;
	while (true) {
		if(move > 0)
			cin >> time >> turn;
		else {
			time = 1000000;
			turn = 'N';
		}
		for (i = cnt; i < time; i++) {
			snake.first += plusx[dir];
			snake.second += plusy[dir];
			if (snake.first < 1 || snake.first > N || snake.second < 1 || snake.second > N) {
				is = true;
				cnt = i + 1;
				break;
			}
			else {
				if (ary[snake.first][snake.second] == 1) {
					q.push(snake);
					ary[snake.first][snake.second] = 2;
				}
				else if (ary[snake.first][snake.second] == 2) {
					is = true;
					cnt = i + 1;
					break;
				}
				else {
					q.push(snake);
					ary[snake.first][snake.second] = 2;
					pair<int, int> temp = q.front();
					ary[temp.first][temp.second] = 0;
					q.pop();
				}
			}
		}
		
		if (is)
			break;
		else
			cnt = time;

		switch (turn) {
		case 'D':
			dir++;
			if (dir == 4)
				dir = 0;
			break;
		case 'L':
			dir--;
			if (dir == -1)
				dir = 3;
			break;
		default:
			break;
		}
		move--;
	}

	cout << cnt << endl;
	return 0;
}