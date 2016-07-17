/*================================================================
*   Copyright (C) 2016 All rights reserved.
*   
*   filename     :test.cpp
*   author       :qinlibin
*   create date  :2016/07/09
*   mail         :qin_libin@foxmail.com
*
================================================================*/
//#include "test.h"

#include<atomic>
#include<thread>
#include<iostream>
#include<mutex>
//#define _USE_MUTEX_
using namespace std;
#ifdef _USE_MUTEX_
long long total = 0;
mutex mtx;
#else
atomic_llong total {0};
#endif


void func(int)
{
    for(long long i = 0; i < 10000000LL; i++)
    {
#ifdef _USE_MUTEX_
        mtx.lock();
#endif
        total+=i;
#ifdef _USE_MUTEX_
        mtx.unlock();
#endif
    }
}

int main()
{
    thread t1(func,0);
    thread t2(func,0);
    t1.join();
    t2.join();
    cout<<total<<endl;
    return 0;
}
