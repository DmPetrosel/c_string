#define s21_size_t unsigned long
#define s21_NULL ((void*)0)
#include <stdio.h>
#include <string.h>
char * s21_strchr(const char * str, int ch);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
int main(){
    char * str = "Anyhow small text\n";
    char *char_pointer = strchr(str, 'y');
    printf("strchr:\n\n");

    printf("%s\n", char_pointer);
    
    char *sub_str = s21_strchr(str, 'y');
    printf("%s\n", sub_str);
    
    printf("strncmp:\n\n");
    char * str2 = "Text1";
    char * str1 = "Tex";
    s21_size_t n = 5;
    printf("Original %d\n", strncmp(str1, str2, n));
    printf("My %d\n", s21_strncmp(str1, str2, n));
    return 0;
}
int s21_strncmp(const char *str1, const char *str2, s21_size_t n){
    s21_size_t i;
    for(i = 0; i < n && str1[i]!='\0'&&str2[i]!='\0' && str1[i]==str2[i]; i++)
        ;
    return (i == n)? 0:((str1[i]==0)?-str2[i]:str1[i]);
}

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