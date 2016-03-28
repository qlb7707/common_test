#================================================================
#   Copyright (C) 2016 All rights reserved.
#   
#   filename     :factor_test.py
#   author       :qinlibin
#   create date  :2016/03/28
#   mail         :qin_libin@foxmail.com
#
#================================================================

def factors1(num):
    sum = 0
    for i in range(num):
        if num % (i+1) == 0:
            sum += 1
    return sum

def factors2(num):
    sum = 0
    sqrt_num = num**.5
    is_sqr = False
    if sqrt_num == int(sqrt_num):
        is_sqr = True
    for i in range(1,int(sqrt_num)):
        if num % (i+1) == 0: 
            sum += 1
    if is_sqr:
        sum = sum * 2 - 1
    else:
        sum = sum *2
    sum = sum + 2
    return sum



def test():
    for i in range(1,10000):
        print factors1(i),factors2(i)




if __name__=='__main__':
    test()


