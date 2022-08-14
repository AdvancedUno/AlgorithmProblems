// Tree_Algorithm.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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


void BFS() {
	
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