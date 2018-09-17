#include "iostream"

#ifndef null
#define null NULL
#endif

using namespace std;

// AVL
typedef struct x
{
  int value;
  struct x *left;
  struct x *right;
  int fb;
} Node;

int height(Node *root)
{
  if (root != null)
  {
    int hright, hleft;
    hright = height(root->right) + 1;
    hleft = height(root->left) + 1;
    if (hright > hleft)
    {
      return hright;
    }
    else
    {
      return hleft;
    }
  }
  return 0;
}

int calc_factor_b(Node *target)
{
  return (height(target->left) - height(target->right));
}

Node *rot_left(Node *t)
{
  Node *aux;
  aux = t->right;
  t->right = aux->left;
  aux->left = t;
  aux->fb = calc_factor_b(aux);
  t->fb = calc_factor_b(t);
  return aux;
}

Node *rot_right(Node *a)
{
  Node *b;
  b = a->left;
  a->left = b->right;
  b->right = a;
  a->fb = calc_factor_b(a);
  b->fb = calc_factor_b(b);
  return b;
}

Node *rot_left_right(Node *root)
{
  root->left = rot_left(root->left);
  root = rot_right(root);
  return root;
}

Node *rot_right_left(Node *root)
{
  root->right = rot_right(root->right);
  root = rot_left(root);
  return root;
}

Node *new_element(int value)
{
  Node *newbie = new Node;
  newbie->value = value;
  newbie->left = newbie->right = NULL;
  newbie->fb = 0;
  return newbie;
}

Node *insert(Node *root, int value)
{
  if (root == null)
  {
    root = new_element(value);
    return root;
  }
  else if (value < root->value)
  {
    root->left = insert(root->left, value);
    root->fb = calc_factor_b(root);
  }
  else if (value > root->value)
  {
    root->right = insert(root->right, value);
    root->fb = calc_factor_b(root);
  }
  if (root->fb > 1)
  {
    if (root->left->fb < 0)
    {
      root = rot_left_right(root);
    }
    else
    {
      root = rot_right(root);
    }
  }
  if (root->fb < -1)
  {
    if (root->right->fb > 0)
    {
      root = rot_right_left(root);
    }
    else
    {
      root = rot_left(root);
    }
  }
  return root;
}

int srch_avl(Node *root, int target)
{
  Node *node;
  node = root;
  while (node != NULL and node->value != target)
  {
    if (target < node->value)
    {
      node = node->left;
    }
    else if (target > node->value)
    {
      node = node->right;
    }
  }
  if (node != NULL)
  {
    return node->value;
  }
  return -1;
}
// ---

// VERMELHO E PRETO
// ---

int main(int argc, char const *argv[])
{
  
  return 0;
}
