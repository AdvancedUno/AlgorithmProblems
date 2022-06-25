#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

int A, B, C;

long long int Devide(long long int Val) {

	long long int temp = 1;
	int rest = 1;

	if (Val == 1)return A % C;
	if (Val > 2) {
		rest = Val % 2;
		temp = Val / 2;
	}


	long long int num = Devide(temp);

	if (Val % 2 == 0) return num * num % C;

	else {
		return (num * num * A % C) % C;
	}

	



	return num;




}


int main()
{


	

	cin >> A;
	cin >> B;
	cin >> C;
	

	cout << Devide(B) << endl;











}
