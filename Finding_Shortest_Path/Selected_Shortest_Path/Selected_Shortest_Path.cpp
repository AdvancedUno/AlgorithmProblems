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
vector<pair<int, int>> iStoreConnectionArray[200100];
int iParentInfoArray[20005];
//int iResultSaveArray[20005];
int iFirstNode;
int iSecondNode;

int iFirstPath;
int iSecondPath;
int iThirdPath;
int iResultSaveArrayFirst[20005];
int iResultSaveArraySecond[20005];
int iResultSaveArrayThird[20005];


void BFS(int iWantedNode, int iResultSaveArray[]) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qSaveCount;
	iResultSaveArray[iWantedNode] = 0;
	qSaveCount.push({ 0, iWantedNode });


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
				qSaveCount.push(make_pair(iResultSaveArray[iNextNode], iNextNode));
			}
		}

	}

	//return iResultSaveArray;


}




int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);


	cin >> N;
	cin >> iNumConnection;


	for (int i = 1; i <= iNumConnection; i++) {
		int tempA, tempB, tempWeight;
		cin >> tempA >> tempB >> tempWeight;
		iStoreConnectionArray[tempA].push_back(make_pair(tempB, tempWeight));
		iStoreConnectionArray[tempB].push_back(make_pair(tempA, tempWeight));
	}

	cin >> iFirstNode >> iSecondNode;




	for (int i = 1; i <= N; i++) {
		iResultSaveArrayFirst[i] = INF;
		iResultSaveArraySecond[i] = INF;
		iResultSaveArrayThird[i] = INF;

	}

	BFS(1, iResultSaveArrayFirst);
	BFS(iFirstNode, iResultSaveArraySecond);
	BFS(iSecondNode, iResultSaveArrayThird);


	if (iResultSaveArrayFirst[iFirstNode] == INF || iResultSaveArraySecond[iSecondNode] == INF || iResultSaveArrayThird[N] == INF ||
		iResultSaveArrayFirst[iSecondNode] == INF || iResultSaveArraySecond[iSecondNode] == INF ||
		iResultSaveArraySecond[N] == INF) {
		cout << -1 << endl;
	}
	else {
		int iAnsFirst = iResultSaveArrayFirst[iFirstNode] + iResultSaveArraySecond[iSecondNode] + iResultSaveArrayThird[N];
		int iAnsSecond = iResultSaveArrayFirst[iSecondNode] + iResultSaveArraySecond[iSecondNode] + iResultSaveArraySecond[N];


		int iAns = min(iAnsFirst, iAnsSecond);


		cout << iAns << endl;
	}

	
	
}