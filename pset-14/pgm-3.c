#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TYPED_ALLOC(type) (type *)malloc(sizeof(type))

typedef struct tree_node_s {
  int key;
  struct tree_node_s *leftp, *rightp;
} tree_node_t;

tree_node_t *tree_insert(tree_node_t *rootp, int new_key);
void tree_inorder(tree_node_t *rootp);

int main() {
  srand(time(NULL));
  tree_node_t *root = NULL;

  for (int i = 0; i < 50; i++) {
    root = tree_insert(root, rand() % 1000);
  }
  tree_inorder(root);

  return 0;
}

// This function must remove the node that matches the key from the binary tree
// and returns a pointer to the root of the tree.
tree_node_t *tree_remove(tree_node_t *root, int key, bool *const found) {
  // TREE-DELETE(root, key, found)
  //      if root == NIL
  //          found = false
  //          return root
  //      elseif key < root.key
  //          root.left = TREE-DELETE(root.left, key)
  //          return root
  //      elseif key > root.key
  //          root.right = TREE-DELETE(root.right, key)
  //          return root
  //
  //      found = true

  //* Remove the node
  //      cases 1 & 2
  //      if root.left == NULL
  //          temp = root.right
  //          free root
  //          return temp
  //      elseif root.right == NULL
  //          temp = root.left
  //          free root
  //          return temp
  //      // case 3
  //      else
  //          parent = root
  //          child = root.right
  //          while child.left != NULL
  //            parent = child
  //            child = child.left

  //          root.key = child.key
  //          if (parent == root)
  //            parent.right = child.right
  //          else
  //            parent.left = child.right

  //          free child
  //          return root
};

// Inserts a new key into the binary tree
tree_node_t *tree_insert(tree_node_t *rootp, int new_key) {
  if (rootp == NULL) {
    rootp = TYPED_ALLOC(tree_node_t);
    rootp->key = new_key;
    rootp->leftp = NULL;
    rootp->rightp = NULL;
  } else if (new_key == rootp->key) {
    // Already exists
    return rootp;
  } else if (new_key < rootp->key) {
    rootp->leftp = tree_insert(rootp->leftp, new_key);
  } else {
    rootp->rightp = tree_insert(rootp->rightp, new_key);
  }

  return rootp;
}

void tree_inorder(tree_node_t *rootp) {
  if (rootp == NULL)
    return;
  tree_inorder(rootp->leftp);
  printf("%d ", rootp->key);
  tree_inorder(rootp->rightp);
}

/*
Program #3
Binary Tree Pruning
Using the code from section 13.8, write code to:

Populate a binary tree with 50 integer values, ranging from 0 through 999.
Output the resulting tree, showing the values for each node in increasing order
Add a new function with a signature similar to the following:
tree_node_t* tree_remove(tree_node_t* root, int key, bool* const found);
This function must remove the node that matches the key from the binary tree and
returns a pointer to the root of the tree.

If the key value is not in the tree, the tree should be unchanged and the found
output parameter should be false. If the key deletes the last node in the tree,
the result should be NULL Write a loop that allows the user to input a key to
remove, and exits when -1 is entered On each iteration of the loop, attempt
removing the key from the tree After each removal attempt, output the tree
contents in ascending order There are three major cases to consider when
deleting a node in a binary tree:


No children: release the memory hold by the node and set the parent's child link
that pointed to it as NULL

One child: release the memory hold by the node and set the parent's child link
that pointed to it as the address of its unique child;


Two children: this is indeed the "complicated" case. Find the rightmost node of
the left child (or the leftmost node of the right child), take its value, remove
it (it is "case 1", so it is easy and can be done recursively) and set the
current node's value as the one of that node. This is O(tree_height) = O(n), but
it is not a problem (at least in theory) because this would be nevertheless the
complexity of finding a node.



Since this is a 1000-level course, and possibly your first time using recursion
and dynamic memory allocation, here's some pseudocode to serve as the basis of
your tree_remove function:

TREE-MINIMUM(x)  -- finds and returns the node with the lowest value in a tree
     while x.left != NULL
         x = x.left
     return x

TREE-DELETE(root, key, found)
     if node == NIL
         found = false
         return root
     elseif key < node.key
         root.left = TREE-DELETE(root.left, key)
         return root
     elseif key > node.key
         root.right = TREE-DELETE(root.right, key)
         return root

     found = true
     // cases 1 & 2
     if root.left == NULL
         temp = root.right
         free root
         return temp
     elseif root.right == NULL
         temp = root.left
         free root
         return temp
     // case 3
     else
         parent = root
         child = root.right
         while child.left != NULL
           parent = child
           child = child.left

         root.key = child.key
         if (parent == root)
           parent.right = child.right
         else
           parent.left = child.right

         free child
         return root
Sample output:

Enter key to remove:485
   Not found - Result:    0   8  21  56  61  83  83  96 131 137 150 155 163 183
225 240 250 267 278 329 341 385 400 419 421 444 447 490 494 517 576 581 612 613
627 637 653 712 718 734 759 767 804 842 849 870 896 897 954 961 Enter key to
remove:385 Node removed - Result:    0   8  21  56  61  83  83  96 131 137 150
155 163 183 225 240 250 267 278 329 341 400 419 421 444 447 490 494 517 576 581
612 613 627 637 653 712 718 734 759 767 804 842 849 870 896 897 954 961 Enter
key to remove:400 Node removed - Result:    0   8  21  56  61  83  83  96 131
137 150 155 163 183 225 240 250 267 278 329 341 419 421 444 447 490 494 517 576
581 612 613 627 637 653 712 718 734 759 767 804 842 849 870 896 897 954 961
Enter key to remove:494
Node removed - Result:    0   8  21  56  61  83  83  96 131 137 150 155 163 183
225 240 250 267 278 329 341 419 421 444 447 490 517 576 581 612 613 627 637 653
712 718 734 759 767 804 842 849 870 896 897 954 961 Enter key to remove:-1
*/