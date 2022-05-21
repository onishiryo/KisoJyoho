//学籍番号：12B34567
//名前：情報 基礎
#pragma warning(disable: 4996)
#include <stdio.h>
#include <stdlib.h> //for malloc
int main(void) {
    double *data;
    int gakuseki = 34567;

    data = (double*)malloc(sizeof(double) * gakuseki);

    for (int i = 0; i < gakuseki; i++) {
        data[i] = (double)i * (double)i; //2乗
    }

//output: 全てのデータを保存したい
    FILE* outfp;
    outfp = fopen("outfile.bin", "wb");

    size_t size_element = 1; //要修正
    size_t num_element = 1; //要修正

    fwrite(data, size_element, num_element, outfp);
    fclose(outfp);

    return 0;
}