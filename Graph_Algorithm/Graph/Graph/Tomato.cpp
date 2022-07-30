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
int bCheckVisitedArray[1001][1001];
vector<int> bResultVector;
vector<pair<int, int>> bWantResultVector;
int iCntIndex = 0;
int iNumLevel = 0;
int iCntEmptyBox = 0;
int iCntTotal = 0;
vector<pair<int, int>> iSaveOneBoxPosList;

int iDirectionListFirst[4] = { -1,0,1,0 };
int iDirectionListSecond[4] = { 0,1,0,-1 };


void BFS(vector<pair<int, int>> OneBoxPosList) {


	if (OneBoxPosList.size() < 1) {
		return;
	}


	vector<pair<int, int>> vectorSaveOneBoxPosList;

	for (int num = 0; num < OneBoxPosList.size(); num++) {
		//bCheckVisitedArray[OneBoxPosList[num].first][OneBoxPosList[num].second] = 1;
		//cout << OneBoxPosList[num].first << "  " << OneBoxPosList[num].second << endl;
		//cout << iStoreConnectionArray[OneBoxPosList[num].first][OneBoxPosList[num].second] << endl;
		
		for (int i = 0; i < 4; i++) {
			
			int iHMove = OneBoxPosList[num].first + iDirectionListFirst[i];
			int iVMove = OneBoxPosList[num].second + iDirectionListSecond[i];
			if (iHMove >= Rows || iHMove < 0 || iVMove >= N || iVMove < 0) continue;
			if (bCheckVisitedArray[iHMove][iVMove] == 0 && iStoreConnectionArray[iHMove][iVMove] == 0) {
				bCheckVisitedArray[iHMove][iVMove] = bCheckVisitedArray[OneBoxPosList[num].first][OneBoxPosList[num].second] + 1;
				vectorSaveOneBoxPosList.push_back(make_pair(iHMove, iVMove));

				iCntTotal++;
			}

		}
		//bCheckVisitedArray[OneBoxPosList[num].first][OneBoxPosList[num].second] = 1;
	}

	if (vectorSaveOneBoxPosList.size() > 0) {
		iNumLevel++;
		BFS(vectorSaveOneBoxPosList);
	}
	
}








int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);
	cin >> N;
	cin >> Rows;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < N; j++) {
			int tempA;
			cin >> tempA;
			iStoreConnectionArray[i][j] = tempA;
			if (tempA == 1) {
				bCheckVisitedArray[i][j] = 1;
				iSaveOneBoxPosList.push_back(make_pair(i, j));
			}
			else if (tempA == -1) {
				bCheckVisitedArray[i][j] = -1;
				iCntEmptyBox++;
			}
		}
	}

	BFS(iSaveOneBoxPosList);

	int iResult = 0;
	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < N; j++) {
			iResult = max(iResult, bCheckVisitedArray[i][j]);
			
		}
	}

	for (int i = 0; i < Rows; i++) {
		for (int j = 0; j < N; j++) {
			if (bCheckVisitedArray[i][j] == 0 && iStoreConnectionArray[i][j] == 0) {
				iResult = 0;
				break;
			}
		}
	}




	printf("%d\n", iResult-1);

}
