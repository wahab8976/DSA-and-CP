#include <bits/stdc++.h> // Includes all standard libraries
using namespace std;

// 1D conversion formula: (row * total_cols) + col

// ==========================================================
// TYPE ALIASES & MACROS
// ==========================================================
using ll = long long;
using vi = vector<int>;
using pii = pair<int, int>;
#define all(x) (x).begin(), (x).end() // Quick full-range selection

// ==========================================================
// CONSTANTS
// ==========================================================
const int MOD = 1e9 + 7;
const int INF = 1e9;       // Safe infinity for ints
const ll LL_INF = 1e18;    // Safe infinity for long longs

// ==========================================================
// GRID TRAVERSAL UTILITIES
// ==========================================================
const int drow[] = {-1, 0, 1, 0};
const int dcol[] = {0, 1, 0, -1};

const int drow[] = {-1, -1, 0, 1, 1, 1, 0, -1};
const int dcol[] = {0, 1, 1, 1, 0, -1, -1, -1};

inline bool isValid(int row, int col, int rowCount, int colCount) {
    return row >= 0 && row < rowCount && col >= 0 && col < colCount;
}


// ==========================================================
// MAIN LOGIC
// ==========================================================
void solve() {
    // Write your problem-specific code here
    
}

int main() {
    // OPTIMIZE STANDARD I/O OPERATIONS (Prevents TLE)
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t = 1;
    // cin >> t; // Uncomment this line if the problem has multiple test cases
    while (t--) {
        solve();
    }
    
    return 0;
}