/*************************************************************************
	> File Name: main.cpp
	> Author:zhaoyihong 
	> Mail:zhaoyihong_at_126_dot_com 
	> Created Time: 2015年03月16日 星期一 15时34分16秒
 ************************************************************************/

#include  <iostream>
using namespace std;

class Solution {
	
	    public:
	        int search(int A[], int n, int target) {
	            if(0 == n)
	            {
	                return -1;
	            }
	            
	            int hi = n-1;
	            int lo = 0;
	            while(lo <= hi)
	            {   
	                int mid = (lo + hi)/2;
	
	                if(A[mid] == target)
	                {
	                    return mid;
	                }
	
	                if( A[lo] <= A[mid]) //if True 左边有序 else  右边有序 
	                {   
	                    if(target < A[mid] && target >= A[lo])
	                    {
	                        hi = mid;
	                    }
	                    else
	                    {
	                        lo = mid+1;
	                    }
	                }
	                else //右边是有序的
	                {
	                    if(target > A[mid] && target <= A[hi])
	                    {
	                        lo = mid+1;
	                    }
	                    else
	                    {
	                        hi = mid;
	                    }
	                }
	            }
	            return -1;
	        }
	};

int main(void)
{
    int A[] ={
        3,1
    };
   
    cout << Solution().search(A,sizeof(A)/sizeof(*A),1) << endl;



    
}
