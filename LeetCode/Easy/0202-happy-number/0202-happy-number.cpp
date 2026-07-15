// class Solution {
// public:
//     int sq(int n){
//         int sum = 0 ;
//         while(n > 0){
//             int d = n % 10;
//             n = n /10;
//             sum += d*d;
//         }
//         return sum;
//     }
//     bool isHappy(int n) {
//         int slow = n , fast = n;
//         while(slow != fast && fast != 1){
//             slow = sq(n);
//             fast = sq(n);
//             fast = sq(n);

//             if(slow == fast && slow != 1){ // cycle detect and slow != 1
//                 return false;

//             }
//         }
//         return fast == 1 ? true : false;


        
//     }
// };


class Solution {
public:
    int sq(int n){
        int sum = 0;
        while(n > 0){
            int d = n % 10;
            n = n / 10;
            sum += d * d;
        }
        return sum;
    }

    bool isHappy(int n) {
        int slow = n, fast = n;

        do {
            slow = sq(slow);          // move 1 step
            fast = sq(sq(fast));      // move 2 steps
        } while(slow != fast);

        return slow == 1;
    }
};