#include <iostream>
using namespace std;

int main()
{
	int T, H, W, N;
	int floor; // �� ��
	int num; // ���������Ϳ������� ������ ���� ��ȣ
	int ans; // ��(�� ��ȣ)
	cin >> T;
	for (int t = 0; t < T; t++) {
		cin >> H >> W >> N;
		num = N / H + 1; 
		floor = N % H ;
		if (floor == 0) // H�� ��������� �� H���� ��ġ
		{
			floor = H;
			num--;
		}
		ans = floor * 100 + num; // YYXX�� ǥ��
		cout << ans << endl;
	}
	return 0;
}