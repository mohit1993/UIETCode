#include <stdio.h>
#include <stdlib.h>

typedef struct node{
	int data;
	int threadval;
	struct node *left,*right;
}Tree;

Tree* insert(Tree*,int);
Tree* delete(Tree*,int);
int search(Tree*,int);
void display(Tree*);
void displaythread(Tree*);
void displaynew(Tree*,int);
Tree* thread(Tree*);
Tree* newdelete(Tree*,int);

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
		printf("\n 4. Delete");
		printf("\n 5. Threaded Tree");
		printf("\n 6. Exit\n");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1: display(root);
					getchar();
					//displaynew(root,6);
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
					{
						printf("\nYes Found");
					}
					getchar();
					break;

			case 4: printf("\nEnter value ");
					scanf("%d",&value);
					root = delete(root,value);
					getchar();
					break;

			case 5: root = thread(root);
					printf("Done");
					//displaythread(root);
					printf("Done2");
					getchar();
					break;

			case 6: getchar();
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

Tree* insert(Tree *root,int val)
{
	if(root == NULL)
	{
		Tree *x;
		x = (Tree*)malloc(sizeof(Tree));
		if(x != NULL)
		{
			x->data = val;
			x->threadval = 0;
			root = x;
			root->left = NULL;
			root->right = NULL;
			return root;
		}
	}
	else if(root->data > val)
	{
		root->left = insert(root->left,val);
		return root;
	}
	else{
		root->right = insert(root->right,val);
		return root;
	}
}

void display(Tree *root)
{
	if(root == NULL)
		return;
	display(root->left);
	//printf(" %d ",root->data);
	display(root->right);
	printf(" %d ",root->data);
}

void displaynew(Tree *root,int level)
{
	//printf
	//while(level--)
		printf(" ");
}
int search(Tree *root,int val)
{
	if(root == NULL)
		return -1;
	else if(root->data == val)
		return val;
	else if(root->data > val)
		search(root->left,val);
	else
		search(root->right,val);
}

Tree* delete(Tree* node,int val)
{
	Tree *temp = NULL;
	Tree *root = node;
	while(node != NULL && node->data != val)
	{
		temp = node;
		if(node->left!= NULL && node->data > val)
			node = node->left;
		else if(node->right != NULL)
			node = node->right;
		else break;
	}
	if(node->data == val && temp == NULL)
	{
		return newdelete(node,val);
	}
	else if(temp->left != NULL && temp->left->data == val)
	{
		temp->left = newdelete(node,val);
		return root;
	}
	else if(temp->right != NULL && temp->right->data == val)
		{
			temp->right = newdelete(node,val);
			return root;
		}
	else
		return root;
}

Tree* newdelete(Tree *head,int val)
{
	if(head != NULL && head->left == NULL && head->right == NULL)
	{
		free(head);
		return NULL;
	}
	else if(head != NULL && head->left == NULL)
	{
		Tree *lefttemp = head->right;
		free(head);
		return lefttemp;
	}
	else if(head != NULL && head->right == NULL)
	{
		Tree *righttemp = head->left;
		free(head);
		return righttemp;
	}
	else
	{
		Tree *parent=head,*max = head->left;
		if(max->right == NULL)
		{
			head->data = max->data + head->data - (max->data = head->data);
			head->left = newdelete(max,val);
			return head;
		}
		while(max->right != NULL)
		{
			parent = max;
			max = max->right;
		}
		head->data = max->data + head->data - (max->data = head->data);
		parent->right = newdelete(max,val);
		return head;
	}
}

Tree* thread(Tree* root)
{
	Tree *stackleft[10],*stackright[10];
	Tree *head = root;
	int leftstack = -1,rightstack = -1;
	while((root!= NULL && root->right != NULL) || (leftstack != -1 || rightstack != -1))
	{
		while(root->left != NULL)
		{
			++rightstack;
			stackright[rightstack] = root;
			root = root->left;
		}
		if(root->right == NULL)
		{
			if(leftstack == -1 && rightstack != -1){
				root->threadval = 1;
				++leftstack;
				stackleft[leftstack] = stackright[rightstack];
				root->right = stackright[rightstack];
				--rightstack;
				root = stackleft[leftstack];
				if(root->right != NULL)
				root = root->right; 
			}
			else if(rightstack == -1 && leftstack != -1)
			{
				root->threadval = 2;
				root->left = stackleft[leftstack];
				--leftstack;
				root = stackright[rightstack];
				--rightstack;
				if(root->right != NULL)
				root = root->right;				
			}
			else{
				root->threadval = 3;
				root->left = stackleft[leftstack];
				stackleft[leftstack] = stackright[rightstack];
				root->right = stackright[rightstack--];
				--rightstack;
				root = stackleft[leftstack];
				if(root->right != NULL)
				root = root->right; 
			}
			
		}
	}
	return head;
}

void displaythread(Tree *root)
{
	while(root->left != NULL)
		root=root->left;
	printf("\n");
	while(root->right != NULL)
	{
		if(root->threadval != 0)
		{	
			printf("%d ",root->data);
			root = root->right;
		}
		else
		{
			root=root->left;
		}
	}
}