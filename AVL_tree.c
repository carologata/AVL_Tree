#include "binary_tree.h"

void	create_node(t_tree_node **root, int data)
{
	*root = malloc(sizeof(t_tree_node));
	(*root)->data = data;
	(*root)->height = 0;
	(*root)->right = NULL;
	(*root)->left = NULL;
}

void	insert_tree_node(t_tree_node **root, int data)
{
	if (*root == NULL)
		create_node(root, data);
	else if (data > (*root)->data)
		insert_tree_node(&(*root)->right, data);
	else if (data < (*root)->data)
		insert_tree_node(&(*root)->left, data);
	else
		;
	return 
}

int	main(void)
{
	t_tree_node root;

	root = insert_tree_node(&root, 25);
	insert_tree_node(&root, 12);
	insert_tree_node(&root, 59);
	insert_tree_node(&root, 1);
	insert_tree_node(&root, 0);
	insert_tree_node(&root, 5);
	insert_tree_node(&root, 19);
	insert_tree_node(&root, 15);
	insert_tree_node(&root, 22);

	printTree(root);
	return (0);
}