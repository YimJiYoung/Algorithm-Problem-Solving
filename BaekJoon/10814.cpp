#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#define MAX_SIZE 100000
using namespace std;


struct Member {
	int age;
	string name;
};

Member sorted_members[MAX_SIZE];
Member members[MAX_SIZE];

void merge(int start, int end) {
	int mid = (start + end) / 2;
	int i = start; 
	int j = mid + 1;
	int k = start; 
	int l;

	while (i <= mid && j <= end) {
		if (members[i].age <= members[j].age)
			sorted_members[k++] = members[i++];
		else 
			sorted_members[k++] = members[j++];

	}
	if (i > mid) {
		for (l=j; l <= end; l++) {
			sorted_members[k++] = members[l];
		}
	}
	else {
		for (l=i; l <= mid; l++) {
			sorted_members[k++] = members[l];
		}
	}

	for (int idx = start; idx <= end; idx++) members[idx] = sorted_members[idx];
}

void merge_sort(int start, int end) {
	int mid= (start + end) / 2;
	if (start < end) {
		merge_sort( start, mid);
		merge_sort( mid + 1, end);
		merge(start, end);
	}
}

/* 
bool cmp(const Member &m1, const Member &m2) {  
	return (m1.age < m2.age);
}*/

int main() {
	int N;
	cin >> N;
	
	for (int n = 0; n < N; n++) {
		cin >> members[n].age >> members[n].name;
	}
	//stable_sort(members, members+N, cmp);
	
	merge_sort(0, N - 1);

	for (int n = 0; n < N; n++) {
		cout << members[n].age << " " << members[n].name << '\n';
	}

	return 0;
}