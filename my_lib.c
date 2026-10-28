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

/**
 * Return `-1` if index is out of range or character is not found.
 */
int string_char_at(String s, int index) {
    if (index < 0 || (size_t)index >= s.length) {
        return -1;
    }

    return s.data[index];
}

/**
 * Return index of 1st occurrence given character
 *
 * Compare return value with `SIZE_MAX` from `stdint.h` to check if index of
 * character was found.
 */
size_t string_char_index(String s, const char c) {
    size_t index = SIZE_MAX;
    for (size_t i = 0; i < s.length; i++) {
        if (s.data[i] == c) {
            index = i;
            break;
        }
    }
    return index;
}

size_t string_count(String s, const char c) {
    size_t cnt = 0;
    for (size_t i = 0; i < s.length; i++) {
        if (s.data[i] == c) {
            cnt++;
        }
    }
    return cnt;
}
