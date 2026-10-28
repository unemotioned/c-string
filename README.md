# C String

Implementing String in C.

> "They're imaginary. We made them up, like the boogeyman." - George Carline (2008)

## References

- [tony - Strings Aren't Real](https://www.youtube.com/watch?v=fUVvfDkDb-Y)
- [Gabe Sampson](https://www.youtube.com/@gabe_sampson/home)
- [Beej's Guide to C Programming](https://beej.us/guide/bgc/html/split/)

---

## TODO

- [x] Create Struct for String `string_new(str)`
  - store text, length and capacity(including nul char)

- [x] `string_length(str)`
- [x] `string_free(String *) -> void`
  - Free the String struct's pointer and initialize with compound literal
  - Get the length of a string, excluding the null terminator.

- [ ] `str_copy(str)`
  - Create and return a new copy of a string.

- [ ] `str_concat(str1, str2)`
  - Combine two strings into a new string.

- [ ] `str_compare(str1, str2)`
  - Return true if two strings contain the same characters.

- [x] `string_is_empty(str)`
  - Return true if the string is empty.

- [ ] `str_char_at(str, index)`
  - Return the character at the given index.

- [ ] `str_contains(str, ch)`
  - Return true if the string contains the given character.

- [ ] `str_starts_with(str, prefix)`
  - Return true if the string starts with the given prefix.

- [ ] `str_ends_with(str, suffix)`
  - Return true if the string ends with the given suffix.

- [ ] `str_index_of(str, ch)`
  - Return the index of the first occurrence of the given character, or -1 if
    not found.

- [ ] `str_count(str, ch)`
  - Count how many times the given character appears in the string.

- [ ] `str_to_upper_case(str)`
  - Return a new string with all lowercase letters converted to uppercase.

- [ ] `str_to_lower_case(str)`
  - Return a new string with all uppercase letters converted to lowercase.

- [ ] `str_trim(str)`
  - Return a new string with leading and trailing whitespace removed.

- [ ] `str_substring(str, start, end)`
  - Return a new string containing characters from the start index up to, but
    not including, the end index.

- [ ] `str_replace(str, index, ch)`
  - Replace the character at the given index with the specified character.

- [ ] `str_insert(str, index, ch)`
  - Return a new string with the character inserted at the given index.

- [ ] `str_remove(str, index)`
  - Remove the character at the given index.

- [ ] `str_split(str, index, left, right)`
  - Split the string at the given index into two strings, store it in `left` and
    `right`.
