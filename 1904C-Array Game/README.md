# Array Game – Codeforces 1904C  

## 📌 Problem Statement  
You are given an array `a` of size `n` and an integer `k`.  
In one operation, you can:  

1. Select two elements `x` and `y` from the array.  
2. Insert their **absolute difference** `|x - y|` into the array.  

You want to minimize the **minimum element** of the array after at most `k` such operations.  

Print the smallest possible minimum value.  

---

## 🔹 Input Format  
- The first line contains a single integer `t` — number of test cases.  
- Each test case consists of:  
  - Two integers `n, k` — size of the array and number of operations allowed.  
  - An array of `n` integers.  

---

## 🔹 Output Format  
For each test case, output a single integer — the minimum possible element after at most `k` operations.  

---

## 🔹 Constraints  
- `1 ≤ t ≤ 1000`  
- `2 ≤ n ≤ 2000`  
- `1 ≤ k ≤ 3`  
- `1 ≤ a[i] ≤ 10^9`  
- The sum of `n` over all test cases does not exceed `2000`.  

---

## 🔹 Example  

### Input  
4  
5 2  
3 9 7 15 1  
4 3  
7 4 15 12  
6 2  
42 47 50 54 62 79  
2 1  
500000000000000000 1000000000000000000  

### Output  
1  
0  
3  
500000000000000000  
