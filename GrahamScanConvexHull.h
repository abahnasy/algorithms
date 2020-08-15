//
// Created by Ahmed Bahnasy on 15.08.20.
//

#ifndef ALGORITHMS_GRAHAMSCANCONVEXHULL_H
#define ALGORITHMS_GRAHAMSCANCONVEXHULL_H

// Time Complexity: O(nlogn)

#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct Point {
    int x, y;

};

Point p0;

Point get_second_top(stack<Point>& s) {
    Point temp = s.top(); s.pop();
    Point res = s.top();
    s.push(temp);
    return res;
}



int cross_product(Point p1, Point p2, Point p3) {
    // +ve if p3 on left on line p1p2, 0 if collinear else -ve
    int x1 = p1.x - p2.x;
    int y1 = p1.y - p2.y;

    int x2 = p1.x - p3.x;
    int y2 = p1.y - p3.y;

    return x1*y2 - x2*y1;

}

int sq_dist(Point p1, Point p2) {
    return ((p2.x - p1.x)*(p2.x - p1.x)) + ((p2.y - p1.y)*(p2.y - p1.y));
}

int cmp (const void* vp1, const void* vp2) {
    Point* p1 = (Point*) vp1;
    Point* p2 = (Point*) vp2;
    int val = cross_product(p0, *p1, *p2);
    if(val == 0) {
        return (sq_dist(p0, *p2) > sq_dist(p0,*p1))? -1 : 1;
    }
    return (val > 0)? -1: 1;
}



vector<Point> convex_hull (vector<Point> points) {

    vector<Point> result;
    int y_min = points[0].y, min_idx = 0;
    for (int i = 1; i < points.size(); ++i) {
        if(points[i].y < y_min || (y_min == points[i].y && points[i].x < points[min_idx].x))
            y_min = points[i].y, min_idx = i;
    }
    p0 = points[min_idx];
    swap(points[0], points[min_idx]);
    qsort(&points[1], points.size()-1, sizeof(Point), cmp);

    //modify points by removing the duplicate angles
    int modified_n = 1;
    for (int i = 1; i < points.size(); ++i) {
        while (i < points.size()-1 && cross_product(p0, points[i], points[i+1]) == 0)
            i++; //get the farthest point
        points[modified_n] = points[i];
        modified_n++;

    }
    if (modified_n < 3)
        return result; // empty list

    stack<Point> s;
    s.push(p0); s.push(points[1]); s.push(points[2]);
    for (int i = 3; i < modified_n; ++i) {
        while(cross_product(get_second_top(s), s.top(), points[i]) <= 0) { // not making left turn
            s.pop();
        }
        s.push(points[i]);
    }



    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }

    return result;
}


#endif //ALGORITHMS_GRAHAMSCANCONVEXHULL_H
