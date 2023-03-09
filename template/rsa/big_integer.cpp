#include <bits/stdc++.h>

using namespace std;
struct BigInteger {
    string s;
    BigInteger(string _s = "0") : s(_s) {}
    BigInteger operator+(BigInteger& o) { return BigInteger(add(s, o.s)); }
    bool operator<(BigInteger& o) { return numcmp(s, o.s) == -1; }
    BigInteger operator-(BigInteger& o) { return BigInteger(sub(s, o.s)); }
    BigInteger operator*(BigInteger& o) { return BigInteger(mul(s, o.s)); }
    BigInteger division(BigInteger& o, int precision) {
        if (o.s != "0") {
            return BigInteger(div(s, o.s, precision));
        }
        return BigInteger("INF");
    }
    BigInteger pow_mod(BigInteger& p, BigInteger& m) {
        return BigInteger(fpow_mod(s, p.s, m.s));
    }
    BigInteger operator/(BigInteger& o) {
        return BigInteger(div(s, o.s).first);
    }
    BigInteger operator%(BigInteger& o) {
        return BigInteger(div(s, o.s).second);
    }
    BigInteger operator^(BigInteger& o) { return BigInteger(fpow(s, o.s)); }
    friend ostream& operator<<(ostream& os, BigInteger& o);
    /*
        大数加,减,乘,除,比较大小
        考虑翻转补0
        考虑最后答案去除前导0, 以及全0情况
    */

    // 大数加法, 非负整数a,b
    string add(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (a.size() < b.size())
            a.push_back('0');
        while (b.size() < a.size())
            b.push_back('0');
        string ans;
        int c = 0;
        for (int i = 0; i < a.size(); i++) {
            int num = (a[i] - '0') + (b[i] - '0') + c;
            ans.push_back(num % 10 + '0');
            c = num / 10;
        }
        if (c)
            ans.push_back(c + '0');
        reverse(ans.begin(), ans.end());
        return ans;
    }

    // 大数比较, 可有前导0, 非负整数
    int numcmp(string a, string b) {
        // 注意前导0
        if (a.find_first_not_of('0') == string::npos)
            a = "0";
        else
            a = a.substr(a.find_first_not_of('0'));
        if (b.find_first_not_of('0') == string::npos)
            b = "0";
        else
            b = b.substr(b.find_first_not_of('0'));
        if (a.size() < b.size())
            return -1;
        else if (a.size() > b.size())
            return 1;
        else {
            if (a < b)
                return -1;
            else if (a > b)
                return 1;
            else
                return 0;
        }
    }

    // 大数减法,非负整数a,b
    string sub(string a, string b) {
        bool flag = false;
        if (numcmp(a, b) == 0)
            return "0";
        if (numcmp(a, b) == -1) {
            flag = true;
            swap(a, b);
        }
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        while (a.size() < b.size())
            a.push_back('0');
        while (b.size() < a.size())
            b.push_back('0');
        string ans;
        int c = 0;
        for (int i = 0; i < a.size(); i++) {
            int num = (a[i] - '0') - (b[i] - '0') - c;
            if (num < 0) {
                num += 10;
                c = 1;
            } else
                c = 0;
            ans.push_back(num + '0');
        }
        reverse(ans.begin(), ans.end());
        if (flag)
            return "-" + ans.substr(ans.find_first_not_of('0'));
        else
            return ans.substr(ans.find_first_not_of('0'));
    }

    // 大数乘法, 非负整数
    string mul(string a, string b) {
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        string ans = "0";
        for (int i = 0; i < a.size(); i++) {
            string t;
            for (int j = 0; j < i; j++)
                t.push_back('0');
            int c = 0;
            for (int j = 0; j < b.size(); j++) {
                int num = (a[i] - '0') * (b[j] - '0') + c;
                t.push_back(num % 10 + '0');
                c = num / 10;
            }
            if (c)
                t.push_back(c + '0');
            reverse(t.begin(), t.end());
            ans = add(ans, t);
        }
        if (ans.find_first_not_of('0') == string::npos)
            return "0";  // 注意乘0情况会得到多个0
        return ans.substr(ans.find_first_not_of('0'));
    }

    // 大数整除, 非负整数, 返回商和余数
    pair<string, string> div(string a, string b) {
        int cp = numcmp(a, b);
        if (cp == 0)
            return make_pair("1", "0");
        if (cp == -1)
            return make_pair("0", a);
        string ans, t;
        for (int i = 0; i < a.size(); i++) {
            t.push_back(a[i]);
            int c = 0;
            while (numcmp(b, t) != 1) {  // b<=t
                t = sub(t, b);
                c++;
            }
            ans.push_back(c + '0');
        }
        // 不会出现全零情况
        return make_pair(ans.substr(ans.find_first_not_of('0')), t);
    }

    // 高精度除法, 非负整数, 截取到小数点后p位
    string div(string a, string b, int p) {
        string ans, t;
        for (int i = 0; i < a.size(); i++) {
            int c = 0;
            t.push_back(a[i]);
            while (numcmp(b, t) != 1) {
                c++;
                t = sub(t, b);
            }
            ans.push_back(c + '0');
        }
        ans.push_back('.');
        for (int i = 0; i < p; i++) {
            int c = 0;
            t.push_back('0');
            while (numcmp(b, t) != 1) {
                c++;
                t = sub(t, b);
            }
            ans.push_back(c + '0');
        }
        if (ans.find_first_not_of('0') == ans.find_first_of('.'))
            return "0" + ans.substr(ans.find_first_of('.'));
        return ans.substr(ans.find_first_not_of('0'));
    }
    // x^p
    string fpow(string x, string p) {
        string rt = "1";
        while (numcmp(p, "0")) {
            if ((p.back() - '0') & 1) {
                rt = mul(rt, x);
            }
            x = mul(x, x);
            p = div(p, "2").first;
        }
        return rt;
    }
    // x^p%m
    string fpow_mod(string x, string p, string m) {
        string rt = "1";
        while (numcmp(p, "0")) {
            if ((p.back() - '0') & 1) {
                rt = mul(rt, x);
                rt = div(rt, m).second;
            }
            x = mul(x, x);
            x = div(x, m).second;
            p = div(p, "2").first;
        }
        return rt;
    }
};
ostream& operator<<(ostream& os, const BigInteger& o) {
    cout << o.s;
    return os;
}
// string add(string a, string b) {
//     reverse(a.begin(), a.end());
//     reverse(b.begin(), b.end());
//     while (a.size() < b.size())
//         a.push_back('0');
//     while (b.size() < a.size())
//         b.push_back('0');
//     string ans;
//     int c = 0;
//     for (int i = 0; i < a.size(); i++) {
//         int num = (a[i] - '0') + (b[i] - '0') + c;
//         ans.push_back(num % 10 + '0');
//         c = num / 10;
//     }
//     if (c)
//         ans.push_back(c + '0');
//     reverse(ans.begin(), ans.end());
//     return ans;
// }
int main() {
    BigInteger a("21"), b("22"), m("4");
    // cout << (a + b) << endl;
    // cout << (a - b) << endl;
    // cout << (a * b) << endl;
    cout << (a / b) << endl;
    cout << (a % b) << endl;
    // cout << (a ^ b) << endl;
    // cout << a.pow_mod(b, m) << endl;
    // cout << a.division(b, 3) << endl;
    return 0;
}