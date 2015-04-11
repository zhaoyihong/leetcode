/*
Rotate an array of n elements to the right by k steps.
For example, with n = 7 and k = 3, the array [1,2,3,4,5,6,7] is rotated to [5,6,7,1,2,3,4].
 
 
*/

#include <iostream>
using namespace std;

class Solution {
public:
    void rotate(int nums[], int n, int k) {
            
        int m = k % n;

        //左移直接使用m
        //右移需要将m改为n-m,题中要求是右移
        m = n-m;

        if(m == 0)
        {
            return;
        }
        
        _reverse(nums,0,m-1);
        _reverse(nums,m,n-1);
        _reverse(nums,0,n-1);       
    }
    
private:   
    void _reverse(int nums[],int lo,int hi)
    {
        if(lo == hi)
        {
            return;
        }
        
        while(lo < hi)
        {
            int t = nums[hi];
            nums[hi] = nums[lo];
            nums[lo] = t;
            ++lo;
            --hi;
        }
    }
};


int main()
{
    int a[] = {0,1,2,3,4,5,6,7};
    int len_a = sizeof(a)/sizeof(*a);
    Solution().rotate(a,len_a,3);

    for(int i=0;i<len_a;++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
