#pragma warning(disable: 4996)
#include <stdio.h>
#include <math.h>

long long gcd(long long a, long long b);
long long lcm(long long a, long long b);
long long ExEuqlid(long long a, long long b);

int main() {

    //異なる素数 p,q (p>q) //p*qが10桁程度までに設定
    long long p=73; //ok
    long long q=71;

    if(p < q) { //to ensure p>q
        long long tmp = p;
        p = q;
        q = tmp;
    }

    printf("P : %lld   Q : %lld\n",p,q);

    //公開鍵 n
    long long n = p * q;

    //公開鍵 e
    long long l = lcm(p-1, q-1); //最小公倍数 l
    long long e = 2;
    while(gcd(l, e) != 1) {
        e++;
    }

    //秘密鍵 d
    long long d = ExEuqlid(e, l);

    printf("N= %lld,  E= %lld,  D= %lld\n",n,e,d);

    return 0;
}

long long gcd(long long a, long long b) {
//最大公約数 Greatest Common Divisor
     long long t;
 
     while (b != 0) {
         t = a % b;  a = b;  b = t;
     }
     return a;
}

long long lcm(long long a, long long b) {
//最小公倍数 Least Common Multiple
    return a * b / gcd(a, b);
}

long long ExEuqlid(long long a,long long b){
    long long x, y, q;
    long long x1 = 1, x2 = 0, x3;
    long long y1 = 0, y2 = 1, y3;
    long long result1 = b;
    long long result2 = a;
    long long result3;
    while(1){
        q = result1 / result2;
        x3 = x1 - (q*x2);
        y3 = y1 - (q*y2);
        result3 = result1 - q*result2;
        if(result3==1){
            if(y3<0){return y3+b;}
            return y3;}
        x1 = x2;
        y1 = y2;
        result1 = result2;
        x2 = x3;
        y2 = y3;
        result2 = result3;
    }
    return 0;
}