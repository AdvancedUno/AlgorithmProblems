#include<iostream>
#include<queue>
#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<stack>
#include<algorithm>

using namespace std;

int N, iNumConnection, iStartNode;
vector<int> iStoreConnectionArray[10001];

queue<int> qStoreBFSOrder;

int bCheckVisitedArrayDFS[10001] = { 0, };
int bCheckVisitedArrayBFS[10001] = { 0, };

int iResultArrayDFS[10001] = { 0, };
int iResultArrayBFS[10001] = { 0, };

int iCntDFS = 0;
int iCntBFS = 0;



void DFS(int iWantedNode) {
	if (bCheckVisitedArrayDFS[iWantedNode] == 1) {
		return;
	}
	printf("%d\n", iWantedNode);
	bCheckVisitedArrayDFS[iWantedNode] = 1;
	iCntDFS++;
	iResultArrayDFS[iWantedNode] = iCntDFS;
	for (int i = 0; i < iStoreConnectionArray[iWantedNode].size(); i++) {
		DFS(iStoreConnectionArray[iWantedNode][i]);
	}
}


void BFS(int iWantedNode) {

	if (bCheckVisitedArrayBFS[iWantedNode] == 1) {
		return;
	}
	printf("%d\n", iWantedNode);
	bCheckVisitedArrayBFS[iWantedNode] = 1;
	iCntBFS++;
	iResultArrayBFS[iWantedNode] = iCntBFS;

	for (int i = 0; i < iStoreConnectionArray[iWantedNode].size(); i++) {
		qStoreBFSOrder.push(iStoreConnectionArray[iWantedNode][i]);
	}

	for (int i = 0; i < iStoreConnectionArray[iWantedNode].size(); i++) {
		int iTempBFSVal = qStoreBFSOrder.front();
		qStoreBFSOrder.pop();
		BFS(iTempBFSVal);
	}
}


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> iNumConnection;
	cin >> iStartNode;
	for (int i = 1; i <= iNumConnection; i++) {
		int tempA, tempB;
		cin >> tempA;
		cin >> tempB;
		iStoreConnectionArray[tempB].push_back(tempA);
		iStoreConnectionArray[tempA].push_back(tempB);
	}
	for (int i = 1; i <= N; i++) {
		sort(iStoreConnectionArray[i].begin(), iStoreConnectionArray[i].end());
	}

	

	DFS(iStartNode);
	BFS(iStartNode);

	int iCntVirusInfected = 0;

	

	for (int i = 1; i <= N; i++) {
		//printf("%d\n", iResultArrayDFS[i]);
	}

	for (int i = 1; i <= N; i++) {
		//printf("%d\n", iResultArrayBFS[i]);
	}

}
