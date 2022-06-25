
#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

int cntWhite = 0;
int cntBlack = 0;

void Devide(vector<vector<int>> vecParts) {

	if (vecParts.size() == 1) {
		if (vecParts[0][0] == 1) {
			cntWhite++;
		}
		else {
			cntBlack++;
		}
		return;
	}

	bool checkSame = true;
	int firstColor = vecParts[0][0];

	//cout << vecParts.size() << endl;

	for (int i = 0; i < vecParts.size(); i++) {
		if (checkSame == false)break;
		for (int k = 0; k < vecParts.size(); k++) {

			if (firstColor != vecParts[i][k]) {
				checkSame = false;
				break;
			}


		}

	}




	if (checkSame == true) {
		if (vecParts[0][0] == 1) {
			cntWhite++;
		}
		else {
			cntBlack++;
		}
	}
	else {
		for (int w = 0; w < 4; w++) {
			int size1 = 0;
			int end1 = 0;
			int size2 = 0;
			int end2 = 0;
			if (w == 0) {
				size1 = 0;
				end1 = vecParts.size() / 2;
				size2 = 0;
				end2 = vecParts.size() / 2;
			}
			else if (w == 1) {
				size1 = vecParts.size() / 2;
				end1 = vecParts.size();
				size2 = 0;
				end2 = vecParts.size() / 2;
			}
			else if (w == 2) {
				size1 = 0;
				end1 = vecParts.size() / 2;
				size2 = vecParts.size() / 2;
				end2 = vecParts.size();
			}
			else if(w == 3) {
				size1 = vecParts.size() / 2;
				end1 = vecParts.size();
				size2 = vecParts.size() / 2;
				end2 = vecParts.size();
			}
			//cout << w << endl;

			vector<vector<int>> vecAll;

			for (int i = size1; i < end1; i++) {
				vector<int> vecTemp;
				for (int k = size2; k < end2; k++) {

					//cout << 1 << endl;

					vecTemp.push_back(vecParts[i][k]);
					
				}
				vecAll.push_back(vecTemp);
			}

			Devide(vecAll);
			
		}
		return;
		
	}

	

}


int main()
{

	int N;


	cin >> N;


	vector<vector<int>> vecAll;

	for (int i = 0; i < N; i++) {
		vector<int> vecTemp;
		for (int k = 0; k < N; k++) {
			int temp;
			cin >> temp;
			vecTemp.push_back(temp);

		}
		vecAll.push_back(vecTemp);
	}
	//asfd
	//cout << vecAll.size() << endl;

	Devide(vecAll);

	cout << cntBlack << endl;
	cout << cntWhite << endl;
	








}


