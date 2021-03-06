#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	int flag;
	struct node *left,*right;
}Tree;

Tree* insert(Tree*,int);
int search(Tree*,int);
void display(Tree*);

int main(void)
{
	int choice,value;
	Tree *root=NULL;
	char ans = 'y';
	while(ans != 'n' && ans != 'N' )
	{	system("clear");
		printf("Enter your choice ");
		printf("\n 1. Display");
		printf("\n 2. Insertion");
		printf("\n 3. Search");
		printf("\n 4. Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: display(root);
					getchar();
					break;

			case 2: printf("\nEnter value ");
					scanf("%d",&value);
					root = insert(root,value);
					getchar();
					break;

			case 3: printf("\nEnter value ");
					scanf("%d",&value);
					value = search(root,value);
					if(value == -1)
						printf("\nNot Found");
					else
						printf("\nYes Found");
					getchar();
					break;

			case 4: getchar();
					ans = 'n';
					continue;

			default: printf("\nPlease re-enter your choice");
		}
		printf("\nDo you wish to do more ");
		fflush(stdin);
		scanf("%c",&ans);
	}
	return 0;
}

void display(Tree *root)
{
	while(root != NULL)
	{
		while(root->left != NULL && root->flag < 2)
			root = root->left;
		
		while(root->flag == 1 || root->flag == 3)
		{
			printf("%d ",root->data);
			root = root->right;
		}
		printf("%d ",root->data);
			root = root->right;
	}
}

int search(Tree* root,int val)
{
	while(root != NULL && root->data != val)
	{
		if(root->flag == 3)
		{
			return -1;
		}
		else if(root->data > val)
		{
			root = root->left;
		}
		else
		{
			root = root->right;
		}
	}
	if(root != NULL)
	return 1;
	else
		return -1;
}

Tree* insert(Tree *root,int val)
{
	Tree *head = root,*pred = root,*succ = root;
	if(root==NULL)
	{
		root = (Tree*)malloc(sizeof(Tree));
		root->data = val;
		root->flag = 0;
		root->left = NULL;
		root->right = NULL;
		return root;
	}
	else
	{
		while(root->left != NULL && root->right != NULL)
		{
			if(root->data > val)
			{
				succ = root;
				if(root->flag > 1)
					break;
				root = root->left;
			}
			else
			{
				pred = root;
				if(root->flag % 2 != 0)
					break;
				root = root->right;
			}
		}
		if(root->left == NULL && root->data < val)
		{
			while(root->right != NULL)
			{
				if(root->data > val)
				{
					succ = root;
					if(root->flag > 1)
						break;
					root = root->left;
				}
				else
				{
					pred = root;
					if(root->flag % 2 != 0)
						break;
					root = root->right;
				}
			}
		}
		else if(root->right == NULL && root->data > val)
		{
			while(root->left != NULL)
			{
				if(root->data > val)
				{
					succ = root;
					if(root->flag > 1)
						break;
					root = root->left;
				}
				else
				{
					pred = root;
					if(root->flag % 2 != 0)
						break;
					root = root->right;
				}
			}
		}
		if(root->left == NULL && root->data > val)
		{
			root->left = (Tree*)malloc(sizeof(Tree));
			root->left->data = val;
			root->left->left = NULL;
			root->left->right = root;
			root->left->flag = 1;
			return head;
		}
		else if(root->right == NULL && root->data < val)
		{
			root->right = (Tree*)malloc(sizeof(Tree));
			root->right->data = val;
			root->right->right = NULL;
			root->right->left = root;
			root->right->flag = 2;
			return head;
		}
		else if(root->data > val)
		{
			root->flag = root->flag - 2;
			root->left = (Tree*)malloc(sizeof(Tree));
			root->left->data = val;
			root->left->left = pred;
			root->left->right = root;
			root->left->flag = 3;
			return head;
		}
		else if(root->data < val)
		{
			root->flag = root->flag - 1;
			root->right = (Tree*)malloc(sizeof(Tree));
			root->right->data = val;
			root->right->left = root;
			root->right->right = succ;
			root->right->flag = 3;
			return head;
		}
		else
			return head;
	}
}

