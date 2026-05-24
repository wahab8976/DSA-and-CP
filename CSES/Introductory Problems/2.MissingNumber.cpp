#include<iostream>
using namespace std;

int main()
{
    int n;
    cin >> n;

    long long sum = 0;
    int a = 0;
    for (int i = 0; i < n - 1; i++) {
        cin >> a;
        sum += a;
    }
	// Formula for first n natural numbers: n * (n + 1) / 2
	long long total = (long long) n * (n + 1) / 2;
	long long ans = (long long) total - sum;
    cout << ans;
}

