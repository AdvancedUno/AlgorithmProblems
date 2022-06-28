#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

int A, B, C, D;

int MatA[100][100] = { 0, };
int MatB[100][100] = { 0, };
int MatC[100][100] = { 0, };



void Mul(int pos, int maxNum) {


	for (int i = 0; i < maxNum; i++) {
		for (int k = 0; k < B; k++) {
			MatC[pos][i] += MatA[pos][k] * MatB[k][i];
		}
	}

}







int main()
{




	cin >> A;
	cin >> B;

	for (int i = 0; i < A; i++) {
		for (int k = 0; k < B; k++) {
			cin >> MatA[i][k];
		}
	}


	cin >> C;
	cin >> D;

	for (int i = 0; i < C; i++) {
		for (int k = 0; k < D; k++) {
			cin >> MatB[i][k];
			
		}
	}

	for (int i = 0; i < A; i++) {
		Mul(i, D);
	}



	for (int i = 0; i < A; i++) {
		for (int k = 0; k < D; k++) {
			cout << MatC[i][k] << " ";
		}
		cout << endl;
	}








}
