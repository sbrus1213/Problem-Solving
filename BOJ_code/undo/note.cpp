#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <queue>
#include <deque>
#include <map>
#include <set>
#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
using namespace std;

namespace geometry {
    const double pi = 3.1415926535;
    const double eps = 1e-8;
    struct Point {
        int x, y;
        Point (int xx, int yy): x(xx), y(yy) {}
        // 
        Point operator + (const Point& rhs) { return Point(x + rhs.x, y + rhs.y); }
        Point operator - (const Point& rhs) { return Point(x - rhs.x, y - rhs.y); }
        Point operator * (const int& rhs) { return Point(x * rhs, y * rhs); }
        Point operator / (const int& rhs) { return Point(x / rhs, y / rhs); }
        bool operator < (const Point& rhs) { return x == rhs.x ? y < rhs.y : x < rhs.x; }
        // inner product
        int inner (const Point& rhs) { return x * rhs.x + y * rhs.y; }
        // outer product
        int cross (const Point &rhs) { return x * rhs.y - y * rhs.x; }
    };
    struct Line {
        Point s, e;
        Line (Point ss, Point ee): s(ss), e(ee) {}
    };

    // ccw
    // counter-clock-wise : 1
    // parallel : 0
    // clock-wise : -1 
    int ccw (Point a, Point b, Point c) {
        Point ab = b - a, bc = c - b;
        int res = ab.cross(bc);
        if (res > 0) return 1;
        else if (res == 0) return 0;
        else return -1;
    }
    int ccw (Line a, Line b) {
        Point ab = a.e - a.s, bc = b.e - b.s;
        int res = ab.cross(bc);
        if (res > 0) return 1;
        else if (res == 0) return 0;
        else return -1;
    }
    // intersect
    int intersect (Line a, Line b) {

    }

    // Convex Hull - graham scan
    vector<Point> P;
    vector<int> Convex_Hull;
    void graham_scan(int n) {
        swap(P[0], *min_element(P.begin(), P.end()));

        sort(P.begin() + 1, P.end(), [&](Point a, Point b) {
            if (ccw(P[0], a, b) == 0)
                return a.x - P[0].x == a.y - P[0].y
                    ? a.y - P[0].y < b.y - P[0].y : a.x - P[0].x < b.x - P[0].x;
            else
                return ccw(P[0], a, b) == 1;
        });

        for (int i = 0; i < n; ++i) {
            while (Convex_Hull.size() >= 2) {
                int sz = Convex_Hull.size();
                if (ccw(P[Convex_Hull[sz - 2]], P[Convex_Hull[sz - 1]], P[i]) < 1)
                    Convex_Hull.pop_back();
                else break;
            }
		    Convex_Hull.push_back(i);
	    }
    }
}