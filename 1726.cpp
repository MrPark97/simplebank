#include <bits/stdc++.h>
using namespace std;

typedef struct Point {
    long long x, y;
} Point;

bool comparePoints(Point p_first, Point p_second)
{
    return ((p_first.X < p_second.X) || (p_first.X == p_second.X && p_first.Y < p_second.Y));
}

int main() {
    long long n;
    cin >> n;
    vector<Point> points(n);
    for(int i=0; i<n; i++) {
        cin >> points[i].x >> points[i].y;
    }
    sort(points.begin(), points.end(), comparePoints);
    long long ans = 0;
    for(long long i=1; i<n; i++) {
        ans += (x[i]-x[i-1]) * (i+1) * (n-i-1) * 2;
        ans += (y[i]-y[i-1]) * (i+1) * (n-i-1) * 2;
    }
    ans /= (n * (n-1));
    cout << ans;
    return 0;
}