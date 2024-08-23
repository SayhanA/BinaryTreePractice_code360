int maxHeight(Node* root){
    if(root == NULL) return 0;
    else{
        int l = maxHeight(root->left);
        int r = maxHeight(root->right);
        return l>r ? l+1 : r+1;
    }
}