# Codeforces 723D — Lakes in Berland

**Problem Statement:**

The map of Berland is a rectangle of the size _n_ × _m_, which consists of cells of size 1 × 1. Each cell is either land or water. The map is surrounded by the ocean.

Lakes are the maximal regions of water cells, connected by sides, which are **not connected with the ocean**. Formally, a lake is a set of water cells such that:

- It's possible to get from any cell of the set to any other without leaving the set and moving only to cells adjacent by sides.
- None of them is located on the border of the rectangle.
- It is impossible to add one more water cell to the set that would be connected with any cell of the set.

You task is to fill up with earth the minimum number of water cells so that there will be exactly **k** lakes in Berland. Note that the initial number of lakes on the map is not less than **k**.

---

**Input**

The first line contains three integers `n, m, k`  
(`1 ≤ n, m ≤ 50`, `0 ≤ k ≤ 50`) — the sizes of the map and the number of lakes that should be left on the map.

The next `n` lines contain `m` characters each — the description of the map. Each character is either:
- `.` (water), or
- `*` (land).

It is guaranteed that the map contains **at least** `k` lakes.

---

**Output**

In the first line, print the minimum number of cells that should be transformed from water to land.

In the next `n` lines, print `m` characters — the map after the changes. The format must strictly follow the format of the map in the input (there is no need to print the size of the map). If there are several valid answers, print any of them.

It is guaranteed that the answer exists for the given input.

---

**Examples**

