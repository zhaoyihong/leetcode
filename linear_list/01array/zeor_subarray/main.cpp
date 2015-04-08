/*************************************************************************
	> File Name: main.cpp
	> Author:zhaoyihong 
	> Mail:zhaoyihong_at_126_dot_com 
	> Created Time: 2015年04月08日 星期三 19时49分31秒

    求对于长度为N的数组A，求子数组的和接近0的子数组，要求时间复杂度O(NlogN)。

    不属于leetcode

    s[i]是a[0]~a[i]的前缀和
    s[i]-s[j] (i>j) 就是从a[i+1]~a[j]的和  
    最近接0的子数组就是前缀数组的和之差，以及前缀数组的和中最小的
    为了一次求出来，我们在前缀数组中放个0值，求出差值最小的即是结果


************************************************************************/

#include    <iostream>
#include    <vector>
#include    <algorithm>
using namespace std;

int nearest_zeor_sum(vector<int>& a)
{
    int len = a.size();
    vector<int> sum(len+1); //前缀数组,sum[i]表示a[0]到a[i-1]的和
    sum[0]=0; // trick

    for(int i=1;i<sum.size();++i)
    {
        sum[i] = sum[i-1] + a[i-1];
    }
    
    sort(sum.begin(),sum.end());//排序

    int min=a[0]; //不要写sum[0],可能取到我们加入的0为初始值。

    //求sum数组的差。
    for(int i=sum.size()-1;i>0;i--)
    {
        if( abs(sum[i] - sum[i-1]) < abs(min))
        {
            min = sum[i] - sum[i-1];
        }
    }

    return min;
}


int main()
{
    int a[] = {-1,-2,-3};
    vector<int> b(a,a+sizeof(a)/sizeof(*a));
    cout <<  nearest_zeor_sum(b) << endl;

}

 