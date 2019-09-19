/**
 * 大数加法，大数减法
 *  * 
 * */

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstring>
using namespace std;

string multi(string num1, string num2)
{
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    string res = "";
    //先按位对齐
    vector<int> result(num1.size() + num2.size(), 0);

    for (size_t i = 0; i < num1.size(); i++)
    {
        for (size_t j = 0; j < num2.size(); j++)
        {
            result[i + j] += (num1[i] - '0') * (num2[j] - '0');
        }
    }

    for (size_t i = 0; i < result.size() - 1; i++)
    {
        if (result[i] >= 10)
        {
            result[i + 1] += result[i] / 10;
            result[i] = result[i] % 10;
        }
    }
    int index = result.size() - 1;
    while (index > 0 && result[index] == 0)
    {
        index--;
    };
    for (; index >= 0; index--)
    {
        res += static_cast<char>(result[index] + '0');
    }
    return res;
}

void printV(vector<int> res)
{
    for(vector<int>::const_iterator iter = res.begin(); iter != res.end(); iter++){
        cout << *iter;
    }
    cout << endl;
}

string bigplus(string num1, string num2)
{
    string res = "";
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    size_t len = num1.size() > num2.size() ? num1.size() : num2.size();
    vector<int> result(len + 1, 0);
    size_t i = 0;
    for (; i < num1.size() && i < num2.size(); i++)
    {
        result[i] += (num1[i] - '0') + (num2[i] - '0');
    }
    if (i >= num1.size())
    {
        for (; i < num2.size(); i++)
        {
            result[i] += num2[i] - '0';
        }
    }
    if (i == num2.size())
    {
        for (; i < num1.size(); i++)
        {
            result[i] += num1[i] - '0';
        }
    }
    for (size_t j = 0; j < result.size()-1; j++)
    {
        if (result[j] >= 10)
        {
            result[j + 1] += result[j] / 10;
            result[j] = result[j] % 10;
        }
    }
    int index = result.size() - 1;
    while(index >= 0 && result[index] == 0) index--;
    for(; index >= 0; index-- ){
        res += (char)(result[index] + '0');
    }
    return res;
}

string bigminus(string num1, string num2)
{
    string res;
    //num1是被减数，num2是减数
    if(num1.size() < num2.size() ||(num1.size() == num2.size() && strcmp(num1.c_str(), num2.c_str()) < 0)){
        string tmp = num1;
        num1 = num2;
        num2 = tmp;
    }
    reverse(num1.begin(), num1.end());
    reverse(num2.begin(), num2.end());
    int len = num1.size();
    vector<int> result(len, 0);
    size_t i = 0;
    for(; i < num2.size(); i++){
        result[i] = num1[i] - num2[i];    
    }
    while(i < num1.size()){
        result[i++] += num1[i] - '0';
    }
    for(size_t j = 0; j < result.size(); j++){
        if(result[j] < 0){
            result[j] += 10;
            result[j+1] -= 1;
        }
    }
    int index = result.size() -1 ;
    for(;index >= 0 && result[index] == 0; index--);
    for(;index >= 0; index--){
        res += (char)(result[index] + '0');
    }
    return res;
}

int main(int argc, char *argv[])
{
    string num1 = "84654894123456413215646548151312";
    string num2 = "5115413245647421657454156415614";

    string res = multi(num1, num2);
    cout << "multi: " << num1 << " * " << num2 << " = " << res << endl;
    cout << "plus: " << num1 << " + " << num2 << " = " << bigplus(num1, num2) << endl;
    cout << "minus: " << num1 << " - " << num2 << " = " << bigminus(num1, num2) << endl;
    return 0;
}