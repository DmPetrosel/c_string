#include "s21_string.h"

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
    
    char str11 [] = "Many elements";
    char str22 [] = "o";
    ;
    printf("s21_strpbrk(str11, str22)\t%s\n",s21_strpbrk(str11, str22));
    printf("s21_strpbrk(str11, str22)\t%s\n",strpbrk(str11, str22));

    char strr [] = "many elements";
    char charr = 'm';
    printf("strrchr \"%s\"\n", strrchr(strr, charr));
    printf("strrchr \"%s\"\n", s21_strrchr(strr, charr));

    for(int i = 0; i < 140; i++){
        printf("%d\t%s\n", i, s21_strerror(i));
    }
    return 0;
}