#include<iostream>
using namespace std;

//8 10 1 -1 -1 6 4 -1 -1 7 -1 -1 3 -1 14 13 -1 -1 -1 
class node{
public:
int data;
node* left;
node* right;
node(int d){
    data=d;
    left=NULL;
    right=NULL;

}
};
node* ct(){
    int data;
    cin>>data;
    if(data==-1){
        return NULL;
    }
    node* root=new node(data);
    root->left=ct();
    root->right=ct();
    return root;
}
void preorder(node *root){
    if(root==NULL){
        return;
    }
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}
void inorder(node *root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void postorder(node *root){
    if(root==NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";
}
int countnodes(node* root){
    if(root==NULL){
        return 0;
    }
    return countnodes(root->left)+countnodes(root->right)+1;
}
int height(node *root){
    if(root==NULL){
        return 0;
    }
    int left=height(root->left);
    int right=height(root->right);
    return max(left,right)+1;
}
int countdimaeter(node* root){
    if(root==NULL){
        return 0;
    }
    //diameter via root node
    int op1=height(root->left)+height(root->right);
    //dia exist  in lst
    int op2=countdimaeter(root->left);
    int op3=countdimaeter(root->right);
    return max(op1,max(op2,op3));

}
node* search(node* root,int key){
    if(root=NULL){
        return NULL;
    }
    if(root->data==key){
        return root;
    }
    node* left=search(root->left,key);
    if(left!=NULL){
        return left;
    }
    node* right=search(root->right,key);
    return right;
}
int main(){
    node* root=ct();
    preorder(root);
    cout<<endl;
    inorder(root);
    cout<<endl;
    postorder(root);
    cout<<countnodes(root)<<endl;
    cout<<height(root)<<endl;
    cout<<countdimaeter(root);
    int key;
    cin>>key;
    node* ans=search(root,key);
    if(ans!=NULL){
        cout<<ans;
    }
    else{
        cout<<"na ji nahin mila";
    }
}

