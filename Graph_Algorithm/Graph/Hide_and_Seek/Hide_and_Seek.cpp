#include<iostream>
#include<queue>
#include<math.h>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include <queue>
#define MAX_SIZE 100000+1
#define endl "\n"
#define INF 987654321

using namespace std;


int N, K, iStartNode;
vector<pair<int, int>> iStoreConnectionArray[MAX_SIZE];
int iVisitedInfoArray[MAX_SIZE];
int iResultSaveArray[MAX_SIZE];


int Dijkstra(int iWantedNode, int iTargetNode) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qSaveCount;
	iResultSaveArray[iWantedNode] = 0;
	qSaveCount.push({ 0, iWantedNode });


	while (!qSaveCount.empty()) {

		int iCurrentNode = qSaveCount.top().second;
		int iCurrentWeight = qSaveCount.top().first;
		qSaveCount.pop();
		//if (iResultSaveArray[iCurrentNode] < iCurrentWeight) {
		//	continue;
		//}

		if (iCurrentNode == iTargetNode) {
			return iCurrentWeight;
		}


		for (int i = 0; i < 3; i++) {

			if (i == 0) {
				int iNextNode = iCurrentNode * 2;
				int iNextWeight = iCurrentWeight;

				if (iNextNode < MAX_SIZE ) {
					iResultSaveArray[iNextNode] = iNextWeight;
					qSaveCount.push(make_pair(iResultSaveArray[iNextNode], iNextNode));
				}
			}

			if (i == 1) {
				int iNextNode = iCurrentNode + 1;
				int iNextWeight = iCurrentWeight + 1;

				if (iNextNode < MAX_SIZE ) {
					iResultSaveArray[iNextNode] = iNextWeight;
					qSaveCount.push(make_pair(iResultSaveArray[iNextNode], iNextNode));
				}
			}

			if (i == 2) {
				int iNextNode = iCurrentNode - 1;
				int iNextWeight = iCurrentWeight + 1;

				if (iNextNode > 0 ) {
					iResultSaveArray[iNextNode] = iNextWeight + iCurrentWeight;
					qSaveCount.push(make_pair(iResultSaveArray[iNextNode], iNextNode));
				}
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
	cin >> K;

	for (int i = 1; i <= N; i++) {
		iResultSaveArray[i] = INF;
	}

	Dijkstra(N, K);

	cout << iResultSaveArray[K-1] << endl;

}
