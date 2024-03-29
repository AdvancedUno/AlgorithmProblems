﻿#include<iostream>
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

int iResultSaveArray[MAX_SIZE];


bool BellmanFord(int iWantedNode) {
	iResultSaveArray[1] = 0;
	for (int loop = 1; loop <= iNodeNum; loop++) {
		for (int i = 1; i <= iNodeNum; i++) {
			for (int j = 0; j < iStoreConnectionArray[i].size(); j++) {
				int iCurrentNode = i;
				int iNextNode = iStoreConnectionArray[iCurrentNode][j].first;
				int iNextWeight = iStoreConnectionArray[iCurrentNode][j].second;

				if (iResultSaveArray[iCurrentNode] == INF)continue;

				if (iResultSaveArray[iNextNode] > iNextWeight + iResultSaveArray[iCurrentNode]) {
					iResultSaveArray[iNextNode] = iNextWeight + iResultSaveArray[iCurrentNode];

					if (loop == iNodeNum) {
						cout << -1 << endl;
						return true;
					}
				}

			}

		}
	}

	for (int i = 2; i <= iNodeNum; i++) {

		if (iResultSaveArray[i] != INF) {
			cout << iResultSaveArray[i] << endl;
		}
		else {
			cout << -1 << endl;
		}
	}

	return false;
}

void Reset() {
	for (int j = 1; j <= iNodeNum; j++) {
		iResultSaveArray[j] = INF;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> iNodeNum >> iConnectionNum;


	for (int j = 0; j < iConnectionNum; j++) {

		int tempA, tempB, tempWeight;
		cin >> tempA >> tempB >> tempWeight;
		iStoreConnectionArray[tempA].push_back(make_pair(tempB, tempWeight));
	}


	iStartPos = 1;
	Reset();
	bool bNegLoop = BellmanFord(iStartPos);


	
	return 0;

}