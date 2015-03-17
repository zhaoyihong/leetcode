#!/usr/bin/env python
# coding=utf-8


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


if __name__ == "__main__":
    s = Solution()
    A = [1,3]
    B = [7,8,9,1,2,3,4]
    C = [1]

    print s.search(A,3)
    print s.search(B,8)
    print s.search(C,1)

