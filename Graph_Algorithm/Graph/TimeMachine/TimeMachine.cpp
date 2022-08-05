﻿#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include <queue>

#define MAX_SIZE 510+1
#define endl "\n"
#define INF 987654321


using namespace std;


vector<pair<int, int>> iStoreConnectionArray[MAX_SIZE];
vector<int> iPredictDesVector;
vector<int> iPredictDesWeightVector;

int iNodeNum, iConnectionNum, iStartPos;

int iResultSaveArray[MAX_SIZE];
int iNextNode;
int iNextWeight;
int iCurrentNode;

bool BellmanFord(int iWantedNode) {
	iResultSaveArray[iWantedNode] = 0;

	for (int loop = 0; loop <= iNodeNum; loop++) {
		for (int i = 1; i <= iNodeNum; i++) {
			for (int j = 0; j < iStoreConnectionArray[i].size(); j++) {
				iCurrentNode = i;
				iNextNode = iStoreConnectionArray[iCurrentNode][j].first;
				iNextWeight = iStoreConnectionArray[iCurrentNode][j].second;

				if (iResultSaveArray[iCurrentNode] == INF)continue;

				if (iResultSaveArray[iNextNode] > iNextWeight + iResultSaveArray[iCurrentNode]) {
					iResultSaveArray[iNextNode] = iNextWeight + iResultSaveArray[iCurrentNode];

					if (loop == iNodeNum) {
						return true;
					}
				}

			}

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


	for (int j = 1; j <= iConnectionNum; j++) {

		int tempA, tempB, tempWeight;
		cin >> tempA >> tempB >> tempWeight;
		iStoreConnectionArray[tempA].push_back(make_pair(tempB, tempWeight));
		//iStoreConnectionArray[tempB].push_back(make_pair(tempA, tempWeight));
	}


	iStartPos = 1;
	Reset();
	bool bNegLoop = BellmanFord(iStartPos);


	if (bNegLoop) {
		cout << -1 << endl;
	}
	else {
		for (int i = 2; i <= iNodeNum; i++) {

			if (iResultSaveArray[i] != INF) {
				cout << iResultSaveArray[i] << endl;
			}
			else {
				cout << -1 << endl;
			}
		}

	}
	
	return 0;

}