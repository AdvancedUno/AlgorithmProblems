#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include <string.h>
#include <queue>

using namespace std;

int iFirst;
int iSecond;
int iVisited[100001];


bool valid(int iPos) {
	if (iPos < 0 || iPos > 100000 || iVisited[iPos] > 0)
		return false;
	return true;
}

int Solve(queue<pair<int, int>> qOperation) {
	
	while (!qOperation.empty()) {

		int iValue = qOperation.front().first;
		int iStep = qOperation.front().second;
		qOperation.pop();


		if (iValue == iSecond) {

			cout << iStep << endl;
			return 0;
		}

		if (valid(iValue + 1)) {
			iVisited[iValue + 1] = iValue;
			qOperation.push(make_pair(iValue+1, iStep + 1));

		}

		if (valid(iValue -1)) {
			iVisited[iValue - 1] = iValue;
			qOperation.push(make_pair(iValue -1, iStep + 1));
		}

		if (valid(iValue * 2)) {
			iVisited[iValue * 2] = iValue;
			qOperation.push(make_pair(iValue * 2, iStep + 1));
		}

	}
	return 0;
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> iFirst >> iSecond;

	queue<pair<int, int>> qOperation;
	qOperation.push(make_pair(iFirst, 0));

	Solve(qOperation);
	vector<int> iPrint;
	iVisited[iFirst] = -1;

	int iPos = iSecond;
	while (iPos > 0) {
		//cout << iVisited[iPos] << endl;
		if (iVisited[iPos] == -1) break;
		if (iVisited[iPos] == iSecond || iVisited[iPos] == iFirst)break;
		iPrint.push_back(iVisited[iPos]);
		iPos = iVisited[iPos];
	}
	cout << iFirst << " ";
	for (int i = iPrint.size() - 1; i >= 0; i--) {
		cout << iPrint[i] << " ";
	}
	cout << iSecond;
	
	return 0;
}