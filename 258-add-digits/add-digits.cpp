class Solution {
public:
    int summation(int num){
        int sum{};
        while(num!=0){
            sum+=num%10;
            num=num/10;
        }
        return sum;
    }
    int addDigits(int num) {
        while(num>9){
            num=summation(num);
        }
        return num;
        
    }
};