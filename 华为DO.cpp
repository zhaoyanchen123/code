// 华为OD，技术二面，查找某序列左右累加和相等的平衡温度点下标，ACM模式。
//剑指 Offer II 012. 左右两边子数组的和相等
/*
实例1：输入：[1,3,3,5,4,1,2]  输出：3    温度为5的为温度平衡点，下标为3
实例2：输入：[1,1,1,1,1,1]   输出：-1    没有温度平衡点
实例3：输入[3,2,-2]  输出：0    温度平衡点为3
*/

#include<vector>
#include<iostream>
using namespace std;

int find(vector<int>& nums){
    // int res; 
    // int left = 0, right = nums.size()-1;
    // int leftSum = nums[left], rightSum = nums[right];
    // while (left <= right){
    //     if(leftSum < rightSum){
    //         left++;
    //         leftSum += nums[left];
    //     }
    //     else if( leftSum > rightSum){
    //         right--;
    //         rightSum += nums[right];
    //     }
    //     else if (leftSum==rightSum && (left+2==right || left == right)){
            
    //         cout<< leftSum<<" "<< rightSum <<endl;
    //         return (left+right)/2;
    //     }
     
    // }
    // return -1;

    // int left = 0, right = nums.size()-1;
    // int leftSum = nums[left], rightSum = nums[right];
    // while (left < right){
    //     if(leftSum < rightSum){
    //         left++;
    //         leftSum += nums[left];
    //     }
    //     else if( leftSum > rightSum){
    //         right--;
    //         rightSum += nums[right];
    //     }
    //     else{
    //         left++;
    //         right--;
    //         leftSum += nums[left];
    //         rightSum += nums[right];
    //     }
    // }
    // return leftSum == rightSum ? left : -1;
    int sum = 0;
    for(auto num : nums) sum += num;
    int leftsum = 0;
    for(int i=0; i<nums.size(); ++i){
        //数组总和为sum；第i个时左侧leftsum，右侧rightsum=sum-nums[i]-leftsum  
        //又因为leftsum=rightsum   sum = 2*leftsum+num[i]
        if(2*leftsum + nums[i] == sum) return i;
        leftsum += nums[i];
    }
    return -1;

        

}


int main(){
    // vector<int> nums {1,3,3,5,4,1,2};
    vector<int> nums {-1,-1,-1,-1};
    int res = find(nums);
    cout<< res <<endl;
    return 0;
}