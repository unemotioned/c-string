#pragma once

#include <stddef.h>

typedef struct {
    char *data;
    size_t length;
} String;

/**
 * Return early if `.data` is `NULL`.
 */
void string_print(const String s);

size_t string_length(const char *text);

String string_new(const char *text);

void string_free(String *s);

int string_is_empty(String s);

/**
 * True if the String only contains whtespaces.
 * Or length of String is 0.
 */
int string_is_blank(String s);

String string_copy(String s);

String string_concat(String a, String b);

/**
 * Return `-1` if index is out of range.
 */
int string_char_at(String s, int index);

/**
 * Return index of 1st occurrence given character(s).
 *
 * Compare return value with `SIZE_MAX` from `stdint.h` to check if index of
 * character was found.
 */
size_t string_index_of(String s, const char c);

size_t string_index_of_str(String a, String b);

size_t string_count(String s, const char c);

int string_equals(String a, String b);

int string_equals_ignore_case(String a, String b);

/**
 * Returns `1` if String a contains String b.
 */
int string_contains(String a, String b);

int string_starts_with(String s, String prefix);

int string_ends_with(String s, String suffix);

String string_to_upper(String s);

String string_to_lower(String s);

String string_toggle_case(String s);

String string_trim(String s);

String string_substring(String s, int start, int stop);

/**
 * Return original String struct if index is out of range.
 */
String string_replace(String s, int index, char c);

/**
 * Insert character in front of the given index.
 * Return original String struct if index is out of range.
 */
String string_insert(String s, int index, char c);

/**
 * Return original String struct if index is out of range.
 */
String string_remove(String s, int index);

/**
 * Character at the index will be included to the String at the rear.
 */
int string_split(const String s, const int index, String *front, String *rear);

int string_region_match(String a, int offset, String b, int start, int stop);

String string_join(int count, ...);
