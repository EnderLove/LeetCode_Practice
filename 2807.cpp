#include <iostream>

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution{
    public:
        ListNode* root = nullptr;
       
        void insert(int val){ root = new ListNode(val, root); }
        ListNode *getHead(){ return root; }

        void showList(){
            ListNode* temp = root;
            while (temp != nullptr){
                std::cout << temp->val << ", ";
                temp = temp->next;
            }
            std::cout << "\n";
        }

        ListNode* insertGreatestCommonDivisors(ListNode* head) {
             
            ListNode* temp = head;
        
            if (head->next == nullptr) return head;

            while (temp->next != nullptr){
                int minor = (temp->val < temp->next->val) ? temp->val : temp->next->val;
                int max   = (temp->val > temp->next->val) ? temp->val : temp->next->val;

                std::cout << minor << std::endl;
    
                int maxDivisor = 0;

                for (int i = minor; i > 0; i--){
                    if (max % i == 0 && minor % i == 0){
                        maxDivisor = i;
                        break;
                    }
                }

                ListNode *node = new ListNode(maxDivisor);

                node->next = temp->next;
                temp->next = node;

                temp = temp->next->next;
            }
            return head;
        }
};


int main(){

    Solution test;
  
    int arr[] = {7};
    //int arr[] = {3, 10, 6, 18};
    for (int it : arr) test.insert(it);

    test.insertGreatestCommonDivisors(test.getHead());



    test.showList();
    
    return 0;
}
