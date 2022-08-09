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
	std::cout.tie(0);
	cin >> iNum;

	for (int i = 1; i <= iNum; i++) {
		int iTemp;
		cin >> iTemp;
		iSaveVec[i] = iTemp;
	}


	int iCnt = 0;
	int iMaxPos = 0;
	int iTrackLarge = 0;


	for (int i = 0; i <= iNum; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (iSaveVec[i] > iSaveVec[j]) {
				if (iSavePast[i] < iSavePast[j] + 1) {
					iSavePrev[i] = j;
				}
				iSavePast[i] = max(iSavePast[i], iSavePast[j] + 1);
			}

		}
		if (iSavePast[i] > iCnt) {
			iMaxPos = i;
		}
		iCnt = max(iCnt, iSavePast[i]);
	}
	std::cout << iCnt << endl;

	vector<int> iTemp;
	while (iMaxPos > 0) {
		//cout << iSaveVec[iMaxPos] << " ";
		iTemp.push_back(iSaveVec[iMaxPos]);
		iMaxPos = iSavePrev[iMaxPos];
	}

	for(int i = iTemp.size() - 1; i >= 0; i--) {
		cout << iTemp[i] << " ";
	}

	return 0;
}