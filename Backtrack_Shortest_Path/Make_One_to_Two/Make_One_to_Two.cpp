#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int iNum;
	cin >> iNum;
	vector<int> iBefore(iNum+1);
	vector<int> iStore(iNum+1);

	iBefore[1] = 1;
	for (int i = 2; i <= iNum; i++) {
		iStore[i] = iStore[i - 1] + 1;
		iBefore[i] = i - 1;
		if (i % 3 == 0) {
			if (iStore[i] > iStore[i / 3] + 1) {
				iStore[i] = iStore[i / 3] + 1;
				iBefore[i] = i / 3;
			}
		}
		if (i % 2 == 0) {
			if (iStore[i] > iStore[i / 2] + 1) {
				iStore[i] = iStore[i / 2] + 1;
				iBefore[i] = i / 2;
			}
		}
	}

	cout << iStore[iNum] << '\n';
	if (iNum != 0) {
		cout << iNum << ' ';
	}
	
	while (iNum != 1) {
		
		iNum = iBefore[iNum];
		cout << iNum << ' ';
	}
	return 0;
}