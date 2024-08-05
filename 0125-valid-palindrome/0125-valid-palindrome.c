bool isalnumeric (char c) {
    bool isUpper = ((c >= 'A' && c <= 'Z') ? 1 : 0);
    bool isLower = ((c >= 'a' && c <= 'z') ? 1 : 0);
    bool isNum = ((c >= '0' && c <= '9') ? 1 : 0);
    
    if (isUpper || isLower || isNum) {
        return true;
    }
    return false;
}

void
reverse_string(char *s, int size) {
    int i = 0;
    int j = size-1;
    while(i<j) {
        char temp = s[i];
        s[i] = s[j];
        s[j] = temp;
        i++;
        j--;
    }
}
bool isPalindrome(char* s) {
    int len = strlen(s);
    if (len <= 1) {
        return true;
    }
    char s1[len+1];
    int j = 0;
    int i;
    for (int i=0;i<len;i++) {
         if (isalnumeric(s[i])) {
             s1[j++] = tolower(s[i]);
         }
    }
    s1[j] = '\0';
    i = 0;
    j = strlen(s1)-1;
    while (i<=j) {
        if (s1[i] != s1[j]) {
            return false;
        }
        i++;
        j--;
    }
    return true;
}



