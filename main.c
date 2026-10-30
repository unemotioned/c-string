#include <stdint.h>
#include <stdio.h>

#include "./my_lib.c"

void test_new(void) {
    printf("\n===== Test New =====\n");

    String s = string_new("Hello, String!");

    int i = 0;
    while (s.data[i] != '\0') {
        putchar(s.data[i]);
        i++;
    }
    printf("]\n");

    for (size_t i = 0; i < s.length; i++) {
        putchar(s.data[i]);
    }
    printf("]\n");
}

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

void test_string_copy(void) {
    printf("\n===== Test Copy =====\n");

    String foo = string_new("Foobar");
    printf("foo pointer: %p\n", (void *)foo.data);

    String bar = string_copy(foo);
    printf("bar pointer: %p\n", (void *)bar.data);

    if (foo.data != bar.data) {
        printf("They are different strings\n");
    }
}

void test_string_concat(void) {
    printf("\n===== Test Concat =====\n");

    String foo = string_new("foo");
    String bar = string_new("bar");

    printf("%s", string_concat(foo, bar).data);
    putchar(']');
    putchar('\n');

    string_free(&bar);
    string_free(&foo);
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

    printf("idx of F: %zu\n", upper_f);
    printf("idx of f: %zu\n", lower_f);
    printf("idx of b: %zu\n", lower_b);
}

void test_count(String s, String foo) {
    printf("\n===== Test Count =====\n");

    size_t yay = string_count(s, 's');
    size_t nay = string_count(foo, 'o');

    printf("yay: %d\n", (int)(size_t)yay);
    printf("nay: %d\n", (int)(size_t)nay);
}

void test_equal(void) {
    printf("\n===== Test Equal =====\n");

    String foo = string_new("Foobar");
    String bar = string_new("Foobar");
    String baz = string_new("Hello, World");
    String f = string_new("foo");

    // same
    printf("cmp foo and bar: %d\n", string_equal(foo, bar));

    // length
    printf("cmp foo and baz: %d\n", string_equal(foo, baz));

    // different
    printf("cmp foo and f: %d\n", string_equal(foo, f));
}

void test_contains(void) {
    printf("\n===== Test Contains =====\n");

    String ref = string_new("foobar");
    String a = string_new("a");
    String b = string_new("foo");
    String c = string_new("bar");
    String d = string_new("Let me go home");
    String e = string_new("foobar");

    printf("do ref contains a? %d\n", string_contains(ref, a));
    printf("do ref contains b? %d\n", string_contains(ref, b));
    printf("do ref contains c? %d\n", string_contains(ref, c));
    printf("do ref contains d? %d\n", string_contains(ref, d));
    printf("do ref contains d? %d\n", string_contains(ref, e));
}

void test_starts_with(void) {
    printf("\n===== Test Starts With =====\n");

    String ref = string_new("Foobar");
    String pre1 = string_new("Foo");
    String pre2 = string_new("foobarfoobar");
    String pre3 = string_new("oob");

    printf("is pre1 prefix of ref? %d\n", string_starts_with(ref, pre1));
    printf("is pre2 prefix of ref? %d\n", string_starts_with(ref, pre2));
    printf("is pre3 prefix of ref? %d\n", string_starts_with(ref, pre3));
}

void test_ends_with(void) {
    printf("\n===== Test Ends With =====\n");

    String ref = string_new("Foobar");
    String suf1 = string_new("bar");
    String suf2 = string_new("Foobar");
    String suf3 = string_new("oob");
    String suf4 = string_new("foofoobar");

    printf("is suf1 suffix of ref? %d\n", string_ends_with(ref, suf1));
    printf("is suf2 suffix of ref? %d\n", string_ends_with(ref, suf2));
    printf("is suf3 suffix of ref? %d\n", string_ends_with(ref, suf3));
    printf("is suf4 suffix of ref? %d\n", string_ends_with(ref, suf4));
}

void test_substring(void) {
    printf("\n===== Test Substring =====\n");

    String s = string_new("Foobar");
    String sub1 = string_substring(s, 2, 5);
    string_print(sub1);

    // start larger then stop exception
    String sub2 = string_substring(s, 5, 2);
    string_print(sub2);

    // index out of range exception
    String sub3 = string_substring(s, -1, 5);
    string_print(sub3);
}

void test_trim(void) {
    printf("\n===== Test Trim =====\n");

    String s1 = string_new("     foobar   ");
    String t1 = string_trim(s1);

    printf("t1: [%s]\n", t1.data);

    String s2 = string_new("     foo  bar");
    String t2 = string_trim(s2);

    printf("t2: [%s]\n", t2.data);

    String s3 = string_new("     foo  bar  ");
    String t3 = string_trim(s3);

    printf("t3: [%s]\n", t3.data);

    String s4 = string_new("Foobar");
    String t4 = string_trim(s4);

    printf("t4: [%s]\n", t4.data);
}

void test_string_replace(void) {
    printf("\n===== Test Replace =====\n");

    String ori = string_new("Learn how to fly");
    //                       0123456789012345
    String rep1 = string_replace(ori, 9, ',');
    printf("rep1: %s\n", rep1.data);

    String rep2 = string_replace(ori, 16, ' ');
    printf("rep2: %s\n", rep2.data);
}

void test_string_insert(void) {
    printf("\n===== Test Insert =====\n");

    //                       012345678901234
    String ori = string_new("Hello, C world!");

    // insert A in front of C
    int index = string_char_index(ori, 'C');
    String ins1 = string_insert(ori, index, 'A');
    printf("ins1: %s", ins1.data);
    putchar(']');
    putchar('\n');

    // nothing changes
    String ins2 = string_insert(ori, 20, 'F');
    printf("ins2: %s", ins2.data);
    putchar(']');
    putchar('\n');
}

void test_string_remove(void) {
    printf("\n===== Test Remove =====\n");

    String ori = string_new("It's a social construct");

    int index = string_char_index(ori, 'a');
    String rm1 = string_remove(ori, index);
    printf("%s\n", rm1.data);
}

void test_split(void) {
    printf("\n===== Test Split =====\n");

    String s = string_new("Hello, World!");

    String a = {0};
    String b = {0};
    printf("a_p: %p\n", (void *)&a);
    printf("b_p: %p\n", (void *)&b);

    int index = 5;
    int res = string_split(s, index, &a, &b);
    if (res == 1) {
        printf("split success\n");
        string_print(a);
        string_print(b);
    } else {
        printf("split failed\n");
    }
}

int main(void) {
    // test_new();
    // test_string_copy();
    // test_string_concat();
    // test_empty(s, foo);
    // test_char_at(foo);
    // test_char_index(foo);
    // test_count(s, foo);
    test_equal();
    // test_contains();
    // test_starts_with();
    // test_ends_with();
    test_substring();
    // test_trim();
    // test_string_replace();
    // test_string_insert();
    // test_string_remove();
    // test_split();

    return 0;
}
