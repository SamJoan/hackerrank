#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <gmp.h>

int factorial(int n) {
    int fac = 1;
    int i;
    for(i = 2; i <= n; i++) {
        printf("%d\n", i);
        fac = fac * i;
    }

    return fac;
}

void mpz_factorial(mpz_t fac, int n) {
    mpz_t temp;
    mpz_init(temp);
    mpz_set_ui(fac, 1);

    int i;
    for(i = 2; i <= n; i++) {
        printf("%d\n", i);
        mpz_set_ui(temp, i);
        mpz_mul(fac, fac, temp);
    }

    mpz_clear(temp);
}

int main() {
    int x;
    scanf("%d", &x);

    mpz_t fac;
    mpz_init(fac);
    mpz_factorial(fac, x);
    mpz_clear(fac);

    gmp_printf("%Zd\n", fac);
}
