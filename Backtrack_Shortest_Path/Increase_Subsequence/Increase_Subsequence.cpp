#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
int iNum;
int iSaveVec[1001];
int iSavePast[1001];
int iSavePrev[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> iNum;

	for (int i = 1; i < iNum; i++) {
		int iTemp;
		cin >> iTemp;
		iSaveVec[i] = iTemp;
	}


	int iCnt = 0;
	iSavePast[0] = 1;
	for (int i = 1; i <= iNum; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (iSaveVec[i] > iSaveVec[j]) {
				iSavePast[i] = max(iSavePast[i], iSavePast[j] +1);
			}
			if (iSavePast[j] +1 < iSavePast[i]) {
				iSavePrev[i] = iSaveVec[i];
			}
		}

		iCnt = max(iCnt, iSavePast[i]);
	}
	cout << iCnt << endl;
	
	for (int i = 0; i < iNum; i++) {
		if (iSavePrev[i] != 0) {
			cout << iSavePrev[i] << " ";
		}
	}


	
	return 0;
}