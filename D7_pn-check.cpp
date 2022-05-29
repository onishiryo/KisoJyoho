//学籍番号：12B34567
//名前：情報 基礎
#pragma warning(disable: 4996)
#include <stdio.h>
#include <errno.h> //to use errno
#include <math.h> //to use math functions, e.g., sqrt, sqrtf, pow, powf
#include <time.h> //for time

long long check_prime(long long);

int main(void) {
    long long ix, isqrtx, i, ipf = 0; //long int=18.9桁: %ld
    time_t tstart, tend;

    tstart = time(NULL);

    ix=67280421310721; // トーマス・クラウセン、1885,14桁

    ipf = check_prime(ix);

    if(ipf==0){ //割り切れる数がなかった場合
        printf("%lld is a prime number.\n", ix);
    }else{
        printf("%lld can be devided by %ld.\n", ix,ipf);
    }

    tend = time(NULL);
    printf("time for computing=%lld [sec]\n", tend-tstart);

    return 0; 
}

long long check_prime(__int64 inum) {
    long long i, isqrt_num, ipfactor;

    ipfactor=0;
    isqrt_num = (long long)sqrt((double)inum);

    for(i=3; i<=isqrt_num; i=i+2){
        if((inum%i)==0){
            ipfactor=i;
            break; }}

    return ipfactor;
}
