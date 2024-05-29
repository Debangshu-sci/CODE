 #include <stdio.h>

double powr(int x, int power) {
    // base condition
    if (power == 0)
        return 1;

    if (power == 1)
        return x;

    double res = powr(x, power / 2);

    // if power is even
    if (power % 2 == 0)
        return res * res;
    else
        return x * res * res; // if power is odd
}

int main() {
    int x, n;
    printf("Enter x: ");
    scanf("%d", &x);

    printf("Enter n: ");
    scanf("%d", &n);

    printf("\n\nPow(%d, %d): %lf\n", x, n, powr(x, n));

    return 0;
}
