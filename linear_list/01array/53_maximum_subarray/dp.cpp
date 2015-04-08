/*************************************************************************
	> File Name: main.cpp
	> Author:zhaoyihong 
	> Mail:zhaoyihong_at_126_dot_com 
	> Created Time: 2015年04月08日 星期三 14时31分07秒
 
 求最大连续字数组
    
 Find the contiguous subarray within an array (containing at least one number) which has the largest sum.

 For example, given the array [−2,1,−3,4,−1,2,1,−5,4],
 the contiguous subarray [4,−1,2,1] has the largest sum = 6.

 click to show more practice.

 More practice:
 If you have figured out the O(n) solution, try coding another solution using the divide and conquer approach, which is more subtle.
 
 
 ************************************************************************/

#include <algorithm>
#include    <iostream>
using namespace std;

//动态规划法


class Solution {
public:
    int maxSubArray(int A[], int n) 
    {
        int current_sum = 0;
        int history_sum = A[0];
        
        for(int i=0;i<n;++i)
        {
            if(current_sum  >= 0)
            {
                current_sum += A[i];
            }
            else
            {
                current_sum = A[i];
            }
            
            if(current_sum > history_sum)
            {
                history_sum = current_sum;
            }
                
        }
        
        return history_sum;
    }
};

int main(void)
{
    int a[] = {-1,-10,2,3,-100};
    cout << Solution().maxSubArray(a,sizeof(a)/sizeof(*a)) << endl;
}
