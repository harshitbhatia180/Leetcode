class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        vector<int> A = nums1, B = nums2;
        int total = A.size() + B.size();
        int half = total / 2;
        
        if(A.size() > B.size()) swap(A, B);
        
        const int MAX = 1000005, MIN = -1000005;
        int l = 0, r = A.size() - 1;
        
        while(true) {
            float i = (l + r) / 2.0;
            if(i < 0.0) {
                i *= -1.0, i = ceil(i), i *= -1.0;
            }
            else i = (int)i;
            float j = half - i - 2;
    
            int Aleft = i >= 0 ? A[i] : MIN;
            int Aright = i + 1 < A.size() ? A[i+1] : MAX;
            int Bleft = j >= 0 ? B[j] : MIN;
            int Bright = j + 1 < B.size() ? B[j+1] : MAX;
            
            if(Aleft <= Bright && Bleft <= Aright) {
                if(total % 2) return 1.0 * min(Aright, Bright);
                else return 1.0 * (max(Aleft, Bleft) + min(Aright, Bright)) / 2;
            }
            else if(Aleft > Bright) r = i - 1;
            else l = i + 1;
        }
    }
};