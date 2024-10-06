#include <stdio.h>
#include <string.h>

static inline size_t min(size_t a, size_t b)
{
    return a < b ? a : b;
}

int main(void) {
    char padder[] = "..........................";
    int len = min(strlen("sizeof(void *)"), sizeof(padder) - 1);
    printf("%.*s%s%2ld\n", len, "sizeof(void *)", padder + len, sizeof(void*));

    len = min(strlen("sizeof(void)"), sizeof(padder) - 1);
    printf("%.*s%s%2ld\n", len, "sizeof(void)", padder + len, sizeof(void));
    
    len = min(strlen("sizeof(char)"), sizeof(padder) - 1);
    printf("%.*s%s%2ld\n", len, "sizeof(char)", padder + len, sizeof(char));

    len = min(strlen("sizeof(short)"), sizeof(padder) - 1);
    printf("%.*s%s%2ld\n", len, "sizeof(short)", padder + len, sizeof(short));
    
    len = min(strlen("sizeof(int)"), sizeof(padder) - 1);
    printf("%.*s%s%2ld\n", len, "sizeof(int)", padder + len, sizeof(int));

    len = min(strlen("sizeof(long)"), sizeof(padder) - 1);
    printf("%.*s%s%2ld\n", len, "sizeof(long)", padder + len, sizeof(long));
    
    len = min(strlen("sizeof(long long)"), sizeof(padder) - 1);
    printf("%.*s%s%2ld\n", len, "sizeof(long long)", padder + len, sizeof(long long));

    len = min(strlen("sizeof(float)"), sizeof(padder) - 1);
    printf("%.*s%s%2ld\n", len, "sizeof(float)", padder + len, sizeof(float));

    len = min(strlen("sizeof(double)"), sizeof(padder) - 1);
    printf("%.*s%s%2ld\n", len, "sizeof(double)", padder + len, sizeof(double));
}