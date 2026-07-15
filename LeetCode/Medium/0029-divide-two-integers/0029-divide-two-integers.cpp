class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;

        if (dividend == divisor) return 1;

        bool sign = true;
        if ((dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0))
            sign = false;

        long long n = llabs((long long)dividend);
        long long d = llabs((long long)divisor);

        long long q = 0;

        while (n >= d) {
            int cnt = 0;
            while (n >= (d << (cnt + 1))) {
                cnt++;
            }
            q += (1LL << cnt);
            n -= (d << cnt);
        }

        if (q >= (1LL << 31)) {
            return sign ? INT_MAX : INT_MIN;
        }

        return sign ? (int)q : -(int)q;
    }
};
