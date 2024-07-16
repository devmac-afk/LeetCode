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
class Solution {
public:
        TreeNode* LowestCommonAncestor(TreeNode* root , int src , int dest){
            if(!root){
                return NULL;
            }
            if(root->val == src || root->val == dest){
                return root;
            }

            TreeNode* l = LowestCommonAncestor(root->left , src , dest);
            TreeNode* r = LowestCommonAncestor(root->right , src , dest);

            if(l && r){
                return root;
            }
            return l ? l : r;
        }

        bool findPath(TreeNode* LCA , int target , string& path){
            if(LCA == NULL){
                return false;
            }
            if(LCA->val == target){
                return true;
            }

            path.push_back('L');
            if(findPath(LCA->left , target , path) == true){
                return true;
            }
            path.pop_back();

            path.push_back('R');
            if(findPath(LCA->right , target , path) == true){
                return true;
            }
            path.pop_back();

            return false;
        }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = LowestCommonAncestor(root, startValue, destValue);

        string lcaTOsrc = "";
        string lcaTOdest = "";

        findPath(LCA , startValue , lcaTOsrc);
        findPath(LCA , destValue , lcaTOdest);

        string result = "";

        for(int i=0 ; i<lcaTOsrc.length(); i++){
            result.push_back('U');
        }

        result += lcaTOdest;

        return result;

    }
};