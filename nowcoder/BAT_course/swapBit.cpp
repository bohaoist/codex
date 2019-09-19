/**
 * 把一个无符号整数的比特位反转顺序。
 * 使用异或，与0异或原值不变，与1异或原值反转。两个bit异或，先判断的值是否相同，如果不同则与1异或，反转各自的值
 * 
 * */

#include<iostream>
using namespace std;

typedef unsigned int UINT;

void swapBit(UINT & num, size_t i, size_t j)
{
    UINT low = ((num >> i) & 1);
    UINT high = ((num >> j) & 1);
    if(low ^ high) {
        num ^= (1U << i) | (1U << j);
    }
}

UINT reverseBit(UINT& num)
{
    size_t len = sizeof(num) * 8;
    for(size_t i = 0; i < len / 2; i++){
        swapBit(num, i, len - i - 1);
    }
    return num;
}


int main(int argc, char * argv[])
{
    UINT num = 1;
    cout << reverseBit(num) << endl;
    return 0;
}