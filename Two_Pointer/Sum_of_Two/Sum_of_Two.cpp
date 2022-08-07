#include <iostream>
#include <math.h>
#include <vector>
#include <stdio.h>
#include <algorithm>

using namespace std;

int iNumbers;
int iResltLeft;
int iResltRight;
long long iMinSum = 200000001;

vector<int> iStoreNumVector;


int GivePos(int iLeft, int iRight,  bool bCheck) {

	if (iLeft > iRight && bCheck) {
		return iLeft;
	}else if (iLeft > iRight && !bCheck) {
		return iRight;
	}

	int iMidPos = (iRight + iLeft) / 2;




	if (bCheck && abs(iStoreNumVector[iMidPos]) > abs(iStoreNumVector[iRight]) ) {
		return iMidPos;
	}
	else if (!bCheck && abs(iStoreNumVector[iMidPos]) < abs(iStoreNumVector[iRight])) {
		return iMidPos;
	}
	else if(bCheck){
		GivePos(iLeft, iMidPos, bCheck);
	}
	else if (!bCheck) {
		GivePos(iMidPos+1, iRight, bCheck);
	}


}

int Solve(int iLeft, int iRight) {

	while (iLeft < iRight) {

		int iSum = iStoreNumVector[iLeft] + iStoreNumVector[iRight];
		if (abs(iSum) < iMinSum) {
			iMinSum = iSum;
			iResltLeft = iStoreNumVector[iLeft];
			iResltRight = iStoreNumVector[iRight];
		}

		if(iSum <= 0){
			iLeft++;
		}
		else {
			iRight--;
		}


	}

	return 0;

}




int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> iNumbers;

	for (int i = 0; i < iNumbers; i++) {
		
		int iTempNum;
		cin >> iTempNum;
		iStoreNumVector.push_back(iTempNum);

	}


	sort(iStoreNumVector.begin(), iStoreNumVector.end());



	Solve(0, iStoreNumVector.size()-1);



	cout << iResltLeft << " " << iResltRight << endl;




}