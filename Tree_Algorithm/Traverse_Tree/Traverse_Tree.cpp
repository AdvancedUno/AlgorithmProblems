#include <iostream>
#include<vector>
#include <queue>
#include <stdio.h>

using namespace std;


int nodeSave[26][2];

int N;

void PreOrder(int rootNode) {

	if (rootNode < 0)return;
	int leftNode = nodeSave[rootNode][0]; 
	int rightNode = nodeSave[rootNode][1];

	printf("%c", rootNode + 65);
	PreOrder(leftNode);
	PreOrder(rightNode);

	
	return;
	
}

void InOrder(int rootNode) {

	if (rootNode < 0)return;
	int leftNode = nodeSave[rootNode][0];
	int rightNode = nodeSave[rootNode][1];

	
	InOrder(leftNode);
	printf("%c", rootNode + 65);
	InOrder(rightNode);
	return;


}

void PostOrder(int rootNode) {
	if (rootNode < 0)return;
	int leftNode = nodeSave[rootNode][0];
	int rightNode = nodeSave[rootNode][1];


	PostOrder(leftNode);
	PostOrder(rightNode);
	printf("%c", rootNode + 65);
	return;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	std::cout.tie(0);
	cin >> N;

	char rootNode, leftNode, rightNode;
	for (int i = 0; i < N ; i++) {
		cin >> rootNode >> leftNode >> rightNode;
		nodeSave[rootNode - 65][0] = leftNode - 65;
		nodeSave[rootNode - 65][1] = rightNode - 65;
	}

	PreOrder(0);
	cout << "\n";
	InOrder(0);
	cout << "\n";
	PostOrder(0);

}