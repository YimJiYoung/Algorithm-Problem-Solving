#include <iostream>
using namespace std;

int main()
{
	int X; // 입력값
	int idx; // 대각선에서 몇 번째 분수인지
	int den; // 분모
	int num; // 분자

		cin >> X;

		for (int i = 1; i <= X; i++)
		{
			if (X <= (i*(i + 1)) / 2) { // i번째 대각선
				idx = X - ((i - 1)*i) / 2;
				if (i % 2 == 0) { // 짝수
					den = i - idx + 1;
					num = idx;
				}
				else { // 홀수
					den = idx;
					num = i - idx + 1;
				}
				break;
			}
		}
		cout << num << '/' << den;
	return 0;
}