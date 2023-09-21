#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count_alpha(char* str) {
    size_t c = 0, i = 0;
    
    while(str[i] != '\0') {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
            c++;
        }
        
        i++;
    }

    return c;
}

int main(void) {
    char *str1, *str2;
    str1 = (char*) calloc(51, sizeof(char));
    str2 = (char*) calloc(51, sizeof(char));

    printf("Insert first string: ");
    scanf("%[^\n]%*c", str1);

    printf("Insert second string: ");
    scanf("%[^\n]%*c", str2);

    printf("%s\n%s\n", str1, str2);

    printf("Number of alphabets in '%s': %d\n", str1, count_alpha(str1));

    free(str1);
    free(str2);
}