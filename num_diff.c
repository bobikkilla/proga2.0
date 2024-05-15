#include <math.h>
#include <stdio.h>

double function(double x, double y) {
    return (cos(y) / 2*cos(x)) + x * y;
}   // a = -1, b = 1, y0 = 0

double max(double a, double b);
double min(double a, double b);
int innacuracy_condition(double y_n, double y_2n, const double eps, int n);

double eiler_count(double x,double y,int n, int b);
double eiler_method(const float eps, float y0, int a, int b);

double eiler_method_corrected(const float eps, float y0, int a, int b);
double eiler_corrected_count(double x,double y,int n, int b);

double runge_kutt_count(double x, double y, int n, int b);
double runge_kutt_method(const float eps, float y0, int a, int b);

int main() {
    const float eps = 1e-9;
    float y0 = 0;
    int a = -1; 
    int b = 1;
    int n;
    printf("y(Eiler method) = %10.8lf\n", eiler_method(eps, y0, a, b)); // not working with eps < 0.00001
    printf("y(Eiler Corrected method) = %10.8lf\n", eiler_method_corrected(eps, y0, a, b)); // mid working
    printf("y(runge-kutt method) = %10.8lf\n", runge_kutt_method(eps, y0, a, b)); // the most working method
    return 0;
}

double max(double a, double b) {
    double to_return = a;
    if (to_return < b) {
        to_return = b;
    }
    return to_return;
} // max function for innacuracy condition

double min(double a, double b) {
    double to_return = a;
    if (to_return > b) {
        to_return = b;
    }
    return to_return;
} // min function for innacuracy condition

int innacuracy_condition(double y_n, double y_2n, const double eps, int n) {
    int status = 1;
    if(max(y_n,y_2n) - min(y_n,y_2n) <= eps) {
        status = 0;
    }
    return status;
}   // innacuracy condition depending on eps value
 
double eiler_method(const float eps, float y0, int a, int b) {   // just iterating bruh
    int n = 20; 
    double y = y0;
    double x = a;
    while(innacuracy_condition(eiler_count(x, y, n, b),eiler_count(x, y, 2*n, b), eps, n)) {   
        printf("%d  %.20lf     %.20lf\n",n, eiler_count(x, y, n, b),eiler_count(x, y, 2*n, b));
        n += 1;
    }   // looking for correct conditions
    y = eiler_count(x, y, n, b); 
    return y;
}   // eiler method

double eiler_count(double x,double y,int n, int b) {
    double h = (b-x) / n;
    
    while(x <= b) {
    y = y + h * function(x, y);
    x += h;
    }

    return y;
}   // count depending on itterations value

double eiler_method_corrected(const float eps, float y0, int a, int b) {
    int n = 20; 
    double y = y0;
    double x = a;

    while(innacuracy_condition(eiler_corrected_count(x, y, n, b), eiler_corrected_count(x, y, 2*n, b), eps, n)) {   
        printf("%d  %.20lf     %.20lf\n",n, eiler_corrected_count(x, y, n, b),eiler_corrected_count(x, y, 2*n, b));
        n += 1;
    }   // looking for correct conditions
    y = eiler_corrected_count(x, y, n, b); 
    return y;
}   // eiler method corrected(maybe better)

double eiler_corrected_count(double x,double y,int n, int b) {
    double h = (b-x) / n;
    
    while(x <= b) {
    y = y + (h/2) * (function(x, y) + function(x+h,y + (h * function(x, y))));
    x += h;
    }
    return y;
} // eiler corrected count idk

double runge_kutt_method(const float eps, float y0, int a, int b) {
    int n = 20; 
    double y = y0;
    double x = a;
    while(innacuracy_condition(runge_kutt_count(x, y, n, b),runge_kutt_count(x, y, 2*n, b), eps, n)) {   
        printf("%d  %.20lf     %.20lf\n",n, runge_kutt_count(x, y, n, b),runge_kutt_count(x, y, 2*n, b));
        n += 1;
    }   // looking for correct conditions
    y = runge_kutt_count(x, y, n, b);
    return y;
}   // runge-kutt is the best method for num diffe

double runge_kutt_count(double x, double y, int n, int b) {
    double h = (b-x) / n;

    while(x <= b) {
    double k1 = function(x, y);
    double k2 = function(x+(h/2), y + (h/2) * k1);
    double k3 = function(x+(h/2), y + (h/2) * k2);
    double k4 = function(x + h, y + h * k3);
    y = y + (h/6)*(k1 + 2 * k2 + 2 * k3 + k4);
    x += h;
    }
    return y;
}   // runge-kutt count