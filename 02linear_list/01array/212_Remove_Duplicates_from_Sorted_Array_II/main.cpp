/*************************************************************************
	> File Name: 211.cpp
	> Author:zhaoyihong 
	> Mail:zhaoyihong_at_126_dot_com 
    > Created Time: 2015年03月16日 星期一 13时36分05秒
 ************************************************************************/

#include  <iostream>
using namespace std;


class Solution {
    public:
        static int removeDuplicates(int A[], int n) 
        {
            if(n <= 2) //允许有2个重复的
            {
                return n;
            }
            
            int index = 1;
            for(int i=2;i<n;++i)
            {
                if(A[index-1] != A[i])
                {
                    A[++index] = A[i];
                }
            }

            return index+1;
        }                    
};

int main(void)
{
    //int a[] = {1,2,2,2,2,2,3,3,4,4,5,5,5,7,8};
    int a[] = {1,2,3};
    int len = Solution::removeDuplicates(a,sizeof(a)/sizeof(*a));
    for(int i=0;i<len;++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
