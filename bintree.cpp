#include <iostream>
using namespace std;

class TreeNode {
  int val;
  TreeNode *prev = NULL, *left = NULL, *right = NULL;
 public:
  TreeNode (int node_val);
  TreeNode (int node_val, TreeNode *a);
  void add (int b);
  void del_subtree ();
  TreeNode* search (int b);
  int getdval () {return val;};
};

TreeNode::TreeNode (int node_val) {
  val = node_val;
  cout << "node created with val=" << val << "\n";
}

TreeNode::TreeNode (int node_val, TreeNode *a) {
  val = node_val;
  prev = a;
  cout << "node created with val=" << val << "\n";
}

void TreeNode::add (int b) {
  if (b < val) {
    if (left == NULL) {
      left = new TreeNode(b, this);      
    } else left -> add(b);
  } else {
    if (right == NULL) {
      right = new TreeNode(b, this);
    } else right -> add(b);
  }
};

void TreeNode::del_subtree () {
  if (left != NULL) left -> del_subtree();
  if (right != NULL) right -> del_subtree();
  cout << "node with val=" << val << " deleted\n";
  delete this;
}

TreeNode* TreeNode::search (int b) {
  if (val == b) return this;
  if (b < val) left -> search(b);
  else right -> search(b);
}

int main () {
  TreeNode *t1 = new TreeNode(5);
  t1 -> add(6);
  t1 -> add(8);
  t1 -> add(3);
  t1 -> add(1);
  t1 -> add(6);
  t1 -> add(6);
  t1 -> add(6);
  t1 -> add(6);
  // t1 -> del_subtree();
  cout << t1 -> search(8) << "\n";  

  return 0;
}
