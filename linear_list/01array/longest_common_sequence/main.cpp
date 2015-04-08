/*************************************************************************
	> File Name: main.cpp
	> Author:zhaoyihong 
	> Mail:zhaoyihong_at_126_dot_com 
	> Created Time: 2015年04月08日 星期三 21时09分46秒

最长公共子序列
如 acdfg,adfc最长公共子序列是adf,不需要连续
一个序列S任意删除若干个字符得到新序列T，则T叫做S的子序列；




非leetcode 

************************************************************************/

#include    <iostream>
#include    <string>
#include    <vector>
using namespace std;


class LCS
{

public:

    LCS(string& _s1,string& _s2):s1(_s1),s2(_s2)
    {
        vector<int> zero(s1.length()+1,0);
        length_array.assign(s2.length()+1,zero);
        dictory_arry.assign(s2.length()+1,zero);
    }
    
    int get_longest_length()
    {

    }

private:

    void _get_arrays()
    {
        int len1 = s1.length()+1;
        int len2 = s2.length()+1;

        for(int i=1;i<len1;++i)
        {
            for(int j=1;j<len2;++j)
            {
                if(s1[i-1] == s2[i-1])
                {
                    length_array[i][j] = length_array[i-1][j-1]+1;
                    dictory_arry[i][j] = LEFT_TOP; 
                }
                else if(s1[i-1][j] >= s2[i][j-1])
                {
                    length_array[i][j] = length_array[i-1][j];
                    dictory_arry[i][j] = TOP;
                }
                else
                {
                    length_array[i][j] = length_array[i][j-1];
                    dictory_arry[i][j] = LEFT;
                }
            }
        }
    }


    string s1,s2; //字符串
    vector<vector<int>> length_array; //长度数组
    vector<vector<int>> dictory_arry; //方向数组

    void printArray(vector<int> &m)
    {
        for(int i=0;i<m.size();++i)
        {
            cout << m[i] << ' ';
        }
        cout << endl;
    }

    enum(LEFT_TOP,LEFT,TOP);
};


int main()
{
    string s1="abcda",s2="bdfga";

    LCS lcs(s1,s2);


}
