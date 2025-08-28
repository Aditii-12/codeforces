# Fall Down (Codeforces 1169G)

## Problem Statement

You are given a grid with `n` rows and `m` columns.  
Each cell of the grid can contain one of the following:

- `*` : a stone  
- `o` : an obstacle  
- `.` : an empty cell  

The stones fall **downward** until they either land on top of an obstacle `o`, another stone `*`, or reach the bottom of the grid.  

Your task is to simulate this process and output the final configuration of the grid after all stones have fallen.

---

## Input Format
- The first line contains two integers `n` and `m` — the number of rows and columns.  
- The next `n` lines each contain a string of length `m`, representing the grid.  

---

## Output Format
- Print the resulting grid after all stones fall down.

---

## Constraints
- `1 ≤ n, m ≤ 500`
- Each character in the grid is either `*`, `o`, or `.`.

---
