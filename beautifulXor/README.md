## ⚙️ Algorithm Explanation

### Step 1. Handle the trivial case
If `a == b`, we already have equality → print `0`.

### Step 2. Find highest set bits
We find the **index of the most significant bit (MSB)** for both `a` and `b`.

```c
for (i = 50; i >= 0; i--) {
    if ((1LL << i) & a) { ha = i; break; }
}
for (i = 50; i >= 0; i--) {
    if ((1LL << i) & b) { hb = i; break; }
}
## 💡 Key Observation

The **highest set bit (MSB)** of a number can **never increase** after applying `a = a XOR x` with `x ≤ a`.  
It can only:
- stay the same, or  
- move to a lower position (if we unset the highest bit).

Therefore:
- If the highest set bit of `b` is **greater** than that of `a`,  
  → it’s **impossible** to reach `b` from `a`.

Otherwise, we can construct a valid sequence of XOR operations.
