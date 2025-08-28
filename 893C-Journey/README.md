# Journey (Codeforces 839C)

There are **n** cities connected by **n − 1** bidirectional roads in the Seven Kingdoms, forming a tree (i.e., any city is reachable from any other). Theon and Yara Greyjoy start in **city 1**, riding a horse. The horse moves as follows:

- Upon arriving at a city (including the first one), it randomly selects one of the adjacent cities **which they have not visited yet** and moves there with **equal probability**.
- The journey continues until there are **no unvisited neighboring cities** to move into.

Each road has a length of **1**. Your task is to determine the **expected total distance** (number of steps) traveled from the start until the horse stops.

---

### Input
- The first line contains a single integer **n** — the number of cities (**1 ≤ n ≤ 100000**).  
- The next **n − 1** lines each contain two integers **u** and **v** (**1 ≤ u, v ≤ n, u ≠ v**), denoting a road between cities **u** and **v**.  

It is guaranteed that all cities are mutually reachable.

---

### Output
Print a single floating-point number — the expected length of their journey. Your answer is accepted if its absolute or relative error does not exceed **10⁻⁶**.

---

### Examples

#### Input  
4  
1 2  
1 3  
2 4  
#### Output  
1.500000000000000  
#### Input  
5  
1 2  
1 3  
3 4  
2 5  
#### Output    
2.000000000000000  

