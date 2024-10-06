#include<stdio.h>
#include<stdlib.h>

int main(void) {
    char first_name[21], last_name[21];
    printf("%p %p\n", first_name, last_name);

    printf("First Name: ");
    fgets(first_name, 21, stdin);
    first_name[5] ='S';
    first_name[20] = '\0';
    printf("Last Name: ");
    fgets(last_name, 21, stdin);

    printf("Hello %s %s\n", first_name, last_name);

    printf("Name: ");
    scanf("%s %s", first_name, last_name);
    first_name[5] ='S';
    first_name[20] = '\0';
    printf("Hello %s %s\n", first_name, last_name);


    /*printf("Age: ");
    char s_age[4];
    fgets(s_age, 4, stdin);
    int age = atoi(s_age);
    printf("Age %d (%s)\n", age, s_age);

    age = 0;
    printf("Age: ");
    scanf("%d", &age);
    printf("Age %d\n", age);*/

    return 0;
}