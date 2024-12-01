int maxSubArray(int* nums, int numsSize) {
    
    int cSum = 0;
    int mSum = INT_MIN;
    for(int i=0;i<numsSize;i++) {
        cSum +=nums[i];
        if (mSum < cSum) mSum = cSum;
        if (cSum < 0) cSum = 0;
    }
    return mSum;
}