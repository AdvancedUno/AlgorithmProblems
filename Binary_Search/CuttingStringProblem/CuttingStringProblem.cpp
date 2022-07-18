﻿


#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

int N, K;


int lineStoreArray[500001];



int Calculate(int n)
{
	int midKey, Left = 1, Right = lineStoreArray[N - 1];
	int cntNum = 0;
	midKey = (Left + Right) / 2;
	int ans = 0;
	while (Left <= Right)
	{
		
		cntNum = 0;
		for (int point = 0; point < N; point++) {
			cntNum += lineStoreArray[point] / midKey;
		}

		if (cntNum >= K) {
			//midKey = (lineStoreArray[N - 1] + midKey) / 2 + midKey;
			Left = midKey + 1;
			if (ans < midKey) {
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
	for (int i = 0; i < N; i++)
		cin >> lineStoreArray[i];

	sort(lineStoreArray, lineStoreArray + N);
	
	

	cout << Calculate(K);

	return 0;
}
