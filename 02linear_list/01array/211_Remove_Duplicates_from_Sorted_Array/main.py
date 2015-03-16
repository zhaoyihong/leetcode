#!/usr/bin/env python
# coding=utf-8

#注意 python中没有++操作符 , a+=1 也不表示一个数

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

if __name__ == "__main__":

    s = Solution()
    A = [1,2,2,3,4,5,5,7]
    len = s.removeDuplicates(A)
    print len
    print A[:len]


