# D. Jumping Through Segments

## Problem Statement

Polycarp is designing a level for a game. The level consists of `n` segments on the number line.  
The player starts at position `0` and makes exactly `n` moves, one per segment.

- In one move, the player can move to any point within distance **≤ k** of their current position.
- After the `i`-th move, the player must land inside the `i`-th segment `[lᵢ, rᵢ]`.

The level is completed if the player reaches the `n`-th segment following these rules.

Your task is to determine the **minimum integer `k`** such that it is possible to complete the level.

---

## Input Format

- The first line contains an integer `t` — the number of test cases.
- Each test case:
  - An integer `n` — the number of segments.
  - Then `n` lines follow, each containing two integers `lᵢ` and `rᵢ` — the boundaries of the `i`-th segment.

---

## Output Format

For each test case, output a single integer — the minimum value of `k`.

---

## Constraints

- `1 ≤ t ≤ 10⁴`
- `1 ≤ n ≤ 2⋅10⁵`
- `0 ≤ lᵢ ≤ rᵢ ≤ 10⁹`
- The sum of `n` across all test cases ≤ `2⋅10⁵`

---

## Example

### Input
2  
3  
0 5  
7 10  
13 17  
3  
1 2  
4 5  
11 12  

### Output
3  
5  
