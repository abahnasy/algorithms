#include <stdio.h>
#include <iostream>
#include <vector>

#include "Determinant.h"


using namespace std;



int main () {



    vdd mat1 = {{1, 0, 2, -1},
                     {3, 0, 0, 5},
                     {2, 1, 4, -3},
                     {1, 0, 5, 0}
    };

    vdd mat = {{1,2}, {3,4}};

    cout << get_determinant(mat1, 4);





    return 0;
}

