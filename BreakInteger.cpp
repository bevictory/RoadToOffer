#include <iostream>
#include "math.h"
using namespace std;
class Solution {
public:
    int integerBreak2(int n){
        if(n==1) return 1;
        if(n == 2) return 2;
        if(n==3) return 3;
        if(n==4) return 4;
        int result=1;
        while(n-3>=2){
            n-=3;
            result *=3;
        }
        result *=n;
        return result;
    }
    int integerBreak(int n) {
        if(n==1) return 1;
        int max =0;
        for(int i=2;i<=n;i++){
            int average = n /i;
            int remain = n - average*i;
            int result =1;
            result= pow(average, i-remain);
            result *= pow(average+1,remain);
            if(result > max){
                max = result ;
            }
        }
        return max;
    }
};
int main(){
    Solution s ;

    cout<<s.integerBreak2(7);
}
