//
// Created by Ahmed Bahnasy on 14.08.20.
//

#ifndef ALGORITHMS_JARVISMARCHCONVEXHULL_H
#define ALGORITHMS_JARVISMARCHCONVEXHULL_H

#include <vector>
#include <unordered_set>
using namespace std;


struct Point {
    int x, y;
    bool operator==(const Point& rhs) const{
        return (this->x == rhs.x) && (this->y == rhs.y);
    }
};

// class for hash function
class MyHashFunction {
public:
    // id is returned as hash function
    size_t operator()(const Point& t) const {
        return t.x + t.y;
    }
};


int cross_product(Point p1, Point p2, Point p3) {
    // +ve if p3 on left on line p1p2, 0 if collinear else -ve
    int x1 = p1.x - p2.x;
    int y1 = p1.y - p2.y;

    int x2 = p1.x - p3.x;
    int y2 = p1.y - p3.y;

    return x1*y2 - x2*y1;

}

int get_far_point(Point p1, Point p2, Point p3) {
    // +ve if p3 is far more than p1
    int x1 = p1.x - p2.x;
    int y1 = p1.y - p2.y;

    int x2 = p1.x - p3.x;
    int y2 = p1.y - p3.y;

    return (x2*x2+y2*y2) - (x1*x1+y1*y1);
}

vector<Point> convex_hull(vector<Point> points) {

    Point start = points[0];
    for (int i = 1; i < points.size(); ++i) {
        if(points[i].x < start.x) {
            start = points[i];
        }
    }
    vector<Point> collinear_set;
    unordered_set<Point, MyHashFunction> result;
    result.insert(start);
    Point current = start;

    while(true) {
        Point next_target = points[0];
        for (int i = 1; i < points.size(); ++i) {
            if (points[i] == current)
                continue;
            int cross_product_val = cross_product(current, next_target, points[i]);
            if(cross_product_val > 0) {
                next_target = points[i];
                collinear_set.clear();
            } else if (cross_product_val == 0) {
                int distance = get_far_point(current, next_target, points[i]);
                if(distance > 0) {
                    collinear_set.push_back(next_target);
                    next_target = points[i];
                } else {
                    collinear_set.push_back(points[i]);
                }
            } else {
                // Do nothing, check the next point
            }

        }



        for (Point p: collinear_set) {
            result.insert(p);
        }

        if(next_target == start)
            break;

        result.insert(next_target);
        current = next_target;
    }


    vector<Point> res;
    res.insert(res.end(), result.begin(), result.end());
    return res;



}


#endif //ALGORITHMS_JARVISMARCHCONVEXHULL_H
