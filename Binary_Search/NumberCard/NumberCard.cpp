#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;
long long vecStoreAll[500001];
int iWantedNum;
bool bAnswer[1000000] = { 0, };
int iNumCasesCnt;
int iWantedNumCnt;
int cntNum = 0;


int Search_B(int iWantedNumber, int startIdx, int endIdx) {

	
	int midIdx = 0;
	if (endIdx < startIdx) {
		return 0;
	}

	midIdx = (endIdx + startIdx) / 2;
	if (vecStoreAll[midIdx] == iWantedNumber) {
		int tempMidDown = midIdx-1;
		int tempMidTop = midIdx+1;
		cntNum++;
		//cout << vecStoreAll[tempMidDown] << endl;
		while (true) {
			
			if (vecStoreAll[tempMidDown] == iWantedNumber) {

				cntNum++;
				tempMidDown--;
				

			}
			else {
				break;
			}

		}
		while (true) {

			if (vecStoreAll[tempMidTop] == iWantedNumber) {

				cntNum++;
				tempMidTop++;

			}
			else {
				break;
			}

		}


		return cntNum;
	}

	if (vecStoreAll[midIdx] > iWantedNumber) {
		if (Search_B(iWantedNumber, startIdx, midIdx - 1) > 0) {
			return cntNum;
		}
	}
	else {
		if (Search_B(iWantedNumber, midIdx + 1, endIdx) > 0) {
			return cntNum;
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
		printf("%d ", Search_B(iWantedNum, 0, iNumCasesCnt - 1));
		cntNum = 0;
	}
}
