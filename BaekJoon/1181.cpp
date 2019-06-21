#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(const string& s1, const string& s2) {
	
	if (s1.length() == s2.length())
		return s1 < s2;
	else
		return s1.length() < s2.length();
}

int main() {
	int N;
	string s;
	vector<string> arr;
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> s;
		arr.push_back(s);
	}
	sort(arr.begin(), arr.end(),cmp);

	cout << arr[0] << endl;
	for (int i = 1; i < N; i++) {
		if(arr[i]!=arr[i-1])
			cout << arr[i] << endl;
	}
	
	return 0;
}