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

void test_empty(void) {
    String s1 = string_new("");
    String s2 = string_new("Foobar");
    String s3 = {0};

    printf("\n===== Test Empty =====\n");

    if (string_is_empty(s1)) {
        printf("s1 is empty\n");
    } else {
        printf("s1 is not empty\n");
    }

    if (string_is_empty(s2)) {
        printf("s2 is empty\n");
    } else {
        printf("s2 is not empty\n");
    }

    if (string_is_empty(s3)) {
        printf("s3 is empty\n");
    } else {
        printf("s3 is not empty\n");
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

void test_char_at() {
    String s = string_new("Foobar is German");
    //                     0123456789012345

    printf("\n===== Test Char At =====\n");

    printf("%s\n", s.data);
    printf("length of foo: %d\n", (int)s.length);

    printf("char at 0: %c\n", string_char_at(s, 0));
    printf("char at 1: %c\n", string_char_at(s, 1));
    printf("char at 16: %c\n", string_char_at(s, 16));
}

void test_index_of() {
    printf("\n===== Test Char Index =====\n");

    String foo = string_new("Foobar");

    size_t upper_f = string_index_of(foo, 'F');
    size_t lower_f = string_index_of(foo, 'f');
    size_t lower_b = string_index_of(foo, 'b');

    if (lower_f == SIZE_MAX) {
        printf("lower case of f is not inside foo\n");
    }

    printf("idx of F: %zu\n", upper_f);
    printf("idx of f: %zu\n", lower_f);
    printf("idx of b: %zu\n", lower_b);
}

void test_index_of_str(void) {
    printf("\n===== Test Index Of Str =====\n");

    String a = string_new("Geeks for geeks");
    //                     012345678901234
    String b = string_new("for");
    String c = string_new("geeks");

    printf("i1: %zu\n", string_index_of_str(a, b)); // 6
    printf("i2: %zu\n", string_index_of_str(a, c)); // 10
}

void test_count() {
    printf("\n===== Test Count =====\n");

    String s1 = string_new("");
    String s2 = string_new("Foobar");

    printf("'s' in s1: %zu\n", string_count(s1, 's'));
    printf("'o' in s2: %zu\n", string_count(s2, 'o'));
}

void test_equals(void) {
    printf("\n===== Test Equal =====\n");

    String foo = string_new("Foobar");
    String bar = string_new("Foobar");
    String baz = string_new("Hello, World");
    String f = string_new("foo");

    // same
    printf("cmp foo and bar: %d\n", string_equals(foo, bar));

    // length
    printf("cmp foo and baz: %d\n", string_equals(foo, baz));

    // different
    printf("cmp foo and f: %d\n", string_equals(foo, f));
}

void test_equals_ignore_case(void) {
    printf("\n===== Test Equal Ignore Case =====\n");

    String s1 = string_new("FooBar1234");
    String s2 = string_new("foobar1234");
    String s3 = string_new("help me");
    String s4 = string_new("HELP ME");

    printf("res1: %d\n", string_equals_ignore_case(s1, s2)); // 1
    printf("res1: %d\n", string_equals_ignore_case(s1, s3)); // 0
    printf("res1: %d\n", string_equals_ignore_case(s3, s4)); // 1

    string_free(&s4);
    string_free(&s3);
    string_free(&s2);
    string_free(&s1);
}

void test_contains(void) {
    printf("\n===== Test Contains =====\n");

    String ref = string_new("foobar");
    String a = string_new("a");
    String b = string_new("foo");
    String c = string_new("bar");
    String d = string_new("Let me go home");
    String e = string_new("foobar");
    String f = string_new("baz");

    printf("do ref contains a? %d\n", string_contains(ref, a));
    printf("do ref contains b? %d\n", string_contains(ref, b));
    printf("do ref contains c? %d\n", string_contains(ref, c));
    printf("do ref contains d? %d\n", string_contains(ref, d));
    printf("do ref contains e? %d\n", string_contains(ref, e));
    printf("do ref contains f? %d\n", string_contains(ref, f));
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

void test_to_upper(void) {
    printf("\n===== Test To Upper =====\n");

    String a = string_new("ThisIsPascalCasing");
    string_print(string_to_upper(a));
}

void test_to_lower(void) {
    printf("\n===== Test To Lower =====\n");

    String a = string_new("ThisIsPascalCasing");
    string_print(string_to_lower(a));
}

void test_toggle_case(void) {
    printf("\n===== Test Toggle Case =====\n");

    String a = string_new("This Is Pascal Casing.");
    string_print(string_toggle_case(a));
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

void test_replace(void) {
    printf("\n===== Test Replace =====\n");

    String ori = string_new("Learn how to fly");
    //                       0123456789012345
    String rep1 = string_replace(ori, 9, ',');
    printf("rep1: %s\n", rep1.data);

    String rep2 = string_replace(ori, 16, ' ');
    printf("rep2: %s\n", rep2.data);
}

void test_insert(void) {
    printf("\n===== Test Insert =====\n");

    //                       012345678901234
    String ori = string_new("Hello, C world!");

    // insert A in front of C
    int index = string_index_of(ori, 'C');
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

void test_remove(void) {
    printf("\n===== Test Remove =====\n");

    String ori = string_new("It's a social construct");

    int index = string_index_of(ori, 'a');
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

void test_region_match(void) {
    printf("\n===== Test Region Match =====\n");

    // length = 23
    String a = string_new("It's a social construct");
    //                     01234567890123456789012

    String b = string_new("socialism");
    //                     012345678

    String c = string_new("uct.");

    int m1 = string_region_match(a, 7, b, 0, 6);
    printf("m1: %d\n", m1);

    int m2 = string_region_match(a, 20, c, 0, c.length);
    printf("m2: %d\n", m2);
}

void test_join(void) {
    printf("\n===== Test Join =====\n");

    String s1 = string_new("Hello");
    String s2 = string_new(",");
    String s3 = string_new(" ");
    String s4 = string_new("World");
    String s5 = string_new("!");
    string_print(string_join(5, s1, s2, s3, s4, s5));

    String f1 = string_new("foo");
    String f2 = string_new("bar");
    String f3 = string_new("baz");
    string_print(string_join(3, f1, f2, f3));
}

int main(void) {
    // test_new();
    // test_string_copy();
    // test_string_concat();
    // test_empty();
    // test_char_at();
    // test_index_of();
    // test_index_of_str();
    // test_count();
    // test_equals();
    test_equals_ignore_case();
    // test_contains();
    // test_starts_with();
    // test_ends_with();
    // test_substring();
    // test_to_upper();
    // test_to_lower();
    // test_toggle_case();
    // test_trim();
    // test_replace();
    // test_insert();
    // test_remove();
    // test_split();
    // test_region_match();
    // test_join();

    return 0;
}
