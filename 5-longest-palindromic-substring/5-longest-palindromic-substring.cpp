class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        int dp[n][n]; // dp[i][j] represents that the substring starting with idx i and ending with idx j is a palindrome(1) or not(0)
        
        string ans = "";
        
        for(int gap = 0;gap<n;gap++){ //no. of elements between starting and ending idx of substring
            for(int i=0;i<n-gap;i++){ // starting  idx of substring
                int j = gap + i;      // ending idx of substring
                if(gap == 0){         //meaning substring with len 1 e.g. a,b,c..
                    dp[i][j] = 1;
                }
                else if(gap ==1){    // substring with len 2 , e.g. aa,bb,cc,..
                    if(s[i] == s[j]){
                        dp[i][j] = 1;
                    }
                    else {
                        dp[i][j] = 0;
                    }
                }
                else{
                    // the case where gap >=2
                    if(s[i] == s[j] && dp[i+1][j-1]){ // if end idx  are matching and the middle substring are palindrome then mark it as true
                        dp[i][j] = 1;
                    }
                    else {
                        // does'nt matter if end idx elements are not matching
                        dp[i][j] = 0;
                    }
                }
                
                // now check  if current substring is palindrome or not && the len is greater then prev. ans
            if(dp[i][j] && (j-i+1) > ans.size()){
                ans = s.substr(i,j-i+1);
             }
          }
        }
        return ans;
    }
};