#include <iostream>

using namespace std;

struct mal {
	mal* up;
	mal* down;
	int r, c, dir, size;
};

void check_mal(mal* tm);
void move_upmal(mal* m);
void reverse_mal(mal* m);

int N, K;
int ary[14][14];
mal m[10];

int main() {
	int pr[5] = { 0, 0, 0, -1, 1 };
	int pc[5] = { 0, 1, -1, 0, 0 };

	cin >> N >> K;
	for (int i = 0; i <= N + 1; i++) {
		ary[0][i] = 2;
		ary[N + 1][i] = 2;
		ary[i][0] = 2;
		ary[i][N + 1] = 2;
	}

	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			cin >> ary[i][j];
	
	for (int i = 0; i < K; i++) {
		cin >> m[i].r >> m[i].c >> m[i].dir;
		m[i].up = NULL;
		m[i].down = NULL;
		m[i].size = 1;
	}

	int turn = 1;
	while (turn <= 1000) {
		for (int i = 0; i < K; i++) {
			
			int tdir = m[i].dir;

			m[i].r += pr[tdir];
			m[i].c += pc[tdir];
			switch (ary[m[i].r][m[i].c]) {
			case 0:
				check_mal(&m[i]);
				move_upmal(&m[i]);
				break;
			case 1:
				check_mal(&m[i]);
				move_upmal(&m[i]);
				reverse_mal(&m[i]);
				break;
			case 2:
				if (ary[m[i].r - (2 * pr[tdir])][m[i].c - (2 * pc[tdir])] == 2) {
					m[i].r -= pr[tdir];
					m[i].c -= pc[tdir];
				}
				else {
					m[i].r -= 2 * pr[tdir];
					m[i].c -= 2 * pc[tdir];
					check_mal(&m[i]);
					move_upmal(&m[i]);
					if(ary[m[i].r][m[i].c] == 1)
						reverse_mal(&m[i]);
				}
				if (tdir % 2 == 0)
					m[i].dir--;
				else
					m[i].dir++;
				break;
			}
			
			for (int j = 0; j < K; j++) {
				if (m[j].size >= 4) {
					cout << turn << endl;
					return 0;
				}
			}
		}
		turn++;
	}
	cout << -1 << endl;
	return 0;
}

void check_mal(mal* tm) {
	int tmin = 100;
	mal* temp = tm->down;
	if (tm->down != NULL) {
		while (temp != NULL) {
			temp->size -= tm->size;
			temp = temp->down;
		}

		tm->down->up = NULL;
		tm->down = NULL;
	}

	for (int i = 0; i < K; i++) {
		if ((tm != &m[i]) && (tm->r == m[i].r) && (tm->c == m[i].c)) {
			if (m[i].size == 1) {
				m[i].up = tm;
				tm->down = &m[i];
			}
			m[i].size += tm->size;
		}
	}
}

void move_upmal(mal* m) {
	while (m->up != NULL) {
		m->up->r = m->r;
		m->up->c = m->c;
		m = m->up;
	}
}

void reverse_mal(mal* m) {
	int size = m->size;
	if (size == 1)
		return;
	mal** nm = new mal*[size];
	for (int i = 0; i < size; i++) {
		nm[i] = m;
		m = m->up;
	}
	nm[0]->up = NULL;
	nm[0]->size = 1;
	nm[size - 1]->down = nm[0]->down;
	if(nm[0]->down != NULL)
		nm[0]->down->up = nm[size - 1];
	for (int i = 1; i < size; i++) {
		nm[i]->up = nm[i - 1];
		nm[i]->size = i + 1;
		nm[i - 1]->down = nm[i];
	}
	delete[] nm;
}