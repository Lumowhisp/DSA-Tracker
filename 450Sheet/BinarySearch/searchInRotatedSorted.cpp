class Solution {
    public:
    int binarySearch(vector<int>&nums,int target,int start,int end){
        while(start<=end){
            int mid=start+(end-start)/2;
            if(nums[mid]==target){
                return mid;
            }
            //left Sorted Half
            if(nums[start]<=nums[mid]){
                if(nums[start]<=target && nums[mid]>target){
                    end=mid-1;
                }
                else{
                    start=mid+1;
                }
            }
            else{
                if(nums[mid]<target && target<=nums[end]){
                    start=mid+1;
                }
                else{
                    end=mid-1;
                }
            }
        }
        return -1;
    
    }
        int search(vector<int>& nums, int target) {
            return binarySearch(nums,target,0,nums.size()-1);
        }
    };