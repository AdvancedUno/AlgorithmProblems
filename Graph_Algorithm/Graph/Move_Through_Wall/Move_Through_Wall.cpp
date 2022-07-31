#include<iostream>
#include<queue>
#include<deque>
#include<string.h>
#include<math.h>
#include<cmath>
#include<stack>
#include<algorithm>

using namespace std;

int N, Rows, iStartNodeFirst, iStartNodeSecond;
int iStoreConnectionArray[1001][1001];
int bCheckVisitedArray[1001][1001][2];
vector<pair<int, int>> bWantResultVector;
int iCntWall = 0;
int iCntEmptyBox = 0;

int iDirectionListFirst[4] = { -1,0,1,0 };
int iDirectionListSecond[4] = { 0,1,0,-1 };


bool CheckError(int iFirst, int iSecond) {

	if (iFirst >= Rows || iFirst < 0 || iSecond >= N || iSecond < 0) {
		return true;
	}
	else {
		return false;
	}
}


int BFS() {

	queue < pair<pair<int, int>, int>> qSavePathInfo;

	qSavePathInfo.push({ { 1,1 }, 1 });
	bCheckVisitedArray[1][1][1] = 1;


	while (!qSavePathInfo.empty()) {

		int iPosY = qSavePathInfo.front().first.first;
		int iPosX = qSavePathInfo.front().first.second;
		int iCheckWall = qSavePathInfo.front().second;


		if (iPosY == N && iPosX == Rows) {
			return bCheckVisitedArray[iPosY][iPosX][iCheckWall];
		}


		for (int i = 0; i < 4; i++) {

			int iHMove = iPosY + iDirectionListFirst[i];
			int iVMove = iPosX + iDirectionListSecond[i];
			if (CheckError(iHMove, iVMove)) continue;
			if (iCheckWall == 1 && iStoreConnectionArray[iHMove][iVMove] == 1) {
				bCheckVisitedArray[iHMove][iVMove][iCheckWall-1] = bCheckVisitedArray[iHMove][iVMove][iCheckWall] + 1;
				qSavePathInfo.push(make_pair(make_pair(iHMove, iVMove), iCheckWall -1));
			}
			if (iStoreConnectionArray[iHMove][iVMove] == 0 && bCheckVisitedArray[iHMove][iVMove][iCheckWall] == 0) {
				bCheckVisitedArray[iHMove][iVMove][iCheckWall] = bCheckVisitedArray[iHMove][iVMove][iCheckWall] + 1;
				qSavePathInfo.push(make_pair(make_pair(iHMove, iVMove), iCheckWall));
			}
		}


	}
	return -1;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> Rows;


	string str;

	for (int i = 0; i < N; i++) {
		cin >> str;
		for (int j = 0; j < str.length(); j++) {
			bCheckVisitedArray[i][j][1] = 0;
			if (str[j] == '1') {
				iStoreConnectionArray[i][j] = 1;
			}
			else iStoreConnectionArray[i][j] = 0;
		}
	}

	//BFS();


	printf("%d\n", BFS());
}
