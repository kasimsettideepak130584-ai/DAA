#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1; 
    
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k <= j - 1; k++) {
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[1][n];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    vector<int> dimensions(n + 1);
    
    cout << "Enter the dimensions (total " << n + 1 << " values):\n";
    for (int i = 0; i <= n; i++) {
        cout << "Dimension " << i << ": ";
        cin >> dimensions[i];
    }

    int minMultiplications = matrixChainOrder(dimensions);

    cout << "\nMinimum number of scalar multiplications is: " << minMultiplications << endl;

    return 0;
}
