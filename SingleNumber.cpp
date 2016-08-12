#include "iostream"
#include "vector"
using namespace std;
class Solution{
public :
    int singleNumber(vector<int>& nums) {
        int ones = 0;
        int twos = 0;
        int three = 0;
        vector<int>::iterator it;
        for(it = nums.begin(); it != nums.end(); it ++){
                cout<<*it<<ends;
            twos|= ones & (*it);
            ones ^= (*it);
            three = ones & twos ;
            ones &= ~three;
            twos &= ~three;
        }
        return ones;
    }
};
int main()
{
    Solution s;
    int nums[] = {1,1,1,2,8,2,5,2,5,5};
    vector<int> vec(&nums[0],&nums[10]);
    cout <<s.singleNumber(vec);

}
