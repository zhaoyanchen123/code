#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

//输入:nums {-1,0,2,-1,4,3} 要求nums[a]+num[b]+nums[c]=0  输出:[[-1,-1,2],[]]

vector<vector<int>> findMiddle(vector<int>& nums){
    vector<vector<int>> res;
    sort(nums.begin(),nums.end());
    for(int i=0; i<nums.size(); i++){
        //1.剪枝
        if(nums[i]>0) return res;
        if(i>0 && nums[i] == nums[i-1]) continue;
        //定义双指针
        int left = i+1, right = nums.size()-1;
        while(left<right){
            if(nums[i]+nums[left]+nums[right] > 0) right--;  //缩小右边大于的值
            else if(nums[i]+nums[left]+nums[right] < 0) left--; // 扩大左边小于的值
            else{ //找到目标值,放到res中
                res.push_back(vector<int>{nums[i],nums[left],nums[right]});
                //去重
                while(right>left && nums[right] == nums[right-1]) right--;  //右边出现相等的,就左移 
                while(right>left && nums[left] == nums[left+1]) left++;
                left++, right--;
            } 
        }
    }
    return res;
}

void print_vec(vector<vector<int>>& nums){
    for(int i=0; i<nums.size(); i++){
        for(int j=0; j<nums[i].size();j++){
            cout <<nums[i][j]<<" ";
        }
        cout << endl;
    }

}

int main(){
    vector<int> nums {-1,0,2,-1,4,3};
    
    vector<vector<int>> vec;
    vec =  findMiddle(nums);
    print_vec(vec);
    return 0;
}