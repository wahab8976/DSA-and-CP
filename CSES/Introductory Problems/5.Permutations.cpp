#include<iostream>
#include<string>
#include<vector>

using namespace std;
/*
Trick:
    Arrange even fist and odd later.
    This sequence will guarantee that there's never a difference of 1 between 2 elements
*/
int main() {
	
	int n = 0;
	cin >> n;

	if (n == 1){
        cout << n << "\n";
        return 0;
    }	

	if (n == 2 || n == 3){
        cout << "NO SOLUTION\n";
        return 0;
    }	


	for (int i = 2; i <= n; i += 2)	cout << i << " ";
	for (int i = 1; i <= n; i += 2)	cout << i << " ";

	cout << "\n";

}