#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

long long int A, B;


vector<vector<int>> MatA(5, vector<int>(5));
vector<vector<int>> MatC(5, vector<int>(5));
vector<vector<int>> Ans(5, vector<int>(5));



vector<vector<int>> Power(vector<vector<int>> FirstMat, vector<vector<int>>SecondMat) {
	vector<vector<int>> MatTemp(5, vector<int>(5));

	vector<vector<int>>temp(5, vector<int>(5));
	
	for (int pos = 0; pos < A; pos++) {

		for (int i = 0; i < A; i++) {
			for (int k = 0; k < A; k++) {
				temp[pos][i] += (FirstMat[pos][k] * SecondMat[k][i]) ;
			}
			temp[pos][i] = temp[pos][i] % 1000;
		}
	}


	for (int i = 0; i < A; i++)
		for (int j = 0; j < A; j++)
			MatTemp[i][j] = temp[i][j];


	return MatTemp;
	
}

vector<vector<int>> Start(long long int num) {
	vector<vector<int>> MatTemp(5, vector<int>(5));



	if (num < 2) {
		return MatA;
	}

	MatTemp = Start(num / 2);


	

	if (num % 2 == 0) {
		return Power(MatTemp, MatTemp);
	}
	else {
		return Power(Power(MatTemp, MatTemp), MatA);
	}

}



//int solution(vector<string> citations) {
//
//	vector<double> Start;
//	vector<double> End;
//
//
//	vector<int> storeH;
//	vector<int> storeM;
//	vector<double> storeS;
//	vector<double> storeT;
//
//	vector<int> storeHEnd;
//	vector<int> storeMEnd;
//	vector<double> storeSEnd;
//
//
//
//
//	for (int i = 0; i < citations.size(); i++) {
//		int storeSF;
//		int storeSB;
//		storeH.push_back(stoi(((citations[i].substr(11, 2)))));
//		storeM.push_back(stoi(((citations[i].substr(14, 2)))));
//		storeSF = stoi(((citations[i].substr(17, 2))));
//		storeSB =stoi(((citations[i].substr(20, 3))));
//		storeS.push_back(storeSF + storeSB * 0.001 );
//
//
//		if (citations[i].size() - 25 > 2) {
//			storeSF = stoi(((citations[i].substr(24, 1))));
//			storeSB = stoi(((citations[i].substr(26, citations[i].size() - 25-2))));
//			if (citations[i].size() - 27 == 1) {
//				storeT.push_back(storeSF + storeSB * 0.1);
//			}
//			if (citations[i].size() - 27 == 2) {
//				storeT.push_back(storeSF + storeSB * 0.01);
//			}
//
//			if (citations[i].size() - 27 == 3) {
//				storeT.push_back(storeSF + storeSB * 0.001);
//			}
//		}
//		else {
//			storeT.push_back(stoi(((citations[i].substr(24, 1)))));
//			
//		}
//		
//
//	}
//
//
//	for (int i = 0; i < citations.size(); i++) {
//
//		if (storeS[i] + storeT[i] < 60) {
//			storeSEnd.push_back(storeS[i] + storeT[i]- 0.001);
//			storeMEnd.push_back(storeM[i]);
//			storeHEnd.push_back(storeH[i]);
//		}
//		else {
//			storeSEnd.push_back(storeS[i] + storeT[i] - 0.001-60);
//			if (storeM[i] + 1 < 60) {
//				storeMEnd.push_back(storeM[i] + 1);
//				storeHEnd.push_back(storeH[i]);
//			}
//			else {
//
//				storeMEnd.push_back(storeM[i] + 1 - 60);
//				storeHEnd.push_back(storeH[i] + 1);
//			}
//			
//		}
//
//	}
//
//	for (int i = 0; i < citations.size(); i++) {
//		cout << fixed;
//		cout.precision(3);
//		
//
//		Start.push_back(storeH[i] * 10000.0 + storeM[i] * 100.0 + storeS[i] * 1.0);
//
//		//cout << storeHEnd[i]  << endl;
//		
//		End.push_back(storeHEnd[i] * 10000.0 + storeMEnd[i] * 100.0 + storeSEnd[i]* 1.0);
//
//		//cout << Start[i] << endl;
//		//cout << End[i] << endl;
//
//
//
//	}
//
//
//
//
//	
//	int Max = 0;
//	int MaxPos = 0;
//
//	for (int i = 0; i < citations.size(); i++) {
//		int iFindMax = 1;
//		for (int k = 0; k < citations.size(); k++) {
//
//			if (Start[i] -1 <= Start[k]) {
//
//				if (Start[k]-1 <= End[i]) {
//					iFindMax++;
//				}
//
//			}
//
//
//		}
//
//		if (iFindMax > Max) {
//			Max = iFindMax;
//			MaxPos = i;
//		}
//
//
//
//
//	}
//
//	Max = 0;
//
//	cout << MaxPos << endl;
//	for (int i = 0; i < storeT[MaxPos] * 1000 +1000 ; i++) {
//		int iFindMax = 1;
//		
//		cout << Start[MaxPos] - 1.00 + i * 0.001  << endl;
//		cout << Start[MaxPos] + i * 0.001 << endl;
//
//		for (int k = 0; k < citations.size(); k++) {
//			
//
//
//
//			if (k == MaxPos) {
//
//			}
//			else if ((Start[MaxPos] - 1.00 + i * 0.001  <= End[k] && Start[MaxPos] - 1.00 + i * 0.001 >= Start[k]))  {
//
//				iFindMax++;
//
//			}
//			else if ((Start[MaxPos] + i * 0.001 > Start[k] && Start[MaxPos] + i * 0.001 < End[k])) {
//				iFindMax++;
//			}
//
//
//
//		}
//
//		if (iFindMax > Max) {
//			Max = iFindMax;
//		}
//
//
//
//	}
//
//
//
//	
//
//	
//
//	
//
//
//	int answer = Max;
//	return answer;
//}

int solution(vector<string> citations) {

	vector<double> Start;
	vector<double> End;


	vector<int> storeH;
	vector<int> storeM;
	vector<double> storeS;
	vector<double> storeT;

	vector<int> storeHEnd;
	vector<int> storeMEnd;
	vector<double> storeSEnd;




	for (int i = 0; i < citations.size(); i++) {
		int storeSF;
		int storeSB;
		storeH.push_back(stoi(((citations[i].substr(11, 2)))));
		storeM.push_back(stoi(((citations[i].substr(14, 2)))));
		storeSF = stoi(((citations[i].substr(17, 2))));
		storeSB = stoi(((citations[i].substr(20, 3))));
		storeS.push_back(storeSF + storeSB * 0.001);


		if (citations[i].size() - 25 > 2) {
			storeSF = stoi(((citations[i].substr(24, 1))));
			storeSB = stoi(((citations[i].substr(26, citations[i].size() - 25 - 2))));
			if (citations[i].size() - 27 == 1) {
				storeT.push_back(storeSF + storeSB * 0.1);
			}
			if (citations[i].size() - 27 == 2) {
				storeT.push_back(storeSF + storeSB * 0.01);
			}

			if (citations[i].size() - 27 == 3) {
				storeT.push_back(storeSF + storeSB * 0.001);
			}
		}
		else {
			storeT.push_back(stoi(((citations[i].substr(24, 1)))));

		}


	}


	for (int i = 0; i < citations.size(); i++) {

		//if (storeS[i] + storeT[i] < 60) {
		storeSEnd.push_back(storeS[i] + storeT[i] - 0.001);
		storeMEnd.push_back(storeM[i]);
		storeHEnd.push_back(storeH[i]);
		//}
		/*else {
			storeSEnd.push_back(storeS[i] + storeT[i] - 0.001 - 60);
			if (storeM[i] + 1 < 60) {
				storeMEnd.push_back(storeM[i] + 1);
				storeHEnd.push_back(storeH[i]);
			}
			else {

				storeMEnd.push_back(storeM[i] + 1 - 60);
				storeHEnd.push_back(storeH[i] + 1);
			}

		}*/

	}

	for (int i = 0; i < citations.size(); i++) {
		cout << fixed;
		cout.precision(3);


		Start.push_back(storeH[i] * 3600.0 + storeM[i] * 60.0 + storeS[i] * 1.0);

		//cout << storeHEnd[i]  << endl;

		End.push_back(storeHEnd[i] * 3600.0 + storeMEnd[i] * 60.0 + storeSEnd[i] * 1.0);

		cout << Start[i] << endl;
		cout << End[i] << endl;



	}





	int Max = 0;
	int MaxPos = 0;

	for (int i = 0; i < citations.size(); i++) {
		int iFindMax = 1;
		for (int k = 0; k < citations.size(); k++) {

			if (Start[i] - 1 <= Start[k]) {

				if (Start[k] - 1 <= End[i]) {
					iFindMax++;
				}

			}


		}

		if (iFindMax > Max) {
			Max = iFindMax;
			MaxPos = i;
		}




	}

	Max = 0;

	cout << storeT[MaxPos] << endl;
	for (int i = 0; i < storeT[MaxPos] * 1000 + 1000; i++) {
		int iFindMax = 1;
		

		for (int k = 0; k < citations.size(); k++) {




			if (k == MaxPos) {

			}
			else if ((Start[MaxPos] - 1.00 + i * 0.001 < End[k] && Start[MaxPos] - 1.00 + i * 0.001 > Start[k])) {

				iFindMax++;

			}
			else if ((Start[MaxPos] + i * 0.001 > Start[k] && Start[MaxPos] + i * 0.001 < End[k])) {
				iFindMax++;
			}
			else if(Start[MaxPos] + i * 0.001 >= End[k] && (Start[MaxPos] - 1.00 + i * 0.001 <= Start[k]))
			{
				iFindMax++;
			}
			else if (Start[MaxPos] + i * 0.001 <= End[k] && (Start[MaxPos] - 1.00 + i * 0.001 >= Start[k]))
			{
				iFindMax++;
			}
		}

		if (iFindMax > Max) {
			Max = iFindMax;
			cout << i << endl;
		}



	}










	int answer = Max;
	return answer;
}


int main()
{

	/*std::vector<string> temp = { "2016-09-15 20:59:57.421 0.351s",
"2016-09-15 20:59:58.233 1.181s",
"2016-09-15 20:59:58.299 0.8s",
"2016-09-15 20:59:58.688 1.041s",
"2016-09-15 20:59:59.591 1.412s",
"2016-09-15 21:00:00.464 1.466s",
"2016-09-15 21:00:00.741 1.581s",
"2016-09-15 21:00:00.748 2.31s",
"2016-09-15 21:00:00.966 0.381s",
"2016-09-15 21:00:02.066 2.62s"

};

	cout << solution(temp);*/

	cin >> A;
	cin >> B;

	for (int i = 0; i < A; i++) {
		for (int k = 0; k < A; k++) {
			int temp;
			cin >> temp;
			MatA[i][k] = temp;

		}
		Ans[i][i] = 1;

	}




	MatC = Start(B);



	for (int i = 0; i < A; i++) {
		for (int k = 0; k < A; k++) {
			cout << MatC[i][k] << " ";
		}
		cout << endl;
	}


}
