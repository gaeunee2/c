#include <stdio.h> 
#include <stdlib.h> 
#include <memory.h> 
#define TRUE 1 
#define FALSE 0 
#define MAX_TREE_SIZE 20

typedef struct TreeNode {
    int data;
    struct TreeNode* left, * right;
} TreeNode;

//   root                           root2
//    15                              15
//   4   15                        4      15
// 15   16  25                  15       16  25
//                                              28

TreeNode n1 = { 15,  NULL, NULL };
TreeNode n2 = { 4,  &n1,  NULL };
TreeNode n3 = { 16, NULL, NULL };
TreeNode n4 = { 25, NULL, NULL };
TreeNode n5 = { 15, &n3,  &n4 };
TreeNode n6 = { 15, &n2,  &n5 };
TreeNode* root = &n6;

TreeNode m1 = { 15,  NULL, NULL };
TreeNode m2 = { 4,  &n1,  NULL };
TreeNode m3 = { 16, NULL, NULL };
TreeNode m7 = { 28, NULL, NULL }; // 추가 
TreeNode m4 = { 25, NULL, &m7 }; // 변경 
TreeNode m5 = { 15, &m3,  &m4 };
TreeNode m6 = { 15, &m2,  &m5 };
TreeNode* root2 = &m6;

int get_leaf_count(TreeNode* root)
{
    if (root == NULL)
        return 0;
    if (root->left == NULL && root->right == NULL)
        return 1;
    return get_leaf_count(root->left) + get_leaf_count(root->right);
}

int get_nonleaf_count(TreeNode* root)
{
    if (root == NULL)
        return 0;
    else if ((root->right == NULL) && (root->left == NULL))
        return 0;
    else
        return 1 + get_nonleaf_count(root->left) + get_nonleaf_count(root->right);
}

int get_oneleaf_count(TreeNode* root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 0;
    else if (root->left == NULL)
        return 1 + get_oneleaf_count(root->right);
    else if (root->right == NULL)
        return 1 + get_oneleaf_count(root->left);
    else
        return get_oneleaf_count(root->left) + get_oneleaf_count(root->right);
}

int get_twoleaf_count(TreeNode* root)
{
    if (root == NULL)
        return 0;
    else if (root->left == NULL && root->right == NULL)
        return 0;
    else if (root->left != NULL)
        return get_twoleaf_count(root->right);
    else if (root->right == NULL)
        return get_twoleaf_count(root->left);
    else
        return  1 + get_twoleaf_count(root->left) + get_twoleaf_count(root->right);

}

int get_max(TreeNode* root)
{
    if (root)
        return max(max(root->data, get_max(root->left)), get_max(root->right));
    else
        return INT_MIN;
}

int get_min(TreeNode* root)
{
    if (root)
        return min(min(root->data, get_min(root->left)), get_min(root->right));
    else
        return INT_MAX;
}

int search(TreeNode* root, int key, TreeNode* result[])
{
    if (root == NULL)
        return 0;

    int count = 0;
    if (root->data == key)
        result[count++] = root;

    count += search(root->left, key, result + count);
    count += search(root->right, key, result + count);

    return count;
}

void node_increase(TreeNode* root)
{
    if (root != NULL) {
        root->data += 1;
        node_increase(root->left);
        node_increase(root->right);
    }
}
int equal(TreeNode* root, TreeNode* root2)
{
    if (root == NULL && root2 == NULL)
        return 1;
    else if (root == NULL || root2 == NULL)
        return 0;
    else {
        if (root->data != root2->data)
            return 0;
        else
            return equal(root->left, root2->left) && equal(root->right, root2->right);
    }
}

TreeNode* copy(TreeNode* root)
{
    TreeNode* tree;
    if (root == NULL)
        return NULL;
    else {
        tree = (TreeNode*)malloc(sizeof(TreeNode));

        tree->data = root->data;
        tree->left = copy(root->left);
        tree->right = copy(root->right);

        return tree;
    }
}

//전위 순회
void preorder(TreeNode* root)
{
    if (root != NULL) {
        printf("%d ", root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

//중위 순회
void inorder(TreeNode* root)
{
    if (root != NULL) {
        inorder(root->left);
        printf("%d ", root->data);
        inorder(root->right);
    }
}

//후위 순회
void postorder(TreeNode* root)
{
    if (root != NULL) {
        postorder(root->left);
        postorder(root->right);
        printf("%d ", root->data);
    }
}

int main(void)
{
    TreeNode* result[MAX_TREE_SIZE];
    TreeNode* clone;
    int i, num;

    printf("가)\n");
    printf("트리 root중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root));
    printf("트리 root2중 비단말노드의 개수는 %d.\n", get_nonleaf_count(root2));

    printf("트리 root중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root));
    printf("트리 root2중 자식이 하나만 있는 노드의 개수는 %d.\n", get_oneleaf_count(root2));

    printf("트리 root중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root));
    printf("트리 root2중 자식이 둘이 있는 노드의 개수는 %d.\n", get_twoleaf_count(root2));

    printf("트리 root에서 가장 큰 수는 %d.\n", get_max(root));
    printf("트리 root2에서 가장 큰 수는 %d.\n", get_max(root2));
    printf("트리 root에서 가장 작은 수는 %d.\n", get_min(root));
    printf("트리 root2에서 가장 작은 수는 %d.\n", get_min(root2));

    printf("\n나)\n");
    num = search(root, 15, result);
    for (i = 0; i < num; i++)
        printf("(0x%p, %d), ", result[i], result[i]->data);
    printf("\n");

    printf("\n다)\n");
    preorder(root);
    printf("\n");
    inorder(root);
    printf("\n");
    postorder(root);
    node_increase(root);
    printf("\n");
    preorder(root);
    printf("\n");
    printf("%s\n", equal(root, root) ? "같다" : "다르다");
    printf("%s\n", equal(root2, root2) ? "같다" : "다르다");
    printf("%s\n", equal(root, root2) ? "같다" : "다르다");

    printf("\n라)\n");
    clone = copy(root);
    preorder(root);
    printf("\n");
    preorder(clone);
    printf("\n");
}