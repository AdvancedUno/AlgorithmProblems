#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

int N, K;


int iStoreDPArray[501][501];
int iStoreNumArray[501];
int iStoreSumArray[501];


int Merge(int iStart, int iEnd) {


	if (iStoreDPArray[iStart][iEnd] != 0x3f3f3f3f) {
		return iStoreDPArray[iStart][iEnd];
	}

	if (iStart == iEnd) {
		iStoreDPArray[iStart][iEnd] = 0;
		return iStoreDPArray[iStart][iEnd];
	}

	if (iEnd - iStart == 1) {
		iStoreDPArray[iStart][iEnd] = iStoreNumArray[iStart] + iStoreNumArray[iEnd];
		return iStoreDPArray[iStart][iEnd];
	}



	for (int iMidNum = 0; iMidNum < iEnd - iStart; iMidNum++) {
		int iLeftMin = Merge(iStart, iStart + iMidNum);
		int iRightMin = Merge(iStart + iMidNum + 1, iEnd);

		iStoreDPArray[iStart][iEnd] = min(iStoreDPArray[iStart][iEnd], iLeftMin + iRightMin );

	}


	return iStoreDPArray[iStart][iEnd] += iStoreSumArray[iEnd] - iStoreSumArray[iStart - 1];
}





int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;

	for (int i = 0; i < N; i++) {

		cin >> K;
		memset(iStoreDPArray, 0x3f, sizeof(iStoreDPArray));
		for (int k = 1; k <= K; k++) {
			cin >> iStoreNumArray[k];
			iStoreSumArray[k] = iStoreNumArray[k] + iStoreSumArray[k-1];
		}
		cout << Merge(1, K) << endl;
	}

	


	return 0;
}





