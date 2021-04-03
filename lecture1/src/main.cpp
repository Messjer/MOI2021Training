#include <iostream>
#include <cmath>

using namespace std;

#include <iostream>
#include <cmath>

using namespace std;

// Euclidean Algorithm
int gcd(int a, int b) {
    if (a < b)
        return gcd(b, a);
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

const int SIZE_N = 100;

int a[SIZE_N], n;

int main() {
    cin >>n;
    while (n != 0) {
        for (int i = 0; i < n; i++)
            cin >>a[i];
        int cnt = 0;
        for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++) {
            if (gcd(a[i], a[j]) == 1) {
                cnt++;
            }
        }
        if (cnt > 0)
            printf("%.6f\n", sqrt((n * (n - 1) / 2)/(cnt * 1.0)*6));
        else
            printf("No estimate for this data set.\n");
        cin >>n;
    }
    return 0;
}
