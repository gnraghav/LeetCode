int characterReplacement(char* s, int k) {
    int a[26] = {0};
    int mCharOcc =0;
    int l = 0;
    int res = 0;
    for (int i=0;i<strlen(s);i++) {
        a[s[i]-'A']++; // maintaining the freq
        mCharOcc = (mCharOcc > a[s[i]-'A'] ? mCharOcc : a[s[i]-'A']);
        while (i-l+1-mCharOcc > k) {
            a[s[l]-'A']--;
            l++;
        }
        res = (res > i-l+1 ? res : i-l+1);
    }
    return res;
}