#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;              // Decimal input
    int ans = 0;
    int place = 1;         // Represents 10^i

    while (n != 0) {
        int bit = n & 1;
        ans += bit * place;
        place *= 10;       // Move to next place (like 1 -> 10 -> 100)
        n = n >> 1;
    }

    cout << ans << endl;   // Output binary as an int (e.g. 101)
}
