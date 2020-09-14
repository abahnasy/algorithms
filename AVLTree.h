//
// Created by Ahmed Bahnasy on 23.08.20.
//

#ifndef ALGORITHMS_AVLTREE_H
#define ALGORITHMS_AVLTREE_H

#include <iostream>
#include <algorithm>
using namespace std;

struct Node {
    int key, height;
    Node* left;
    Node* right;
};

int find_max (Node* node) {
    if(node == NULL)
        return 0;
    Node* current = node;
    while (current->right != NULL) {
        current = current->right;
    }
    return current->key;
}

int height(Node* node) {
    if(node == NULL) {
        return 0;
    } else {
        return node->height;
    }
}
Node* newNode(int key_) {
    Node* node = new Node();
    node->key = key_;
    node->height = 1;
    node->left = nullptr;
    node->right = nullptr;
    return node;
}

// to rotate right, there must be a node and node->left;
Node* rotate_right (Node* node) {
    Node* temp = node->left;
    Node* t2 = temp->right;
    temp->right = node;
    node->left = t2;

    //update node first since it is a child of temp now
    node->height = 1 + max(height(node->left), height(node->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));

    return temp;
}

// to rotate left, there must be a node and node->right
Node* rotate_left (Node* node) {
    Node* temp = node->right;
    Node* t2 = temp->left;

    temp->left = node;
    node->right = t2;

    //update node height first
    node->height = 1 + max(height(node->left), height(node->right));
    temp->height = 1 + max(height(temp->left), height(temp->right));

    return temp;
}

void pre_order(Node* node) {
    if (node == nullptr)
        return;
    cout << node->key << " ";
    pre_order(node->left);
    pre_order(node->right);
}

// inputs are root of the tree and newly inserted key
Node* insert(Node* root, int key) {
    if(root == NULL)
        return newNode(key);
    if (root->key > key)
        root->left = insert(root->left, key);
    else if (root->key < key)
        root->right = insert(root->right, key);
    else
        // equal keys are not allowed, return the same node
        return root;
    // update height of the node
    root->height = 1 + max(height(root->left), height(root->right));

    int balance_factor = height(root->left) - height(root->right);


    if(balance_factor > 1 && key < root->left->key) { // left left case
        return rotate_right(root);
    }
    if(balance_factor < -1 && key > root->right->key) { //right right
        return rotate_left(root);
    }
    if (balance_factor > 1 && key > root->left->key) { // left right

        root->left = rotate_left(root->left);
        return rotate_right(root);

    }
    if (balance_factor < -1 && key < root->right->key) { // right left
        root->right = rotate_right(root->right);
        return rotate_left(root);

    }
    return root;
}

Node* find_min (Node* root) {
    Node* current = root;
    while (current->left != NULL) {
        current = current->left;
    }
    return current;
}
int get_balance_factor (Node* node) {
    if(node == NULL)
        return 0;
   return height(node->left) - height(node->right);
}


Node* delete_node(Node* root, int key)
{
    if (root == NULL) return root;
    if ( key < root->key ) root->left = delete_node(root->left, key);
    else if( key > root->key ) root->right = delete_node(root->right, key);
    else {
        if( (root->left == NULL) || (root->right == NULL) ) {
            Node *temp = root->left ? root->left : root->right;
            if (temp == NULL) {
                temp = root;
                root = NULL;
            } else *root = *temp; // Copy the contents of
            free(temp);
        }
        else {
            Node* temp = find_min(root->right);
            root->key = temp->key;
            root->right = delete_node(root->right, temp->key);
        }
    }


    if (root == NULL)
        return root;

    root->height = 1 + max(height(root->left),
                           height(root->right));


    int balance = get_balance_factor(root);



    // Left Left Case
    if (balance > 1 &&
            get_balance_factor(root->left) >= 0)
        return rotate_right(root);

    // Left Right Case
    if (balance > 1 &&
            get_balance_factor(root->left) < 0)
    {
        root->left = rotate_left(root->left);
        return rotate_right(root);
    }

    // Right Right Case
    if (balance < -1 &&
            get_balance_factor(root->right) <= 0)
        return rotate_left(root);

    // Right Left Case
    if (balance < -1 &&
            get_balance_factor(root->right) > 0)
    {
        root->right = rotate_right(root->right);
        return rotate_left(root);
    }

    return root;
}

//Node* delete_node(Node* root, int key) {
//    if(root == NULL) return root;
//    else if (root->key > key) delete_node(root->left, key);
//    else if (root->key < key) delete_node(root->right, key);
//    else { // found it
//        if (root->left == NULL || root->right == NULL) {
//            Node* temp = root->left? root->left:root->right;
//            if(temp == NULL) { // no child
//                temp = root;
//                root = NULL;
//            } else {
//                *root = *temp;
//            }
//            free(temp);
//
//        } else { // node with two children
//            Node* temp = find_min(root->right);
//            root->key = temp->key;
//            root->right = delete_node(root->right, temp->key);
//        }
//    }
//    if (root == NULL)
//        return root;
//    root->height = 1 + max (get_height(root->left), get_height(root->right));
//    int balance_factor = get_balance_factor(root);
//    if(balance_factor > 1 && get_balance_factor(root->left) >= 0) { //left left case
//        return rotate_right(root);
//    }
//    if(balance_factor < -1 && get_balance_factor(root->right) <= 0) {
//        return rotate_left(root);
//    }
//    if(balance_factor > 1 && get_balance_factor(root->left) < 0) { // left right
//        root->left = rotate_left(root->left);
//        return rotate_right(root);
//
//    }
//    if(balance_factor < -1 && get_balance_factor(root->right) > 0) { // right left
//        root->right = rotate_right(root->right);
//        return rotate_left(root);
//    }
//    return root;
//}

#endif //ALGORITHMS_AVLTREE_H
