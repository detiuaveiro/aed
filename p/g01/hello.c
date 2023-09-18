#include<stdio.h>
#include<string.h>

int main(void) {
    char first_name[21], last_name[21];
    printf("%p %p\n", first_name, last_name);
    
    memcpy(first_name, "Mario Antunes",sizeof(char)*14);
    printf("Hello %s %s!!\n", first_name, last_name);

    first_name[5] = '\0';
    printf("Hello %s %s!!\n", first_name, last_name);

    char *temp_name = &first_name[6]; 
    printf("Hello %s %s!!\n", temp_name, last_name);

    char c = '@';
    char c2 = c + 1;
    printf("%c(%d)\n", c, c);
    printf("%c(%d)\n", c2, c2);
    
    return 0;
}