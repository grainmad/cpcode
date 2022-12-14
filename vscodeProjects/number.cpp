#include <iostream>
#include <cstdio>

using namespace std;

class Number {
    private:
    int pow(int p) {
        int rt = 1;
        while (p) {
            rt *= 10;
            p--;
        }
        return rt;
    }
    public:
    int number;
    Number(int num):number(num){}
    Number get(int idx) {
        return Number(number/pow(idx)%10);
    }
    Number remove(int idx) {
        int p = pow(idx+1);
        return Number(number/p*p+number%(p/10));
    }
    Number change(int idx, int a) {
        int p = pow(idx+1);
        return Number(number/p*p+a*(p/10)+number%(p/10));
    }
    Number exchange(int x, int y) {
        return Number(change(x, get(y).number).change(y, get(x).number));
    }
};

int main() {
    Number a(12345);
    for (int i=0; i<5; i++) {
        cout<<a.get(i).number << endl;
    }
    for (int i=0; i<5; i++) {
        cout << a.remove(i).number << endl;
    }
    for (int i=0; i<5; i++) {
        cout << a.change(i, 6).number << endl;
    }
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            cout << i << " " << j << " " << a.exchange(i, j).number << endl;
        }
    }
    return 0;
}
