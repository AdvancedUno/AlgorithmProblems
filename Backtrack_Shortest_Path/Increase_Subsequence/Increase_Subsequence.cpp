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

	for (int i = 0; i < iNum; i++) {
		int iTemp;
		cin >> iTemp;
		iSaveVec[i] = iTemp;
	}
	std::fill_n(iSavePast, 1001, 1);

	int iCnt = 1;

	for (int i = 0; i < iNum; i++) {
		for (int j = 0; j < i; j++) {
			if (iSaveVec[i] > iSaveVec[j]) {
				iSavePast[i] = max(iSavePast[i], iSavePast[j] +1);
			}
			if (iSavePast[i] == iSavePast[j]) {
				iSavePrev[i] = min(iSaveVec[i], iSaveVec[j]);
			}


		}
		if (iSavePast[i] > iCnt) {
			iSavePrev[i] = iSaveVec[i];
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