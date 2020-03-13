#include <iostream>
#include <string>
#include <vector>
#include <string.h>

#define UNCHECK -1
#define INVALID -2
#define ZEROCASE -3

using namespace std;

string sentence;
int word_st[1001];
int alpha_st[26];

bool isUpperCase(char c) {
	return (c >= 'A' && c <= 'Z');
}
bool isLowerCase(char c) {
	return (c >= 'a' && c <= 'z');
}
bool isAllUpper(int st, int end) {
	for (int i = st; i <= end; i++) {
		if (isLowerCase(sentence[i]))
			return false;
	}
	return true;
}
bool ismatchRule2(int st, int end) {
	bool flag = true;
	if (end - st < 2)
		return false;

	char c = sentence[st + 1];
	if (isUpperCase(c) || isLowerCase(sentence[end]))
		return false;
	if (alpha_st[c - 'a'] != st + 1)
		return false;

	for (int i = st; i <= end; i++) {
		if (flag) {
			if (isLowerCase(sentence[i]))
				return false;
			flag = false;
		}
		else {
			if (c != sentence[i])
				return false;
			flag = true;
		}
	}
	return true;
}
bool ismatchRule(int st, int end) {
	if (isLowerCase(sentence[st]) && sentence[st] == sentence[end]) {
		if (end - st < 2)
			return false;
		if (alpha_st[sentence[st] - 'a'] != st)
			return false;
		return isAllUpper(st + 1, end - 1) || ismatchRule2(st + 1, end - 1);
	}
	return isAllUpper(st, end) || ismatchRule2(st, end);
}
int getWordStPos(int pos) {
	if (pos == -1)
		return ZEROCASE;
	if (word_st[pos] != UNCHECK)
		return word_st[pos];
	word_st[pos] = INVALID;

	for (int i = 0; i <= pos; i++) {
		if (ismatchRule(i, pos) && getWordStPos(i - 1) != INVALID) {
			word_st[pos] = i;
			break;
		}
	}

	return word_st[pos];
}

string solution(string sent) {
	string answer = "";
	sentence = sent;
	memset(word_st, UNCHECK, sizeof(word_st));
	memset(alpha_st, -1, sizeof(alpha_st));
	for (int i = 0; i < sent.size(); i++) {
		if (sent[i] == ' ')
			return "invalid";
		if (isLowerCase(sent[i]) && alpha_st[sent[i] - 'a'] == -1)
			alpha_st[sent[i] - 'a'] = i;
	}
	if (getWordStPos(sentence.size() - 1) == INVALID)
		return "invalid";

	int lastind = 0;
	for (int i = 0; i < sentence.size(); i++) {
		if (word_st[i] < 0)
			continue;
		for (int j = word_st[i]; j <= i; j++) {
			if (isUpperCase(sentence[j]))
				answer += sentence[j];
		}
		if(i != sentence.size() - 1)
			answer += " ";
	}

	return answer;
}

int main() {
	cout << solution("AAAAxA") << endl;
	return 0;
}