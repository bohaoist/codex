#include<iostream>
#include<cstring>
#include<memory>
using namespace std;

void loopMove(char* pStr, int steps){
    size_t len = strlen(pStr);
    char tmp[strlen(pStr)+1];
    memset(tmp, 0, len+1);
    memcpy(tmp,pStr + steps, len-steps);
    memcpy(tmp+len-steps, pStr, steps);
    tmp[len] = '\0';
    memcpy(pStr, tmp, len+1);
}

int main() {
    char str[] = {"hello world."};
    loopMove(str, 4);
    char tmp[strlen(str)];
    strcpy(tmp,str);
    cout << str << endl;
    cout << tmp<< endl;
}