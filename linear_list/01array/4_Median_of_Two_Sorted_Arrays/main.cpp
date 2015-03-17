/*************************************************************************
	> File Name: main.cpp
	> Author:zhaoyihong 
	> Mail:zhaoyihong_at_126_dot_com 
	> Created Time: 2015年03月17日 星期二 15时44分45秒
 ************************************************************************/

#include  <iostream>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
  
        if(m == 0 && n == 0)
        {
            return -1.0;
        }

        int mid = (m+n)/2;
        int index_a = 0,index_b = 0,index_all = 0;
        int num_bf = 0; //上一个数值,m+n为偶数时要用到
        int num_now = 0; 

        while(index_all < m+n)
        {
            while( index_b == n ||( index_a < m  && A[index_a] <= B[index_b]))
            {
                if(index_all == mid)
                {
                    num_now =  A[index_a];
                    goto END;    
                }

                num_bf = A[index_a];
                index_all ++;
                index_a ++;
            }

            while( index_a == m  || ( index_b < n && B[index_b] <= A[index_a]))
            {
                if(index_all == mid)
                {
                    num_now = B[index_b];
                    goto END;
                }

                num_bf = B[index_b];
                index_all ++;
                index_b ++;
            }
        }

        END:
        if( (m+n) & 0x1 )
        {
            return num_now;
        }
        else
        {
            return (num_now + num_bf)*1.0/2;
        }

    }
};



int main(void)
{
    int A[] = {
    };

    int B[] = {
        2,3
    };

    double result;
    result = Solution().findMedianSortedArrays(A,sizeof(A)/sizeof(*A),B,sizeof(B)/sizeof(*B));

    cout << result << endl;                                              

}
