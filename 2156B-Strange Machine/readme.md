# Problem Statement

You are given 𝑛 machines arranged in a circle, where 𝑛 is at most 20. Each machine is either of type A or type B. The machines are numbered clockwise from 1 to 𝑛, and the type of the 𝑖-th machine is denoted by 𝑠𝑖.

Each machine takes an integer 𝑥 and updates it according to its type:

* **Type A:** Decrease 𝑥 by 1. Formally, update 𝑥 := 𝑥 − 1.
* **Type B:** Replace 𝑥 with the floor of half its value. Formally, update 𝑥 := ⌊𝑥/2⌋, where ⌊𝑦⌋ denotes the floor of 𝑦.

You are given 𝑞 queries, each consisting of a single integer 𝑎. In each query, you start at machine 1 holding an integer 𝑎.

Each second, the following two actions occur in order:

1. The current machine updates 𝑎 according to its type.
2. Move one step clockwise to the next machine:

   * If you are at machine 𝑖 where 1 ≤ 𝑖 ≤ 𝑛−1, move to machine 𝑖 + 1.
   * If you are at machine 𝑛, move to machine 1.

This process continues until your integer 𝑎 becomes 0. For each query, determine the number of seconds required for 𝑎 to reach 0.

All queries are independent.

---

## Input

Each test contains multiple test cases. The first line contains the number of test cases 𝑡 (1 ≤ 𝑡 ≤ 10⁴).

The description of each test case follows:

* The first line of each test case contains two integers 𝑛 and 𝑞 (1 ≤ 𝑛 ≤ 20, 1 ≤ 𝑞 ≤ 10⁴).
* The second line contains a string 𝑠 (|𝑠| = 𝑛 and 𝑠𝑖 = A or B), representing the types of machines.
* The third line contains 𝑞 integers 𝑎₁, 𝑎₂, …, 𝑎𝑞 (1 ≤ 𝑎ᵢ ≤ 10⁹).

There are no constraints on the sum of 𝑛 across test cases.
It is guaranteed that the sum of 𝑞 over all test cases does not exceed 10⁴.

---

## Output

For each test case, output 𝑞 integers representing the answers to each query.

---

## Example

### Input

```
3
2 2
BA
3 4
1 1
B
20
6 4
BAABBA
2 8 32 95
```

### Output

```
2 3
5
2 5 8 11
```

---

## Note

### Test Case 1

* Query: 𝑎 = 3

  * Machine 1 (B): 𝑎 = ⌊3/2⌋ = 1 → Move
  * Machine 2 (A): 𝑎 = 1 − 1 = 0
    → Takes 2 seconds

* Query: 𝑎 = 4

  * Machine 1 (B): 𝑎 = ⌊4/2⌋ = 2 → Move
  * Machine 2 (A): 𝑎 = 2 − 1 = 1 → Move
  * Machine 1 (B): 𝑎 = ⌊1/2⌋ = 0
    → Takes 3 seconds

### Test Case 2

* Only one machine of type B
* Query: 𝑎 = 20
  Sequence:
  20 → 10 → 5 → 2 → 1 → 0
  → Takes 5 seconds
