#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
	int arr[4];
	cin >> arr[0] >> arr[1] >> arr[2] >> arr[3];
	sort(arr, arr + 4);
	cout << arr[0] * arr[2] << '\n'; //가장 작은 선분 x 두번째로 긴 선분
	
	return 0;
}