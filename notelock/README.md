# Notelock Algorithm Explained

This file explains the algorithm used to solve the "Notelock" problem.

---

## The Core Idea 💡

The algorithm uses a **greedy strategy**. It scans the sequence of 0s and 1s from left to right, making the most "efficient" choice at every step.

The main idea is to keep track of just one thing: the position of the **last '1' that we know is safe**. This is the `last_safe_one`.

---

## The Algorithm Step-by-Step

1.  Start by assuming no '1's are safe (you can imagine the `last_safe_one` is at an invalid spot, like -1). Also, set your `protections` counter to 0.

2.  Iterate through the sequence, one character at a time.

3.  If the character is a **'0'**, just ignore it and move on. It doesn't need to be safe.

4.  If the character is a **'1'**, you must ensure it becomes safe. You have to ask a simple question:
    * "Is this '1' already *passively* safe?"
    * It's passively safe if the `last_safe_one` is "close enough" to cover it. "Close enough" means it's within the $K-1$ spots immediately before the current '1'.

5.  Based on the answer, you do one of two things:

    * **Case 1: The `last_safe_one` is too far away** (or we haven't seen a safe '1' yet).
        * This current '1' is *not* passively safe.
        * To make it safe, we **must** manually protect it.
        * Increment the `protections` counter by 1.

    * **Case 2: The `last_safe_one` is close enough.**
        * This current '1' is already "covered" by that previous safe '1'.
        * It's passively safe, so we don't need to spend a protection. We do nothing.

6.  Finally, no matter which case it was, the '1' you are currently on is **now safe** (either because you just protected it or because it was already covered). You must **update** your tracker: the `last_safe_one` is now the position of this current '1'.

7.  Repeat this process until you reach the end of the sequence. The final value of the `protections` counter is the minimum number needed.
