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


int N, K, iStartNode;
vector<pair<int, int>> iStoreConnectionArray[20010];
int iVisitedInfoArray[20005];
int iResultSaveArray[20005];


void Dijkstra(int iWantedNode, int iTargetNode) {
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
		// d
		if (iCurrentNode == iTargetNode) {
			break;
		}


		for (int i = 0; i < 3; i++) {

			if (int k = 0) {
				int iNextNode = iStoreConnectionArray[iCurrentNode][i].first * 2;
				int iNextWeight = iStoreConnectionArray[iCurrentNode][i].second;

				if (iResultSaveArray[iNextNode] > iNextWeight + iCurrentWeight) {
					iResultSaveArray[iNextNode] = iNextWeight + iCurrentWeight;
					qSaveCount.push(make_pair(iResultSaveArray[iNextNode], iNextNode));
				}
			}

			if (int k = 1) {
				int iNextNode = iStoreConnectionArray[iCurrentNode][i].first + 1;
				int iNextWeight = iStoreConnectionArray[iCurrentNode][i].second;

				if (iResultSaveArray[iNextNode] > iNextWeight + iCurrentWeight) {
					iResultSaveArray[iNextNode] = iNextWeight + iCurrentWeight;
					qSaveCount.push(make_pair(iResultSaveArray[iNextNode], iNextNode));
				}
			}

			if (int k = 2) {
				int iNextNode = iStoreConnectionArray[iCurrentNode][i].first -1;
				int iNextWeight = iStoreConnectionArray[iCurrentNode][i].second;

				if (iResultSaveArray[iNextNode] > iNextWeight + iCurrentWeight) {
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

}
