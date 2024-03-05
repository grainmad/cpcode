#include<bits/stdc++.h>

using namespace std;

#define A 0
#define B 1

random_device seed;

mt19937 engine(seed());

uniform_int_distribution<> distrib(A, B);

int main() {
    for (int i=0; i<100; i++) {
        cout << distrib(engine);
    }
    cout << "\n";
    return 0;
}
