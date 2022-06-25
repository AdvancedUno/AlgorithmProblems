#include <iostream>
#include <math.h> 
#include <algorithm>
#include <vector>

using namespace std;

int A, B;
long long int C = 1000000007;
//long long int save[4000000][4000000] = { 0, };

long long int Devide(long long int num, long long int Val) {



	if (Val == 0 || Val == num)return 1;



	long long int num1 = Devide(num - 1, Val - 1) % C;
	long long int num2 = Devide(num - 1, Val) % C;


	return (num1 + num2)%C;


}







int main()
{




	cin >> A;
	cin >> B;



	cout << Devide(A, B) << endl;





}
