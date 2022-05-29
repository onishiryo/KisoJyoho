#pragma warning(disable: 4996)
#include <stdio.h>
#include <time.h> //for time

int main(void) {
    
    time_t tstart, tend; //sec (s)

    int i,j,k;
    int n=1000;

//加算
    tstart = time(NULL);
    double a=1.0, b=3.0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                a=a+b;}}}
    tend = time(NULL);
    printf("加算 にかかった時間=%ld [sec]\n", tend-tstart);

//減算
    tstart = time(NULL);
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                a=a-b;}}}
    tend = time(NULL);
    printf("減算 にかかった時間=%ld [sec]\n", tend-tstart);

//乗算
    tstart = time(NULL);
    a=1.0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                a=a*b;}}}
    tend = time(NULL);
    printf("乗算 にかかった時間=%ld [sec]\n", tend-tstart);

//除算
    tstart = time(NULL);
    a=1.0;
    for(i=0; i<n; i++){
        for(j=0; j<n; j++){
            for(k=0; k<n; k++){
                a=a/b;}}}
    tend = time(NULL);
    printf("除算 にかかった時間=%ld [sec]\n", tend-tstart);

    return 0;
}
