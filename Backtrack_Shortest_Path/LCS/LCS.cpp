#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>


using namespace std;
int iNum;
string sFirst;
string sSecond;
int iSaveList[1001][1001];
string sStore = "";

void LCS() {

	

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
	LCS();
	cout << iSaveList[sFirst.size()][sSecond.size()] << endl;
	//for (int i = 0; i < iStorePos.size(); i++) {
	//	cout << sFirst[iStorePos[i]] << " ";
	//}
	int iPos = sFirst.size();
	int jPos = sSecond.size();
	while (iSaveList[iPos][jPos] > 0) {

		
		if (iSaveList[iPos][jPos] == iSaveList[iPos][jPos - 1] ) {
			jPos--;
		}
		else if (iSaveList[iPos][jPos] == iSaveList[iPos - 1][jPos]) {
			iPos--;
		}
		else if (iSaveList[iPos][jPos] == iSaveList[iPos-1][jPos - 1] + 1) {
			//cout << sFirst[iPos - 1];
			sStore += sFirst[iPos - 1];
			iPos--;
			jPos--;
			
		}

		if (iPos == 0 || jPos == 0) break;


	}

	for (int i = sStore.size() - 1; i >= 0; i--) {
		cout << sStore[i];
	}




	return 0;
}
