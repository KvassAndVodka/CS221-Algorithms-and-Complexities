#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct Point {
    int x, y;
    Point(int x, int y) : x(x), y(y) {}
};

bool compareX(const Point& p1, const Point& p2) {
    return p1.x < p2.x;
}

bool compareY(const Point& p1, const Point& p2) {
    return p1.y < p2.y;
}

double distance(const Point& p1, const Point& p2) {
    return sqrt(pow(p1.x - p2.x, 2) + pow(p1.y - p2.y, 2));
}

double bruteForce(vector<Point>& points, int left, int right) {
    double minDist = numeric_limits<double>::max();
    for (int i = left; i <= right; i++) {
        for (int j = i + 1; j <= right; j++) {
            minDist = min(minDist, distance(points[i], points[j]));
        }
    }
    return minDist;
}

double closestUtil(vector<Point>& points, int left, int right) {
    if (right - left + 1 <= 3) {
        return bruteForce(points, left, right);
    }

    int mid = left + (right - left) / 2;
    double leftMinDist = closestUtil(points, left, mid);
    double rightMinDist = closestUtil(points, mid + 1, right);
    double minDist = min(leftMinDist, rightMinDist);

    vector<Point> strip;
    for (int i = left; i <= right; i++) {
        if (abs(points[i].x - points[mid].x) < minDist) {
            strip.push_back(points[i]);
        }
    }

    sort(strip.begin(), strip.end(), compareY);

    for (int i = 0; i < strip.size(); i++) {
        for (int j = i + 1; j < strip.size() && (strip[j].y - strip[i].y) < minDist; j++) {
            minDist = min(minDist, distance(strip[i], strip[j]));
        }
    }

    return minDist;
}

double closestPair(vector<Point>& points) {
    sort(points.begin(), points.end(), compareX);
    return closestUtil(points, 0, points.size() - 1);
}

int main() {
    vector<Point> points = {{2, 3}, {12, 30}, {4, 1}, {7, 16}, {5, 5}};
    cout << "Given points: ";
    for (const auto& p : points) {
        cout << "(" << p.x << ", " << p.y << ") ";
    }
    cout << endl;

    double minDist = closestPair(points);
    cout << "Closest pair: ";
    for (const auto& p : points) {
        for (const auto& q : points) {
            if (distance(p, q) == minDist && p.x < q.x) {
                cout << "(" << p.x << ", " << p.y << ") and (" << q.x << ", " << q.y << ") ";
            }
        }
    }
    cout << "with distance = " << minDist << endl;

    return 0;
}