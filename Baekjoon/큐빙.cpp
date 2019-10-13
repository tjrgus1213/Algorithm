#include<iostream>

using namespace std;

int n;
char turn[1000][2];

int main()
{
	int test_case;
	cin >> test_case;
	for (int x = 0; x < test_case; x++) {
		char up[3][3];
		cin >> n;
		for (int i = 0; i < n; i++)
			cin >> turn[i][0] >> turn[i][1];

		// U, D, F, B, L, R
		int r, c;
		char f;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				r = i;	c = j;	f = 'U';
				for (int k = n - 1; k >= 0; k--) {
					switch (turn[k][0]) {
					case 'U':
						if (f == 'U') {
							int tr, tc;
							if (turn[k][1] == '-') {
								tr = c;
								tc = 2 - r;
							}
							else {
								tc = r;
								tr = 2 - c;
							}
							r = tr;	c = tc;
						}
						else if (f == 'D') {
							continue;
						}
						else {
							if ((r == 0 && f != 'B') || (f == 'B' && r == 2)) {
								if (turn[k][1] == '+') {
									switch (f) {
									case 'F':
										f = 'R';
										break;
									case 'R':
										f = 'B';
										r = 2 - r;
										c = 2 - c;
										break;
									case 'B':
										r = 2 - r;
										c = 2 - c;
										f = 'L';
										break;
									case 'L':
										f = 'F';
										break;
									}
								}
								else {
									switch (f) {
									case 'F':
										f = 'L';
										break;
									case 'R':
										f = 'F';
										break;
									case 'B':
										r = 2 - r;
										c = 2 - c;
										f = 'R';
										break;
									case 'L':
										r = 2 - r;
										c = 2 - c;
										f = 'B';
										break;
									}
								}
							}
							else
								continue;
						}
						break;

					case 'D':
						if (f == 'D') {
							int tr, tc;
							if (turn[k][1] == '-') {
								tr = c;
								tc = 2 - r;
							}
							else {
								tc = r;
								tr = 2 - c;
							}
							r = tr;	c = tc;
						}
						else if (f == 'U') {
							continue;
						}
						else {
							if ((r == 2 && f != 'B') || (f == 'B' && r == 0)) {
								if (turn[k][1] == '-') {
									switch (f) {
									case 'F':
										f = 'R';
										break;
									case 'R':
										f = 'B';
										r = 2 - r;
										c = 2 - c;
										break;
									case 'B':
										f = 'L';
										r = 2 - r;
										c = 2 - c;
										break;
									case 'L':
										f = 'F';
										break;
									}
								}
								else {
									switch (f) {
									case 'F':
										f = 'L';
										break;
									case 'R':
										f = 'F';
										break;
									case 'B':
										f = 'R';
										r = 2 - r;
										c = 2 - c;
										break;
									case 'L':
										f = 'B';
										r = 2 - r;
										c = 2 - c;
										break;
									}
								}
							}
							else
								continue;
						}
						break;

					case 'F':
						if (f == 'F') {
							int tr, tc;
							if (turn[k][1] == '-') {
								tr = c;
								tc = 2 - r;
							}
							else {
								tc = r;
								tr = 2 - c;
							}
							r = tr;	c = tc;
						}
						else if (f == 'B') {
							continue;
						}
						else {
							if (f == 'U' && r == 2) {
								if (turn[k][1] == '-') {
									f = 'R';
									r = c;
									c = 0;
								}
								else {
									f = 'L';
									r = 2 - c;
									c = 2;
								}
							}
							else if (f == 'R' && c == 0) {
								if (turn[k][1] == '-') {
									f = 'D';
									c = 2 - r;
									r = 0;
								}
								else {
									f = 'U';
									c = r;
									r = 2;
								}
							}
							else if (f == 'L' && c == 2) {
								if (turn[k][1] == '-') {
									f = 'U';
									c = 2 - r;
									r = 2;
								}
								else {
									f = 'D';
									c = r;
									r = 0;
								}

							}
							else if (f == 'D' && r == 0) {
								if (turn[k][1] == '-') {
									f = 'L';
									r = c;
									c = 2;
								}
								else {
									f = 'R';
									r = 2 - c;
									c = 0;
								}

							}
						}
						break;

					case 'B':
						if (f == 'B') {
							int tr, tc;
							if (turn[k][1] == '-') {
								tr = c;
								tc = 2 - r;
							}
							else {
								tc = r;
								tr = 2 - c;
							}
							r = tr;	c = tc;
						}
						else if (f == 'F') {
							continue;
						}
						else {
							if (f == 'U' && r == 0) {
								if (turn[k][1] == '-') {
									f = 'L';
									r = 2 - c;
									c = 0;
								}
								else {
									f = 'R';
									r = c;
									c = 2;
								}
							}
							else if (f == 'L' && c == 0) {
								if (turn[k][1] == '-') {
									f = 'D';
									c = r;
									r = 2;
								}
								else {
									f = 'U';
									c = 2 - r;
									r = 0;
								}

							}
							else if (f == 'D' && r == 2) {
								if (turn[k][1] == '-') {
									f = 'R';
									r = 2 - c;
									c = 2;
								}
								else {
									f = 'L';
									r = c;
									c = 0;
								}

							}
							else if (f == 'R' && c == 2) {
								if (turn[k][1] == '-') {
									f = 'U';
									c = r;
									r = 0;
								}
								else {
									f = 'D';
									c = 2 - r;
									r = 2;
								}

							}
						}
						break;

					case 'L':
						if (f == 'L') {
							int tr, tc;
							if (turn[k][1] == '-') {
								tr = c;
								tc = 2 - r;
							}
							else {
								tc = r;
								tr = 2 - c;
							}
							r = tr;	c = tc;
						}
						else if (f == 'R') {
							continue;
						}
						else {
							if (c == 0) {
								if (turn[k][1] == '-') {
									switch (f) {
									case 'U':
										f = 'F';
										break;
									case 'F':
										f = 'D';
										break;
									case 'D':
										f = 'B';
										break;
									case 'B':
										f = 'U';
										break;
									}
								}
								else {
									switch (f) {
									case 'U':
										f = 'B';
										break;
									case 'F':
										f = 'U';
										break;
									case 'D':
										f = 'F';
										break;
									case 'B':
										f = 'D';
										break;
									}
								}
							}
						}
						break;

					case 'R':
						if (f == 'R') {
							int tr, tc;
							if (turn[k][1] == '-') {
								tr = c;
								tc = 2 - r;
							}
							else {
								tc = r;
								tr = 2 - c;
							}
							r = tr;	c = tc;
						}
						else if (f == 'L') {
							continue;
						}
						else {
							if (c == 2) {
								if (turn[k][1] == '+') {
									switch (f) {
									case 'U':
										f = 'F';
										break;
									case 'F':
										f = 'D';
										break;
									case 'D':
										f = 'B';
										break;
									case 'B':
										f = 'U';
										break;
									}
								}
								else {
									switch (f) {
									case 'U':
										f = 'B';
										break;
									case 'F':
										f = 'U';
										break;
									case 'D':
										f = 'F';
										break;
									case 'B':
										f = 'D';
										break;
									}
								}
							}
						}
						break;
					}
				}
				switch (f) {
				case 'U':
					up[i][j] = 'w';
					break;
				case 'D':
					up[i][j] = 'y';
					break;
				case 'F':
					up[i][j] = 'r';
					break;
				case 'B':
					up[i][j] = 'o';
					break;
				case 'L':
					up[i][j] = 'g';
					break;
				case 'R':
					up[i][j] = 'b';
					break;
				}
			}
		}

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++)
				cout << up[i][j];
			cout << endl;
		}
	}
	return 0;
}