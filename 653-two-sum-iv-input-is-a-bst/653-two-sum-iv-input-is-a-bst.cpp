/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
    stack<TreeNode*> st;
    bool reverse = true;
    
    void pushAll(TreeNode* root){
        while(root != NULL){
            st.push(root);
            if(reverse == false){
                root = root->left;
            } else{
                root = root->right;
            }
        }
    }
public:
    BSTIterator(TreeNode* root, bool isReverse) {
        reverse = isReverse;
        pushAll(root);
    }
    
    int next() {
        /// root node
        TreeNode* temp = st.top();
        st.pop();
        
        if(reverse == false){
            pushAll(temp->right);
        }
        else{
            pushAll(temp->left);
        }
        
        return temp->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};

class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(root == NULL){
            return false;
        }
        
        /// next
        BSTIterator l(root, false);
        /// before
        BSTIterator r(root, true);
        
        int i = l.next();
        int j = r.next();
        
        while(i < j){
            if(i + j == k){
                return true;
            }
            else if(i + j < k){
                i = l.next();
            }
            else{
                j = r.next();
            }
        }
        return false;
    }
};