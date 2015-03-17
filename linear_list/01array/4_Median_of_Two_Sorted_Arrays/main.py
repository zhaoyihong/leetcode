#!/usr/bin/env python
# coding=utf-8

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


if __name__ == "__main__":
    A = [ 10001 ]
    B = [ 10000 ]

    print Solution().findMedianSortedArrays(A,B)

