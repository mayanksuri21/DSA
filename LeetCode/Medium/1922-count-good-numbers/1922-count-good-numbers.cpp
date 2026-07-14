class Solution {
public:
    const int M = 1e9 + 7;
    int findPow(long long x , long long n){
        if(n == 0) return 1;

        long long half = findPow(x,n/2);
        int result = (half * half) % M;

        if(n%2 == 1){
            return ((x * result)% M);
        }
        return result;
    }
    int countGoodNumbers(long long n) {

        return (long long)findPow(5,(n+1)/2) * findPow(4,n/2) % M;
        
    }
};