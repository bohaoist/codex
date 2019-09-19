#include<stack>
/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/

class Solution {
public:
//反转二叉树
void Mirror(TreeNode * pRoot){
    if(pRoot == nullptr){
        return;
    }
    std::swap(pRoot->left, pRoot->right);
    Mirror(pRoot->left);
    Mirror(pRoot->right);
}
};

void preOrderRecur(TreeNode * head){
    if(head == nullptr){
        return;
    }
    cout << head->data;
    preOrderRecur(head->left);
    preOrderRecur(head->right);
}

void preOrderIter(TreeNode * head)
{
    if(head == null){
        return;
    }
    stack<TreeNode> stacks;
    stacks.push(*head);
    while(!stack.empty()){
        TreeNode val = stack.pop()
        //visit root
        cout << val << endl;
        if(val->right != nullptr){
            stacks.push(val->right)
        }
        if(val->left != nullptr){
            stack.push(val->left);
        }        
    }
}

