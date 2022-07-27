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
vector<int> iStoreConnectionArray[100001];
int bCheckVisitedArray[100001] = { 0, };
int bResultArray[100001] = { 0, };
int cnt = 0;


void DFS(int iWantedNode) {
	if (bCheckVisitedArray[iWantedNode] == 1) {
		return;
	}
	bCheckVisitedArray[iWantedNode] = 1;
	bResultArray[iWantedNode] = 1;
	for (int i = 0; i < iStoreConnectionArray[iWantedNode].size(); i++) {
		DFS(iStoreConnectionArray[iWantedNode][i]);
	}
}


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> iNumConnection;
	for (int i = 1; i <= iNumConnection; i++) {
		int tempA, tempB;
		cin >> tempA;
		cin >> tempB;
		iStoreConnectionArray[tempB].push_back(tempA);
		iStoreConnectionArray[tempA].push_back(tempB);
	}
	//for (int i = 1; i <= N; i++) {
	//	sort(iStoreConnectionArray[i].begin(), iStoreConnectionArray[i].end(), cmp);
	//}

	iStartNode = 1;

	DFS(iStartNode);

	int iCntVirusInfected = 0;

	for (int i = 2; i <= N; i++) {
		if (bResultArray[i] > 0) {
			iCntVirusInfected++;
		}
	}

	printf("%d\n", iCntVirusInfected);
}
