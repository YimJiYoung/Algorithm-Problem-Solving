#include <iostream>
using namespace std;

int main()
{
	int X; // �Է°�
	int idx; // �밢������ �� ��° �м�����
	int den; // �и�
	int num; // ����

		cin >> X;

		for (int i = 1; i <= X; i++)
		{
			if (X <= (i*(i + 1)) / 2) { // i��° �밢��
				idx = X - ((i - 1)*i) / 2;
				if (i % 2 == 0) { // ¦��
					den = i - idx + 1;
					num = idx;
				}
				else { // Ȧ��
					den = idx;
					num = i - idx + 1;
				}
				break;
			}
		}
		cout << num << '/' << den;
	return 0;
}