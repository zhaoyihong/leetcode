#2.1.1  Remove Duplicates from Sorted Array  #

Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.

Do not allocate extra space for another array, you must do this in place with constant memory.

For example,
Given input array A = [1,1,2],

Your function should return length = 2, and A is now [1,2].

翻译 : 去除数组重复元素,且不能申请额外空间

	下面代码中:
	
	i 表示未排序的第一个元素
	
	index 表示新生成数组的最后一个元素

c++
	
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

	
python

	class Solution:
	    # @param a list of integers
	    # @return an integer
	    def removeDuplicates(self, A):
	        n = len(A)
	        if 0 == n:
	            return 0;
	        index = 0
	        i = 1
	        while i < n:
	            if A[index] != A[i]:
	                index += 1
	                A[index] = A[i]
	            i += 1
	
	        return index+1


# 2.1.2  Remove Duplicates from Sorted Array II  #

Follow up for "Remove Duplicates":
What if duplicates are allowed at most twice?

For example,
Given sorted array A = [1,1,1,2,2,3],

Your function should return length = 5, and A is now [1,1,2,2,3].


翻译:去除数组重复元素,但是重复元素最多存在两次
 

	下面代码中:
 
	i 表示未排序的第一个元素

	index 表示新生成数组的最后一个元素


c++:

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


python:
 


	class Solution:
	    # @param a list of integers
	    # @return an integer
	    def removeDuplicates(self, A):
	        n = len(A)
	        if n <= 2:
	            return n
	  
	        i = 2
	        index = 1
	        while i < n:
	            if A[index-1] != A[i]:
	                index += 1
	                A[index] = A[i]
	            i += 1
	
	        return index+1
	
#2.1.3 Search in Rotated Sorted Array

Suppose a sorted array is rotated at some pivot unknown to you beforehand.

(i.e., 0 1 2 4 5 6 7 might become 4 5 6 7 0 1 2).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

pivot: 轴心

翻译:一个已序数组被按照某个元素进行旋转后 , 变成了 0 1 2 3 4 6 7 -> 4 5 6 7 0 1 2, 假设数组中没有重复,要求从中找到某个指定的数,找不到返回-1,找到返回序号


解题方法:
	
	这题由于不是完全有序的,要在二分查找法的基础上改进
	
	1 需要知道哪边仍然是有序区间:

		 在没有重复元素的情况下,当A[low] < A[mid]时,可以说明左边是有序的,否则就是右边
	
	2 判断target是否在有序区间内
		
		如果target在有序区间内,下一步就在有序区间总寻找,否则在另一个区间中寻找
 
	
	3 边界
		
		[lo,hi]中 如果mid=(lo+hi)/2 ,那么不要写mid-1,容易出现越界问题
		
		比如 lo =2 ,hi=3中,mid=2,mid-1就越界了而mid+1不会



c++:	
		
		 
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


python:

	class Solution:
	        # @param A, a list of integers
	        # @param target, an integer to be searched
	        # @return an integer
	        def search(self, A, target):
	            lo = 0
	            hi = len(A)-1
	            
	            while lo <= hi:
	                mid = (lo + hi)/2
	                if target == A[mid]:
	                    return mid
	
	                if A[lo] <= A[mid]:
	                    if target < A[mid] and target >= A[lo]:
	                        hi = mid
	                    else:
	                        lo = mid+1
	                else:
	                    if target > A[mid] and target <= A[hi]:
	                        lo = mid+1
	                    else:
	                        hi = mid
	
	            return -1



# 2.1.4 Search in Rotated Sorted Array II #
 
Follow up for ”Search in Rotated Sorted Array”: What if duplicates are allowed?
Would this affect the run-time complexity? How and why?
Write a function to determine if a given target is in the array.


翻译: 如果旋转数组中的元素允许重复,写一个函数判断元素是否在数组中

	
	如果允许重复元素，则上一题中如果 A[m]>=A[l],那么 [l,m]为递增序列的假设就不能成立了，比
	如 [1,3,1,1,1]。
	如果 A[m]>=A[l]不能确定递增，那就把它拆分成两个条件：
	• 若 A[m]>A[l]，则区间 [l,m]一定递增
	• 若 A[m]==A[l]确定不了，那就 l++，往下看一步即可。
		

c++:

	
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



python:

	
	
	class Solution:
	        # @param A, a list of integers
	        # @param target, an integer to be searched
	        # @return an integer
	        def search(self, A, target):
	            lo = 0
	            hi = len(A)-1
	            
	            while lo <= hi:
	                mid = (lo + hi)/2
	                if target == A[mid]:
	                    return True
	
	                if A[lo] < A[mid]:
	                    if target < A[mid] and target >= A[lo]:
	                        hi = mid
	                    else:
	                        lo = mid+1
	                elif A[lo] > A[mid]:
	                    if target > A[mid] and target <= A[hi]:
	                        lo = mid+1
	                    else:
	                        hi = mid
	                else:
	                    lo = lo+1
	
	            return False