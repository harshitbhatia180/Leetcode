class Solution {
public:
    bool isPalindrome(int x) {
        int a=0,b=x;
        long int num=0;
        
        while(x>0){
            a=x%10;
            num=num*10+a;
            x=x/10;
        }
        if(num==b){
            return true;
        }
        else{
            return false;
    }
}};