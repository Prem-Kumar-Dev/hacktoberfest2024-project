// A   recursive implementation of LCS problem
#include <bits/stdc++.h>
using namespace std;

 
int lcs(string &S1, string &S2, int m, int n){
     
    if (m == 0 || n == 0)
        return 0;

     
    if (S1[m - 1] == S2[n - 1])
         
        return 1 + lcs(S1, S2, m - 1, n - 1);

    else {
        
        return max(lcs(S1, S2, m, n - 1), lcs(S1, S2, m - 1, n));
    }
}

int main() {
    string S1 = "AGGTAB";
    string S2 = "GXTXAYB";
    int m = S1.size();
    int n = S2.size();

    cout << "Length of LCS is " << lcs(S1, S2, m, n);

    return 0;
}
