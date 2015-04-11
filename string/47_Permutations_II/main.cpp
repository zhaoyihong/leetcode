/*************************************************************************
	> File Name: main.cpp
	> Author:zhaoyihong 
	> Mail:zhaoyihong_at_126_dot_com 
	> Created Time: 2015年04月10日 星期五 10时11分43秒


 Given a collection of numbers that might contain duplicates, return all possible unique permutations.

For example,
[1,1,2] have the following unique permutations:
[1,1,2], [1,2,1], and [2,1,1].

    ************************************************************************/

#include    <iostream>
#include    <vector>
#include    <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int> &num) {
          
        _permute(num,0,num.size()-1);
        return _permute_list; 
    }
    
    
private:
    
    vector<vector<int> > _permute_list;

    void _permute(vector<int> &num,int from,int to)
    {
        if(from == to)
        {
            _permute_list.push_back(num);
            return;
        }
        
        int hash[20] = {0};
        for(int i=from;i<=to;++i)
        {
            int hash_index = num[i]>=0?num[i]:(-num[i]+10);
            if(hash[hash_index] == 0)
            {
                swap(num[from],num[i]);
                _permute(num,from+1,to);
                swap(num[from],num[i]);
                hash[hash_index] = 1;
            }
        
        }
        
    }
};


int main()
{
    int a[] = {1,1,-1,-2,1};
    vector<int> va(a,a+5);
    vector<vector<int> > result = Solution().permute(va);
    
    for(int i=0;i<result.size();++i)
    {
        for(int j=0;j<result[i].size();++j)
        {
            cout << result[i][j] ;    
        }
        cout << endl;
    }
    
}
