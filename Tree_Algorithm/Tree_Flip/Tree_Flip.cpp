#include <iostream>
#include<vector>
#include <queue>

using namespace std;

vector<int> childTree;



void Solve(int start, int end) {
	
	if (start >= end)return;

	if (start == end-1) {
		cout << childTree[start] << endl;
		return;
	}

	int idx = start+1;
	while (idx < end) {

		if (childTree[start] < childTree[idx])break;
		idx++;
	}


	Solve(start+1, idx);
	Solve(idx, end);

	cout << childTree[start] << endl;



}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);	
	int N;
	
	while (cin >> N) {
		if (N == EOF) break;
		childTree.push_back(N);

	}
	Solve(0, childTree.size()-1);

	return 0;
}