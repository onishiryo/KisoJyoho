#pragma warning(disable: 4996)
#include <stdio.h>
#include <math.h>

long int PowerMod(long int a, long int k, long int n);

int main() {
    long int n=5183; //公開鍵 n=p*q
    long int e=11; //公開鍵 e
    long int d=2291; //秘密鍵 d
    long int inum_input=754; //input number

    int imode=2; //1=encode, 2=decode
    switch(imode){
        case 1: //encoding, e&n required
          printf("Encoding the number: %ld\n", inum_input);
          long int inum_encrypted = PowerMod(inum_input, e, n);
          printf("encrypted number=%lu\n",inum_encrypted);
          break;
        case 2: //decoding, d&n required
          printf("Decoding the number: %ld\n", inum_input);
          long int inum_decoded = PowerMod(inum_input, d, n);
          printf("(decoded) plain number=%ld\n",inum_decoded);          
          break;
    }

    return 0;
}

long int PowerMod(long int a, long int k, long int n) {
/*
単純にa^k (mod n)を計算したいところだけど、
a^kが非常に大きい数字になり得るので、少し工夫する（繰り返し自乗法）。
*/
    long int i;
    long int value = 1;
    a = a%n;
    for(i = 0; i < k; i++) {
        value = value*a;
        if(value >= n) {
            value = value%n;}}
    return value;
}