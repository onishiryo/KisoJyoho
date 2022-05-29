#pragma warning(disable: 4996)
#include <stdio.h>
#include <errno.h> //to use errno
#include <math.h> //to use math functions, e.g., sqrt, sqrtf, pow, powf
#include <time.h> //for time

long int check_prime (long int);

int main(void) {
    long int ix, isqrtx, i, ipf=0; //long int=18.9桁: %ld
    time_t tstart, tend;    

    tstart = time(NULL);

    ix=67280421310721; // トーマス・クラウセン、1885,14桁

    ipf = check_prime(ix);

    if(ipf==0){ //割り切れる数がなかった場合
        printf("%ld is a prime number.\n", ix);
    }else{
        printf("%ld can be devided by %ld.\n", ix,ipf);
    }

    tend = time(NULL);
    printf("time for computing=%ld [sec]\n", tend-tstart);

    return 0; 
}

long int check_prime(long int inum){
    long int i, isqrt_num, ipfactor;

    ipfactor=0;
    isqrt_num=(long int)sqrt((double)inum);

    for(i=3; i<=isqrt_num; i=i+2){
        if((inum%i)==0){
            ipfactor=i;
            break; }}

    return ipfactor;
}