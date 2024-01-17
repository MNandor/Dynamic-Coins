# Coin Change Problem

Solve the Coin Change Problem using Dynamic Programming.
`c`

## Explanation

The **Coin Change Problem** is a poster-child of Dynamic Programming.

You have `n` types of coins, each with a given value.
You want to pay `x` amount of money in **as few coins as possible**.

## Example

You have `3` coins with values: `1, 4, 5`.
You want to pay `13`.

Greedy solution (use largest coin possible): `5 + 5 + 1 + 1 + 1`
Dynamic solution: `5 + 4 + 4`

## How to Run


`gcc main.c && ./a.out 54` where 54 is the value to pay.
