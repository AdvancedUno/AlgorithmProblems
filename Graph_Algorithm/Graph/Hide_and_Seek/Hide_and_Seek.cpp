#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include <queue>

#define MAX_SIZE 100000+1
#define endl "\n"
#define INF 987654321

using namespace std;


int N, K;
vector<pair<int, int>> iStoreConnectionArray[MAX_SIZE];
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
		//int iCurrentWeight = iResultSaveArray[iCurrentNode];
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

				if (iNextNode >= 0 && iResultSaveArray[iNextNode] > iNextWeight) {
					iResultSaveArray[iNextNode] = iNextWeight ;
					qSaveCount.push(make_pair(iResultSaveArray[iNextNode], iNextNode));
				}
			}
			
			
		}

	}
	return 0;
}




int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> N;
	cin >> K;
	int maxNum = max(N, K);

	for (int i = 0; i <= maxNum; i++) {
		iResultSaveArray[i] = INF;
	}

	//Dijkstra(N, K);

	cout << Dijkstra(N, K) << endl;

}
