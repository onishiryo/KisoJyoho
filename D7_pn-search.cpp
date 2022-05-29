#pragma warning(disable: 4996)
#include <stdio.h>
#include <errno.h> //to use errno
#include <math.h> //to use math functions, e.g., sqrt, sqrtf, pow, powf
#include <time.h> //for time

long int check_prime (long int);

int main(void) {
    long int ix, ipf=0;
    long int ix_start, ix_end;
    time_t tstart, tend;    

    FILE *outfp;
    outfp = fopen("pnlist.txt", "w");

    tstart = time(NULL); //for computing time measurement
    ix_start=1; // 奇数であるべき。18桁以下。
    //        1234567890123456789
    ix_end  =100000000;

    if((ix_start)%2==0){ix_start=ix_start+1;} //for safety

    for(ix=ix_start; ix<=ix_end; ix=ix+2){        
        ipf = check_prime(ix);
        if(ipf==0){
            printf("%ld is a prime number.\n", ix);
            fprintf(outfp, "%ld\n", ix);}}

    fclose(outfp);
    tend = time(NULL); //for computing time measurement
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