#define s21_size_t unsigned long
#define s21_NULL ((void*)0)

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char * s21_strchr(const char * str, int ch);
int s21_strncmp(const char *str1, const char *str2, s21_size_t n);
char *s21_strncpy(char *dest, const char *src, s21_size_t n);
s21_size_t s21_strlen(const char *str);
s21_size_t s21_strcspn(const char *str1, const char *str2);


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
    printf("strlen:\n\n");

    printf("Original %ld\n", strlen(str));
    printf("My %ld\n", s21_strlen(str));

    printf("strncpy:\n\n");
    char dest [] = "Many";
    char src [] = "some elem";
    strncpy(dest, src, 15);
    printf("%s\n",dest);
    char dest1 [] = "Many";
    char src1 [] = "some elem";
    s21_strncpy(dest1, src1, 15);
    printf("%s\n",dest1);

     // Массив со строкой для поиска
    char strcs []="0123456789";
    // Набор символов, которые не должны входить в искомый сегмент
    char sym [10]="9876";
  
    // Определяем длину начального сегмента, не содержащего символы “9876”
    printf ("Длина сегмента: %ld\n",strcspn (strcs,sym));
    printf ("my Длина сегмента: %ld\n",s21_strcspn (strcs,sym));
    return 0;
}

s21_size_t s21_strcspn(const char *str1, const char *str2){
    s21_size_t i;
    for(i = 0; str1[i]!='\0'; i++){
        for(s21_size_t j = 0; str2[j]!='\0'; j++){
            if(str1[i]==str2[j]) return i;         
        }
        
    }
    return i;
}

s21_size_t s21_strlen(const char *str){
    s21_size_t i = 0;
    while(str[i] != '\0'){
        i++;
    }
    return i;
}

char *s21_strncpy(char *dest, const char *src, s21_size_t n){
  for(s21_size_t i = 0; i < n; i++){
    dest[i] = src[i];
  }
  return dest;
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