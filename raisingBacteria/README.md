# Raising Bacteria - Solution

## Problem Overview
The problem "Raising Bacteria" asks to determine the minimum number of steps required to reach a number `x` starting from 1, using the following operations:  
1. Double the current number.
2. Add 1 to the current number.  

A simpler way to solve the problem is to **count the number of 1s in the binary representation of `x`**. Each `1` represents a step where we had to add 1, while `0`s represent steps where we only doubled.

---

## Algorithm Explanation
1. **Input**: Read the integer `x`.  
2. **Count 1-bits**:
   - Initialize a counter `ans = 0`.
   - While `x > 0`:
     - Check if the last bit is 1 using `x & 1`.
     - Increment the counter `ans` if it is 1.
     - Shift `x` right by 1 (`x >>= 1`) to process the next bit.
3. **Output**: Print the counter `ans`, which represents the minimum number of steps.
