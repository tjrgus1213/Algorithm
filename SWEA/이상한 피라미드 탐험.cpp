#include<iostream>
#include<algorithm>

using namespace std;

int flr[200];

int main() {
	ios::sync_with_stdio(false);
	int test_case = 1;
	int num = 1;
	while (num <= 20000) {
		flr[test_case++] = num;
		num += test_case;
	}

	cin >> test_case;

	for (int T = 1; T <= test_case; T++) {
		int pos, des, mv = 0;
		cin >> pos >> des;
		if (des < pos)
			swap(pos, des);

		int pflr = 1, dflr = 1;
		while (pos > flr[pflr])
			pflr++;
		while (des > flr[dflr])
			dflr++;
		mv += dflr - pflr;

		int pw, dw;
		pw = flr[pflr] - pos;
		dw = flr[dflr] - des;
		if (pw > dw)
			mv += pw - dw;
		else if (dw - pw > dflr - pflr)
			mv += dw - pw - dflr + pflr;
		cout << "#" << T << " ";
		cout << mv << endl;
	}
	return 0;
}