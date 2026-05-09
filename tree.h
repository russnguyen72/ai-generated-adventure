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

    bool addNode(const string &parentID, const string &childID, const U &value) {
        if (parentID == id) {
            children.push_back(new Node<U>(childID, value));
            return true;
        }

        for (Node<U>* child : children) {
            if (child->addNode(parentID, childID, value)) return true;
        }

        return false;
    }

    Node<U>* findNode(const string &id) {
        if (this->id == id) return this;

        for (Node<U>* child : this->children) {
            Node<U>* temp = child->findNode(id);
            if (temp) return temp;
        }

        return nullptr;
    }

    ~Node() {
        for (const Node<U>* child : this->children) {
            delete child;
        }

        this->children.clear();
    }
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
        if (root->addNode(parentID, childID, value)) return true;

        return false;
    }
    // TODO: Find parent, create child, link parent to child
    // TODO: Support repeated children under multiple parents

    Node<T>* findNode(const string &id) {
        if (!root) return nullptr;
        return root->findNode(id);
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

    void playGame() {
        if (!root) return;

        queue<Node<T>*> q;
        q.push(root);
        while (!q.empty()) {
            Node<T>* temp = q.front();
            q.pop();
            cout << temp->id << ": " << temp->data << endl;
            string newID;
            getline(cin, newID);

            for (Node<T>* child : temp->children) {
                Node<T>* next = child->findNode(newID);
                if (next) {
                    q.push(next);
                }
                else {
                    cerr << newID << ": No such node exists" << endl;
                }
            }
        }
        cout << "Thanks for playing!" << endl;
    }

    ~Tree() {
        delete root;
    }
    // TODO: Free all allocated memory
};

#endif //FA25EC3_TREE_H
