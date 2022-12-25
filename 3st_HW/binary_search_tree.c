#include <stdio.h>
#include <stdlib.h>

struct node
{
	int data;
	struct node *left;
	struct node *right;
};

void inorder(struct node *root)
{
	if (root)
	{
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
void preorder(struct node *root)
{
	if (root)
	{
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct node *root)
{
	if (root)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}

int main()
{
	while (1)
	{
		int n, i;
		struct node *input_node, *comparing_node, *root;  //pointer to null

		scanf("%d", &n);

		if (n != -1)
		{
			for (i = 0; i < n; i++)
			{
				input_node = (struct node *)malloc(sizeof(struct node));
				scanf("%d", &input_node->data);
				input_node->left = NULL;
				input_node->right = NULL;
				if (i == 0)
				{
					root = input_node; // point to the root node
				}
				else
				{
					comparing_node = root; // comparing_node is used to traverse the tree
					while (1)
					{
						if (input_node->data > comparing_node->data)
						{
							if (comparing_node->right == NULL)
							{
								comparing_node->right = input_node;
								break;
							}
							else
								comparing_node = comparing_node->right;
						}
						else
						{
							if (comparing_node->left == NULL)
							{
								comparing_node->left =input_node;
								break;
							}
							else
								comparing_node = comparing_node->left;
						}
					}
				}
			}
			printf("preorder:");
			preorder(root);
			printf("\ninorder:");
			inorder(root);
			printf("\npostorder:");
			postorder(root);
			printf("\n\n");
		}
		else
			break;
	}

	return 0;
}
