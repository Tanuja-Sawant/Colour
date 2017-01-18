#include<stdio.h>
#include<stdlib.h>

struct node{
	int key;
	struct node* left;
	struct node* right;
};


struct node* newNode(int key){
	struct node *temp=(struct node*)malloc(sizeof(struct node));
	temp->left=NULL;
	temp->right=NULL;
	temp->key=key;
	return temp;

}

	struct node* searchNode(int key, struct node* root){
		if(root==NULL || root->key==key)
			return root;
		if(root->key<key)
		{
			root=root->right;
			return searchNode(key,root);
		}
		if(root->key>key)
		{
			root=root->left;
			return searchNode(key,root);
		}

	}

	struct node* insertNode(int key, struct node* root){
		if(root==NULL || root->key==key)
			return root;
		if(root->key<key )
		{
			if(root->right==NULL )
			{
				struct node *inserted=newNode(key);
				root->right=inserted;
				return inserted;
			}
			else
			{
				root=root->right;
				return insertNode(key,root);
			}
		}
		if(root->key>key)
		{
			if(root->left==NULL )
			{
				struct node *inserted=newNode(key);
				root->left=inserted;
				return inserted;
			}
			else
				{
				root=root->left;
				return insertNode(key,root);
			}
		}
    }

    void inorder(struct node* root){
    	if(root->left!=NULL)
    	{
    		inorder(root->left);
    	}
    		printf("%d	",root->key);
    	if(root->right!=NULL)
    	{
    		inorder(root->right);
    	}
    }

int main(int argc, char const *argv[])
{
	struct node* n1=newNode(1);
	struct node* n2=insertNode(6,n1);
	struct node* n3=insertNode(3,n2);
	struct node* n4=insertNode(4,n2);
	struct node* n5=insertNode(5,n3);
	

	inorder(n1);
	

	return 0;
}