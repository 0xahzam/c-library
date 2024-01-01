#include <stdio.h>
#include <math.h>

typedef long double ld;
typedef unsigned long long ull;


ull factorial(int n){
    if (n >= 0){
        return (ull) tgamma(n+1);
    } else{
        printf("Error, -ve number");
        return 0;
    }
}

ld chudnovsky(long long iterations){
    ld pi = 0.0;

    for (int k = 0; k < iterations; k++){
        ld numerator = powl(-1,k) * factorial(6*k) * (545140134*k + 13591409);
        ld denominator = factorial(3*k) * powl(factorial(k),3) * powl(640320,3*k+1.5);
        ld calc = numerator / denominator;
        pi += calc;
    }

    pi = 1.0 / (12 * pi);
    return pi;
}

int main() {
    ull iterations = 100000;
    ld approx = chudnovsky(iterations);
    printf("%.30Lf\n", approx);

    return 0;
}
