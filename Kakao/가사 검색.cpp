#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

class trie {

public:
	trie() {
		finish = false;
		for (int i = 0; i < 26; i++)
			next[i] = NULL;
	}

	~trie() {
		for (int i = 0; i < 26; i++)
			if (next[i])
				delete next[i];
	}

	void insert(const char* s, int len) {
		if (*s == '\0') {
			finish = true;
			return;
		}

		int c = *s - 'a';
		if (next[c] == NULL) {
			next[c] = new trie();
		}
		numOfchild[len]++;
		next[c]->insert(s + 1, len - 1);
	}

	trie* find(const char* s) {
		if (*s == '\0')
			return this;
		int c = *s - 'a';
		if (next[c] == NULL)
			return NULL;
		return next[c]->find(s + 1);
	}

	int getchildNum(int depth) {
		if (this == NULL)
			return 0;
		/*if (depth == 0 && finish)
		return 1;

		int sum = 0;
		for (int i = 0; i < 26; i++) {
		if (next[i] == NULL)
		continue;

		if (depth != 0)
		sum += next[i]->getchildNum(depth - 1);
		}
		return sum;*/
		return numOfchild[depth];
	}

	bool getfinish() {
		return finish;
	}

private:
	trie* next[26];
	bool finish;
	map<int, int> numOfchild;
};

vector<int> solution(vector<string> words, vector<string> queries) {
	vector<int> answer;
	trie t, rt;
	string tempstr;
	for (int i = 0; i < words.size(); i++) {
		tempstr = words[i];
		t.insert(tempstr.c_str(), tempstr.size());
		std::reverse(tempstr.begin(), tempstr.end());
		rt.insert(tempstr.c_str(), tempstr.size());
	}

	string query;
	for (int i = 0; i < queries.size(); i++) {
		query = "";
		if (queries[i][0] == '?') {
			for (int j = queries[i].size() - 1; j >= 0 && queries[i][j] != '?'; j--)
				query += queries[i][j];
			answer.push_back(rt.find(query.c_str())->getchildNum(queries[i].size() - query.size()));
		}
		else {
			for (int j = 0; j < queries[i].size() && queries[i][j] != '?'; j++)
				query += queries[i][j];
			answer.push_back(t.find(query.c_str())->getchildNum(queries[i].size() - query.size()));
		}
	}
	return answer;
}