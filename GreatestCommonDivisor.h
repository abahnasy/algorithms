//
// Created by Ahmed Bahnasy on 15.08.20.
//

#ifndef ALGORITHMS_GREATESTCOMMONDIVISOR_H
#define ALGORITHMS_GREATESTCOMMONDIVISOR_H

int gcd (int a, int b) {
    if (b == 0) {
        return a;
    } else {
        return (b%a, a);
    }
}

#endif //ALGORITHMS_GREATESTCOMMONDIVISOR_H
