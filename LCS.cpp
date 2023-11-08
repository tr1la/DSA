#include <bits/stdc++.h>
using namespace std;

int LCS_length(vector<int>& a, vector<int>& b) {
    int m = a.size();
    int n = b.size();
    vector<vector<int>> lcs(m+1, vector<int>(n+1, 0));
    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (a[i-1] == b[j-1]) {
                lcs[i][j] = 1 + lcs[i-1][j-1];
            } else {
                lcs[i][j] = max(lcs[i-1][j], lcs[i][j-1]);
            }
        }
    }
    return lcs[m][n];
}

int main() {
    vector<int> a = {1, 2, 3, 4, 5, 6};
    vector<int> b = {3, 4, 5, 3};
    int lcs_length = LCS_length(a, b);
    cout << lcs_length;
}