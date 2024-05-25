// 引入标准输入输出库
#include <iostream>

// 使用标准命名空间，简化代码
using namespace std;

// 宏定义max，这里定义为一个空的宏，将在后面被重新定义
#define max

// 宏定义maximum，用于比较两个数x和y的大小，返回较大的数
#define maximum(x,y) (((x)>(y))?(x):(y))

// 宏定义minimum，用于比较两个数x和y的大小，返回较小的数
#define minimum(x,y) (((x)>(y))?(y):(x))

// 定义main函数，程序的入口点
int main()
{
    // 定义两个整型变量a和b，并初始化
    int a=10, b=20;

    // 使用#ifdef检查宏max是否已定义，如果已定义则执行下面的代码
    #ifdef max
     // 输出较大的数
     cout<<" the larger one is "<<maximum(a,b)<<endl;
     // 如果宏max未定义，则执行下面的代码
     #else
        cout<<" the lower one is "<<minimum(a,b)<<endl;
    // 结束#ifdef检查
    #endif
    // 使用#ifndef检查宏min是否未定义，如果未定义则执行下面的代码
    #ifndef min

    cout<<" the lower one is "<<minimum(a,b)<<endl;
    // 如果宏min已定义，则执行下面的代码
    #else
    cout<<" the larger one is "<<maximum(a,b)<<endl;
    // 结束#ifndef检查
    #endif

    // 重新定义宏max，这次将其定义为一个非空的宏
    #undef max

    // 再次使用#ifdef检查宏max是否已定义，如果已定义则执行下面的代码
    #ifdef max
        cout<<" the larger one is "<<maximum(a,b)<<endl;
    // 如果宏max未定义，则执行下面的代码
    #else
        cout<<" the lower one is  "<<minimum(a,b)<<endl;
    // 结束#ifdef检查
    #endif

    // 使用#define重新定义宏min
    #define min

    // 使用#ifndef检查宏min是否未定义，如果未定义则执行下面的代码
    #ifndef min
        cout<<" the lower one is "<<minimum(a,b)<<endl;
    // 如果宏min已定义，则执行下面的代码
    #else
        cout<<" the larger one is "<<maximum(a,b)<<endl;
    // 结束#ifndef检查
    #endif

    // 程序结束，没有返回值
}