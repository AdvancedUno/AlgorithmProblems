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

	if (iFirst > N || iFirst <= 0 || iSecond > Rows || iSecond <= 0) {
		return true;
	}
	else {
		return false;
	}
}

bool is_inside(int _ny, int _nx) {
	return (_ny >= 1 && _ny <= N && _nx >= 1 && _nx <= Rows);
}


int BFS() {

	queue < pair<pair<int, int>, int>> qSavePathInfo;

	qSavePathInfo.push({ { 1,1 }, 1 });
	bCheckVisitedArray[1][1][1] = 1;


	while (!qSavePathInfo.empty()) {
		
		
		int iPosY = qSavePathInfo.front().first.first;
		int iPosX = qSavePathInfo.front().first.second;
		int iCheckWall = qSavePathInfo.front().second;
		qSavePathInfo.pop();

		if (iPosY == N && iPosX == Rows) {
			
			return bCheckVisitedArray[iPosY][iPosX][iCheckWall];
		}


		for (int i = 0; i < 4; i++) {

			int iHMove = iPosY + iDirectionListFirst[i];
			int iVMove = iPosX + iDirectionListSecond[i];
			if (!is_inside(iHMove, iVMove)) continue;
			if (iCheckWall == 1 && iStoreConnectionArray[iHMove][iVMove] == 1) {
				bCheckVisitedArray[iHMove][iVMove][iCheckWall-1] = bCheckVisitedArray[iPosY][iPosX][iCheckWall] + 1;
				//qSavePathInfo.push(make_pair(make_pair(iHMove, iVMove), iCheckWall -1));
				
				qSavePathInfo.push({ {iHMove, iVMove}, iCheckWall - 1 });
			}
			else if (iStoreConnectionArray[iHMove][iVMove] == 0 && bCheckVisitedArray[iHMove][iVMove][iCheckWall] == 0) {
				bCheckVisitedArray[iHMove][iVMove][iCheckWall] = bCheckVisitedArray[iPosY][iPosX][iCheckWall] + 1;
				//qSavePathInfo.push(make_pair(make_pair(iHMove, iVMove), iCheckWall));
				
				qSavePathInfo.push({ {iHMove, iVMove}, iCheckWall });
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

	for (int i = 1; i <= N; i++) {
		cin >> str;
		
		for (int j = 0; j < Rows; j++) {
			if (str[j] == '1') {
				iStoreConnectionArray[i][j+1] = 1;
			}
			else iStoreConnectionArray[i][j+1] = 0;
		}
	}


	for (int i = 1; i <= N; i++) {


		for (int j = 0; j < Rows; j++) {
			
			//cout << iStoreConnectionArray[i][j+1] << " ";


		}
		//cout << "\n";
	}

	


	//BFS();


	printf("%d\n", BFS());
}
