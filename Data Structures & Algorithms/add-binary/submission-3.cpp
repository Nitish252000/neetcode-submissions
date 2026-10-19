
class Solution {
public:
    long long toDecimal(string str) {
        long long ans = 0;

        for (auto c : str) {
            ans = 2 * ans + (c - '0');
        }

        return ans;
    }

    string toBinary(long long n) {
        if (n == 0) return "0";

        string res;
        while (n != 0) {
            int bit = n & 1;
            n = n >> 1;
            res = to_string(bit) + res;
        }

        return res;
    }

    string addBinary(string a, string b) {
        long long num1 = toDecimal(a);
        long long num2 = toDecimal(b);

        long long num = num1 + num2;

        return toBinary(num);
    }
};
