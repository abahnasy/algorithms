//
// Created by Ahmed Bahnasy on 16.08.20.
//

#ifndef ALGORITHMS_KNAPSACK_H
#define ALGORITHMS_KNAPSACK_H

#include <vector>
using namespace std;

int knapsack_recursion (vector<int> weights, vector<int> values, int n, int w) {

    //base case
    if(n == 0 || w == 0) {
        return 0;
    }

    if(weights[n-1] > w) {
        return knapsack_recursion(weights, values, n-1, w);
    } else {
        return max(values[n-1] + knapsack_recursion(weights, values, n-1, w-weights[n-1]), knapsack_recursion(weights, values, n-1, w));
    }


}

int knapsack_DP(vector<int> weights, vector<int> values, int w) {
    int n = weights.size();
    vector<vector<int>> DP (n+1, vector<int>(w+1, 0));
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= w; ++j) {
            if(weights[i-1]>j)
                DP[i][j] = DP[i-1][j];
            else {
                DP[i][j] = max(values[i-1]+DP[i-1][j-weights[i-1]],
                        DP[i-1][j]);
            }
        }
    }




    //print the values taken
    int i=n,j=w;
    while(i > 0){
        while (j > 0) {
            if(DP[i][j] != DP[i-1][j]) {
                cout << i << " ";
                j=j-weights[i-1];
            }
            break;
        }
        i =i-1;
    }
    cout << "\n";
    return DP[n][w];
}

#endif //ALGORITHMS_KNAPSACK_H
