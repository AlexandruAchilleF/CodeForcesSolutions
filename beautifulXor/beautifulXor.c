#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare a variable 'tt' (test cases) of type long long
    long long tt;
    // Read the number of test cases from standard input
    scanf("%lld", &tt);

    // Loop for each test case
    while (tt--)
    {
        // Declare variables 'a' and 'b' of type long long
        long long a, b;
        // Read the two integers for the current test case
        scanf("%lld %lld", &a, &b);

        // If a and b are already equal, no operations are needed.
        if (a == b)
        {
            printf("0\n"); // Print 0 operations
            continue;      // Skip to the next test case
        }

        // --- Find the highest set bit (MSB) of a and b ---
        // 'ha' will store the index of the highest bit of a
        // 'hb' will store the index of the highest bit of b
        long long ha = 0, hb = 0;
        
        // Loop from a high bit index down to 0
        for (long long i = 50; i >= 0; i--)
        {
            // (1LL << i) creates a number with only the i-th bit set 
            // The '&' operator is a bitwise AND.
            // If (a & (1LL << i)) is non-zero, it means the i-th bit of 'a' is 1.
            if ((1LL << i) & a)
            {
                ha = i;  // Store the index of this highest bit
                break;   // Stop the loop since we found the highest one
            }
        }
        // Repeat the same process for 'b'
        for (long long i = 50; i >= 0; i--)
        {
            if ((1LL << i) & b)
            {
                hb = i;
                break;
            }
        }

        // --- Check for the impossible case ---
        // The operation a := a XOR x (where x <= a) can *never* increase the
        // highest set bit of 'a'. It can only keep it the same or lower it.
        // So, if b's highest bit is greater than a's highest bit,
        // it is impossible to transform 'a' into 'b'.
        if (hb > ha)
        {
            printf("-1\n"); // Print -1
            continue;       // Skip to the next test case
        }
        else // --- Handle the possible case (ha >= hb) ---
        {
            // 'v' will store the sequence of 'x' values for our operations
            long long v[64]; // 64 is a safe size (max 50-60 bits)
            // 'sz' will count the number of operations
            int sz = 0;

            // We will find all bit positions 'i' where 'a' and 'b' differ.
            // For each mismatch, we will add x = 2^i to our operation list 'v'.
            // We only need to check bits up to 'ha', since ha >= hb and any
            // bits higher than 'ha' are 0 in both 'a' and 'b' (or 'a' only).
            // The code uses (ha > hb ? ha : hb) which is just 'ha' in this 'else' block.
            for (long long i = 0; i <= (ha > hb ? ha : hb); i++)
            {
                // Check if the i-th bit is set (1) in 'b'
                if ((1LL << i) & b)
                {
                    // If bit 'i' is 1 in 'b' but 0 in 'a' (a mismatch)
                    if (!((1LL << i) & a))
                    {
                        long long ok = 1LL << i; // The value x = 2^i
                        v[sz++] = ok;            // Add it to our operation list
                    }
                }
                // Else (the i-th bit is 0 in 'b')
                else if ((1LL << i) & a)
                {
                    // If bit 'i' is 0 in 'b' but 1 in 'a' (a mismatch)
                    // The inner 'if' is redundant but correct: if (!((1LL << i) & b))
                    // (We already know this from the 'else' branch)
                    {
                        long long ok = 1LL << i; // The value x = 2^i
                        v[sz++] = ok;            // Add it to our operation list
                    }
                }
            }
          
            // Print the number of operations
            printf("%d\n", sz);
            // Print the sequence of 'x' values
            for (int i = 0; i < sz; i++)
            {
                printf("%lld ", v[i]);
            }
            printf("\n"); // Print a newline at the end
        }
    }
    return 0;
}
