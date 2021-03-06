#include "iostream"
#include <ctype.h>

#define RED 0
#define BLACK 1
#define NO_INFO -666
#define OPTIONS "\n\nO que deseja fazer?\nI- inserir valor na AVL\nB- buscar valor na AVL\nD- deletar valor na AVL\nP- imprimir AVL\nX- sair"

using namespace std;

// AVL
typedef struct x
{
  int value;
  struct x *left;
  struct x *right;
  int height;
  int fb;
} Node;

int height(Node *root)
{
  if (root != NULL)
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
  if (root == NULL)
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

void pre_order(Node *root)
{
  if (root != NULL)
  {
    pre_order(root->left);
    cout << root->value << ' ';
    pre_order(root->right);
  }
}
// ---

// VERMELHO E PRETO
// typedef struct t
// {
//   int color = BLACK;
//   int value;
//   struct t* parent = NULL;
//   struct t* left = NULL;
//   struct t* right = NULL;
// } Brnode;

// Brnode * create_brnode(int value, int color = RED)
// {
//   Brnode* noob_node = (Brnode*) malloc(sizeof(Brnode));
//   noob_node->value = value;
//   noob_node->color = color;
//   return noob_node;
// }

// void set_parent(Brnode *daddy, Brnode *child)
// {
//   child->parent = daddy;
// }

// Brnode * br_insert(Brnode * root, int value)
// {
//   if (root == NULL)
//   {
//     root = create_brnode(value);
//     root->left = NULL;
//     root->right = NULL;
//     return root;
//   }
//   else if (value > root->value)
//   {
//     root->right = br_insert(root->right, value);
//     set_parent(root, root->right);
//     // check color change
//   }
//   else if (value <= root->value)
//   {
//     root->left = br_insert(root->left, value);
//     set_parent(root, root->left);
//     // check color change
//   }
  
// }
// ---

int main(int argc, char const *argv[])
{
  Node* avl = NULL;
  char opt;
  int value = 0;

  do
  {
    cout << OPTIONS << endl;
    cin >> opt;
    opt = tolower(opt);
    
    switch (opt)
    {
      case 'i':
        cout << "digite o valor: ";
        cin >> value;
        avl = insert(avl, value);
        break;

      case 'b':
        cout << "digite o valor: ";
        cin >> value;
        if(srch_avl(avl, value) != -1)
        {
          cout << "Encontrado o número " << value << '!' << endl;
          cout << endl;
          pre_order(avl);
        }
        else
        {
          cout << "Valor nao encontrado" << endl;
        }
        break;
      case 'd':
        // cout << "digite o valor: ";
        // cin >> value;
        // avl = ;
        break;
      case 'p':
          pre_order(avl);
        break;

      default:
        break;
    }
  } while (opt != 'x');
   
  return 0;
}
