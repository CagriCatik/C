# Operator Precedence and Associativity in C

## Introduction to Operator Precedence

Operator precedence in C determines the order in which different operators in an expression are evaluated. Understanding operator precedence is crucial for writing correct and predictable C programs, especially when multiple operators are involved in a single expression. This tutorial explores operator precedence in detail, explains how different operators interact, and demonstrates how associativity resolves ambiguities when operators have the same precedence.

## Importance of Operator Precedence

Operator precedence defines the rules for grouping terms in expressions and influences how these expressions are evaluated. Misunderstanding these rules can lead to incorrect results and bugs that are difficult to trace. Consider the following example:

```c
int x = 7 + 3 * 2;
```

In this expression, the multiplication operator `*` has a higher precedence than the addition operator `+`. Therefore, the expression is evaluated as:

```c
int x = 7 + (3 * 2);
```

The result of `3 * 2` is `6`, and adding `7` yields `13`. If the addition were performed first, the result would be different:

```c
int x = (7 + 3) * 2;  // This would yield 20.
```

## Rules of Operator Precedence

C provides specific rules for determining the order of evaluation when two or more operators share an operand. The following list outlines the precedence levels from highest to lowest, along with examples of each type of operator.

### Highest Precedence Operators

1. **Postfix operators**: `()`, `[]`, `->`, `++`, `--`

   ```c
   a[i], p->m, x++, y--
   ```
2. **Unary operators**: `+`, `-`, `!`, `~`, `++`, `--`, `*`, `&`, `sizeof`, `(type)`

   ```c
   -a, !b, ++c, --d, *p, &q, sizeof(r), (int)s
   ```

### Arithmetic Operators

3. **Multiplicative operators**: `*`, `/`, `%`

   ```c
   a * b, c / d, e % f
   ```
4. **Additive operators**: `+`, `-`

   ```c
   a + b, c - d
   ```

### Bitwise and Shift Operators

5. **Shift operators**: `<<`, `>>`

   ```c
   a << b, c >> d
   ```
6. **Relational operators**: `<`, `<=`, `>`, `>=`

   ```c
   a < b, c <= d, e > f, g >= h
   ```
7. **Equality operators**: `==`, `!=`

   ```c
   a == b, c != d
   ```
8. **Bitwise AND**: `&`

   ```c
   a & b
   ```
9. **Bitwise XOR**: `^`

   ```c
   a ^ b
   ```
10. **Bitwise OR**: `|`

    ```c
    a | b
    ```

### Logical Operators

11. **Logical AND**: `&&`

    ```c
    a && b
    ```
12. **Logical OR**: `||`

    ```c
    a || b
    ```

### Conditional and Assignment Operators

13. **Conditional operator**: `?:`

    ```c
    a ? b : c
    ```
14. **Assignment operators**: `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `|=`, `^=`, `<<=`, `>>=`

    ```c
    a = b, c += d, e *= f
    ```

### Comma Operator

15. **Comma operator**: `,`
    ```c
    a, b
    ```

## Associativity

Associativity determines the order of evaluation when multiple operators of the same precedence appear in an expression. The two types of associativity are:

1. **Left to Right**: Most operators, including arithmetic, relational, and logical operators.
2. **Right to Left**: Unary, assignment, and conditional operators.

### Example of Associativity

Consider the expression:

```c
int x = 1 == 2 != 3;
```

Both `==` and `!=` have the same precedence, and they associate from left to right. Thus, the expression is evaluated as:

```c
int x = (1 == 2) != 3;
```

First, `1 == 2` evaluates to `0` (false), and then `0 != 3` evaluates to `1` (true). Therefore, `x` is assigned the value `1`.

## Using Parentheses for Clarity

To avoid confusion and ensure the intended order of evaluation, always use parentheses to explicitly specify the order of operations. For example:

```c
int result = (7 + 3) * 2;
```

Here, the parentheses ensure that the addition is performed first, followed by the multiplication.

## Summary

Understanding operator precedence and associativity is essential for writing correct and efficient C programs. While memorizing all the precedence rules can be challenging, using parentheses to explicitly define the order of operations can simplify your code and prevent errors. Always aim for clarity in your expressions to ensure that the program behaves as expected.

For reference, consult the following table, which outlines operator precedence and associativity in C:

| Precedence Level | Operator Type  | Operators                                                                        | Associativity                |
| ---------------- | -------------- | -------------------------------------------------------------------------------- | ---------------------------- |
| 1                | Postfix        | `()`, `[]`, `->`, `++`, `--`                                           | Left to Right                |
| 2                | Unary          | `+`, `-`, `!`, `~`, `++`, `--`, `*`, `&`, `sizeof`, `(type)` | Right to Left                |
| 3                | Multiplicative | `*`, `/`, `%`                                                              | Left to Right                |
| 4                | Additive       | `+`, `-`                                                                     | Left to Right                |
| 5                | Shift          | `<<`, `>>`                                                                   | Left to Right                |
| 6                | Relational     | `<`, `<=`, `>`, `>=`                                                     | Left to Right                |
| 7                | Equality       | `==`, `!=`                                                                   | Left to Right                |
| 8                | Bitwise AND    | `&`                                                                            | Left to Right                |
| 9                | Bitwise XOR    | `^`                                                                            | Left to Right                |
| 10               | Bitwise OR     | `                                                                                | `                            |
| 11               | Logical AND    | `&&`                                                                           | Left to Right                |
| 12               | Logical OR     | `                                                                                |                              |
| 13               | Conditional    | `?:`                                                                           | Right to Left                |
| 14               | Assignment     | `=`, `+=`, `-=`, `*=`, `/=`, `%=`, `&=`, `                         | =`, `^=`, `<<=`, `>>=` |
| 15               | Comma          | `,`                                                                            | Left to Right                |

By adhering to these rules and using parentheses effectively, you can ensure that your C programs are both correct and maintainable.
