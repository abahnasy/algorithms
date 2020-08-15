//
// Created by Ahmed Bahnasy on 15.08.20.
//

#ifndef ALGORITHMS_DETERMINANT_H
#define ALGORITHMS_DETERMINANT_H

#include <vector>

using namespace std;

typedef vector<vector<double>> vdd;
typedef vector<double> vd;

void co_factor(vdd& mat, vdd& temp, int pos_x, int pos_y, int n) {
    int i = 0, j = 0;
    for (int row = 0; row < n; ++row) {
        for (int col = 0; col < n; ++col) {
            if(row!= pos_x && col != pos_y) {
                temp[i][j++] = mat[row][col];
                if (j == n-1) { // if row is filled
                    j = 0;
                    i++;
                }
            }
        }
    }
}
double get_determinant(vdd& mat, int n) {
    if(n == 1) // base case
        return mat[0][0];
    double result = 0; //result
    int sign = 1;
    vdd temp(mat.size(), vd(mat.size()));
    for (int f = 0; f< n; ++f) {
        co_factor(mat, temp, 0, f, n);
        result += sign * mat[0][f] * get_determinant(temp, n-1);
        sign = -sign;
    }
    return result;
}

#endif //ALGORITHMS_DETERMINANT_H
