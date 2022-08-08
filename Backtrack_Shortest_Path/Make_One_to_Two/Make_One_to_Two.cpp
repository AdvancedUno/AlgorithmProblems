#include <iostream>
#include<vector>
#include<math.h>
#include<algorithm>

using namespace std;


int iNum;

int iBefore[1000001];
int iStore[1000001];


int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);


	cin >> iNum;

	iStore[1] = 0;
	iBefore[1] = 1;
	for (int i = 2; i <= iNum; i++) {
		iStore[i] = iStore[i - 1] + 1;
		iBefore[i] = i - 1;
		if (i % 3 == 0) {
			if (iStore[i] > iStore[1 / 3] + 1) {
				iStore[i] = iStore[1 / 3] + 1;
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


	cout << iStore[iNum] << endl;
	if (iNum != 0) {
		cout << iNum << " ";
	}
	
	while (iNum != 1) {
		
		iNum = iBefore[iNum];
		cout << iNum << " ";
	}

	return 0;
}