#pragma warning(disable: 4996)
#include <stdio.h>
int main(void) {
    char in_str[6]; //null文字分一つ余計に宣言（5+1=6）
    char out_str[20];

    FILE *infp;  //infile.txt
    FILE *outfp; //outfile.txt

    //input
    infp = fopen("infile.txt", "r");
//    fopen_s(&infp, "infile.txt", "r"); //VSonly
    fscanf(infp, "%5s", in_str); //infpから文字をスキャンして、うち5文字までを in_str に代入
//    fscanf_s(infp, "%5s", in_str, 6); //VSonly
    printf("input string=%s\n", in_str);
    fclose(infp);

    //MountainEcho
    sprintf(out_str, "%s %s %.3s %s", in_str, in_str, in_str, "...");
//    sprintf_s(out_str, "%s %s %.3s %s", in_str, in_str, in_str, "..."); //VSonly
    printf("output string=%s\n", out_str);

    //output
    outfp = fopen("outfile.txt", "w");
//    fopen_s(&outfp, "outfile.txt", "w"); //VSonly
    fprintf(outfp, "%s", out_str);
//    fprintf_s(outfp, "%s", out_str); //VSonly
    fclose(outfp);

    return 0;
}