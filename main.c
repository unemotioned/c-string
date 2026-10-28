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

    while (text[cnt] != '\0') {
        cnt++;
    }

    return cnt;
}

String string_new(const char *text) {
    String s;

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

void string_free(String *s) {
    // free s.data which is char *
    free(s->data);    // access struct's member via pointer
    *s = (String){0}; // initialize all values with 0s
}

int string_is_empty(String s) {
    if (s.length == 0) {
        return 1;
    }

    return 0;
}

int main(void) {
    String s = string_new("");

    printf("data: %s\n", s.data);
    printf("length: %zu\n", s.length);
    printf("capacity: %zu\n", s.capacity);

    if (string_is_empty(s)) {
        printf("s is empty\n");
    } else {
        printf("s is not empty\n");
    }

    putchar('\n');

    String foo = string_new("Foobar");

    printf("data: %s\n", foo.data);
    printf("length: %zu\n", foo.length);
    printf("capacity: %zu\n", foo.capacity);

    if (string_is_empty(foo)) {
        printf("foo is empty\n");
    } else {
        printf("foo is not empty\n");
    }

    string_free(&foo);
    string_free(&s);

    return 0;
}
