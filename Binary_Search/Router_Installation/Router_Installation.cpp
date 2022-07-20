#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

long long N, K;


long long lineStoreArray[1000001];



long long Calculate(int n)
{
	long long midKey, Left = 1, Right = lineStoreArray[N-1] - lineStoreArray[0];
	long long cntNum = 1;
	midKey = (Left + Right) / 2;
	long long ans = 0;
	long long currentNum;

	while (Left <= Right){
	

		cntNum = 1;
		currentNum = lineStoreArray[0];
		for (long long point = 1; point < N; point++) {
			long long temp = lineStoreArray[point] - currentNum;
			if (temp >= midKey) {
				cntNum ++;
				currentNum = lineStoreArray[point];
			}
		}

		if (cntNum >= K) {
			//midKey = (lineStoreArray[N - 1] + midKey) / 2 + midKey;
			Left = midKey + 1;
			if (ans <= midKey) {
				ans = midKey;
			}
		}

		if (cntNum < K) {
			//midKey = midKey / 2;
			Right = midKey - 1;
		}

		midKey = (Right + Left) / 2;

	}
	return ans;
}

int main(void)
{
	cin.tie(NULL);
	ios::sync_with_stdio(false);

	cin >> N;
	cin >> K;
	for (long long i = 0; i < N; i++)
		cin >> lineStoreArray[i];

	sort(lineStoreArray, lineStoreArray + N);



	cout << Calculate(K);

	return 0;
}
