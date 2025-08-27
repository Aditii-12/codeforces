# Codeforces 771A — Bear and Friendship Condition

**Problem Statement:**

Bear Limak examines a social network. Its main functionality is that two members can become friends (then they can talk with each other and share funny pictures).

There are **n** members, numbered from **1** through **n**. There are **m** pairs of members who are friends. Of course, a member can't be a friend with themselves.

Let **A–B** denote that members A and B are friends. Limak thinks that a network is *reasonable* if and only if the following condition is satisfied:

> For every three distinct members (X, Y, Z), if X–Y and Y–Z then also X–Z.

In other words: if Alan and Bob are friends, and Bob and Ciri are friends, then Alan and Ciri should be friends as well.

You need to help Limak check if the network is reasonable. Print `"YES"` or `"NO"` (without the quotes) accordingly.

---

**Input**

The first line contains two integers `n` and `m`  
(`3 ≤ n ≤ 150 000`, `0 ≤ m ≤ …`) — the number of members and the number of friendship pairs.

Each of the next `m` lines contains two **distinct** integers `aᵢ` and `bᵢ` (1 ≤ aᵢ, bᵢ ≤ n, aᵢ ≠ bᵢ), meaning that those two members are friends. No pair appears more than once.

---

**Output**

Print `"YES"` if the network is reasonable; otherwise, print `"NO"`.

---

**Examples**

**input**  
4 3  
1 3  
3 4  
1 4  
**output**  
YES  

**input**  
4 4  
3 1  
2 3  
3 4  
1 2  
**output**  
NO   

**input**  
3 2  
1 2  
2 3  
**output**  
NO   
