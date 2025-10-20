#include <stdio.h>

int main() 
{
    int x, ans = 0;
    scanf("%d", &x);

    // Count the number of 1 bits in x
    while (x > 0) {
        ans += x & 1;   // Add 1 if the last bit of x is 1
        x >>= 1;        // Shift x right by 1 bit
    }

    printf("%d\n", ans); // Print the result
    return 0;
}
