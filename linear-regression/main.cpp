#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

double find_average(vector<double> data){
    double total = 0;
    for(double num: data){
        total += num;
    }

    return total/double(data.size());
}

vector<double> find_deviations(vector<double> data, double avg){
    vector<double> deviations;

    for (double num: data){
        deviations.push_back(num - avg);
    }

    return deviations;
}

double find_slope(vector<double> x_dev, vector<double> y_dev){
    // i have to assume here that both arrays have same length to keep things simple here
    // so i will find the len of only one array

    int len = x_dev.size();

    // now i will simultaneous.. whats the spelling of this
    // i will go thru both at the same time

    double numerator = 0; // basically summation of x_dev * y_dev
    double denominator = 0; // and the summation of each element of x_dev squared

    int i = 0;
    while (i < len){
        numerator += x_dev[i] * y_dev[i];
        denominator += x_dev[i] * x_dev[i];
        i++;
    }

    return numerator/denominator;
}

void write_points(vector<double> x, vector<double> y, double m, double b){
    fstream pointfile("linear-regression/points.txt", ios::out);

    if(pointfile.is_open()){
        for(int i = 0; i < x.size(); i++){
            pointfile << x[i] << " " << y[i] << endl;
        }
    } else{
        cerr << "points file not opened" << endl;
    }

    pointfile.close();

    fstream eqnfile("linear-regression/eqn.txt", ios::out);
    
    if(eqnfile.is_open()){
        eqnfile << m << " " << b << endl;
    }else{
        cerr << "eqn file not opened" << endl;
    }

    eqnfile.close();
}

int main(){
    // i am using this as my first dataset just to get this working
    vector<double> x = {
    1.2,  3.5,  2.1,  7.8,  5.3,  9.4,  4.0,  11.2, 8.7,  13.5,
    6.0,  15.1, 10.3, 18.2, 12.4, 20.0, 14.6, 22.3, 16.7, 25.1,
    19.0, 27.4, 21.5, 29.6, 23.8, 31.0, 26.2, 33.4, 28.5, 35.6,
    30.7, 38.0, 32.9, 40.2, 34.5, 42.1, 36.8, 44.3, 39.0, 46.5,
    41.2, 48.0, 43.4, 50.1, 45.6, 52.3, 47.8, 54.0, 50.2, 55.0
    };

    vector<double> y = {
    18.3, 12.1, 25.4, 30.2, 19.8, 42.6, 15.3, 48.9, 38.7, 55.1,
    32.0, 60.2, 45.6, 65.3, 49.8, 70.1, 52.4, 75.6, 58.9, 80.3,
    62.1, 85.0, 68.7, 90.2, 72.4, 95.1, 80.3, 98.6, 85.2, 105.4,
    92.1, 110.0, 95.3, 115.2, 100.1, 118.3, 105.6, 122.4, 110.2, 125.7,
    115.3, 130.0, 120.1, 135.2, 128.4, 139.6, 132.8, 142.0, 145.3, 148.7
    };

    // finding mean of both
    double avg_x = find_average(x);
    double avg_y = find_average(y);

    // lets find the deviations now
    vector<double> x_dev = find_deviations(x, avg_x);
    vector<double> y_dev = find_deviations(y, avg_y);

    // now gotta find the slope, lets goo
    double m = find_slope(x_dev, y_dev);

    // now the intercept b
    double b = avg_y - (m * avg_x);

    write_points(x, y, m, b);
    cout << "the equation is therefore ig: y = " << m << "x + " << b << endl;
    return 0;
}