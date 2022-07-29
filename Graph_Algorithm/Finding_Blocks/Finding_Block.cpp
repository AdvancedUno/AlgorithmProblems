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
vector<int> bResultVector;
vector<pair<int,int>> bWantResultVector;
int iCntIndex = 0;
int iNumBlocks = 0;
int iDirectionListFirst[4] = { -1,0,1,0 };
int iDirectionListSecond[4] = { 0,1,0,-1 };


void DFS(int iWantedNodeFirst, int iWantedNodeSecond) {
	for (int i = 0; i < 4; i++) {

		int iHMove = iWantedNodeFirst + iDirectionListFirst[i];
		int iVMove = iWantedNodeSecond + iDirectionListSecond[i];
		if (iHMove >= N || iHMove < 0 || iVMove >= N || iVMove < 0) continue;
		if (bCheckVisitedArray[iHMove][iVMove] == 0 && iStoreConnectionArray[iHMove][iVMove] == 1) {
			bCheckVisitedArray[iHMove][iVMove] = 1;   
			iCntIndex++;           
			DFS(iHMove, iVMove);
		}
	}
}


int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	for (int i = 0; i < N; i++) {
		int tempA;
		cin >> tempA;
		for (int j = 0; j < N; j++) {
			int iWantNum = tempA % 10;
			tempA /= 10;
			iStoreConnectionArray[i].push_back(iWantNum);
		}
		reverse(iStoreConnectionArray[i].begin(), iStoreConnectionArray[i].end());

	}

	iStartNodeFirst = 0;
	iStartNodeSecond = 0;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (bCheckVisitedArray[i][j] == 0 && iStoreConnectionArray[i][j] != 0) {
				bCheckVisitedArray[i][j] = 1;
				iCntIndex = 1;
				DFS(i, j);
				bResultVector.push_back(iCntIndex);
				
				iNumBlocks++;
			}
		}
	}

	sort(bResultVector.begin(), bResultVector.end());
	printf("%d\n", iNumBlocks);
	for (int i = 0; i < bResultVector.size(); i ++) {
		if (bResultVector[i] > 0) {
			printf("%d\n", bResultVector[i]);
		}
	}
}
