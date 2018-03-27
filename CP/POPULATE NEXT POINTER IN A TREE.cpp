class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode* leftWall = NULL; // leftmost node of the next level.
        TreeLinkNode* prev = NULL; // leading node on the next level
        TreeLinkNode* cur = root; // current node on the current level

        while (cur != NULL) {
            
            while (cur != NULL) {
                if (cur->left != NULL) {
                    if (prev != NULL) {
                        prev->next = cur->left;
                    } else {
                        leftWall = cur->left;
                    }
                    prev = cur->left;
                }

                if (cur->right != NULL) {
                    if (prev != NULL) {
                        prev->next = cur->right;
                    } else {
                        leftWall = cur->right;
                    }
                    prev = cur->right;
                }

                // move to the next node
                cur = cur->next;
            }

            // move to the next level
            cur = leftWall;
            leftWall = NULL;
            prev = NULL;

        }
    }
};
