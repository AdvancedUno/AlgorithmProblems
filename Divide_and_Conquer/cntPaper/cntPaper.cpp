#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

int cntNeg = 0;
int cntPos = 0;
int cntZero = 0;
int vecAll[2200][2200];
void Devide(int startX, int startY, int N) {

	int firstColor = vecAll[startX][startY];

	if (N == 0) {
		if (firstColor == 1) {
			cntPos++;
		}
		else if (firstColor == -1) {
			cntNeg++;
		}
		else {
			cntZero++;
		}
		return;
	}

	bool checkSame = true;
	

	for (int i = 0; i < N; i++) {
		if (checkSame == false)break;
		for (int k = 0; k < N; k++) {

			if (firstColor != vecAll[startX + i][startY + k]) {
				checkSame = false;
				break;
			}
		}
	}




	if (checkSame == true) {
		if (firstColor == 1) {
			cntPos++;
		}
		else if (firstColor == -1) {
			cntNeg++;
		}
		else {
			cntZero++;
		}


		return;
		
	}


	else {
		N = N / 3;

		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				Devide(startX + N * i, startY + N * j, N);
			}
		}
	}
}


int main()
{

	int N;


	cin >> N;


	

	for (int i = 0; i < N; i++) {
		vector<int> vecTemp;
		for (int k = 0; k < N; k++) {
			int temp;
			cin >> vecAll[i][k];

		}
		
	}



	Devide(0, 0, N);

	cout << cntNeg << endl;
	cout << cntZero << endl;
	cout << cntPos << endl;

}


