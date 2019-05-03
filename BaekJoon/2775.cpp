#include <iostream>
using namespace std;

int apt[15][15]; // ����Ʈ �� ȣ�� �����ϴ� ������� �� 

int GetNumberOfPeople(int k, int n) {

	int res = 0;

	if (apt[k][n] != 0) // �̹� ���� ���� ���� ��
		return apt[k][n];

	for (int i = 1; i <= n; i++) { // �Ʒ���(k-1) 1~nȣ���� ������� �� �� 
		if (apt[k - 1][i] != 0) // �̹� ���� ���� ���� ��
			res += apt[k - 1][i];
		else {
			res+=GetNumberOfPeople(k - 1, i);
		}
	}
	apt[k][n] = res;

	return res;
}

int main() {

	int T, k, n;

	for (int i = 0; i < 15; i++) // 0���� iȣ���� i���� ���
		apt[0][i] = i;

	for (int i = 1; i < 15; i++)
		for (int j = 0; j < 15; j++)
			apt[i][j] = 0; // 0���� �ʱ�ȭ
	
	cin >> T;

	for (int t = 0; t < T; t++) {
		cin >> k >> n;
		cout<<GetNumberOfPeople(k, n)<<endl;
	}
	
	return 0;
}