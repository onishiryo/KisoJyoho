#pragma warning(disable: 4996)
#include <stdio.h>
#include <errno.h> //to use errno
#include <math.h> //to use math functions, e.g., sqrt, sqrtf, pow, powf
#include <time.h> //for time

long long check_prime (long long);

int main(void) {
    long long ix, ipf=0;
    long long ix_start, ix_end;
    time_t tstart, tend;    

    FILE *outfp;
    outfp = fopen("pnlist.txt", "w");

    tstart = time(NULL); //for computing time measurement
    ix_start=1; // 奇数であるべき。18桁以下。
    //        1234567890123456789
    ix_end = 1000000; // 100000000;

    if((ix_start)%2==0){ix_start=ix_start+1;} //for safety

    for(ix=ix_start; ix<=ix_end; ix=ix+2){        
        ipf = check_prime(ix);
        if(ipf==0){
            printf("%lld is a prime number.\n", ix);
            fprintf(outfp, "%lld\n", ix);}}

    fclose(outfp);
    tend = time(NULL); //for computing time measurement
    printf("time for computing=%ld [sec]\n", tend-tstart);

    return 0; 
}

long long check_prime(long long inum){
    long long i, isqrt_num, ipfactor;

    ipfactor=0;
    isqrt_num=(long long)sqrt((double)inum);

    for(i=3; i<=isqrt_num; i=i+2){
        if((inum%i)==0){
            ipfactor=i;
            break; }}

    return ipfactor;
}