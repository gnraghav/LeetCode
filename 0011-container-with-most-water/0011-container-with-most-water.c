int maxArea(int* height, int heightSize) {
    int i = 0;
    int j = heightSize-1;
    int res = INT_MIN;
    int totalWa = INT_MAX;
    while (i<j) {
        totalWa = (height[i] < height[j] ? height[i] * (j-i) : height[j] * (j-i)); // find the element
        res = (res > totalWa ? res : totalWa);
        if (height[i] < height[j]) {
            i++;
        } else {
            j--;
        }
    }
    return res;
}