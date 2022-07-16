#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;
int vecStoreAll[1000000];
int iWantedNum;
bool bAnswer[1000000] = { 0, };
int iNumCasesCnt;
int iWantedNumCnt;


bool Search_B(int iWantedNumber, int startIdx, int endIdx) {
	int midIdx = 0;
	if (endIdx < startIdx) {
		return 0;
	}

	midIdx = (endIdx + startIdx) / 2;
	if (vecStoreAll[midIdx] == iWantedNumber) {
		return 1;
	}

	if (vecStoreAll[midIdx] > iWantedNumber) {
		if (Search_B(iWantedNumber, startIdx, midIdx - 1)) {
			return 1;
		}
	}
	else {
		if (Search_B(iWantedNumber, midIdx + 1, endIdx)) {
			return 1;
		}
	}
	return 0;
}


int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> iNumCasesCnt;

	for (int i = 0; i < iNumCasesCnt; i++) {
		cin >> vecStoreAll[i];
	}

	sort(vecStoreAll, vecStoreAll + iNumCasesCnt);

	cin >> iWantedNumCnt;

	for (int i = 0; i < iWantedNumCnt; i++) {
		cin >> iWantedNum;
		cout << Search_B(iWantedNum, 0, iNumCasesCnt - 1) << "\n";
	}
}
