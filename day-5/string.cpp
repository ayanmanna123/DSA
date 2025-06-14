#include <iostream>
using namespace std;

int main()
{
    string s1 = "eetdgfjg";
    string s2 = "gf";
    bool found = false;

    for (int i = 0; i <= s1.length() - s2.length(); i++) {
        if (s1.substr(i, s2.length()) == s2) {
            cout << "ok";
            found = true;
            break;
        }
    }
    if (!found) cout << "not found";

    return 0;
}
