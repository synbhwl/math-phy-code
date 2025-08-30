#include <iostream>
#include <cmath>
#include <utility>

using namespace std;

// this is in m/s sq.
const double gravity = 9.80665;

pair<double, double> find_position(double vx, double vy, double t){
    double x;
    double y;

    // this is plugged from the formula
    x = vx * t;
    y = (vy * t) - 0.5 * (gravity * pow(t, 2));

    return {x, y};
}

int main(){
    // i looked up what i need, turns out there are 4 major inputs
    // v0 for initial velocity, angle for launch angle
    // gravity is self-evident, and p means position
    double v0 = 10;
    double angle = 45 * M_PI/180.0;
    // double p;

    // then we need velocity broken into components
    // vx for horizontal speed and vy for initial vertical speed
    double vx = v0 * cos(angle);
    double vy = v0 * sin(angle);

    pair <double, double> result = find_position(vx, vy, 0.5);
    cout << "(" << result.first << ", " << result.second << ")" << endl;

    // i wanted to see the maximum time in flight
    cout << "maximum time in flight: " << (2 * vy)/gravity << endl;

    return 0;
}