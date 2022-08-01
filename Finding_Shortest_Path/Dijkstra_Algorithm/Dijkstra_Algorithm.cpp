//#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<queue>
#include<math.h>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include <queue>

#define endl "\n"
#define INF 987654321

using namespace std;


int N, iNumConnection, iStartNode;
vector<pair<int,int>> iStoreConnectionArray[20010];
int iParentInfoArray[20005];
int iResultSaveArray[20005];





void BFS(int iWantedNode) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qSaveCount;
	iResultSaveArray[iWantedNode] = 0;
	qSaveCount.push({ 0, iWantedNode});


	while (!qSaveCount.empty()) {

		int iCurrentNode = qSaveCount.top().second;
		int iCurrentWeight = qSaveCount.top().first;
		qSaveCount.pop();
		if (iResultSaveArray[iCurrentNode] < iCurrentWeight) {
			continue;
		}

		for (int i = 0; i < iStoreConnectionArray[iCurrentNode].size(); i++) {

			int iNextNode = iStoreConnectionArray[iCurrentNode][i].first;
			int iNextWeight = iStoreConnectionArray[iCurrentNode][i].second;

			if (iResultSaveArray[iNextNode] > iNextWeight + iCurrentWeight) {
				iResultSaveArray[iNextNode] = iNextWeight + iCurrentWeight;
				qSaveCount.push(make_pair(iResultSaveArray[iNextNode],iNextNode));
			}
		}

	}
}




int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> iNumConnection;
	cin >> iStartNode;

	for (int i = 1; i <= iNumConnection; i++) {
		int tempA, tempB, tempWeight;
		cin >> tempA >> tempB >> tempWeight;
		iStoreConnectionArray[tempA].push_back(make_pair(tempB, tempWeight));
	}
	for (int i = 1; i <= N; i++) {
		iResultSaveArray[i] = INF;
	}

	BFS(iStartNode);

	for (int i = 1; i <= N; i++) {
		if (iResultSaveArray[i] == INF) {
			cout << "INF" << endl;
		}
		else {
			cout << iResultSaveArray[i] << endl;
		}
	}
}

