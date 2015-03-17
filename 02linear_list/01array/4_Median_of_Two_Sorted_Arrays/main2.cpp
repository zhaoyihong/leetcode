/*************************************************************************
	> File Name: main.cpp
	> Author:zhaoyihong 
	> Mail:zhaoyihong_at_126_dot_com 
	> Created Time: 2015年03月17日 星期二 15时44分45秒
 ************************************************************************/

#include  <iostream>
#include  <algorithm>
using namespace std;


class Solution {
public:
    double findMedianSortedArrays(int A[], int m, int B[], int n) {
        
        int total = m+n;
        if( total & 0x1 )
        {
            return find_kth(A,m,B,n,total/2+1);
        }
        else
        {
            return ( find_kth(A,m,B,n,total/2) + find_kth(A,m,B,n,total/2+1) )/2.0;
        }
    }

private:

    //获取两个数组中第k大的数值
    int find_kth(int A[],int m,int B[],int n,int k)
    {
        //let m<n

        if(m>n)
        {
            return find_kth(B,n,A,m,k);
        }

        if(m == 0)
        {
            return B[k-1];
        }

        if(k == 1)
        {
            return min(A[0],B[0]);
        }

        int ia = min(k/2 , m) , ib = k - ia;

        if(A[ia-1] < B[ib-1])
        {
            return find_kth(A+ia,m-ia,B,n,k-ia);
        }
        else if(A[ia-1] > B[ib-1])
        {
            return find_kth(A,m,B+ib,n-ib,k-ib);
        }
        else
        {
            return A[ia-1];
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
