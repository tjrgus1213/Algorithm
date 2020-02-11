#include <string>
#include <vector>

using namespace std;

int N, cnt = 0;

void func(int open, int close) {
	if (open == N && close == N) {
		cnt++;
		return;
	}

	if (open < N)
		func(open + 1, close);
	if (close < open)
		func(open, close + 1);
}

int solution(int n) {
	N = n;
	func(0, 0);
	return cnt;
}