#define s21_size_t unsigned long
#define s21_NULL ((void*)0)
#include <stdio.h>
#include <string.h>
char * s21_strchr(char * str, int ch);

int main(){
    char * str = "Anyhow small text\n";
    char *char_pointer = strchr(str, 'y');
    printf("%s\n", char_pointer);
    
    char *sub_str = s21_strchr(str, 'y');
    printf("%s\n", sub_str);
    
    return 0;
}

char * s21_strchr(char * str, int ch){
    char * result = s21_NULL;
    unsigned char cha = ch;
    int i = 0;
    while(str[i]!=cha && str[i]!='\0'){
        i++;
    }
    if(str[i]=='\0') result = s21_NULL;
    else result = str + i;
    return result;
}