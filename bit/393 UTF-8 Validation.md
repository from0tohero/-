# UTF-8 Validation
[Link](https://leetcode.com/problems/utf-8-validation/description)

## Lessons Learned
* We don't really need `bitset<>` in general, use `>>` or `<<` to shift to the position you want
* The priority of `>>` is **lower** than `==`, remember to wrap a `()` around `>>`
