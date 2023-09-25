#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

int count_alpha(const char* str) {
    size_t c = 0, i = 0;
    
    while(str[i] != '\0') {
        if((str[i]>='a' && str[i]<='z') || (str[i]>='A' && str[i]<='Z')) {
            c++;
        }
        
        i++;
    }

    return c;
}


int count_alpha_upper(const char* str) {
    size_t c = 0, i = 0;
    
    while(str[i] != '\0') {
        if (str[i]>='A' && str[i]<='Z') {
            c++;
        }
        
        i++;
    }

    return c;
}

void to_lower(char* str) {
    size_t i = 0;
    
    while(str[i] != '\0') {
        if (str[i] >='A' && str[i]<='Z') {
            str[i] += ('a' - 'A');
        }
        
        i++;
    }
}

void to_upper(char* str) {
    size_t i = 0;
    
    while(str[i] != '\0') {
        if (str[i] >='a' && str[i]<='z') {
            str[i] -= ('a' - 'A');
        }
        
        i++;
    }
}

int count_alpha_2(const char* str) {
    size_t c = 0;
    for (size_t i = 0; str[i]!= '\0'; i++) {
        if (isalpha(str[i])) {
            c += 1;
        }
    }
    return c;
}

int count_alpha_upper_2(const char* str) {
    size_t i = 0, c = 0;
    for(; str[i]!='\0'; i++) {
        if (isupper(str[i])) {
            c++;
        }
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
    printf("Number of alphabets in '%s': %d\n", str1, count_alpha_2(str1));
    printf("Number of alphabets (upper) in '%s': %d\n", str2, count_alpha_upper(str2));
    printf("Number of alphabets (upper) in '%s': %d\n", str2, count_alpha_upper_2(str2));

    to_lower(str1);
    //to_upper(str2);

    printf("%s\n%s\n", str1, str2);

    int cmp = strcmp(str1, str2);

    if (cmp == 0) {
        printf("Same string.\n");
    } else if(cmp < 0) {
        printf("%s -> %s\n", str1, str2);
    } else {
        printf("%s -> %s\n", str2, str1);
    }

    free(str1);
    free(str2);
}