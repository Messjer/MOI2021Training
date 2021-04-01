#include <iostream>
#include "lecture1.h"

using namespace std;

// hint: substitute the solution into main.cpp

/* TIOJ1001
int main1() {
    cout << "Hello Tmt World XD!!" << endl;
    return 0;
}
*/

/* TIOJ1002
int a, b;
int main() {

    cin >>a >>b;
    cout <<a+b <<endl;
    return 0;
}
*/


/* TIOJ1003
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
*/

/* TIOJ 1004

const int SIZE_N = 100;

bool dead[SIZE_N];
int cnt, i;
int n, alive;

int main()
{
    cin >>n;
    alive = n;
    i = -1; // remember 0 is number 1, so i=-1 before we start counting
    while (alive != 1) {
        i = (i + 1) % n;
        if (dead[i])
            continue;
        cnt++;
        if (cnt % 2 == 0) {
            dead[i] = true;
            cnt = 0;
            alive--;
        }
    }
    for (int i = 0; i < n; i++)
        if (!dead[i])
            cout <<i + 1 <<endl;
    return 0;
}

*/
