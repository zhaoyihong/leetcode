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
            if(n == 0 || A==nullptr) 
            {
                return 0;
            }
            
            int index = 0;
            for(int i=1;i<n;++i)
            {
                if(A[index] != A[i])
                {
                    A[++index] = A[i];
                }
            }
            return index+1;
        }                    
};

int main(void)
{
    int a[] = {1,2,2,3,4,5,5,5,7};
    int len = Solution::removeDuplicates(a,sizeof(a)/sizeof(*a));
    for(int i=0;i<len;++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}
