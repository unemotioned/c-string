# C String

Implementing String in C.

> "They're imaginary. We made them up, like the boogeyman." - George Carline (2008)

## References

- [tony - Strings Aren't Real](https://www.youtube.com/watch?v=fUVvfDkDb-Y)
- [Gabe Sampson](https://www.youtube.com/@gabe_sampson/home)
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/html/split/)

---

## Compile and Run

```sh
gcc -xc -std=c11 -Wall -Wextra -pedantic -O2 main.c -o main
./main
```

---

## Functions

- [x] `string_new(char *) -> String`
  - Create Struct for String that store text, length and capacity(including
    terminator)

- [x] `string_free(String *) -> void`
  - Free the String struct's pointer and initialize with compound literal

- [x] `string_length(char *) -> size_t`
  - Get the length of a string, excluding the null terminator.

- [x] `string_copy(String) -> String`
  - Create and return a new copy of a string.

- [x] `string_concat(String, String) -> String`
  - Combine two strings into a new string.

- [x] `string_equal(String, String) -> int`
  - Return true if two strings contain the same characters.

- [ ] `string_equal_ignore_case(String, String) -> int`
  - Return true if two strings contain the same characters regardless of upper
    or lower case.

- [x] `string_is_empty(String) -> int`
  - Return true if the string is empty.

- [x] `string_char_at(String, int) -> int`
  - Return the character at the given index.

- [x] `string_contains(String, String) -> int`
  - Return true if the string contains the given character.

- [x] `string_starts_with(String, String) -> int`
  - Return true if the string starts with the given prefix.

- [x] `string_ends_with(String, String) -> int`
  - Return true if the string ends with the given suffix.

- [x] `string_index_of(String, char) -> int`
  - Return the index of the first occurrence of the given character(s), or -1 if
    not found.

- [x] `string_count(String, char) -> int`
  - Count how many times the given character appears in the string.

- [ ] `string_to_upper(String) -> String`
  - Return a new string with all lowercase letters converted to uppercase.

- [ ] `string_to_lower(String) -> String`
  - Return a new string with all uppercase letters converted to lowercase.

- [x] `string_trim(String) -> String`
  - Return a new string with leading and trailing whitespace removed.

- [x] `string_substring(String, int, int) -> String`
  - Return a new string containing characters from the start index up to, but
    not including, the end index.

- [x] `string_replace(String, int, char) -> String`
  - Replace the character at the given index with the specified character.

- [x] `string_insert(String, int, char) -> String`
  - Return a new string with the character inserted at the given index.

- [x] `string_remove(String, int) -> String`
  - Remove the character at the given index.

- [x] `string_split(String, int, String *, String *) -> int`
  - Split the string at the given index into two strings, store each into given
    String pointers.
  - Return true on success.

- [ ] `string_region_match(String, String) -> int`
  - compare regions in two different strings to check if they are equal.

- [ ] `string_join(String, ...) -> String`
  - Take multiple String structs as arguments and return single string joined
    all together.
