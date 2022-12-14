#include <iostream>
#include <cstdio>
using namespace std;

int status[9];

void up(int x);
void down(int x);

void printStatus() {
    for (int i=0; i<9; i++) {
        cout << status[i] << " ";
    } cout << endl;
}

void down(int x) {
    if (x>1) down(x-2);
    status[x] = 0;
    printStatus();
    if (x>1) up(x-2);
    if (x>0) down(x-1);
}

void up(int x) {
    if (x>0) up(x-1);
    if (x>1) down(x-2);
    status[x] = 1;
    printStatus();
    if (x>1) up(x-2);
}


int main() {
    freopen("9rings.txt", "w", stdout);
    for (int i=0; i<9; i++) {
        status[i] = 1;
    }
    down(8);
    // system("pause");
    return 0;
}