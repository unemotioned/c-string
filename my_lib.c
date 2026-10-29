#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char *data;
    size_t length;
    size_t capacity; // including terminator
} String;

void string_print(const String s) {
    char c = ' ';
    size_t index = 0;
    while (c = s.data[index], c != '\0') {
        putchar(c);
        index++;
    }
    putchar('\n');
}

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

String string_copy(String s) {
    return string_new(s.data);
}

String string_concat(String a, String b) {
    char *new_p = malloc(a.length + b.length);
    if (new_p == NULL) {
        printf("Failed to malloc string_concat\n");
        exit(1);
    }

    for (size_t i = 0; i < a.length; i++) {
        new_p[i] = a.data[i];
    }
    for (size_t i = 0; i < b.length; i++) {
        new_p[i + a.length] = b.data[i];
    }
    new_p[a.length + b.length + 1] = '\0';

    return string_new(new_p);
}

/**
 * Return `-1` if index is out of range.
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

int string_compare(String a, String b) {
    if (a.length != b.length) {
        return 0;
    }

    for (size_t i = 0; i < a.length; i++) {
        if (a.data[i] != b.data[i]) {
            return 0;
        }
    }

    return 1;
}

/**
 * Returns `1` if String a contains String b.
 */
int string_contains(String a, String b) {
    if (a.length < b.length) {
        return 0;
    }

    size_t i = 0;
    for (size_t j = 0; j < a.length; j++) {
        for (size_t k = 0; k < b.length; k++) {
            if (a.data[j + k] == b.data[k]) {
                i++;
            }
        }

        // return when there is a match
        if (i == b.length) {
            return 1;
        } else {
            i = 0;
        }
    }

    return 0;
}

int string_starts_with(String s, String prefix) {
    if (s.length < prefix.length) {
        return 0;
    }

    for (size_t i = 0; i < prefix.length; i++) {
        if (s.data[i] != prefix.data[i]) {
            return 0;
        }
    }

    return 1;
}

int string_ends_with(String s, String suffix) {
    if (s.length < suffix.length) {
        return 0;
    }

    for (size_t i = 0; i < suffix.length; i++) {
        if (s.data[i + suffix.length] != suffix.data[i]) {
            return 0;
        }
    }

    return 1;
}

String string_trim(String s) {
    size_t front = 0;
    for (size_t i = 0; i < s.length; i++) {
        if (s.data[i] == ' ') {
            front++;
        } else {
            break;
        }
    }

    size_t rear = s.length - 1;
    for (size_t i = rear; i > front; i--) {
        if (s.data[i] == ' ') {
            rear--;
        } else {
            break;
        }
    }

    int trimmed_size = rear - front + 1;
    char *new_p = NULL;
    new_p = malloc(trimmed_size);
    if (new_p == NULL) {
        printf("Failed to malloc string_trim\n");
        exit(1);
    }

    for (size_t i = front; i <= rear; i++) {
        new_p[i - front] = s.data[i];
    }
    new_p[trimmed_size] = '\0';

    return string_new(new_p);
}

/**
 * Return original String struct if index is out of range.
 */
String string_replace(String s, int index, char c) {
    if (index < 0 || (size_t)index >= s.length) {
        return s;
    }

    char *og = s.data;
    og[index] = c;
    return string_new(og);
}

/**
 * Insert character in front of the given index.
 * Return original String struct if index is out of range.
 */
String string_insert(String s, int index, char c) {
    if (index < 0 || (size_t)index > s.length) {
        return s;
    }

    char *new_p = malloc(s.capacity + 1);
    if (new_p == NULL) {
        printf("Failed to malloc string_insert");
        exit(1);
    }

    for (int i = 0; i < index; i++) {
        new_p[i] = s.data[i];
    }
    new_p[index] = c;
    for (size_t i = (size_t)index; i < s.length; i++) {
        new_p[i + 1] = s.data[i];
    }

    new_p[s.capacity] = '\0';

    return string_new(new_p);
}

/**
 * Return original String struct if index is out of range.
 */
String string_remove(String s, int index) {
    if (index < 0 || (size_t)index > s.length) {
        return s;
    }

    char *new_p = malloc(s.length);
    if (new_p == NULL) {
        printf("Failed to malloc string_remove");
        exit(1);
    }

    for (int i = 0; i < index; i++) {
        new_p[i] = s.data[i];
    }

    int offset = sizeof(char);
    for (size_t i = (size_t)(index + 1); i < s.length; i++) {
        new_p[i - offset] = s.data[i];
    }

    return string_new(new_p);
}

/**
 * Character at the index will be included to the String at the rear.
 */
int string_split(const String s, const int index, String *front, String *rear) {
    if (index < 0 || (size_t)index >= s.length) {
        return 0;
    }

    // TODO: try refactoring `front->data` to pointer-pointer
    const short term = 1;
    front->data = malloc(index + term);
    if (front->data == NULL) {
        printf("Failed to malloc front at string_split\n");
        return 0;
    }

    for (int i = 0; i < index; i++) {
        front->data[i] = s.data[i];
    }
    front->data[index] = '\0';
    front->length = string_length(front->data);
    front->capacity = front->length + 1;

    const short term_and_index = 2;
    rear->data = malloc(s.length - index + term_and_index);
    if (rear->data == NULL) {
        printf("Failed to malloc rear at string_split\n");
        return 0;
    }

    for (size_t i = index; i < s.length; i++) {
        rear->data[i - index] = s.data[i];
    }
    rear->length = string_length(rear->data);
    rear->capacity = rear->length + 1;

    return 1;
}
