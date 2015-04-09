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
        array_rows = s1.length() + 1;
        array_cols = s2.length() + 1;
        vector<int> zero(array_cols,0);
        length_array.assign(array_rows,zero);
        direction_arry.assign(array_rows,zero);
        _get_arrays();
    }
    
    int get_lcs_len()
    {
       return length_array[array_rows-1][array_cols-1]; 
    }

    void print_arrays()
    {
        vector<vector<int>>::iterator it1;
        vector<int>::iterator it2;

        cout << "length_array:" << endl;
        for(it1=length_array.begin();it1!=length_array.end();++it1)
        {
            for(it2=it1->begin();it2!=it1->end();++it2)
            {
                cout << *it2 << " ";
            }
            cout << endl;
        }
        
        cout << "direction_arry:" << endl;
        for(it1=direction_arry.begin();it1!=direction_arry.end();++it1)
        {
            for(it2=it1->begin();it2!=it1->end();++it2)
            {
                cout << *it2 << " ";
            }
            cout << endl;
        }
    }

    /**
     * 获取一个最长子序列
     * x是输出参数
     */
    void get_one_lcs(string &x)
    {
        vector<char> vc;
        _get_one_lcs(array_rows-1,array_cols-1,vc);
        x.assign(vc.rbegin(),vc.rend());
    }

private:
    
    //获取一个最长子序列,私有函数,供get_one_lcs调用
    void _get_one_lcs(int i,int j,vector<char>& vc)
    {
        if(i==0 || j==0) return;

        if(direction_arry[i][j] == LEFT_TOP)
        {

            vc.push_back(s1[i-1]);
            _get_one_lcs(i-1,j-1,vc);
        }
        else if(direction_arry[i][j] == TOP)
        {
            _get_one_lcs(i-1,j,vc);
        }
        else if(direction_arry[i][j] == LEFT)
        {
            _get_one_lcs(i,j-1,vc);
        }
        else  //TOP_OR_LEFT
        {
            _get_one_lcs(i,j-1,vc);
        }
    }


private:

    //获取长度矩阵和方向矩阵
    void _get_arrays()
    {
        for(int i=1;i<array_rows;++i)
        {
            for(int j=1;j<array_cols;++j)
            {
                if(s1[i-1] == s2[j-1])
                {
                    length_array[i][j] = length_array[i-1][j-1]+1;
                    direction_arry[i][j] = LEFT_TOP; 
                }
                else if(length_array[i-1][j] > length_array[i][j-1])
                {
                    length_array[i][j] = length_array[i-1][j];
                    direction_arry[i][j] = TOP;
                }
                else if(length_array[i-1][j] < length_array[i][j-1])
                {
                    length_array[i][j] = length_array[i][j-1];
                    direction_arry[i][j] = LEFT;
                }
                else if(length_array[i-1][j] == length_array[i][j-1])
                {
                    length_array[i][j] = length_array[i][j-1];
                    direction_arry[i][j] = LEFT_OR_TOP; 
                }
            }
        }
    }

    string s1,s2; //字符串
    vector<vector<int>> length_array; //长度数组
    vector<vector<int>> direction_arry; //方向数组
    int array_rows; //数组行数
    int array_cols; //数组列数

    enum{INIT=0,LEFT_TOP=1,LEFT=2,TOP=3,LEFT_OR_TOP=4};

    vector<string> all_lcs;
    
};


int main()
{
    string s1="113121",s2="211211";

    LCS lcs(s1,s2);

    cout << lcs.get_lcs_len() << endl;
    string str;
    lcs.get_one_lcs(str);
    cout << str << endl;
}
