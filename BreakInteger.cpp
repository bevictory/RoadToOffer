#include <iostream>
#include "math.h"
using namespace std;
class Solution {
public:
    int integerBreak(int n) {
        if(n==1) return 1;
        int max =0;
        for(int i=2;i<n;i++){
            int average = n /i;
            int remain = n - average*i;
            int result =1;
            result*= pow(average, i-remain);
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

    cout<<s.integerBreak(5);
}
