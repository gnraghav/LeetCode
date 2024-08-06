int lengthOfLongestSubstring(char* s) {
    int a[256];
    for (int i = 0; i < 256; i++) {
        a[i] = -1;  // Initialize all elements to -1
    }
    int res = 0;
    int start = -1;  // Index starts with -1 to handle the first character correctly
    for (int i = 0; s[i] != '\0'; i++) {
        if (a[s[i]] > start) {
            start = a[s[i]];
        }
        a[s[i]] = i;
        res = (res > i - start ? res : i - start);
    }
    return res;
}