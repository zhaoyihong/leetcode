/*************************************************************************
	> File Name: main.cpp
	> Author:zhaoyihong 
	> Mail:zhaoyihong_at_126_dot_com 
	> Created Time: 2015年03月16日 星期一 17时28分16秒
 ************************************************************************/

#include  <iostream>
using namespace std;


class Solution {
public:
    bool search(int A[], int n, int target) {
        
        int lo = 0 ,hi = n-1;
        
        while(lo <= hi)
        {
            int mid = (lo + hi) / 2;
            
            if(target == A[mid])
            {
                return true;
            }
            
            if(A[lo] < A[mid])
            {
                //左边有序的情况

                //判断目标是否在左边的区间中
                if(target < A[mid] && target >= A[lo])
                {
                    hi = mid;
                }
                else
                {
                    lo = mid + 1;
                }

            }
            else if(A[lo] > A[mid])
            {
                //左边无序,说明右边有序
                
                //判断target是否在右边的区间中
                if(target > A[mid]  && target <= A[hi])
                {
                    lo = mid+1;
                }
                else
                {
                    hi = mid;
                }

            }
            else
            {
                lo++;
            }
        }

        return false;

    }
};


int main()
{
    int A[] = {
        2,2,2,3,3,1,1,2
    };

    cout << boolalpha <<  Solution().search(A,sizeof(A)/sizeof(*A),2) << endl;
    cout << boolalpha <<  Solution().search(A,sizeof(A)/sizeof(*A),3) << endl;
    cout << boolalpha <<  Solution().search(A,sizeof(A)/sizeof(*A),1) << endl;
}
