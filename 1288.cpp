//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//using namespace std;
//
//void sheep(int n) {
//	int check = 0;
//	int kn = 0;
//
//	while (1) {
//		kn += n;
//		int tmp = kn;
//
//		while (tmp > 0) {
//			check |= 1 << (tmp % 10);
//			tmp /= 10;
//		}
//
//		if (check == (1 << 10) - 1) {
//			cout << kn;
//			break;
//		}
//	}
//}
//
//int main() {
//	freopen("input.txt", "r", stdin);
//	int tc; cin >> tc;
//	for (int i = 1; i <= tc; i++) {
//		int n; cin >> n; 
//		cout << "#" << i << " ";
//		sheep(n);
//		cout << '\n';
//	}
//
//	return 0;
//}

#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include <cstring>
using namespace std;

bool numCount[10] = { false, };

bool isAllCount()
{
    for (int i = 0; i < 10; i++) {
        if (numCount[i] == false) {
            return false;
        }
    }
    return true;
}
int main(int argc, char** argv)
{

    freopen("input.txt", "r", stdin);


    int test_case;
    int T;
    cin >> T;

    for (test_case = 1; test_case <= T; ++test_case)
    {
        int x;
        cin >> x;
        int n = 1;
     
        memset(numCount, 0, sizeof(numCount));

        while (1) {
            int xn = x * n;
            while (xn != 0) {
                numCount[xn % 10] = true;
                xn /= 10;
            }
            if (isAllCount() == true)
                break;
            else
                n++;
        }
        cout << "#" << test_case << " " << x * n << '\n';

    }
    return 0;//정상종료시 반드시 0을 리턴해야합니다.
}