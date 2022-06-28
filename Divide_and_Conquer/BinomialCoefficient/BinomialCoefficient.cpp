#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

int A, B;
long long int C = 1000000007;
//long long int save[4000000][4000000] = { 0, };

long long int Factorial(long long int num, long long int Val) {

	long long int temp = 1;

	for (int i = Val; i <= num; i++) {
		temp = temp * i%C;
	}

	return temp;



}

long long int Devide(long long int num, long long int Val) {



	if (Val == 1)return num%C;

	long long int tempVal = Devide(num, Val / 2)%C;

	if (Val % 2 == 0) {
		return (tempVal * tempVal)%C;
	}

	else {
		return (tempVal * tempVal) % C * num % C;
	}


}







int main()
{




	cin >> A;
	cin >> B;





	cout << Factorial(A,A-B+1)%C * Devide(Factorial(B,1), C-2)%C << endl;





}
