#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;
int iNum;
vector<int> iSaveVec;
int iSavePast[1001];
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin >> iNum;

	for (int i = 0; i < iNum; i++) {
		int iTemp;
		cin >> iTemp;
		iSaveVec.push_back(iTemp);
	}


	int iCnt = 0;
	iSavePast[0] = 1;
	for (int i = 1; i < iNum; i++) {
		for (int j = i - 1; j >= 0; j--) {
			if (iSaveVec[i] > iSaveVec[j]) {
				iSavePast[i] = max(iSavePast[i], iSavePast[j] +1);
			}
		}
		iCnt = max(iCnt, iSavePast[i]);
	}
	cout << iCnt << endl;
	








	
	return 0;
}