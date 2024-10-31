# String to Integer (atoi)

**Difficulty**: Medium

### Topics

- String

### Hint

Implement the `myAtoi(string s)` function, which converts a string to a 32-bit signed integer. The algorithm follows these steps:

1. **Whitespace**: Ignore any leading whitespace (`" "`).
2. **Signedness**: Check if the next character is `'-'` or `'+'` to determine the sign, assuming positivity if neither is present.
3. **Conversion**: Read the integer by skipping leading zeros until a non-digit character or end of string is reached. If no digits are read, the result is `0`.
4. **Rounding**: If the integer exceeds the 32-bit signed range `[-2^31, 2^31 - 1]`, round to remain within this range. Specifically, integers less than `-2^31` should be rounded to `-2^31`, and those greater than `2^31 - 1` should be rounded to `2^31 - 1`.

### Examples

#### Example 1

- **Input**: `s = "42"`
- **Output**: `42`

#### Example 2

- **Input**: `s = "   -042"`
- **Output**: `-42`

#### Example 3

- **Input**: `s = "1337c0d3"`
- **Output**: `1337`

#### Example 4

- **Input**: `s = "0-1"`
- **Output**: `0`

#### Example 5

- **Input**: `s = "words and 987"`
- **Output**: `0`

### Constraints

- `0 <= s.length <= 200`
- `s` consists of English letters (lower-case and upper-case), digits (`0-9`), `' '`, `'+'`, `'-'`, and `'.'`.
