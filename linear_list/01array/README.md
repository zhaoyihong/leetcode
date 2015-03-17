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



# 4 Median of Two Sorted Arrays  #

There are two sorted arrays A and B of size m and n respectively. Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

获取两个排序数组最中间的元素

注意,如果所有元素个数为偶数,返回最中间的两个元素的平均值


两个数组轮询的解法

		
		
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


利用找到k大的值的解法:

有没有更好的方案呢？我们可以考虑从 k 入手。如果我们每次都能够删除一个一定在第 k 大元素之前的元素，那么我们需要进行 k 次。

但是如果每次我们都删除一半呢？由于 A 和 B 都是有序的，我们应该充分利用这里面的信息，类似于二分查找，也是充分利用了“有序”。

假设 A 和 B 的元素个数都大于 k/2，我们将 A 的第 k/2 个元素（即 A[k/2-1]）和 B 的第 k/2个元素（即 B[k/2-1]）进行比较，有以下三种情况（为了简化这里先假设k 为偶数，所得到的结论对于k 是奇数也是成立的）：

• A[k/2-1] == B[k/2-1]

• A[k/2-1] > B[k/2-1]

• A[k/2-1] < B[k/2-1]

如果 A[k/2-1] < B[k/2-1]，意味着 A[0] 到 A[k/2-1] 的肯定在 A U B 的 top k 元素的范围内，换句话说，A[k/2-1]不可能大于 A U B 的第k 大元素。

	反证法:
		如果 A[k/2-1] 大于第k个元素,假设它是第k+1个元素
		又因为B[k/2-1]大于A[k/2-1],假设它是k+2个元素
		那么A[k/2-1]和B[k/2-1]前面至少因为该有k个元素,但是它们前面只有(m+n)/2个元素


因此，我们可以放心的删除 A 数组的这 k/2 个元素。同理，当 A[k/2-1] > B[k/2-1] 时，可以删除 B数组的 k/2 个元素。

当 A[k/2-1] == B[k/2-1] 时，说明找到了第 k 大的元素，直接返回 A[k/2-1] 或 B[k/2-1]即可。

因此，我们可以写一个递归函数。那么函数什么时候应该终止呢？

• 当 A 或 B是空时，直接返回 B[k-1]或 A[k-1]；

• 当 k=1是，返回 min(A[0], B[0])；

• 当 A[k/2-1] == B[k/2-1] 时，返回 A[k/2-1] 或 B[k/2-1]



	
	
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

python
	
	
	class Solution:
	    # @return a float
	    def findMedianSortedArrays(self, A, B):
	        len_a = len(A)
	        len_b = len(B)
	        total = len_a + len_b
	        if total & 0x1:
	            return self.__find_kth(A,B,total/2+1)
	        else:
	            return (self.__find_kth(A,B,total/2) + self.__find_kth(A,B,total/2+1))/2.0
	
	    
	    def __find_kth(self,A,B,k):
	        len_a = len(A)
	        len_b = len(B)
	
	        #let len_a < len_b
	        if len_a > len_b:
	            return self.__find_kth(B,A,k)
	
	        if len_a == 0:
	            return B[k-1]
	
	        if k == 1:
	            return min(A[0],B[0])
	
	        ia = min(k/2,len_a)
	        ib = k - ia
	
	        if A[ia-1] < B[ib-1]:
	            return self.__find_kth(A[ia:],B,k-ia)
	        elif A[ia-1] > B[ib-1]:
	            return self.__find_kth(A,B[ib:],k-ib)
	        else:
	            return A[ia-1]

 