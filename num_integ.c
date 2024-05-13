#include <stdio.h>
#include <math.h>

double func(double x) {
    return tan(x + 3) / ((pow(x, 2) * 2) + 1);
}

double integrate1(double a, double b, double eps) { // part-const approx 
    double sum = 0;
    double dx = (b - a) * eps;
    double x;

    for (x = a; x < b; x += dx) {
        sum += func(x) * dx;
    }

    return sum;
}

// x0 = a, xN = b, Ei = rand(x(i); x(i+1))

double integrate2(double a, double b, double eps) { // part-linear approx
    double sum = 0;
    double dx = (b - a) * eps;
    double x;

    for (x = a; x < b; x += dx) {
        sum += (func(x)+func(x+dx))/2 * dx;
    }

    return sum;
}

double integrate3(double a, double b, double n) { // simpson method
    double h = (b - a) / n;
    double sum = func(a) + func(b);
    
    for (int i = 1; i < n; i += 2) {
        sum += 4 * func(a + i * h);
    }
    
    for (int i = 2; i < n - 1; i += 2) {
        sum += 2 * func(a + i * h);
    }
    
    return h * sum / 3;
}

// double integrate4(double a, double b, double eps);

int main() {    // -0.184865 = ~-0.185  
    double a = 0.4;
    double b = 1.0;
    double eps = 0.001;

    printf("Integral value(Part-Const approx) = %lf\n", integrate1(a, b, eps));
    printf("Integral value(Part-linear approx) = %lf\n", integrate2(a, b, eps));
    printf("Integral value(Simpson Method) = %lf\n", integrate3(a, b, 1./eps));
    return 0;
}