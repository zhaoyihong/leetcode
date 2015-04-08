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

#include    <iostream>
using namespace std;


/**
*
*分析法
*1 生成前缀和数组
*2 获取前缀和数组中最小的值
*3 
1 2 3 4 -100 10 20
*/
class Solution {
public:
    int maxSubArray(int A[], int n) 
    {

        int p[n+1]; //前缀和数组，p[i]表示a[0]到a[i-1]的和
        p[0] = 0;

        int m[n+1]; //最小前缀和数组,m[i]表示p[0]到p[i-1]中最小的值
        m[0] = 0;
        
        int minp = p[0];
        
         for(int i=1;i<n+1;++i)
        {
            p[i] = p[i-1]+A[i-1];
            if(p[i-1] < minp)
            {
                minp = p[i-1];
            }
            m[i] = minp;
        }

 
        
        int maxsum = A[0];
         for(int i=1;i<n+1;++i)
         {
            if(p[i]-m[i] > maxsum)
            {
                maxsum = p[i]-m[i];
            }
         }

        return maxsum;
    }
};

int main(void)
{
    //int a[] = {-1,-10,2,3,-100};
    int a[] = {-1,-2,-3};
    cout << Solution().maxSubArray(a,sizeof(a)/sizeof(*a)) << endl;
}
