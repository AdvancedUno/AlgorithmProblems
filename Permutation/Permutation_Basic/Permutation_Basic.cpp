#include <iostream>
#include <string>
#include <vector>

#include <math.h>


using namespace std;

string sInput = "ABCDE";
int cnt = 0;
int Solve(bool iSaveInfo[5], string sString) {
	if (sString.size() == sInput.size()) {
		cout << sString << endl;
		cnt++;
	}

	for (int i = 0; i <= sizeof(iSaveInfo) / sizeof(bool); i++) {
		if (iSaveInfo[i] == 0) {
			string sTemp = sString;
			iSaveInfo[i] = 1;
			sTemp = sString + sInput[i];
			Solve(iSaveInfo, sTemp);
			iSaveInfo[i] = 0; 
		}
	}
	return 0;


}

int main()
{
	bool iSaveInfo[5] = { 0, };
	char cString[5];
	string sIn = "";
	

	for (int i = 0; i < sInput.length(); i++) {
		cString[i] = sInput[i];
	}

	Solve(iSaveInfo, sIn);


	cout << cnt << endl;
	

	


}

