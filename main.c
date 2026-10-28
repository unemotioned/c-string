#include <stdint.h>
#include <stdio.h>

#include "./my_lib.c"

void test_empty(String s, String foo) {
    printf("\n===== Test Empty =====\n");

    if (string_is_empty(s)) {
        printf("s is empty\n");
    } else {
        printf("s is not empty\n");
    }

    if (string_is_empty(foo)) {
        printf("foo is empty\n");
    } else {
        printf("foo is not empty\n");
    }
}

void test_char_at(String foo) {
    printf("\n===== Test Char At =====\n");

    printf("%s\n", foo.data);
    printf("length of foo: %d\n", (int)foo.length);

    char c0 = string_char_at(foo, 0);
    char c1 = string_char_at(foo, 1);
    char c6 = string_char_at(foo, 6);

    printf("char at 0: %c\n", c0);
    printf("char at 1: %c\n", c1);
    printf("char at 6: %c\n", c6);
}

void test_char_index(String foo) {
    printf("\n===== Test Char Index =====\n");

    size_t upper_f = string_char_index(foo, 'F');
    size_t lower_f = string_char_index(foo, 'f');
    size_t lower_b = string_char_index(foo, 'b');

    if (lower_f == SIZE_MAX) {
        printf("lower case of f is not inside foo\n");
    }

    printf("idx of F: %llu\n", upper_f);
    printf("idx of f: %llu\n", lower_f);
    printf("idx of b: %llu\n", lower_b);
}

void test_count(String s, String foo) {
    printf("\n===== Test Count =====\n");

    size_t yay = string_count(s, 's');
    size_t nay = string_count(foo, 'o');

    printf("yay: %d\n", (int)(size_t)yay);
    printf("nay: %d\n", (int)(size_t)nay);
}

int main(void) {
    printf("===== My String =====\n");

    String s = string_new("");
    String foo = string_new("Foobar");

    test_empty(s, foo);
    test_char_at(foo);
    test_char_index(foo);
    test_count(s, foo);

    string_free(&foo);
    string_free(&s);

    return 0;
}
