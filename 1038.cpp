#include <iostream>

//Definition for a binary tree node.
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
    int temp = 0;
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
        std::cout << "VAL: " << node->val << std::endl;
        sum += temp;
        temp = node->val;
        valRight = (node->right) ? node->right->val : 0;
        node->val += valRight;
        bstToGst(node->left);

        return node;
    }

    TreeNode* testing(TreeNode* node) {
        if (node == nullptr) return node;        

        testing(node->right);
        std::cout << "VAL: " << node->val << std::endl;
        std::cout << "Temp: " << temp << std::endl;
        std::cout << "Sum : " << sum  << std::endl;
        sum += temp;
        temp = node->val;
        valRight = (node->right) ? node->right->val : 0;
        node->val = temp + sum;
        testing(node->left);

        return node;
    }

    TreeNode* foo(TreeNode* node) {
        if (node == nullptr) return node;        

        bstToGst(node->left);
        node->val -= sum;
        std::cout << "VAL: " << node->val << std::endl;
        bstToGst(node->right);

        return node;
    }

    int prefix(TreeNode *node){
        if (node == nullptr) return 0;

        prefix(node->right);
        sum += node->val;
        prefix(node->left);
        std::cout << sum << std::endl;
        return sum;
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

    test.testing(test.root);
    //test.bstToGst(test.root);
    //test.prefix(test.root);
    //test.foo(test.root);
    test.printTree(test.root);



    std::cout << "\n";
    return 0;
}
