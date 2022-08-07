#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int iNumbers, iTargetNum; \
int iCntNum = 0;

vector<int> iStoreNumVector;

int Solve(int iLeft, int iRight) {

	while (iLeft < iRight) {

		if (iStoreNumVector[iLeft] + iStoreNumVector[iRight] == iTargetNum) {
			iCntNum++;
			iLeft++;
		}
		else if (iStoreNumVector[iLeft] + iStoreNumVector[iRight] > iTargetNum) {
			iRight--;
		}
		else if (iStoreNumVector[iLeft] + iStoreNumVector[iRight] < iTargetNum) {
			iLeft++;
		}

	}

	return 0;

}




int main() {

	cin >> iNumbers;

	for (int i = 0; i < iNumbers; i++) {

		int iTempNum;
		cin >> iTempNum;
		iStoreNumVector.push_back(iTempNum);

	}

	cin >> iTargetNum;

	sort(iStoreNumVector.begin(), iStoreNumVector.end());



	Solve(0, iStoreNumVector.size() - 1);



	cout << iCntNum << endl;



}