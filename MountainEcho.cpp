#pragma warning(disable: 4996)
#include <stdio.h>
int main(void) {
    char in_str[6]; //null文字分一つ余計に宣言（5+1=6）
    char out_str[20];

    scanf("%5s", in_str); //キー入力のうち5文字まで受入れて in_str に代入
//    scanf_s("%5s", in_str, 6); //VSonly
    sprintf(out_str, "%s %s %.3s %s", in_str, in_str, in_str, "...");
//    sprintf_s(out_str, "%s %s %.3s %s", in_str, in_str, in_str, "..."); //VSonly
    printf("%s", out_str);

    return 0;
}