//////////////////////////////////////////////////////////////////////////////////

/* CE1007/CZ1007 Data Structures
Lab Test: Section E - Binary Trees Questions
Purpose: Implementing the required functions for Question 4 */

//////////////////////////////////////////////////////////////////////////////////

#include <stdio.h>
#include <stdlib.h>

//////////////////////////////////////////////////////////////////////////////////

typedef struct _btnode
{
    int item;
    struct _btnode *left;
    struct _btnode *right;
} BTNode;   // You should not change the definition of BTNode

/////////////////////////////////////////////////////////////////////////////////

typedef struct _stackNode
{
    BTNode *btnode;
    struct _stackNode *next;
} StackNode;

typedef struct _stack
{
    StackNode *top;
} Stack;


///////////////////////// Function prototypes ////////////////////////////////////

// You should not change the prototypes of these functions
int sumOfOddNodes(BTNode *root);

BTNode *createBTNode(int item);

BTNode *createTree();
void push( Stack *stack, BTNode *node);
BTNode* pop(Stack *stack);

void printTree(BTNode *node);
void removeAll(BTNode **node);

///////////////////////////// main() /////////////////////////////////////////////

int main()
{
    char e;
    int c,oddValueCount;
    BTNode *root;

    c = 1;
    oddValueCount = 0;
    root = NULL;

    printf("1: Create a binary tree.\n");
    printf("2: Find the sum of all odd numbers in the binary tree.\n");
    printf("0: Quit;\n");

    while(c != 0)
    {
        printf("Please input your choice(1/2/0): ");
        if( scanf("%d",&c) > 0)
        {
            switch(c)
            {
            case 1:
                removeAll(&root);
                root = createTree();
                printf("The resulting binary tree is: ");
                printTree(root);
                printf("\n");
                break;
            case 2:
                oddValueCount = sumOfOddNodes(root);
                printf("The sum of all odd numbers in the binary tree is: %d.\n",oddValueCount);
                removeAll(&root);
                break;
            case 0:
                removeAll(&root);
                break;
            default:
                printf("Choice unknown;\n");
                break;
            }
        }
        else
        {
            scanf("%c",&e);
        }

    }
    return 0;
}

//////////////////////////////////////////////////////////////////////////////////

int sumOfOddNodes(BTNode *node)

{
    //   // 기저조건 설정
    // if(node == NULL) {
    //     return 0;
    // }

    // int result = 0;

    // if(node->item %2 != 0) {
    //     result += node -> item; 
    // }

    // result += sumOfOddNodes(node->left);
    // result += sumOfOddNodes(node->right);

    // return result;
// 노드가 NULL이면 0을 반환한다 (기저 조건)
if (node == NULL) return 0;

// 왼쪽 서브트리의 홀수 합을 재귀적으로 구한다
int left = sumOfOddNodes(node->left);
// 오른쪽 서브트리의 홀수 합을 재귀적으로 구한다
int right = sumOfOddNodes(node->right);
// 결과를 저장할 변수 초기화
int result = 0;
// 현재 노드의 값이 홀수이면 result에 더한다
if (node->item % 2 != 0) {
    result += node->item;
}
// 왼쪽 서브트리의 합을 result에 누적
result += left;
// 오른쪽 서브트리의 합을 result에 누적
result += right;
}

//////////////////////////////////////////////////////////////////////////////////

BTNode *createBTNode(int item)
{
    BTNode *newNode = malloc(sizeof(BTNode));
    newNode->item = item;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}

//////////////////////////////////////////////////////////////////////////////////


BTNode *createTree()
{
    Stack stack;
    BTNode *root, *temp;
    char s;
    int item;

    stack.top = NULL;
    root = NULL;
    printf("Input an integer that you want to add to the binary tree. Any Alpha value will be treated as NULL.\n");
    printf("Enter an integer value for the root: ");
    if(scanf("%d",&item) > 0)
    {
        root = createBTNode(item);
        push(&stack,root);
    }
    else
    {
        scanf("%c",&s);
    }

    while((temp =pop(&stack)) != NULL)
    {

        printf("Enter an integer value for the Left child of %d: ", temp->item);

        if(scanf("%d",&item)> 0)
        {
            temp->left = createBTNode(item);
        }
        else
        {
            scanf("%c",&s);
        }

        printf("Enter an integer value for the Right child of %d: ", temp->item);
        if(scanf("%d",&item)>0)
        {
            temp->right = createBTNode(item);
        }
        else
        {
            scanf("%c",&s);
        }

        if(temp->right != NULL)
            push(&stack,temp->right);
        if(temp->left != NULL)
            push(&stack,temp->left);
    }
    return root;
}

void push( Stack *stack, BTNode *node)
{
    StackNode *temp;

    temp = malloc(sizeof(StackNode));
    if(temp == NULL)
        return;
    temp->btnode = node;
    if(stack->top == NULL)
    {
        stack->top = temp;
        temp->next = NULL;
    }
    else
    {
        temp->next = stack->top;
        stack->top = temp;
    }
}

BTNode* pop(Stack *stack)
{
    StackNode *temp, *top;
    BTNode *ptr;
    ptr = NULL;

    top = stack->top;
    if(top != NULL)
    {
        temp = top->next;
        ptr = top->btnode;

        stack->top = temp;
        free(top);
        top = NULL;
    }
    return ptr;
}

void printTree(BTNode *node)
{
    if(node == NULL) return;

    printTree(node->left);
    printf("%d ",node->item);
    printTree(node->right);
}

void removeAll(BTNode **node)
{
    if(*node != NULL)
    {
        removeAll(&((*node)->left));
        removeAll(&((*node)->right));
        free(*node);
        *node = NULL;
    }
}

