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

#include    <algorithm>
#include    <iostream>
using namespace std;


//分治法

class Solution {
public:
    int maxSubArray(int A[], int n) 
    { 
        
        return _max_sub_array(A,0,n-1);
    
    }
    
    int _max_sub_array(int A[],int lo,int hi)
    {

        if(lo == hi)
        {
            return A[lo];
        }

        int mid = (lo+hi)/2;

        int left_sum = _max_sub_array(A,lo,mid);
        int right_sum = _max_sub_array(A,mid+1,hi);

        int mid_sum = 0;
        int left_part =A[mid];
        int now = A[mid];

        for(int i=mid-1;i>=lo;--i)
        {
            now += A[i];
            left_part = max(left_part,now);
        }

        int right_part = 0;
        now = 0;
        for(int i=mid+1;i<=hi;++i)
        {
            now += A[i];
            right_part = max(now,right_part);
        }

        mid_sum = left_part + right_part;


        return max(left_sum,max(mid_sum,right_sum));

    }
    
};

int main(void)
{
    int a[] = {-1,-10,2,3,-100};
    cout << Solution().maxSubArray(a,sizeof(a)/sizeof(*a)) << endl;
}
