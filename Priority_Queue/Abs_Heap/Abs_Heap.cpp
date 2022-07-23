#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

long long N;


long long lineStoreArray[100002];

void DeleteAbsHeap(int currentIdx) {

	cout << lineStoreArray[1] << "\n";
	lineStoreArray[1] = lineStoreArray[currentIdx];




	int parent = 1;
	int child;

	for (int i = 1; i < currentIdx; i++) {


		child = parent * 2;


		if (child + 1 < currentIdx && abs(lineStoreArray[child]) > abs(lineStoreArray[child + 1])) {
			child++;
		}
		else if (child + 1 < currentIdx && abs(lineStoreArray[child]) == abs(lineStoreArray[child + 1])) {

			if (lineStoreArray[child] > lineStoreArray[child + 1]) {
				child++;
			}

		}

		if (child < currentIdx && abs(lineStoreArray[parent]) > abs(lineStoreArray[child])) {
			int temp = lineStoreArray[child];
			lineStoreArray[child] = lineStoreArray[parent];
			lineStoreArray[parent] = temp;
			parent = child;
		}
		else if (child < currentIdx && abs(lineStoreArray[parent]) == abs(lineStoreArray[child]) && lineStoreArray[parent] > lineStoreArray[child]) {
			int temp = lineStoreArray[child];
			lineStoreArray[child] = lineStoreArray[parent];
			lineStoreArray[parent] = temp;
			parent = child;
		}
		else {
			break;
		}




	}






}

void InsertAbsHeap(int n, int currentIdx)
{

	lineStoreArray[currentIdx] = n;


	for (int i = currentIdx; i > 1; i /= 2) {

		if (abs(lineStoreArray[i]) < abs(lineStoreArray[i / 2])) {

			int temp = lineStoreArray[i / 2];
			lineStoreArray[i / 2] = lineStoreArray[i];
			lineStoreArray[i] = temp;
		}
		else if (abs(lineStoreArray[i]) == abs(lineStoreArray[i / 2]) && lineStoreArray[i] < lineStoreArray[i / 2]) {
			
			int temp = lineStoreArray[i / 2];
			lineStoreArray[i / 2] = lineStoreArray[i];
			lineStoreArray[i] = temp;
		}
		else {

			break;
		}

	}

}





int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	int numberTemp;
	int currentIdx = 0;
	for (long long i = 0; i < N; i++) {
		cin >> numberTemp;
		if (numberTemp == 0) {

			if (currentIdx > 0) {

				DeleteAbsHeap(currentIdx);
				currentIdx--;
			}
			else {
				cout << 0 << "\n";
			}


		}
		else {
			currentIdx++;
			InsertAbsHeap(numberTemp, currentIdx);

		}


	}



	return 0;
}
