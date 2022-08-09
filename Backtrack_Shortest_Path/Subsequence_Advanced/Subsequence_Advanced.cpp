#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
int iNum;
int iSaveVec[1000001];
vector<int> iSavePast;
int iSavePrev[1000001];
vector <int>::iterator iVecIter;
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
	int iMaxPos = 1;
	int iTrackLarge = 0;

	
	iSavePast.push_back(iSaveVec[1]);
	iSavePrev[1] = 0;
	

	for (int i = 2; i <= iNum; i++) {

		
		if (iSaveVec[i] > iSavePast.back()) {
			iSavePast.push_back(iSaveVec[i]);
			iSavePrev[i] = iMaxPos;
			iMaxPos = i;
			continue;
		}

		if (iSaveVec[i] < iSavePast.front()) {
			iSavePast[0] = iSaveVec[i];
			iSavePrev[i] = 0;
		}
		else if (iSaveVec[i] > iSavePast.front() && iSaveVec[i] < iSavePast.back()) {
			iVecIter = lower_bound(iSavePast.begin(), iSavePast.end(), iSaveVec[i]);
			(*iVecIter) = iSaveVec[i];
			iSavePrev[i] = iVecIter - iSavePast.begin() +1;
		}
		
	}
	std::cout << iSavePast.size() << endl;

	vector<int> iTemp;
	while (iMaxPos > 0) {
		//cout << iSaveVec[iMaxPos] << " ";
		iTemp.push_back(iSaveVec[iMaxPos]);
		iMaxPos = iSavePrev[iMaxPos];
	}

	for (int i = iTemp.size() - 1; i >= 0; i--) {
		cout << iTemp[i] << " ";
	}

	return 0;
}