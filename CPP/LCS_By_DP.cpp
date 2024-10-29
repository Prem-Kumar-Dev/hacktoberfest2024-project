// C++ implementation of Top-Down DP
// of LCS problem
#include <bits/stdc++.h>
using namespace std;

 
int lcs(string &S1, string &S2, int m, int n, vector<vector<int>> &memo) {

     
    if (m == 0 || n == 0)
        return 0;

    
    if (memo[m][n] != -1)
        return memo[m][n];

    
    if (S1[m - 1] == S2[n - 1])
        return memo[m][n] = 1 + lcs(S1, S2, m - 1, n - 1, memo);

     
    return memo[m][n] = max(lcs(S1, S2, m, n - 1, memo), lcs(S1, S2, m - 1, n, memo));
}

int main() {
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";

    int m = S1.length();
    int n = S2.length();
    vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));

    cout << "Length of LCS is " << lcs(S1, S2, m, n, memo) << endl;

    return 0;
}
