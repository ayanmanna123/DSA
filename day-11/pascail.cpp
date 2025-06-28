#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> generate(numRows);

        for (int i = 0; i < numRows; i++) {
            generate[i].resize(i + 1);   
            generate[i][0] = 1;         
            generate[i][i] = 1;         
            for (int j = 1; j < i; j++) {
                generate[i][j] = generate[i - 1][j - 1] + generate[i - 1][j];
            }
        }

        return generate;
    }
};

int main() {

    Solution sol;
    vector<vector<int>> result = sol.generate(10);

    // Optional: print the result
    for (const auto& row : result) {
        for (int num : row) {
            cout << num << " ";
        }
        cout << endl;
    }
}