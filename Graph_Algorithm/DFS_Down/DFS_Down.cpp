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
int bResultArray[100001];
int cnt = 0;

bool cmp(int a, int b) {
	return a > b;
}

void DFS(int iWantedNode) {
	if (bCheckVisitedArray[iWantedNode] == 1) {
		return;
	}
	bCheckVisitedArray[iWantedNode] = 1;
	cnt++;
	bResultArray[iWantedNode] = cnt;
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
	cin >> iStartNode;
	for (int i = 1; i <= iNumConnection; i++) {
		int tempA, tempB;
		cin >> tempA;
		cin >> tempB;
		iStoreConnectionArray[tempB].push_back(tempA);
		iStoreConnectionArray[tempA].push_back(tempB);
	}
	for (int i = 1; i <= N; i++) {
		sort(iStoreConnectionArray[i].begin(), iStoreConnectionArray[i].end(), cmp);
	}
	DFS(iStartNode);

	for (int i = 1; i <= N; i++) {

		printf("%d\n", bResultArray[i]);
	}
}

