//
//  main.c
//  Assignment_4
//
//  Created by Jacob Karcz on 10/24/16.
//  Copyright © 2016 Jacob Karcz. All rights reserved.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}

void initBST(struct BinarySearchTree *tree) {
    tree->size = 0;
    tree->root = 0:
}


void addBST(struct BinarySearchTree *tree, TYPE newValue) {
    tree->root = _nodeAddBST(tree->root, newValue);
    tree->size++;
}


int sizeBST (struct binarySearchTree *tree) {
    return tree->size;
}
/*****************************************************************************************
 *	function: _addNode
 *	type
 
 *****************************************************************************************/
struct Node * _nodeAddBST (struct Node *current, TYPE newValue) {
    struct Node * newNode;
    
    //baseCase
    if (current == NULL) { 						//found a spot
        newNode = malloc(sizeof(struct Node));	//malloc node
        assert(newNode != 0);						//check malloc
        newNode->value = newValue				//set newNode value
        newNode->left = 0;
        newNode->right = 0;						// set leaf's children to null
        return newNode;							//return the new node to caller
    }
    //recursive case; current node is not null, compare the value passed to current value
    if (newValue < current->value)
        current->left = _nodeAddBST (current->left , newValue); //newValue is less than
    else
        current->right = _addNode (current->right, newValue);  //newValue is >= current
    return current; 		  //return current (moded) node to caller to rebuild the tree
}


int containsBST (struct binarySearchTree *tree, TYPE val) {
    assert(tree != NULL);
    assert(val != NULL);
    
    /*write this*/
    struct Node * thisNode;
    thisNode = tree->root;
    
    while (thisNode != NULL) {
        if (val == thisNode->val)		//found it
            return 1;
        else if (val < thisNode->val) 	//d < this node
            thisNode = thisNode->left;
        else if (val > thisNode->val)	//d > this node
            thisNode = thisNode->right;
    }
    return 0; 							//failed to find it
}


void removeBST (struct binarySearchTree *tree, TYPE d) {
    if (containsBST(tree, d) {
        tree->root = _nodeRemoveBST(tree->root, d);
        tree->size--;
    }
        }
        
TYPE _leftMostChild (struct Node * current) {
    while (current->left != NULL) {
        current = current->left;	//move to left subtree until null is encountered
    }
    return current->value;			//return value at current [leftmost] node
            
}
        
struct node * _removeLeftmostChild (struct Node *current) {
    //baseCase
    if (current->left->left == NULL) { 			//curent node's left child is the leftmost
        free(current->left);
        current->left = 0;						//null the pointer to leftMost
        return current;							//return the node to the caller
    }
    //recursive case; continue traversing top leftMost
    else (newValue < current->value)
        current->left = _removeLeftmostChild(current->left ); //move further down
    return current; 		  //return current (moded) node to caller to rebuild the tree
}
        
        
struct Node *  _nodeRemoveBST (struct Node * current, TYPE d) {
    assert (current != NULL);
    struct Node *temp;
    
    //baseCase
    if (current->left->value == d) { 		//found it
        free (current->left);				//freed it
        current->left = 0;					//erase it from memory
        return current;						//return the new node to caller
    }
    else if (current->right->value == d) { 	//found it
        free (current->left);					//freed it
        current->left = 0;						//erase it from memory
        return current;							//return the new node to caller
    }
    
    //recursive case; keep searching for value d
    if (newValue < current->value)
        current->left = _nodeRemoveBST (current->left , d); //d is less than current
    else
        current->right = _nodeRemoveBST (current->right, d);  //d is >= current
    return current; 		  //return current (moded) node to caller to rebuild the tree
    
}
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
        
