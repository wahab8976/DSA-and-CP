#include<iostream>
#include<string>
using namespace std;


// Sliding Window Approach

int main() {
	string s = "";
	cin >> s;
	int left = 0;
	int right = 0;

	int mx = 0;
	int len = 0;
	int n = s.size();

	while (left < n && right < n)
	{
		if (s[left] == s[right]) {
			len++;
			mx = max(mx, len);
			right++;    // Keep expanding window
		}
		else {
			len = 0;
			left = right;   // Shrink to make new window, once new character is here
		}
		
	}

	cout << mx;
}