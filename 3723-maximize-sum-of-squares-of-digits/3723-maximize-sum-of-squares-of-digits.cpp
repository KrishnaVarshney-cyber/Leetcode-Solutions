class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        string ans;
        if(num*9<sum){
            return "";
        }
        while(num>0 && sum>0){
            while(sum>=9){
                ans+=to_string(9);
                sum-=9;
                num--;
            }
            while(sum>=8){
                ans+=to_string(8);
                sum-=8;
                num--;
            }
            while(sum>=7){
                ans+=to_string(7);
                sum-=7;
                num--;
            }
            while(sum>=6){
                ans+=to_string(6);
                sum-=6;
                num--;
            }
            while(sum>=5){
                ans+=to_string(5);
                sum-=5;
                num--;
            }
            while(sum>=4){
                ans+=to_string(4);
                sum-=4;
                num--;
            }
            while(sum>=3){
                ans+=to_string(3);
                sum-=3;
                num--;
            }
            while(sum>=2){
                ans+=to_string(2);
                sum-=2;
                num--;
            }
            while(sum>=1){
                ans+=to_string(1);
                sum-=1;
                num--;
            }
        }
        while(num>0){
            ans+=to_string(0);
            num--;
        }
        return ans;
    }
};