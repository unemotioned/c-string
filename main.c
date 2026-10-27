#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t length;
    size_t capacity; // including NUL char
} String;

size_t string_length(const char *text) {
    size_t cnt = 0;
    char c = ' ';

    while (c = text[cnt], c != '\0') {
        cnt++;
    }

    return cnt;
}

String string_new(const char *text) {
    String s = {};

    s.length = string_length(text);
    s.capacity = s.length + 1;

    s.data = malloc(s.capacity);
    if (s.data == NULL) {
        printf("Failed to malloc String\n");
        exit(1);
    }

    memcpy(s.data, text, s.capacity);

    return s;
}

int main(void) {
    String s = string_new("");

    printf("data: %s\n", s.data);
    printf("length: %zu\n", s.length);
    printf("capacity: %zu\n", s.capacity);

    putchar('\n');

    String foo = string_new("Foobar");

    printf("data: %s\n", foo.data);
    printf("length: %zu\n", foo.length);
    printf("capacity: %zu\n", foo.capacity);

    return 0;
}
