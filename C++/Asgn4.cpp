#include <stdio.h>
#include <ctype.h>

int main(){
    FILE *in=fopen("file1_In.txt","r");
    FILE *out=fopen("file1_out.txt","w");

    char ch;
    int newWord=1;

    while((ch=fgetc(in))!=EOF){
        if(newWord && ch>='a'&&ch<='z')
            ch-=32;
        newWord=(ch==' '||ch=='\n');
        fputc(ch,out);
    }
    fclose(in); fclose(out);
}

