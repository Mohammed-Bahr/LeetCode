#include <bits/stdc++.h>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;
  TreeNode() : val(0), left(nullptr), right(nullptr) {}
  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
  TreeNode(int x, TreeNode *left, TreeNode *right)
      : val(x), left(left), right(right) {}
};

class Solution {
public:
  int kthSmallest(TreeNode *root, int k) {
    TreeNode *curr = root;
    TreeNode *curr2 = root;
    int count = 1;
    while (curr->left != NULL) {
      curr = curr->left;
      count++;
    }
    int target = count - k;
    if (target == 0){
        return curr->val ;
    }
    while(target >= 0){
        curr2 = curr2->left;
        target--;
    }
    return curr2->val;
    
  }
};


int main(){
    Solution s;
    TreeNode *root = new TreeNode(3);
    root->left = new TreeNode(1);
    root->right = new TreeNode(4);
    root->left->right = new TreeNode(2);
    cout << s.kthSmallest(root, 1) << endl;
}