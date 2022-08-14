// Tree_Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include <iostream>
#include <iostream>
#include<vector>
#include <queue>

using namespace std;

vector<int> childTree[100001];
int visited[100001];
int parent[100001];
int N;


void Solve() {
	queue<int> qSave;
	qSave.push(1);
	visited[1] = true;

	while (!qSave.empty()) {
		int root = qSave.front();
		qSave.pop();

		for (int i = 0; i < childTree[root].size(); i++) {
			int child = childTree[root][i];
			if (!visited[child]) {
				qSave.push(child);
				parent[child] = root;
				visited[child] = true;
			}
		}
	}
}



int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);

	cin >> N;

	for (int i = 0; i < N - 1; i++) {
		int temp1;
		int temp2;
		cin >> temp1 >> temp2;
		childTree[temp1].push_back(temp2);
		childTree[temp2].push_back(temp1);
	}

	Solve();

	for (int i = 2; i <= N; i++) {
		cout << parent[i] << "\n";
	}

}