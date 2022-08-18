#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include <queue>

#define MAX_SIZE 500+1
#define endl "\n"
#define INF 987654321 


using namespace std;


vector<pair<int, int>> iStoreConnectionArray[MAX_SIZE];

int iNodeNum, iConnectionNum, iStartPos;

int iResultSaveArray[MAX_SIZE][MAX_SIZE];


bool BellmanFord(int iWantedNode) {
	
	for (int loop = 1; loop <= iNodeNum; loop++) {
		iResultSaveArray[loop][loop] = 0;
		for (int i = 1; i <= iNodeNum; i++) {
			for (int j = 1; j <= iNodeNum; j++) {
				if (i == loop || i == j)continue;
				int iCurrentNode = i;
				int iTo = j;

				if (iResultSaveArray[iCurrentNode][iTo] >  iResultSaveArray[iCurrentNode][loop] + iResultSaveArray[loop][iTo]) {
					iResultSaveArray[iCurrentNode][iTo] = iResultSaveArray[iCurrentNode][loop] + iResultSaveArray[loop][iTo];
				}

			}

		}
	}

	for (int i = 1; i <= iNodeNum; i++) {
		for (int j = 1; j <= iNodeNum; j++) {
			if (iResultSaveArray[i][j] != INF) {
				cout << iResultSaveArray[i][j] << " ";
			}
			else {
				cout << 0 << " ";
			}
		}

		cout << "\n";
	}


	return false;
}

void Reset() {
	for (int i = 1; i <= iNodeNum; i++) {
		for (int j = 1; j <= iNodeNum; j++) {
			iResultSaveArray[i][j] = INF;
		}
	}

}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> iNodeNum >> iConnectionNum;

	Reset();
	for (int j = 0; j < iConnectionNum; j++) {

		int tempA, tempB, tempWeight;
		cin >> tempA >> tempB >> tempWeight;

		if (iResultSaveArray[tempA][tempB] > tempWeight) {
			iResultSaveArray[tempA][tempB] = tempWeight;
		}

	}


	iStartPos = 1;
	
	BellmanFord(iStartPos);



	return 0;

}