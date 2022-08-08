#include<iostream>
#include<math.h>
#include<stdio.h>
#include<algorithm>
#include <queue>

#define MAX_SIZE 2000+1
#define endl "\n"
#define INF 987654321

using namespace std;


int iTestCases, iNodeNum, iConnectionNum, iDestNum, iStartPos, iMidFirst, iMidSecond;

int iResultSaveArray[MAX_SIZE];
int iNextNode;
int iNextWeight;

int Dijkstra(int iWantedNode, vector<pair<int, int>> iStoreConnectionArray[MAX_SIZE]) {
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > qSaveCount;
	iResultSaveArray[iWantedNode] = 0;
	qSaveCount.push({ 0, iWantedNode });


	while (!qSaveCount.empty()) {

		int iCurrentNode = qSaveCount.top().second;
		int iCurrentWeight = qSaveCount.top().first;
		qSaveCount.pop();

		if (iResultSaveArray[iCurrentNode] < iCurrentWeight) {
			continue;
		}
		
		for (int i = 0; i < iStoreConnectionArray[iCurrentNode].size(); i++) {
			iNextNode = iStoreConnectionArray[iCurrentNode][i].first;
			iNextWeight = iStoreConnectionArray[iCurrentNode][i].second;

			if (iResultSaveArray[iNextNode] > iNextWeight + iCurrentWeight) {
				iResultSaveArray[iNextNode] = iNextWeight + iCurrentWeight;
				qSaveCount.push(make_pair(iResultSaveArray[iNextNode], iNextNode));
			}
		}

	}
	return 0;
}

void Reset() {
	for (int j = 0; j <= iNodeNum; j++) {
		iResultSaveArray[j] = INF;
	}
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	cin >> iTestCases;
	for (int i = 0; i < iTestCases; i++) {
		vector<pair<int, int>> iStoreConnectionArray[MAX_SIZE];
		vector<int> iPredictDesVector;
		vector<int> iPredictDesWeightVector;
		cin >> iNodeNum >> iConnectionNum >> iDestNum;
		cin >> iStartPos >> iMidFirst >> iMidSecond;
		
		for (int j = 1; j <= iConnectionNum; j++) {

			int tempA, tempB, tempWeight;
			cin >> tempA >> tempB >> tempWeight;
			iStoreConnectionArray[tempA].push_back(make_pair(tempB, tempWeight));
			iStoreConnectionArray[tempB].push_back(make_pair(tempA, tempWeight));
		}
		for (int j = 0; j < iDestNum; j++) {
			int iTempNum;
			cin >> iTempNum;
			iPredictDesVector.push_back(iTempNum);
		}
		Reset();
		Dijkstra(iStartPos, iStoreConnectionArray);
		int iToMidFirst = iResultSaveArray[iMidFirst];
		int iToMidSecond = iResultSaveArray[iMidSecond];
		for (int j = 0; j < iDestNum; j++) {
			iPredictDesWeightVector.push_back(iResultSaveArray[iPredictDesVector[j]]);
		}

		int iTempVec[2001];

		int iMidBetweenWeight;
		Reset();
		Dijkstra(iMidFirst, iStoreConnectionArray);
		iMidBetweenWeight = iResultSaveArray[iMidSecond];
		for (int j = 0; j < iDestNum; j++) {
			if (iPredictDesWeightVector[j] < iResultSaveArray[iPredictDesVector[j]] + iMidBetweenWeight + iToMidSecond) {
				iTempVec[j] = -1;
			}
			else {
				iTempVec[j] = 1;
			}
		}

		Reset();
		Dijkstra(iMidSecond, iStoreConnectionArray);
		for (int j = 0; j < iDestNum; j++) {
			if (iPredictDesWeightVector[j] < iResultSaveArray[iPredictDesVector[j]] + iMidBetweenWeight + iToMidFirst && iTempVec[j] != 1) {
				iTempVec[j] = -1;
			}
			else if (iPredictDesWeightVector[j] >= iResultSaveArray[iPredictDesVector[j]] + iMidBetweenWeight + iToMidFirst) {
				iTempVec[j] = 1;
			}
		}
		vector<int> ResultVec;
		
		for (int j = 0; j < iDestNum; j++) {
			if (iTempVec[j] == 1) {
				ResultVec.push_back(iPredictDesVector[j]);	
			}
		}
		sort(ResultVec.begin(), ResultVec.end());
		for (int j = 0; j < ResultVec.size(); j++) {
			cout << ResultVec[j] << " ";
		}
		cout << "\n";
	}

}
