#include "iostream"
using namespace std;
class Solution{
public :
    bool isPowerOfFour(int num) {

        if((num&(num-1)) ==0) {
             if((num&0x55555555)!=0)   return true;
        }
       return false;
    }
};
int main()
{
    Solution s;
    cout<< s.isPowerOfFour(8);

}
