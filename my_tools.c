#include <unistd.h>

int my_putchar(char c) {
    if ((write(1, &c, 1)) == -1)
        return (0);
    return (0);
}

int my_putstr(char *str) {
    int inc;

    inc = 0;
    while (str[inc] != '\0') {
        my_putchar(str[inc]);
        inc++;
    }
    return (0);
}

