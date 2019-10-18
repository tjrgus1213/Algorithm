#include<iostream>
#include<cstring>
#include<vector>

using namespace std;

int mem[100000];
char code[4096], input[4096];
int jump[4096];

int main()
{
	ios::sync_with_stdio(false);
	int T;
	cin >> T;
	for (int test_case = 0; test_case < T; test_case++) {
		int sm, sc, si;
		cin >> sm >> sc >> si;
		memset(mem, 0, sizeof(int) * sm);
		memset(jump, 0, sizeof(jump));
		memset(code, 0, sizeof(code));
		memset(input, 0, sizeof(input));

		vector<int> left;
		int cnt = -1;
		for (int i = 0; i < sc; i++) {
			cin >> code[i];
			if (code[i] == '[') {
				cnt++;
				if (left.size() <= cnt)
					left.push_back(i);
				else
					left[cnt] = i;
			}
			if (code[i] == ']' && cnt > -1) {
				jump[left[cnt]] = i;
				jump[i] = left[cnt];
				cnt--;
			}
		}
		for (int i = 0; i < si; i++)
			cin >> input[i];


		int ptr = 0, ind = 0, input_ind = 0, maxind = 0;
		cnt = 0;
		bool loop = false;
		while (ind < sc) {
			switch (code[ind]) {
			case '-':
				mem[ptr]--;
				if (mem[ptr] < 0)
					mem[ptr] = 255;
				ind++;
				break;

			case '+':
				mem[ptr]++;
				if (mem[ptr] > 255)
					mem[ptr] -= 256;
				ind++;
				break;

			case '<':
				ptr--;
				if (ptr < 0)
					ptr = sm - 1;
				ind++;
				break;

			case '>':
				ptr++;
				if (ptr == sm)
					ptr = 0;
				ind++;
				break;

			case '[':
				if (mem[ptr] == 0)
					ind = jump[ind];
				else
					ind++;
				break;

			case ']':
				if (mem[ptr] != 0)
					ind = jump[ind];
				else
					ind++;
				break;

			case '.':
				ind++;
				break;

			case ',':
				if (input_ind < si) {
					mem[ptr] = input[input_ind];
					input_ind++;
				}
				else
					mem[ptr] = 255;
				ind++;
				break;
			}
			if (maxind < ind)
				maxind = ind;
			cnt++;
			if (cnt >= 50000000) {
				loop = true;
				break;
			}
		}
		if (loop) 
			cout << "Loops " << jump[maxind] << " " << maxind << endl;
		else
			cout << "Terminates" << endl;
	}
	return 0;
}