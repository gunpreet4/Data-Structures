#include<iostream>
#include<conio.h>
#include<stdlib.h>
#include<queue>
using namespace std;
struct BstNode
{
	int data;
	BstNode* left;
	BstNode* right;
};
BstNode* GetNewNode(int data)
{
	BstNode* temp=new BstNode();
	temp->data=data;
	temp->left=temp->right=NULL;
	return temp;
}
BstNode* FindMin(BstNode* root)
{
	if(root==NULL)
	{
		printf("Error: Tree is Empty");
		return NULL;
	}
	//BstNode* temp=root;
	while(root->left!=NULL)
		root=root->left;
	//printf("Min element is -> %d",root->data);
	return root;
}

BstNode* Delete(BstNode* root,int data)
{
	if(root==NULL)
		return root;
	else if(root->data>data)
		root->left=Delete(root->left,data);
	else if(root->data<data)
		root->right=Delete(root->right,data);
	else
	{
		if(root->left==NULL && root->right==NULL)
		{
			delete root;
			root=NULL;
		}
		else if(root->left==NULL)
		{
			BstNode* temp=root;
			root=root->right;
			delete temp;
		}
		else if(root->right==NULL)
		{
			BstNode* temp=root;
			root=root->left;
			delete temp;
		}
		else
		{
			BstNode* temp=FindMin(root->right);
			root->data=temp->data;
			root->right=Delete(root->right,temp->data);
		}
	}
	return root;
}
bool Search(BstNode* root,int data)
{
	if(root==NULL)
		return false;
	if(root->data==data)
		return true;
	else if(data<=root->data)
		return Search(root->left,data);
	else
		return Search(root->right,data);
}
bool InorderSuccessor(BstNode* root,int data)
{
	static int c=0;
	if(c==0){ 
		c++;
		if(!Search(root,data))
		{
			printf("\nInorderSuccessor -> Error: Element not found");
			return true;
		}
	}
		static int count=0;
	if(root==NULL)
	{
		//printf("\nInorderSuccessor -> Error: No node in the tree");
		return true;
	}
	InorderSuccessor(root->left,data);
	if(root->data>data)
	{
		printf("\nInorderSuccessor -> %d",root->data);
		return true;
	}
	InorderSuccessor(root->right,data);
}
BstNode* Insert(BstNode* root,int data)
{
	if(root==NULL)
	{
		root=GetNewNode(data);
	}
	else if(data<=root->data)
		root->left=Insert(root->left,data);
	else
		root->right=Insert(root->right,data);
	return root;
}
struct Node{
		int data;
		Node* link;
	};
Node* head=NULL;
void add(int data)
{
	Node* temp=new Node();
	temp->data=data;
	temp->link=NULL;
	if(head==NULL)
	{
	head=temp;
		return;
	}
	while(head->link!=NULL)
		head=head->link;
	head->link=temp;
}
void Inorder1(BstNode* root)
{
	if(root==NULL)
		return;
	Inorder1(root->left);
	 add(root->data);
	Inorder1(root->right);
}
bool IsBinarySearchTree(BstNode* root)
{
	Inorder1(root);
	while(head->link!=NULL)
	{
		Node* t=head->link;
		if(head->data>t->data)
			return false;
		head=head->link;
	}
	return true;
}
	/*if(root==NULL)
		return true;
	if(root->data>min && root->data<max && IsBinarySearchTree(root->left,min,root->data) && IsBinarySearchTree(root->right,root->data,max))
		return true;
	else
		return false;*/
		

int FindHeight(BstNode* root)
{
	if(root==NULL)
		return -1;
	int leftheight=FindHeight(root->left);
	int rightheight=FindHeight(root->right);
	if(leftheight>rightheight)
		return (leftheight+1);
	else
		return (rightheight+1);
}
/*void leftprint(BstNode* root)
{
	printf("%d ",root->data);
	if(root->left==NULL)
	return;
	leftprint(root->left);
}
void rightprint(BstNode* root)
{
	printf("%d ",root->data);
	if(root->right==NULL)
	return;
	leftprint(root->right);
}*/
void min(BstNode* root)
{
	if(root==NULL)
	{
		printf("Error: Tree is Empty");
		return;
	}
	//BstNode* temp=root;
	while(root->left!=NULL)
		root=root->left;
	printf("Min element is -> %d",root->data);
}
void max(BstNode* root)
{
	if(root==NULL)
	{
		printf("Error: Tree is Empty");
		return;
	}
	//BstNode* temp=root;
	while(root->right!=NULL)
		root=root->right;
	printf("\nMax element is -> %d",root->data);
}
void LevelOrder(BstNode* root)
{
	if(root==NULL)
		return;
	queue<BstNode*> q;
	q.push(root);
	while(!q.empty())
	{
		BstNode* current=q.front();
		printf("%d ",current->data);
		if(current->left!=NULL)
			q.push(current->left);
		if(current->right!=NULL)
			q.push(current->right);
			q.pop();
	}
	
}
void Preorder(BstNode* root)
{
	if(root==NULL)
		return;
	printf("%d ",root->data);
	Preorder(root->left);
	Preorder(root->right);
}
void Inorder(BstNode* root)
{
	if(root==NULL)
		return;
	Inorder(root->left);
	printf("%d ",root->data);
	Inorder(root->right);
}
void Postorder(BstNode* root)
{
	if(root==NULL)
		return;
	Postorder(root->left);
	Postorder(root->right);
	printf("%d ",root->data);
}
int main()
{
	BstNode* root=NULL;
	root=Insert(root,10);
	root=Insert(root,43);
	root=Insert(root,66);
	root=Insert(root,611);
	root=Insert(root,4);
	//root=Insert(root,17);
	//root=Insert(root,25);
	printf("Height of tree -> %d\n",FindHeight(root));
	LevelOrder(root);
	//leftprint(root);
	//printf("\n");
	//rightprint(root);
	if(Search(root,20))
		printf("\nNo is found\n");
	else
		printf("\nNo is not found\n");
	min(root);
	max(root);
	printf("\nPreorder -> ");
	Preorder(root);
	printf("\nInorder -> ");
	Inorder(root);
	printf("\nPostorder -> ");
	Postorder(root);
	/*int min=0;
	while(min<=0)
	{
		//printf("cv");
		min--;
	}
	min++;
	int max=0;
	while(max>=0)
		max++;
	max--;
	//printf("%d ",min);
	//printf("%d",max);*/
	if(IsBinarySearchTree(root))
		printf("\nBinarySearchTree\n");
	else
		printf("\nNot BinarySearchTree\n");
		root=Delete(root,7);
		printf("After Deletion -> ");
		Inorder(root);
		if(!InorderSuccessor(root,10))
			printf("\nElement doesn't have any InorderSuccessor");
}
