/*************************************************************************
	> File Name: main.cpp
	> Author:zhaoyihong 
	> Mail:zhaoyihong_at_126_dot_com 
	> Created Time: 2015年04月11日 星期六 14时38分26秒
    Implement strStr().
Returns the index of the first occurrence of needle in haystack, 
    or -1 if needle is not part of haystack.
 ************************************************************************/
#include    <iostream>
#include    <cstring>
using namespace std;
class Solution {
public:
    int strStr(char *haystack, char *needle) {
        
            //如果不是字符串，直接返回-1
            if(haystack == NULL || needle == NULL)
            {
                return -1;
            }    
            int hay_len = strlen(haystack);
            int needle_len = strlen(needle);
            //如果模式串为空，则直接返回找到了
            if(needle_len == 0)
            {
                return 0;
            }
            //如果模式串不为空，被匹配串为空，则返回-1
            else if(hay_len == 0)
            {
                return -1;
            }
            int next[needle_len]; //next数组
            _calc_next(needle,next);
        /*
            for(auto i : next)
                cout << i << " ";
            cout << endl;
        */
            int ans = -1;
            int i = 0,j = 0; // i : haystack index; j : needle index;
            while(i < hay_len)
            {
                if(j == -1 || haystack[i] == needle[j])
                {
                    i++;
                    j++;
                }
                else
                {
                    j = next[j];
                }
                if(j == needle_len)
                {
                    ans = i - needle_len;
                    break;
                }
            }
            return ans;
    }
    void _calc_next(char *haystack,int* next)
    {
        int len = strlen(haystack);
        next[0] = -1;
        int k = -1,j = 0;
        while( j < len-1 )
        {
            if(k == -1 || haystack[k] == haystack[j])
            {
               ++k;
               ++j;
               next[j] = k;
            }
            else
            {
                k = next[k];
            }
        }
    }
};
int main(void)
{
    char *str1 = NULL;
    char *str2 = NULL;
    cout << Solution().strStr(str1,str2) << endl;
}
