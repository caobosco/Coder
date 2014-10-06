#include <cstdio>

struct TreeNode{
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

bool flag;
TreeNode *ancestor, *n1, *n2;

int cnt(TreeNode *node) {
    if (!node)
        return 0;
    if ( flag )
        return 0;
    int count = cnt(node->left) + cnt(node->right);
    if (node == n1 || node == n2)
        count++;
    if( count == 2) {
        ancestor = node;
        flag = 1;
    }
    return count;
}

TreeNode *leastCommonAncestor(TreeNode *root, TreeNode *node1, TreeNode *node2) {
    flag = 0;
    n1 = node1, n2 = node2;
    cnt(root);
    return ancestor;
}
    
int main(){
    TreeNode *n1 = new TreeNode(1);
    TreeNode *n2 = new TreeNode(2);
    n1->right = n2;
    TreeNode *n3 = leastCommonAncestor(n1, n1, n2);
    return 0;
}
