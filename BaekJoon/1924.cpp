#include <iostream>
using namespace std;

int main()
{
	int x, y; // x�� y��
	int days=0; // x�� y�� ~ 1�� 1�� ������ �ϼ�
	int day; // ����
	
	cin >> x >> y;

		for (int m = 1; m < x; m++) { 
			if (m == 4 || m == 6 || m == 9 || m == 11) //4,6,9,11��->30��
				days += 30;
			else if (m == 2)//2��->28��
				days += 28;
			else
				days += 31;
		}

	days += y - 1; 
	day = days % 7;
	
	switch (day)
	{
	case 0:
		cout << "MON";
		break;
	case 1:
		cout << "TUE";
		break;
	case 2:
		cout << "WED";
		break;
	case 3:
		cout << "THU";
		break;
	case 4:
		cout << "FRI";
		break;
	case 5:
		cout << "SAT";
		break;
	case 6:
		cout << "SUN";
		break;
	}
	return 0;
}