#include <iostream>
#include <queue>

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
    TreeNode *node = nullptr;
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        std::queue<TreeNode*> q;
        q.push(root);

        while (!q.empty()){
            TreeNode *current = q.front();
            q.pop();

            std::cout << current->val << std::endl;

            if (current->left)  q.push(current->left);
            if (current->right) q.push(current->right);
        }



        return root;
    }
    
    void printTree(TreeNode *node){
        if (node != nullptr){
            std::cout << node->val << ", ";
            printTree(node->right);
            printTree(node->left);
        }
    }

};

int main(){
    Solution test;
    // [2,3,5,8,13,21,34]

    test.node        = new TreeNode(2);
    test.node->left  = new TreeNode(3);
    test.node->right = new TreeNode(5);
    test.node->left->left   = new TreeNode(8);
    test.node->left->right  = new TreeNode(13);
    test.node->right->right = new TreeNode(34);
    test.node->right->left  = new TreeNode(21);


    //test.printTree(test.node);

    test.reverseOddLevels(test.node);

    std::cout << "\n";
    return 0;
}
