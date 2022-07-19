#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

long long N, K;


long long lineStoreArray[100001];



long long Calculate(long long n)
{
	long long midKey, Left = 0, Right = 1000000000;
	long long cntNum = 0;
	midKey = (Left + Right) / 2;
	long long ans = 0;
	while (Left <= Right)
	{

		cntNum = 0;
		for (long long point = 0; point < N; point++) {
			long long temp = lineStoreArray[point] - midKey;
			if (temp > 0) {
				cntNum += lineStoreArray[point] - midKey;
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
