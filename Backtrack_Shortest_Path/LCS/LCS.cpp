
﻿#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include <string.h>
#include <queue>
using namespace std;
int iFirst;
int iSecond;
int iVisited[100001];
bool valid(int iPos) {
	if (iPos < 0 || iPos > 100000 || iVisited[iPos] > 0)
		return false;
	return true;
}
int Solve(queue<pair<int, int>> qOperation) {
	
	while (!qOperation.empty()) {

		int iValue = qOperation.front().first;
		int iStep = qOperation.front().second;
		qOperation.pop();


		if (iValue == iSecond) {

			cout << iStep << endl;
			return 0;
		}

		if (valid(iValue + 1)) {
			iVisited[iValue + 1] = iValue;
			qOperation.push(make_pair(iValue+1, iStep + 1));

		}

		if (valid(iValue -1)) {
			iVisited[iValue - 1] = iValue;
			qOperation.push(make_pair(iValue -1, iStep + 1));
		}

		if (valid(iValue * 2)) {
			iVisited[iValue * 2] = iValue;
			qOperation.push(make_pair(iValue * 2, iStep + 1));
		}

	}
	return 0;
}



=======
#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>


using namespace std;
int iNum;
string sFirst;
string sSecond;
int iSaveList[1001][1001];
string sStore = "";

void Solve() {

	

	for (int i = 1; i <= sFirst.size(); i++) {
		for (int j = 1; j <= sSecond.size(); j++) {

			if (sFirst[i-1] == sSecond[j-1]) {
				iSaveList[i][j] = iSaveList[i - 1][j - 1] + 1;
				
			}
			else {
				iSaveList[i][j] = max(iSaveList[i][j - 1], iSaveList[i-1][j]);
			}

		}
	}


}

>>>>>>> 2edfe8a066be460775d5cffb5bc8a5509d5289dd
int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
<<<<<<< HEAD

	cin >> iFirst >> iSecond;

	queue<pair<int, int>> qOperation;
	qOperation.push(make_pair(iFirst, 0));

	Solve(qOperation);
	vector<int> iPrint;
	iVisited[iFirst] = -1;

	int iPos = iSecond;
	while (iPos > 0) {
		//cout << iVisited[iPos] << endl;
		if (iVisited[iPos] == -1) break;
		if (iVisited[iPos] == iSecond || iVisited[iPos] == iFirst)break;
		iPrint.push_back(iVisited[iPos]);
		iPos = iVisited[iPos];
	}
	cout << iFirst << " ";
	for (int i = iPrint.size() - 1; i >= 0; i--) {
		cout << iPrint[i] << " ";
	}
	cout << iSecond;
	
	return 0;
}
=======
	cin >> sFirst;
	cin >> sSecond;
	Solve();
	cout << iSaveList[sFirst.size()][sSecond.size()] << endl;
	//for (int i = 0; i < iStorePos.size(); i++) {
	//	cout << sFirst[iStorePos[i]] << " ";
	//}
	int iPos = sFirst.size();
	int jPos = sSecond.size();
	while (iSaveList[iPos][jPos] > 0) {

		
		if (iSaveList[iPos][jPos] == iSaveList[iPos][jPos - 1] ) {
			jPos--;
		}
		else if (iSaveList[iPos][jPos] == iSaveList[iPos - 1][jPos]) {
			iPos--;
		}
		else if (iSaveList[iPos][jPos] == iSaveList[iPos-1][jPos - 1] + 1) {
			//cout << sFirst[iPos - 1];
			sStore += sFirst[iPos - 1];
			iPos--;
			jPos--;
			
		}

		if (iPos == 0 || jPos == 0) break;


	}

	for (int i = sStore.size() - 1; i >= 0; i--) {
		cout << sStore[i];
	}




	return 0;
}

