#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>


using namespace std;
int iNum;
string sFirst;
string sSecond;
int iSaveList[1001][1001];

void Solve() {

	

	for (int i = 1; i <= sFirst.size(); i++) {
		for (int j = 1; j <= sSecond.size(); j++) {

			if (sFirst[i-1] == sSecond[j-1]) {
				iSaveList[i][j] = iSaveList[i - 1][j - 1] + 1;
			}
			else {
				iSaveList[i][j] = max(iSaveList[i][j - 1], iSaveList[i-1][j]);
			}


		}
	}


}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
	cin >> sFirst;
	cin >> sSecond;
	Solve();
	cout << iSaveList[sFirst.size()][sSecond.size()] << endl;




	return 0;
}
