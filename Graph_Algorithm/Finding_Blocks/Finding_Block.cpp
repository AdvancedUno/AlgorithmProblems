#include<iostream>
#include<queue>
#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<stack>
#include<algorithm>

using namespace std;

int N, iNumConnection, iStartNodeFirst, iStartNodeSecond;
vector<int> iStoreConnectionArray[26];
int bCheckVisitedArray[26][26];
int iSaveResultArray[100001];
vector<int> bResultVector;
int iCntIndex = 0;
int iNumBlocks = 0;



void DFS(int iWantedNodeFirst, int iWantedNodeSecond) {

	if (iStoreConnectionArray[iWantedNodeFirst][iWantedNodeSecond] == 0) {
		return;
	}

	if (bCheckVisitedArray[iWantedNodeFirst][iWantedNodeSecond] == 1) {
		return;
	}



	bCheckVisitedArray[iWantedNodeFirst][iWantedNodeSecond] = 1;

	iCntIndex++;

	if (iWantedNodeFirst - 1 >= 0 && bCheckVisitedArray[iWantedNodeFirst][iWantedNodeSecond] == bCheckVisitedArray[iWantedNodeFirst - 1][iWantedNodeSecond]) {
		DFS(iWantedNodeFirst - 1, iWantedNodeSecond);
	}


	if (iWantedNodeFirst + 1 < N && bCheckVisitedArray[iWantedNodeFirst][iWantedNodeSecond] == bCheckVisitedArray[iWantedNodeFirst + 1][iWantedNodeSecond]) {
		DFS(iWantedNodeFirst + 1, iWantedNodeSecond);
	}


	if (iWantedNodeSecond - 1 >= 0 && bCheckVisitedArray[iWantedNodeFirst][iWantedNodeSecond] == bCheckVisitedArray[iWantedNodeFirst][iWantedNodeSecond + 1]) {
		DFS(iWantedNodeFirst, iWantedNodeSecond -1);
	}


	if (iWantedNodeSecond + 1 < N && bCheckVisitedArray[iWantedNodeFirst][iWantedNodeSecond] == bCheckVisitedArray[iWantedNodeFirst][iWantedNodeSecond - 1]) {
		DFS(iWantedNodeFirst, iWantedNodeSecond + 1);
	}
}


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			int tempA;
			cin >> tempA;
			iStoreConnectionArray[i].push_back(tempA);
		}
	}

	iStartNodeFirst = 0;
	iStartNodeSecond = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			DFS(i, j);
			bResultVector.push_back(iCntIndex);
			iCntIndex = 0;
		}
	}

	sort(bResultVector.begin(), bResultVector.end());

	for (int i = 0; i < bResultVector.size(); i ++) {
		if (bResultVector[i] > 0) {
			printf("%d\n", bResultVector[i]);
		}
		
	}
	
	
}
