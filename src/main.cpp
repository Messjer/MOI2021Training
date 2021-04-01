#include <iostream>

using namespace std;

int pizza(int n) {
    if (n == 0)
        return 1;
    else {
        // n-th line can have at most n intersections
        // with existing lines, giving n new areas
        return pizza(n - 1) + n;
    }
}
int n;

int main() {
    cin >>n;
    cout <<pizza(n) <<endl;
    return 0;
}
