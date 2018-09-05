// Design and implement a lexical analyzer for given
// language using C and the lexical analyzer should
// ignore redundant spaces, tabs and new lines.


#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int isKeyword(char buffer[]){
    char keywords[32][10] = {"auto","break","case","char","const","continue","default",
                            "do","double","else","enum","extern","float","for","goto",
                            "if","int","long","register","return","short","signed",
                            "sizeof","static","struct","switch","typedef","union",
                            "unsigned","void","volatile","while"};
    int i, flag = 0;

    for(i=0; i<32; ++i) {
        if(strcmp(keywords[i], buffer) == 0) {
            flag = 1;
            break;
        }
    }
    return flag;
}

int isOperator(char ch){
    char operators[] = "+-*/=%";
    for(int i = 0; i<6; ++i) {
        if(ch == operators[i])
            return 1;
    }
}

int main() {
    char ch, buffer[15];
    FILE *fp;
    int i,j = 0;

    fp = fopen("program.txt", "r");

    if (fp == NULL) {
        printf("Error while opening the file!\n");
        exit(0);
    }

    while((ch = fgetc(fp)) != EOF) {
        if(isOperator(ch) == 1)
            printf("%c is an operator\n", ch);
        else if(isalnum(ch))
            buffer[j++] = ch;
        else if((ch == ' ' || ch == '\n') && (j != 0)) {
            buffer[j] = '\0';
            j = 0;
            if (isKeyword(buffer) == 1)
                printf("%s is a keyword\n", buffer);
            else 
                printf("%s is an identifier\n", buffer);

        }
    }

    fclose(fp);
    return 0;
}