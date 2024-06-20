#include "s21_string.h"

char * s21_strchr(const char * str, int ch){
    char * result = (char*)str;
    unsigned char cha = ch;
    int i = 0;
    while(str[i]!=cha && str[i]!='\0'){
        i++;
    }
    if(str[i]=='\0') result = s21_NULL;
    else result+= i;
    return result;
}
