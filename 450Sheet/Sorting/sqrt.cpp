class Solution {
    public:
      int countSquares(int n) {
          // code here
          int count=0;
          for(int i=1;i<n;i++){
              int sqr=i*i;
              if(sqr<n){
                  count++;
              }
              else{
                  break;
              }
          }
          return count;
      }
  };