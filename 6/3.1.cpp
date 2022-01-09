//
// Created by mashichen on 2021/11/7.
//
#include <iostream>
#include <algorithm>
#include "queue"
#include "vector"

using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    int leftType;
    int rightType;
};

void creatTree(TreeNode *root) {
    vector<int> vec;
    int c;
    cin >> c;
    while (c != -1) {
        vec.push_back(c);
        cin >> c;
    }
    root->val = vec[0];
    root->left = NULL;
    root->right = NULL;
    root->leftType = 0;
    root->rightType = 0;
    int index = 1;
    queue<TreeNode *> queue;
    queue.push(root);
    while (!queue.empty()) {
        int n = queue.size();
        for (int i = 0; i < n; i++) {
            TreeNode *temp = queue.front();
            queue.pop();
            int left = vec[index++];
            int right = vec[index++];
            if (left) {
                TreeNode *leftNode = (TreeNode *) malloc(sizeof(TreeNode));
                leftNode->val = left;
                temp->left = leftNode;
                leftNode->leftType = 0;
                leftNode->rightType = 0;
                queue.push(leftNode);
            } else {
                temp->left = NULL;
            }
            if (right) {
                TreeNode *rightNode = (TreeNode *) malloc(sizeof(TreeNode));
                rightNode->val = right;
                temp->right = rightNode;
                rightNode->leftType = 0;
                rightNode->rightType = 0;
                queue.push(rightNode);
            } else {
                temp->right = NULL;
            }
        }
    }
}

TreeNode *preTreeNode;

//中序线索化二叉树
void inThreadOrder(TreeNode *root) {
    if (root == NULL) return;
    inThreadOrder(root->left);
    if (root->left == NULL) {
        root->left = preTreeNode;
        root->leftType = 1;
    }
    if (preTreeNode != NULL && preTreeNode->right == NULL) {
        preTreeNode->right = root;
        preTreeNode->rightType = 1;
    }
    preTreeNode = root;
    inThreadOrder(root->right);
}


TreeNode *priorNode(TreeNode *root) {
    if (root->leftType) return root->left;
    TreeNode *pre = root->left;
    while (pre != NULL && !pre->rightType) {
        pre = pre->right;
    }
    return pre;
}

TreeNode *nextNode(TreeNode *root) {
    if (root->rightType) return root->right;
    TreeNode *next = root->right;
    while (next != NULL && !next->leftType) {
        next = next->left;
    }
    return next;
}

void findPriorAndNextNode(TreeNode *root) {
    queue<TreeNode *> deque;
    deque.push(root);
    while (!deque.empty()) {
        int n = deque.size();
        for (int i = 0; i < n; i++) {
            TreeNode *temp = deque.front();
            deque.pop();
            TreeNode *pre = priorNode(temp);
            TreeNode *next = nextNode(temp);
            if (pre ==NULL) {
                cout << "0 ";
            } else {
                cout << pre->val << " ";
            }
            if (next == NULL) {
                cout << "0 ";
            } else {
                cout << next->val << " ";
            }
            if (temp->left != NULL && !temp->leftType) deque.push(temp->left);
            if (temp->right != NULL && !temp->rightType) deque.push(temp->right);
        }
    }
    cout << endl;
}


int main() {
    int T;
    cin >> T;
    while (T--) {
        TreeNode *root = (TreeNode *) malloc(sizeof(TreeNode));
        creatTree(root);
        preTreeNode = NULL;
        inThreadOrder(root);
        findPriorAndNextNode(root);
    }
    return 0;
}
