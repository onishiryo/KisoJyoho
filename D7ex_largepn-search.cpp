#pragma warning(disable: 4996)
#include <stdio.h>
#include <errno.h> //to use errno
#include <math.h> //to use math functions, e.g., sqrt, sqrtf, pow, powf
#include <time.h> //for time

/*
19桁を超える大きな数LGをinum[0](18桁)+inum[1](18桁)で表す。。
つまり、
LG=inum[0]*10^18 +inum[1]
このとき、
sqrt(LG) ~< sqrt(inum[0])*10^9 + sqrt(inum[1])
LG(mod N)=[{inum[0](mod N)}*{10^18(mod N)}(mod N) +inum[1](mod N)](mod N)
*/

long int check_lprime (long int[2]);

int main(void) {
    long int ix0, ix1_start, ix1_end, ix1, ipf=0;
    long int ix[2];
    time_t tstart, tend;    

    FILE *outfp; //outfile.txt
    outfp = fopen("lpnlist.txt", "w");

    tstart = time(NULL); //for computing time measurement

    //   109 876543210987654321
    //ix=147 573952589676412927 (21桁)
//    ix0=147;
//    ix1_start=  573952589676412927;
//    ix1_end  =  573952589676412927;

//               109 876543210987654321
//    ix_start=12345 000000000000000001; // 18桁以下
//    ix_end  =12345 000000000000000100;
    ix0      =12345;
    ix1_start=1; // 奇数とすべき。18桁以下。
    ix1_end  =100;

    if((ix1_start)%2==0){ix1_start=ix1_start+1;} //for safety

    ix[0]=ix0;
    for(ix1=ix1_start; ix1<=ix1_end; ix1=ix1+2){
        ix[0]=ix0;
        ix[1]=ix1;
        printf("Let's check %lu %018lu...\n", ix[0],ix[1]);

        ipf = check_lprime(ix);
        if(ipf==0){
            printf("%lu %018lu is a prime number.\n", ix[0],ix[1]);
            fprintf(outfp, "%lu %018lu\n", ix[0],ix[1]); }}

    fclose(outfp);
    tend = time(NULL); //for computing time measurement
    printf("time for computing=%ld [sec]\n", tend-tstart);

    return 0; 
}

long int check_lprime(long int inum[2]){
    long int i, isqrt_num2, ipfactor;
    long int imod0,imod_1e18,imod1,imod;
    
    ipfactor=0;

    isqrt_num2 = (long int)sqrt((double)inum[0])*1000000000 
               + (long int)sqrt((double)inum[1]);

    for(i=3; i<isqrt_num2; i=i+2){
        imod0=inum[0]%i;
                // 123456789012345678
        imod_1e18=1000000000000000000%i;
        imod1=inum[1]%i;
        imod =119; //correct using imod0, imod_1e18, imod1

        if(imod==0){
            printf("%ld %018ld can be devided by %ld.\n", inum[0],inum[1],i);
            ipfactor=i;
            break;}}

    return ipfactor;
}