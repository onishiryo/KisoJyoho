#pragma warning(disable: 4996)
#include <stdio.h>
#include <math.h>

long long PowerMod(long long a, long long k, long long n);

int main() {
    long long n=5183; //公開鍵 n=p*q
    long long e=11; //公開鍵 e
    long long d=2291; //秘密鍵 d
    long long inum_input=754; //input number

    long long inum_encrypted, inum_decoded;

    int imode=2; //1=encode, 2=decode
    switch(imode){
        case 1: //encoding, e&n required
          printf("Encoding the number: %lld\n", inum_input);
          inum_encrypted = PowerMod(inum_input, e, n);
          printf("encrypted number=%lld\n",inum_encrypted);
          break;
        case 2: //decoding, d&n required
          printf("Decoding the number: %lld\n", inum_input);
          inum_decoded = PowerMod(inum_input, d, n);
          printf("(decoded) plain number=%lld\n",inum_decoded);          
          break;
    }

    return 0;
}

long long PowerMod(long long a, long long k, long long n) {
/*
単純にa^k (mod n)を計算したいところだけど、
a^kが非常に大きい数字になり得るので、少し工夫する（繰り返し自乗法）。
*/
    long long i;
    long long value = 1;
    a = a%n;
    for(i = 0; i < k; i++) {
        value = value*a;
        if(value >= n) {
            value = value%n;}}
    return value;
}