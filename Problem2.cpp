class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int,int>inMap;

        for(int i = 0; i< inorder.size(); i++)
        {
            inMap[inorder[i]] = i;
        }

        TreeNode *root = buildTreePreIn(preorder, 0, preorder.size()-1, inorder, 0 , inorder.size()-1,inMap);
        return root;
    }

  TreeNode* buildTreePreIn(vector<int>&preorder,int preStart, int preEnd, vector<int>&inorder,int inStart, int inEnd, map<int, int>inMap)
  {
      if(preStart>preEnd || inStart > inEnd) return NULL;

      TreeNode *root = new TreeNode(preorder[preStart]);

      int inRoot = inMap[root->val];
      int numsLeft = inRoot - inStart;

      root->left = buildTreePreIn(preorder,preStart+1,preStart+numsLeft, inorder,inStart ,inRoot-1, inMap);
      root->right = buildTreePreIn(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd , inMap);

      return root;
  } 
};
