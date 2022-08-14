//

#include <iostream>
#include <iostream>
#include<vector>
#include <queue>

using namespace std;

vector<pair<int, int>> childTree[100001];
int visited[100001];
int parent[100001];
int N;


void DFS() {

}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N;

	for (int i = 0; i < N; i++) {
		int temp1;
		int temp2;
		int iWeight;
		cin >> temp1;
		while (true) {
			cin >> temp2;
			if (temp2 == -1)break;
			cin >> iWeight;
			childTree[temp1].push_back(make_pair(temp2, iWeight));
		}
	}




	for (int i = 1; i <= N; i++) {
		cout << childTree[i].front().first << "\n";
	}

}