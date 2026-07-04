class Solution {
    public:
    int binarySearchFirst(vector<int>&arr,int start,int end,int target){
        int first=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==target){
                first=mid;
                end=mid-1;
            }
            else if(arr[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return first;
    }
    int binarySearchLast(vector<int>&arr,int start,int end,int target){
        int last=-1;
        while(start<=end){
            int mid=start+(end-start)/2;
            if(arr[mid]==target){
                last=mid;
                start=mid+1;
            }
            else if (arr[mid]>target){
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        return last;
    }
      vector<int> find(vector<int>& arr, int x) {
          // code here
          int end=arr.size()-1;
          int first=binarySearchFirst(arr,0,end,x);
          int last=binarySearchLast(arr,0,end,x);
          return {first,last};
      }
  };