#include <iostream>

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    TreeNode *root = nullptr;
    int sum  = 0;
    int valRight = 0;

    TreeNode* insert(int val, TreeNode *node){
        if (node == nullptr) return new TreeNode(val);
        if (val < node->val) node->left  = insert(val, node->left );
        if (val > node->val) node->right = insert(val, node->right);
        return node;
    }

    TreeNode* bstToGst(TreeNode* node) {
        if (node == nullptr) return node;        

        bstToGst(node->right);
        sum += node->val;
        node->val = sum;
        bstToGst(node->left);

        return node;
    }
    
    int pre = 0;
    TreeNode* toGst(TreeNode* root) {
        if (root->right) toGst(root->right);
        pre = root->val = pre + root->val;
        if (root->left) toGst(root->left);
        return root;
    }

    void printTree(TreeNode *node){
        if (node != nullptr){
            printTree(node->right);
            std::cout << node->val << ", ";
            printTree(node->left);
        }
    }
};

int main(){
    Solution test;
    //root = [4,1,6,0,2,5,7,null,null,null,3,null,null,null,8]
    int root[] = {4,1,6,0,2,5,7,3,8};

    for (int it : root) test.root = test.insert(it, test.root);

    test.bstToGst(test.root);
    test.printTree(test.root);

    std::cout << "\n";
    return 0;
}
