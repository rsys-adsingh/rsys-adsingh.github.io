#include <stdio.h>
#include <stdint.h>

int main(void) {
    uint64_t number = 4294967295ULL;
    number += 1;

    printf("Pointer: %zu bytes\n", sizeof(void *));
    printf("int: %zu bytes\n", sizeof(int));
    printf("long: %zu bytes\n", sizeof(long));
    printf("uint64_t: %zu bytes\n", sizeof(number));
    printf("Value: %llu\n", (unsigned long long)number);
    return 0;
}
