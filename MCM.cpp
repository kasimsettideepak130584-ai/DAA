#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Function to find the most efficient way to multiply matrix chain
int matrixChainOrder(const vector<int>& p) {
    int n = p.size() - 1; // Number of matrices
    
    // dp[i][j] stores the minimum number of scalar multiplications needed 
    // to compute the matrix A[i]...A[j]
    vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

    // l is chain length
    for (int l = 2; l <= n; l++) {
        for (int i = 1; i <= n - l + 1; i++) {
            int j = i + l - 1;
            dp[i][j] = INT_MAX;
            
            for (int k = i; k <= j - 1; k++) {
                // cost = cost/splits + cost of multiplying resulting matrices
                int cost = dp[i][k] + dp[k + 1][j] + p[i - 1] * p[k] * p[j];
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    // Return minimum multiplications needed for matrix 1 to n
    return dp[1][n];
}

int main() {
    int n;
    cout << "Enter the number of matrices: ";
    cin >> n;

    // There are n matrices, so we need n + 1 dimension values
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
