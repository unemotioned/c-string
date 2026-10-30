#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int OFFSET = (int)'a' - (int)'A';

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
    String new = {0};

    new.length = string_length(text);
    new.capacity = new.length + 1;

    new.data = malloc(new.capacity);
    if (new.data == NULL) {
        printf("Failed to malloc String\n");
        return new;
    }

    memcpy(new.data, text, new.capacity);

    return new;
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
        String empty = {0};
        return empty;
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
 * Return index of 1st occurrence given character(s).
 *
 * Compare return value with `SIZE_MAX` from `stdint.h` to check if index of
 * character was found.
 */
size_t string_index_of(String s, const char c) {
    size_t index = SIZE_MAX;
    for (size_t i = 0; i < s.length; i++) {
        if (s.data[i] == c) {
            index = i;
            break;
        }
    }
    return index;
}

size_t string_index_of_str(String a, String b) {
    if (a.length < b.length) {
        return SIZE_MAX;
    }

    for (size_t j = 0; j < a.length - b.length + 1; j++) {
        for (size_t k = 0; k < b.length; k++) {
            if (a.data[j + k] != b.data[k]) {
                break;
            }
            if (k == b.length - 1) {
                return j;
            }
        }
    }

    return SIZE_MAX;
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

int string_equals(String a, String b) {
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

static int is_ascii_alpha(char c) {
    if (c >= 'A' && c <= 'Z') {
        return 1;
    } else if (c >= 'a' && c <= 'z') {
        return 1;
    }

    return 0;
}

int string_equals_ignore_case(String a, String b) {
    if (a.length != b.length) {
        return 0;
    }

    for (size_t i = 0; i < a.length; i++) {
        if (is_ascii_alpha(a.data[i])) {
            if (a.data[i] > b.data[i] && a.data[i] - OFFSET != b.data[i]) {
                return 0;
            }
            if (a.data[i] < b.data[i] && a.data[i] + OFFSET != b.data[i]) {
                return 0;
            }
        } else {
            if (a.data[i] != b.data[i]) {
                return 0;
            }
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
    for (size_t j = 0; j < a.length - b.length + 1; j++) {
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

String string_to_upper(String s) {
    char *p = malloc(s.capacity);
    if (p == NULL) {
        printf("Failed to malloc string_to_upper\n");
        return s;
    }

    for (size_t i = 0; i < s.length; i++) {
        if ((int)s.data[i] >= (int)'a' && (int)s.data[i] <= (int)'z') {
            p[i] = (char)((int)s.data[i] - OFFSET);
        } else {
            p[i] = s.data[i];
        }
    }
    p[s.length] = '\0';

    String upper = {
        .data = p,
        .length = s.length,
        .capacity = s.capacity,
    };
    p = NULL; // to avoid dangling pointer

    return upper;
}

String string_to_lower(String s) {
    char *p = malloc(s.capacity);
    if (p == NULL) {
        printf("Failed to malloc string_to_lower\n");
        return s;
    }

    for (size_t i = 0; i < s.length; i++) {
        if ((int)s.data[i] >= (int)'A' && (int)s.data[i] <= (int)'Z') {
            p[i] = (char)((int)s.data[i] + OFFSET);
        } else {
            p[i] = s.data[i];
        }
    }
    p[s.length] = '\0';

    String lower = {
        .data = p,
        .length = s.length,
        .capacity = s.capacity,
    };
    p = NULL;

    return lower;
}

String string_toggle_case(String s) {
    char *p = malloc(s.capacity);
    if (p == NULL) {
        printf("Failed to malloc string_toggle_case\n");
        return s;
    }

    for (size_t i = 0; i < s.length; i++) {
        if (s.data[i] >= 'A' && s.data[i] <= 'Z') {
            p[i] = s.data[i] + OFFSET;
        } else if (s.data[i] >= 'a' && s.data[i] <= 'z') {
            p[i] = s.data[i] - OFFSET;
        } else {
            p[i] = s.data[i];
        }
    }
    p[s.length] = '\0';

    String toggle = {
        .data = p,
        .length = s.length,
        .capacity = s.capacity,
    };
    p = NULL;

    return toggle;
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
        return s;
    }

    for (size_t i = front; i <= rear; i++) {
        new_p[i - front] = s.data[i];
    }
    new_p[trimmed_size] = '\0';

    return string_new(new_p);
}

String string_substring(String s, int start, int stop) {
    if (start < 0 || (size_t)stop > s.length || start >= stop) {
        return s;
    }

    size_t size = stop - start;
    char *sub_p = NULL;

    sub_p = malloc(size + 1);
    if (sub_p == NULL) {
        printf("Failed to malloc string_substring\n");
        return s;
    }

    for (int i = start; i < stop; i++) {
        sub_p[i - start] = s.data[i];
    }
    sub_p[size] = '\0';

    return string_new(sub_p);
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
        return s;
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
        return s;
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

int string_region_match(String a, int offset, String b, int start, int stop) {
    int len = stop - start;

    if (len > a.length - offset) {
        return 0;
    }

    for (size_t i = 0; i < len; i++) {
        if (a.data[i + offset] != b.data[i + start]) {
            return 0;
        }
    }

    return 1;
}

String string_join(int count, ...) {
    String joined = {0};
    size_t prev_size = 0;
    size_t curr_size = 0;
    char *joined_p = NULL;

    va_list args;
    // initialize args to point to first argument after count
    va_start(args, count);

    for (int i = 0; i < count; i++) {
        String s = va_arg(args, String);

        curr_size += s.length;

        char *new_p = realloc(joined_p, curr_size - 1);
        if (new_p == NULL) {
            printf("Failed to malloc string_join\n");
            return joined;
        }
        joined_p = new_p;

        joined_p[prev_size + s.length] = '\0';
        for (int j = 0; j < s.length; j++) {
            joined_p[prev_size + j] = s.data[j];
        }

        prev_size = curr_size;
        string_free(&s);
    }

    va_end(args); // free memory

    joined = string_new(joined_p);

    return joined;
}
