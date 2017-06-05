#include <cmath>
#include <cstdio>
#include <vector>
#include <string.h>
#include <iostream>
#include <algorithm>

using namespace std;

typedef unsigned long long UDLONG;

bool IsPrime(int number);
void ArrPrime(vector<int>& arr, int n_prime);
UDLONG GetWays(vector<int>& c, int m, int n);
int GetLocated(vector<int>& arr, int r);

//this function same with problem "The coin change problem"
UDLONG GetWays(vector<int>& c, int m, int n){

	UDLONG table[n+1];
	memset(table, 0, sizeof(table));
	table[0] = 1;
	for (int i = 0; i<m; ++i)
		for (UDLONG j = c[i]; j <= n; ++j){
			table[j] += table[j - c[i]];
		}
	return table[n];
}

bool IsPrime(int number){
	int num_sqrt = floor(sqrt(number));
	for (int i = 2; i <= num_sqrt; ++i)
		if (number%i == 0) return false;
	return true;
}

//arr is content prime number from 1 to 1000
void ArrPrime(vector<int>& arr, int n_prime){
    arr.push_back(2);
	for (int i_p = 3; i_p <= n_prime; i_p+=2)
		if (IsPrime(i_p)) arr.push_back(i_p);
}

int GetLocated(vector<int>& arr, int r){
	if (r >= 997) return arr.size();
    int located = 0;
	for(;arr[located]<=r;++located)
        continue;
	return located;
}

int main() {
	int T;
	cin >> T;
	vector<int> r(T);
	vector<int> arrPrime;
	for (int i_r = 0; i_r < T; ++i_r)
		cin >> r[i_r];
	ArrPrime(arrPrime, 1000);
	for (int i = 0; i < T; ++i)
	{
		int arr_size = GetLocated(arrPrime, r[i]);
		cout << GetWays(arrPrime, arr_size, r[i]) << endl;
	}
	return 0;
}