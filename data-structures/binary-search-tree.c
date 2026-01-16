/************************************************************************************* 
* This program implements a binary search tree
*************************************************************************************/

#include<stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct node *BSTREE;

struct node
{
	int data;
	BSTREE left;
	BSTREE right;
};

BSTREE insert(BSTREE root, int number);
BSTREE find(BSTREE root, int number);
void inOrderTraversal(BSTREE subtree, FILE *fp);



int main()
{
	BSTREE root = NULL;

	root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 70);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 60);
    root = insert(root, 80);

    BSTREE foundNode = find(root, 40);
    if (foundNode)
        printf("Node found: %d\n", foundNode->data);
    else
        printf("Node not found\n");

    FILE *fp = fopen("output.txt", "w");
    if (fp != NULL)
    {
        inOrderTraversal(root, fp);
        fclose(fp);
    }

    return 0;
}

BSTREE insert(BSTREE root, int number)
{
	if (!root) {
		root = (BSTREE)malloc(sizeof(struct node));
		root->left = NULL;
		root->right = NULL;
		root->data = number;
		return root;
	}
	if (number < root->data)
    {
        root->left = insert(root->left, number);
    }
    else if (number > root->data)
    {
        root->right = insert(root->right, number);
    }

    return root;
}

BSTREE find(BSTREE root, int number)
{
	if (root == NULL || root->data == number)
    {
        return root;}

    if (number < root->data)
    {
        return find(root->left, number);}
    else
    {
        return find(root->right, number);}
}

void inOrderTraversal(BSTREE root, FILE *fp)
{
	if (root == NULL)
    {
        return;
    }

    inOrderTraversal(root->left, fp);
    fprintf(fp, "%d\n", root->data);
    inOrderTraversal(root->right, fp);
}


