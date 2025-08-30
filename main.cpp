#include <iostream>
#include <vector>

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

int main(){
    // i am using this as my first dataset just to get this working
    vector<double> x = {
        1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0,
        11.0, 12.0, 13.0, 14.0, 15.0, 16.0, 17.0, 18.0, 19.0, 20.0,
        21.0, 22.0, 23.0, 24.0, 25.0, 26.0, 27.0, 28.0, 29.0, 30.0,
        31.0, 32.0, 33.0, 34.0, 35.0, 36.0, 37.0, 38.0, 39.0, 40.0,
        41.0, 42.0, 43.0, 44.0, 45.0, 46.0, 47.0, 48.0, 49.0, 50.0
    };

    vector<double> y = {
        2.2, 3.8, 6.1, 7.7, 9.9, 11.8, 14.3, 15.8, 17.6, 20.1,
        22.2, 23.9, 26.0, 28.1, 29.8, 32.2, 33.7, 35.9, 38.2, 39.7,
        41.9, 43.6, 46.1, 48.2, 49.9, 52.1, 53.6, 56.1, 58.2, 60.0,
        61.7, 63.8, 66.2, 68.3, 70.1, 72.0, 74.2, 76.0, 78.1, 80.0,
        81.9, 83.7, 86.2, 88.0, 90.0, 92.2, 94.0, 96.1, 98.2, 99.9
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

    cout << "the equation is therefore ig: y = " << m << "x + " << b;
    return 0;
}