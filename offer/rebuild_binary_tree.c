#include <cstdio>
struct TreeNode {
    int val;
    TreeNode *left, *right;
    TreeNode(int x):val(x), left(NULL), right(NULL){}
};

bool isLegal;
int preorder[1001], inorder[1001];

TreeNode *rebuild_binary_tree(int s1, int e1, int s2, int e2){
    if(!isLegal || s1 >= e1)
        return NULL;
    int val = preorder[s1];
    int pos = s2;
    while(inorder[pos]!= val && pos < e2)
        pos++;
    if(pos == e2){
        isLegal = 0;
        return NULL;
    }
    TreeNode *root = new TreeNode(val);
    root->left = rebuild_binary_tree(s1+ 1, s1+1+ pos- s2, s2, pos);
    root->right = rebuild_binary_tree(s1+1+pos- s2, e1, pos+ 1, e2);    
    if(!isLegal)
        return NULL;
    return root;
}

void post_traverse(TreeNode *root) {
    if(!root)
        return;
    post_traverse(root->left);
    post_traverse(root->right);
    printf("%d ", root->val);
}

int main(){
    int num;
    while(scanf("%d", &num) != EOF) {
        isLegal = 1;
        for(int i = 0; i < num; ++i)
            scanf("%d", &preorder[i]);
        for(int i = 0; i < num; ++i)
            scanf("%d", &inorder[i]);
        post_traverse(rebuild_binary_tree(0, num, 0, num));
        if(!isLegal)
            printf("No");
        putchar('\n');
    }
    return 0;
}
