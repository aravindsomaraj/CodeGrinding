#include <bits/stdc++.h>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
int minDepth(TreeNode* root) 
{
        
        if(root==NULL)
            return 0;
        // cout << root->val << " ";
        if(root->left!=NULL && root->right!=NULL )
            return min(1+minDepth(root->left),1+minDepth(root->right));
        else if(root->left == NULL)
            return 1+minDepth(root->right);
        else
            return 1+minDepth(root->left);
}

int main()
{
    TreeNode *t5 = new TreeNode(5,NULL,NULL);
    TreeNode *t4 = new TreeNode(4,NULL,t5);
    TreeNode *t3 = new TreeNode(3,NULL,t4);
    TreeNode *t2 = new TreeNode(2,NULL,t3);
    TreeNode *t1 = new TreeNode(1,NULL,t2);

    int x = minDepth(t1);
    cout << x << " ";
}