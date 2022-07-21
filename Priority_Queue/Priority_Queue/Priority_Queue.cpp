#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

long long N, K;


long long lineStoreArray[100001];

void DeleteMaxHeap() {




}

void InsertMaxHeap(int n, int currentIdx)
{
	lineStoreArray[currentIdx] = n;


	for (int i = currentIdx; i > 1; i=i/2) {

		if (lineStoreArray[i] > lineStoreArray[i / 2]) {
			
			int temp = lineStoreArray[i / 2];
			//cout << lineStoreArray[i] << " " << temp << endl;
			lineStoreArray[i / 2] = lineStoreArray[i];
			lineStoreArray[i] = temp;
		}
		else {
			cout << lineStoreArray[i] << " " << lineStoreArray[i / 2] << endl;
			break;
		}

	}

}





int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	//cin >> K;
	int numberTemp;
	int currentIdx = 1;
	for (long long i = 0; i < N; i++) {
		cin >> numberTemp;
		if (numberTemp == 0) {
			DeleteMaxHeap();
			if (currentIdx > 1) {
				currentIdx--;
			}
		}
		else {
			InsertMaxHeap(numberTemp, currentIdx);
			currentIdx++;
		}
		

	}


	for (int i =1; i < N+1; i++) {
		cout << lineStoreArray[i] << endl;
	}
		
		

	//sort(lineStoreArray, lineStoreArray + N);



	//cout << Calculate(K);

	return 0;
}
