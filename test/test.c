char* my_substring(char* s, int begin, int end) {
    char* result = (char*)malloc(end - begin + 1);
    int i;
    for(i = begin; i < end; i++) {
        result[i - begin] = s[i];
    }
    result[i - begin] = 0;
    return result;
}