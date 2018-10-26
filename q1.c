#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *my_strcat( const char * const str1, const char * const str2);

int main(void){
    char *str = my_strcat("jayda", "tawana");
    printf("%s\n", str);

    return 0;
}

char *my_strcat( const char * const str1, const char * const str2){
    int i, n;
    char *str3 = calloc(strlen(str1) + strlen(str2), sizeof(char));

    for(i = 0; i != strlen(str1); i++)
        *(str3 + i) = *(str1 + i);

    for(n = 0; *(str2+n) != '\0'; n++)
        *(str3 + i + n) = *(str2 + n);

    return str3;
}
