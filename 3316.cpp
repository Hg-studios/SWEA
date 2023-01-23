#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
constexpr int MAX = 1e4;
using namespace std;

long long dp[MAX][16]; //A, B, C, D ����� �� 2^4 - 1 = 15

void solve() {
	string club; cin >> club;

	long long case_cnt = 0;
	memset(dp, 0, sizeof(dp));

	for (int day = 0; day < club.size(); day++) {
		int admin = 1 << (club[day] - 'A');

		for (int i = 0; i < 16; i++) {
			if (day == 0) { //1����
				//i��° ��쿡 �����ڿ� A�� ���ԵǸ�
				if ((i & admin) != 0 && (i & 1) != 0) {
					dp[day][i] = 1;
				}
			}
			else { //2����~
				//���������� ����� ���� 0�� �ƴϸ�
				if (dp[day - 1][i] != 0) {
					for (int j = 0; j < 16; j++) {
						//���� ���� ����� ���õ� ������ 
						//���� ���»���� �������� ���
						if ((i & j) != 0 && (j & admin) != 0) {
							dp[day][j] += dp[day - 1][i];
							dp[day][j]%= 1000000007;
						}
					}
				}
			}
		}
	}

	for (int i = 1; i < 16; i++) {
		case_cnt += dp[club.size() - 1][i];
		case_cnt %= 1000000007;
	}
	cout << case_cnt;
}

int main() {
	//freopen("input.txt", "r", stdin);
	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		cout << "#" << i << " ";
		solve();
		cout << '\n';
	}

	return 0;
}