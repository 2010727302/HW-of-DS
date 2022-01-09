
#include <iostream>
#include <algorithm>
#include "queue"
#include "vector"

using namespace std;

typedef struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
} *Node;


int leaf(TreeNode *root) {
    if (root == NULL) return 0;
    if (root->left == NULL && root->right == NULL) return 1;
    return leaf(root->left) + leaf(root->right);
}

int main() {

    int T;
    cin >> T;
    while (T--) {
        vector<int> vector;
        int c;
        cin >> c;
        while (c!=-1){
            vector.push_back(c);
            cin >> c;
        }
        TreeNode* root = (TreeNode*) malloc(sizeof (TreeNode));
        root->val = vector[0];
        root->left = NULL;
        root->right = NULL;
        int index = 1;
        queue<TreeNode*> queue;
        queue.push(root);
        while (!queue.empty()){
            int n = queue.size();
            for(int i=0;i< n;i++){
                TreeNode* temp = queue.front();
                queue.pop();
                int left = vector[index++];
                int right = vector[index++];
                if(left){
                    TreeNode* leftNode = (TreeNode*) malloc(sizeof (TreeNode));
                    leftNode->val = left;
                    temp->left = leftNode;
                    queue.push(leftNode);
                } else{
                    temp->left = NULL;
                }
                if(right){
                    TreeNode* rightNode = (TreeNode*) malloc(sizeof (TreeNode));
                    rightNode->val = right;
                    temp->right = rightNode;
                    queue.push(rightNode);
                } else{
                    temp->right = NULL;
                }
            }
        }
        cout << leaf(root) << endl;
    }
    
	}


