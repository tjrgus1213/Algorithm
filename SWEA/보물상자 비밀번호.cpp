#include<iostream>
#include<set>
#include<string>
#include<algorithm>
#include<sstream>

using namespace std;

int main(int argc, char** argv)
{
	int test_case;
	int T;
	cin >> T;

	for (test_case = 1; test_case <= T; ++test_case) {
		set<int> m;
		int N, K, num;
		char str[28];
		cin >> N >> K;
		for (int i = 0; i < N; i++)
			cin >> str[i];
		num = N / 4;

		for (int i = 0; i < N; i++) {
			string temp = "";
			int conv;
			for (int j = 0; j < num; j++) {
				if (i + j >= N)
					temp += str[i + j - N];
				else
					temp += str[i + j];
			}
			stringstream ss(temp);
			ss >> std::hex >> conv;
			m.insert(conv);
		}
		set<int>::iterator it = m.end();
		while (K-- > 0)
			it--;

		cout << "#" << test_case << " ";
		cout << *it << endl;
	}
	return 0;
}