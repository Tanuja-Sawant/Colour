#include<stdio.h>
#include<stdlib.h>


struct node{
	int data;
	struct node *left;
	struct node *right;
};

struct node * makeNode(int data){

	struct node * temp = malloc(sizeof(struct node));

    temp->data=data;
    temp->left=NULL;
    temp->right=NULL;

	return temp;

}

struct node * makeTree(int data){
	return makeNode(data);
}









void inorder(struct node* root){
	
	if(root->left!=NULL){
		
		inorder(root->left);
	}

	printf("%d ",root->data);
	if(root->right!=NULL){
		inorder(root->right);
	}
}








void addNode(struct node * root,int data){


	while(1==1){

		if(root->data>data){
			if(root->left==NULL){
				root->left=makeNode(data);
				break;
			}
			else{
				root=root->left;
			}
		}
		else{
			if(root->right==NULL){
				root->right=makeNode(data);
				break;
			}
			else{
				root=root->right;
			}
		}
	}
}

int main(){

	struct node * tree = makeTree(5);
	addNode(tree,1);
	addNode(tree,2);
	addNode(tree,11);
	addNode(tree,25);
	addNode(tree,199);
	addNode(tree,-7);
	addNode(tree,78);
	addNode(tree,56);
	
	inorder(tree);
	//printf("%d %d %d",tree->data,tree->left->data,tree->right->right->right->left->left->data);
	return(0);
}
