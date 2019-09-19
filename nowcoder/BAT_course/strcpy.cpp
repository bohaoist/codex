int strlen(const char * src){
    assert(src != NULL);
    int len = 0;
    while(*src++ != '\0'){
        len++;
    }
    return len;
}