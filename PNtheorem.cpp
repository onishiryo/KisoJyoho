#pragma warning(disable: 4996)
#include <stdio.h>
#include <math.h> //to use math functions, e.g., log, sqrt, pow
int main(void) {
    FILE* outfp; //result.txt
    double x[10] = { 10.,1e2,1e3,1e4,1e5,1e6,1e7,1e8,1e9,1e10 };

    outfp = fopen("result.txt", "w");

    printf("       x,   Pi(x) \n");
    fprintf(outfp, "      x,    Pi(x) \n");

    for (int i = 0; i < 10; i++) {
        double pix = x[i] / log(x[i]);
        printf("x=%7.2e, pix=%.2e\n", x[i], pix);
        fprintf(outfp, "%7.2e, %7.2e\n", x[i], pix);
    }

    fclose(outfp);

    return 0;
}
