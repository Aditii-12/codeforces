# Codeforces 802J - Send the Fool Further! (easy)

Heidi has received a letter from her friend Jenny. The letter contains an instruction: "send the fool further!"  
Jenny and Heidi have many mutual friends. Heidi can choose one of them and send the letter to that person.  
This friend, in turn, will do the same thing — choose another one of his friends (excluding the one who gave him the letter) and send it further.  
Convinced that it is some prank, Heidi wants to know how far this joke can go on.  

Formally, there are **n** friends (numbered 0 to n−1). Jenny is friend number **0**. Friendships are given in the form of a tree (n−1 edges).  
Each edge has a **cost** (time in minutes) Heidi spends to deliver the letter along that edge.  
Heidi wants to avoid visiting anyone more than once, including Jenny.  
Your task is to find the **maximum total cost** she can spend delivering the letter.

---

## Input
- The first line contains a single integer **n** (3 ≤ n ≤ 100) — the number of friends.  
- Each of the next **n−1** lines contains three integers `u v c`  
  - `u` and `v` (0 ≤ u, v ≤ n−1, u ≠ v) denote that `u` and `v` are friends.  
  - `c` (1 ≤ c ≤ 10^4) is the cost of delivering the letter between `u` and `v`.  

It is guaranteed that the given graph is a tree.

---

## Output
- Print a single integer — the **maximum possible total cost** of delivering the letter starting from Jenny (friend 0).

---

## Example

### Input  
11  
1 0 1664  
2 0 881
3 2 4670  
4 2 1555  
5 1 1870  
6 2 1265  
7 2 288  
8 7 2266  
9 2 1536  
### Output  
5551  
