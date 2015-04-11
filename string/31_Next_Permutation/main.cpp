/*************************************************************************
	> File Name: main.cpp
	> Author:zhaoyihong 
	> Mail:zhaoyihong_at_126_dot_com 
	> Created Time: 2015年04月10日 星期五 11时52分12秒
Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
The replacement must be in-place, do not allocate extra memory.
Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
1,2,3 → 1,3,2
3,2,1 → 1,2,3
1,1,5 → 1,5,1
 ************************************************************************/
    #include    <vector>
    #include    <iostream>
    #include    <algorithm>
    using namespace std;
    class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            int len = num.size();
            
            //从右往左寻找第一个右边有比自身值大的num[i]
            for(int i=len-2;i>=0;--i)
            {
                //寻找i右边比num[i]大的最小值。
                int min_value; //比num[i]大的最小值
                int min_index = -1;
                for(int j=len-1;j>i;--j)
                {    
                    if(num[j] > num[i])
                    {
                        if(min_index < 0)
                        {
                            min_value = num[j];
                            min_index = j;
                        }
                        else
                        {
                            if(num[j] < min_value)
                            {
                               min_value = num[j];
                                min_index = j;
                            }
                        }
                    }   
                }
                
                //找到后，交换num[i]和num[min_index].并将num[i]右边的数字排序
                if(min_index != -1)
                {
                    swap(num[i],num[min_index]);
                    sort(num.begin()+i+1,num.end());
                    return;
                }
            }
            //如果走到这里，说明已经是最大值了。
            
            sort(num.begin(),num.end());
            
        }
    };
int main(void)
{
    int a[] = {3,2,1};
    vector<int> num(a,a+sizeof(a)/sizeof(*a));
    Solution().nextPermutation(num);
    for(auto i: num)
    {
        cout << i;
    }
}
