#include <iostream>
using namespace std;

int main()
{
	long T, x, y;
	long len; // ������������ �Ÿ�
	long k; // ���� �̵� �Ÿ�
	long cnt; // �̵� Ƚ��
	long tmp; // �̵� ���� �Ÿ�
	cin >> T;
	for (int t = 0; t < T; t++) {
		cnt = 0;
		cin >> x >> y;
		len = y - x;

		if (len <=2)
			cnt = len;
		else {
			len--; // �� ó�� 1��ŭ �̵�
			k = 1;
			cnt++;

			while (len > 1) {
				for (int i = 1; i >= -1; i--) { // k+1, K, K-1 ��ŭ �̵� ����
					tmp = k + i;
					if (len >= (tmp*(tmp + 1)) / 2) // tmp ��ŭ �̵��Ϸ��� �ּ� 1+2+..+tmp ��ŭ�� �Ÿ��� �����־�� ��
					{
						k = tmp;
						len -= tmp;
						cnt++;
						break;
					}
				}
			}
			cnt++;
		}
		cout << cnt<<endl;
	}

	return 0;
}