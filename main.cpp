
// // Add two matrices
// vector<vector<int>> add(vector<vector<int>>& A, vector<vector<int>>& B) {
//     int n = A.size();
//     vector<vector<int>> C(n, vector<int>(n, 0));
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             C[i][j] = A[i][j] + B[j][i];
//     return C;
// }

// // Subtract two matrices
// vector<vector<int>> subtract(vector<vector<int>>& A, vector<vector<int>>& B) {
//     int n = A.size();
//     vector<vector<int>> C(n, vector<int>(n, 0));
//     for(int i = 0; i < n; i++)
//         for(int j = 0; j < n; j++)
//             C[i][j] = A[i][j] - B[i][j];
//     return C;
// }

// // Strassen Algorithm
// vector<vector<int>> strassen(vector<vector<int>> A, vector<vector<int>> B) {
//     int n = A.size();
//     if(n == 1) {
//         return {{A[0][0] * B[0][0]}};
//     }

//     int k = n / 2;

//     vector<vector<int>>
//         A11(k, vector<int>(k)), A12(k, vector<int>(k)),
//         A21(k, vector<int>(k)), A22(k, vector<int>(k));

//     vector<vector<int>>
//         B11(k, vector<int>(k)), B12(k, vector<int>(k)),
//         B21(k, vector<int>(k)), B22(k, vector<int>(k));

//     // Split matrices
//     for(int i = 0; i < k; i++)
//         for(int j = 0; j < k; j++) {
//             A11[i][j] = A[i][j];
//             A12[i][j] = A[i][j+k];
//             A21[i][j] = A[i+k][j];
//             A22[i][j] = A[i+k][j+k];

//             B11[i][j] = B[i][j];
//             B12[i][j] = B[i][j+k];
//             B21[i][j] = B[i+k][j];
//             B22[i][j] = B[i+k][j+k];
//         }

//     // 7 multiplications
//     auto M1 = strassen(add(A11, A22), add(B11, B22));
//     auto M2 = strassen(add(A21, A22), B11);
//     auto M3 = strassen(A11, subtract(B12, B22));
//     auto M4 = strassen(A22, subtract(B21, B11));
//     auto M5 = strassen(add(A11, A12), B22);
//     auto M6 = strassen(subtract(A21, A11), add(B11, B12));
//     auto M7 = strassen(subtract(A12, A22), add(B21, B22));

//     // Combine the results
//     vector<vector<int>> C(n, vector<int>(n));

//     for(int i = 0; i < k; i++)
//         for(int j = 0; j < k; j++) {
//             C[i][j] = M1[i][j] + M4[i][j] - M5[i][j] + M7[i][j];
//             C[i][j+k] = M3[i][j] + M5[i][j];
//             C[i+k][j] = M2[i][j] + M4[i][j];
//             C[i+k][j+k] = M1[i][j] - M2[i][j] + M3[i][j] + M6[i][j];
//         }

//     return C;
// }

// Definition for singly-linked list.
#include <bits/stdc++.h>
using namespace std;

// class Solution {
// public:
//     bool isSubsequence(string s, string t) {
//         int len1 = s.size();
//         int len2 = t.size();

//         int p1 = 0;
//         int p2 = 0;

//         while(p1 < len1 && p2 < len2){
//             if(s[p1] == t[p2]){
//                 p1++;
//                 p2++;
//             }else{
//                 p2++;
//             }
//         }
//         if(p1 == len1) return true;
//         return false;

//     }
// };


class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end(), greater<int>());
        int avg = 0;
        for(int i = 0 ; i < k ; i++){
            avg += nums[i];
        }
        return avg / k ;
    }
};


int main() {
    string s = "abc";
    string t = "ahbgdc";
    vector <int> nums = {1,12,-5,-6,50,3};
    int k = 4;
    Solution S; 
    cout << S.findMaxAverage(nums , k);

    return 0;
}
