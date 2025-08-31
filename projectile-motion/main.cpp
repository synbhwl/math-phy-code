#include <iostream>
#include <cmath>
#include <utility>
#include <fstream>

using namespace std;

//this is in m/s sq.
const double gravity = 9.80665;

pair<double, double> find_position(double vx, double vy, double t){
    double x;
    double y;

    //this is plugged from the formula
    x = vx * t;
    y = (vy * t) - 0.5 * (gravity * pow(t, 2));

    return {x, y};
}

void write_all_positions(double maxt, double vx, double vy){
    fstream ptnfile("positions.txt", ios::out);

    if(ptnfile.is_open()){
        for (double i=0; i <= maxt; i += 0.01){
            pair<double, double> p = find_position(vx, vy, i);
            ptnfile << p.first << " " << p.second << endl;
        }
    }else{
        cerr << "file not opened" << endl;
    }
    ptnfile.close();
}

int main(){
    double v0 = 10;
    double angle = 45 * M_PI/180.0;

    //vx for horizontal speed and vy for initial vertical speed
    double vx = v0 * cos(angle);
    double vy = v0 * sin(angle);

    double maxt = (2 * vy)/gravity;
    write_all_positions(maxt, vx, vy);

    cout << "successfull" << endl;
    return 0;
}