class Solution {
public:
    TreeNode* sortedListToBST(ListNode* head) {
        if(head==NULL) return NULL;
        // Find mid of linked list
        ListNode* prev = NULL;
        ListNode* mid = head;
        ListNode* fast = head->next;
        while(fast && fast->next){
            prev = mid;
            mid = mid->next;
            fast = fast->next->next;
        }
        // mid will be the root
        TreeNode* root = new TreeNode(mid->val);
        // All nodes after mid will be right subtree
        root->right = sortedListToBST(mid->next);
        if(prev){
            // All nodes before mid will be left subtree
            prev->next = NULL;
            root->left = sortedListToBST(head);
        }
        else root->left = NULL;
        return root;
    }
};