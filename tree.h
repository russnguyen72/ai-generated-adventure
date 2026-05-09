//
// Created by Manju Muralidharan on 11/22/25.
//

#ifndef FA25EC3_TREE_H
#define FA25EC3_TREE_H

#include <iostream>
#include <queue>
#include <string>
#include <vector>
using namespace std;

/*
   TEMPLATE TREE CLASS
   Multiple parents may point to the same child.
   Students must manage storage, pointers, and dynamic allocation.

   Requirements:
   1. Templated Tree class.
   2. Nodes stored dynamically.
   3. Each node has:
      - id
      - data
      - vector of children pointers
   4. Students must prevent memory leaks.
   5. Students must create createRoot, addNode, findNode, print functions, etc.

   DO NOT IMPLEMENT ANYTHING HERE.
   Only placeholders and TODO comments.
*/


template <typename U>
class Node {
public:
    string id;
    U data;
    vector<Node<U>*> children;

    // TODO: Write constructor
    Node(const string &nodeID, const U &value) : id(nodeID), data(value) {}
};

template <typename T>
class Tree {
private:
    Node<T>* root;

public:
    Tree() : root(nullptr) {}
    // TODO: Initialize root pointer to nullptr

    void createRoot(const string &id, const T &value) {
        if (root) return;
        root = new Node<T>(id, value);
    }
    // TODO: Allocate memory, assign id, assign data, set as root

    bool addNode(const string &parentID, const string &childID, const T &value) {
        if (!root) return false;
        if (root->id == parentID) {
            root->children.push_back(new Node<T>(childID, value));
            return true;
        }
        else {
            for (Node<T>* child : root->children) {
                if (child->addNode(parentID, childID, value)) return true;
            }
        }

        return false;
    }
    // TODO: Find parent, create child, link parent to child
    // TODO: Support repeated children under multiple parents

    Node<T>* findNode(const string &id) {
        if (!root) return nullptr;
        if (root->id == id) return root;
        else {
            for (Node<T>* child : root->children) {
                Node<T>* temp = child->findNode(id);
                if (temp) return temp;
            }
        }

        return nullptr;
    }
    // TODO: Use DFS or BFS to search tree

    void printAll() {
        if (!root) return;
        queue<Node<T>*> q;
        q.push(root);

        while (!q.empty()) {
            Node<T>* temp = q.front();
            q.pop();
            cout << temp->id << ": " << temp->data << endl;
            for (Node<T>* child : temp->children) {
                q.push(child);
            }
        }
    }
    // TODO: Print entire structure in readable form

    ~Tree() {
        delete root;
    }
    // TODO: Free all allocated memory
};

#endif //FA25EC3_TREE_H
