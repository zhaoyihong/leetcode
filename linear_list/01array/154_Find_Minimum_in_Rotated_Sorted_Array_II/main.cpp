/*
    
寻找旋转数组中的最小值

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

Find the minimum element.

You may assume no duplicate exists in the array.




Follow up for "Find Minimum in Rotated Sorted Array":
What if duplicates are allowed?""

*/

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int findMin(vector<int> &num) {
        
        return _find_min(num,0,num.size()-1);
       
    }
    
    int _find_min(vector<int> &num,int lo,int hi)
    {
        //4567123
        //[lo,mid]是有序的，因此(mid,hi]是无序的.最小值在无序区中找
        
        while(lo < hi)
        {
            int mid = (lo + hi)/2;
         
            if( num[mid] < num[hi]) //右边有序，在左边找值
            {
                hi = mid;
            }
            else if(num[mid] > num[hi]) //最小值在左边
            {
                lo = mid+1;
            }
            else
            {   
                hi--;
            }
        }
        
        return num[lo];
    }
};


int main(void)
{
    //int a[] = {4,5,6,1,2,3};
    int a[] = {5,6,1,1,1,2,2,2,2,3,4};

    vector<int> b(a,a+sizeof(a)/sizeof(*a));

    cout << Solution().findMin(b) << endl;
}
