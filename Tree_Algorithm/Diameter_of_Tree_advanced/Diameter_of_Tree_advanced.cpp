#include <iostream>
#include <iostream>
#include<vector>
#include <queue>

using namespace std;
vector<pair<int, int>> childTree[100001];
int visited[100001];
int iCostSave[100001];
int N;
int maxWeight = 0;
int maxPos;
void DFS(int node) {
	for (int i = 0; i < childTree[node].size(); i++) {
		int nextNode = childTree[node][i].first;
		int iWeight = childTree[node][i].second;
		if (visited[nextNode] == true) {
			continue;
		}
		visited[nextNode] = true;
		iCostSave[nextNode] = iCostSave[node] + iWeight;
		if (iCostSave[nextNode] > maxWeight) {
			maxWeight = iCostSave[nextNode];
			maxPos = nextNode;
		}
		DFS(nextNode);
	}
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
	cin >> N;
	for (int i = 0; i < N-1; i++) {
		int temp1;
		int temp2;
		int iWeight;
		cin >> temp1;
		cin >> temp2;
		cin >> iWeight;
		childTree[temp1].push_back(make_pair(temp2, iWeight));
		childTree[temp2].push_back(make_pair(temp1, iWeight));
	}

	visited[1] = true;
	DFS(1);
	//cout << maxWeight << endl;
	//cout << maxPos << endl;
	for (int i = 0; i <= N; i++) {
		visited[i] = false;
		iCostSave[i] = 0;
		maxWeight = 0;
	}

	visited[maxPos] = true;
	DFS(maxPos);
	cout << maxWeight << endl;

}