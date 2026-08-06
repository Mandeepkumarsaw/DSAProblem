#include <iostream>
using namespace std;

class Solution {
public:
    int smallestNumber(int n, int t) {
        while (true) {
            int prod = 1;
            int temp = n;

            // Compute product of digits
            while (temp > 0) {
                prod *= (temp % 10);
                temp /= 10;
            }

            // Check divisibility
            if (prod % t == 0) {
                return n;
            }
            n++;
        }
    }
};

int main() {
    Solution s;

    int n, t;
    cout << "Enter n: ";
    cin >> n;
    cout << "Enter t: ";
    cin >> t;

    int result = s.smallestNumber(n, t);
    cout << "Smallest number >= " << n << " with digit product divisible by " << t << " is: " << result << endl;

    return 0;
}
