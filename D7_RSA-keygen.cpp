#pragma warning(disable: 4996)
#include <stdio.h>
#include <math.h>

long int gcd(long int a, long int b);
long int lcm(long int a, long int b);
long int ExEuqlid(long int a, long int b);

int main() {

    //異なる素数 p,q (p>q) //p*qが10桁程度までに設定
    long int p=73; //ok
    long int q=71;

    if(p < q) { //to ensure p>q
        long int tmp = p;
        p = q;
        q = tmp;
    }

    printf("P : %ld   Q : %ld\n",p,q);

    //公開鍵 n
    long int n = p * q;

    //公開鍵 e
    long int l = lcm(p-1, q-1); //最小公倍数 l
    long int e = 2;
    while(gcd(l, e) != 1) {
        e++;
    }

    //秘密鍵 d
    long int d = ExEuqlid(e, l);

    printf("N= %ld,  E= %ld,  D= %ld\n",n,e,d);

    return 0;
}

long int gcd(long int a, long int b) {
//最大公約数 Greatest Common Divisor
     long int t;
 
     while (b != 0) {
         t = a % b;  a = b;  b = t;
     }
     return a;
}

long int lcm(long int a, long int b) {
//最小公倍数 Least Common Multiple
    return a * b / gcd(a, b);
}

long int ExEuqlid(long int a,long int b){
    long int x, y, q;
    long int x1 = 1, x2 = 0, x3;
    long int y1 = 0, y2 = 1, y3;
    long int result1 = b;
    long int result2 = a;
    long int result3;
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