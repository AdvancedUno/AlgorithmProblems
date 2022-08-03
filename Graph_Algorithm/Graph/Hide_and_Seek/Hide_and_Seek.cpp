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
int iNextNode ;
int iNextWeight ;

int Dijkstra(int iWantedNode, int iTargetNode) {
	queue<pair<int, int> > qSaveCount;
	iResultSaveArray[iWantedNode] = 0;
	qSaveCount.push({ 0, iWantedNode });


	while (!qSaveCount.empty()) {

		int iCurrentNode = qSaveCount.front().second;
		int iCurrentWeight = qSaveCount.front().first;
		qSaveCount.pop();


		if (iCurrentNode == iTargetNode) {
			return iCurrentWeight;
		}


		for (int i = 0; i < 3; i++) {

			if (i == 0) {
				iNextNode = iCurrentNode * 2;
				iNextWeight = iCurrentWeight;

				if (iNextNode < MAX_SIZE ) {
					iResultSaveArray[iNextNode] = iNextWeight;
					qSaveCount.push(make_pair(iResultSaveArray[iNextNode], iNextNode));
				}
			}

			if (i == 1) {
				iNextNode = iCurrentNode + 1;
				iNextWeight = iCurrentWeight + 1;

				if (iNextNode < MAX_SIZE && iResultSaveArray[iNextNode] > iNextWeight) {
					iResultSaveArray[iNextNode] = iNextWeight;
					qSaveCount.push(make_pair(iResultSaveArray[iNextNode], iNextNode));
				}
			}

			if (i == 2) {
				iNextNode = iCurrentNode - 1;
				iNextWeight = iCurrentWeight + 1;

				if (iNextNode > 0 && iResultSaveArray[iNextNode] > iNextWeight) {
					iResultSaveArray[iNextNode] = iNextWeight ;
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

	for (int i = 1; i <= max(N,K); i++) {
		iResultSaveArray[i] = INF;
	}



	cout << Dijkstra(N, K) << endl;

}
