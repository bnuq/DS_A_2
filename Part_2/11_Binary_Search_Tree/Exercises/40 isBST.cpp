#include<bits/stdc++.h>
using namespace std;

class Node
{
  public:
   int key;
   Node *left;
   Node *right;

   Node(int key){
       this->key = key;
       left = right  = NULL;
   }
};

/* 
    접근방식은 동일했나봐
 */
bool isBSTUtil(Node* node, int min, int max)
{
    /* an empty tree is BST */
    if (node==NULL)
        return true;
             
    /* false if this node violates
    the min/max constraint */
    if (node->key < min || node->key > max)
        return false;
     
    /* otherwise check the subtrees recursively,
    tightening the min or max constraint */
    /* 
        Top Down 방식으로, 해당 노드를 루트로 가지는 트리가
        주어진 범위 내의 값을 가지는 지를 조사

        해당 서브트리가 가질 수 있는 값의 범위를 먼저 주는 방식
        먼저 제한을 걸고, 이 서브트리가 그걸 만족하는 지를 확인    
     */
    return
        isBSTUtil(node->left, min, node->key) &&
        isBSTUtil(node->right, node->key, max); 
}

bool isBST(Node * root){
    //complete this method
    return isBSTUtil(root, INT_MIN,INT_MAX);
    
}