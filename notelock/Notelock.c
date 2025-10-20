#include <stdio.h>
#include <string.h>

/*
 * Helper macro to find the maximum of two numbers
 * We need this to calculate the start of the (k-1) window
 */
#define MAX(a, b) ((a) > (b) ? (a) : (b))

/**
 * Solves a single test case for the Notelock problem
 */
void solve() {
    int n, k;
    scanf("%d %d", &n, &k);
    
    // n <= 1000. Add +5 for safety (null terminator, etc.)
    char s[1005];
    scanf("%s", s);

    int protections = 0;
    // Tracks the index of the last '1' that Teto cannot change
    // Initialized to -1 (meaning no safe '1's seen yet)
    int last_safe_one = -1;

    // Iterate through the string, 0-indexed
    for (int i = 0; i < n; i++) {
        if (s[i] == '1') {
            /*
             * Teto looks at the window of k-1 elements before index i
             * In 0-based indexing, this window starts at
             * Index: i, 1-based: i+1
             * Window starts at 1-based: max(1, (i+1) - k + 1) = max(1, i - k + 2)
             * Back to 0-based: max(0, i - k + 1)
             */
            int window_start = MAX(0, i - k + 1);

            // Check if the last safe '1' is *outside* this window
            if (last_safe_one < window_start) {
                // Yes. This means any '1's in the window were *not* safe
                // and Teto changed them to '0'
                // Teto *will* change s[i] unless we protect it
                protections++;
                
                // This '1' is now safe (because we protected it)
                last_safe_one = i;
            } else {
                // No. The '1' at last_safe_one is in the window
                // It blocks Teto from changing s[i]
                // This '1' is "passively" safe
                last_safe_one = i;
            }
        }
    }
    
    printf("%d\n", protections);
}

int main() {
    int t;
    // Read the number of test cases
    scanf("%d", &t);
    // Loop t times
    while (t--) {
        solve();
    }
    return 0;
}
