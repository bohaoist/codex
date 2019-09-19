#include<cstring>
#include<iostream>
#include<vector>
using namespace std;

class String {
public:
    String(const char * pStr = nullptr);
    String(const String & str);
    ~String();
    String & operator = (const String &other);
    operator char*();
    vector<String> split(const String &str, const char *delim);
    bool operator == (const char * str);
    friend bool operator == (const String &left, const char * str);
    size_t getLength() const;
    const char* c_str() const;
private:
    char * m_data;
};

const char* String::c_str() const{
    return (const char*)m_data;
}

size_t String::getLength() const{
    size_t size = strlen(m_data);
    return size;
}

String::String(const char* pStr) {
    if(pStr == nullptr){
        m_data = new char[1];
        m_data[0] = '\0';
    } else {
        int len = strlen(pStr);
        m_data = new char[len];
        strcpy(m_data, pStr);
    }
}

String::~String(){
    if(m_data != nullptr){
        delete [] m_data;
    }
}

String::String(const String &other){
    int len = strlen(other.m_data);
    m_data = new char[len+1];
    strcpy(m_data, other.m_data);
}

String& String::operator=(const String &other){
    if(this == &other){
        return *this;
    }
    delete [] m_data;
    int len = strlen(other.m_data);
    m_data = new char[len+1];
    strcpy(m_data, other.m_data);
    return *this;
}

String::operator char*(){
    return m_data;
}

bool operator == (const String &left, const char * str){
    bool flag = false;
    int isEqual = strcmp(left.m_data, str);
    if(isEqual == 0) {
        flag = true;
    }
    return flag;
}

vector<String> String::split(const String & str, const char *delim){
    vector<String> res;
    if(str == ""){
        return res;
    }
    char * temp = new char[str.getLength() + 1];
    strcpy(temp, str.c_str());
    while(temp){
        const char * p= strtok(temp, delim);
        res.push_back(p);
    }

}

int main(){
    String str("hello world");
    cout << str << endl;
}