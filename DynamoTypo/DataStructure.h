#pragma once
#include<iostream>
#include<string>
using namespace std;
template<typename T>
class Queue {
public:

    Queue()
    {
        size = 0;
        capacity = 5;
        arr = new T[capacity]{ };
        front = rear = -1;
    }

    bool enqueue(T value) {
        if (rear == capacity - 1 && front == 0 || rear == front - 1)throw out_of_range("queue is full");
        else if (rear == -1)
            front = 0;

        //increment then assign
        rear = (rear + 1) % capacity;
        arr[rear] = value;//////////////////////////////////////override = operator
        size++;
        return 1;
    }

    T dequeue() {

        if (rear == front) throw underflow_error("queue is empty");
        // assign then increment
        T value;
        value = arr[front];
        front = (front + 1) % capacity;
        size--;
        return value;
    }

    size_t Size() {
        return size;
    }

    bool isEmpty() {
        return rear == front;
    }

    bool isFull() const
    {
        return size == capacity;
    }

    void display() {
        if (!isEmpty()) {
            for (size_t i = front; (i + 1) % capacity != (rear + 1) % capacity; i = (i + 1) % capacity) {
                cout << arr[i] << " - ";
            }
            cout << arr[rear];
        }
        else {
            cout << "Empty Queue";
        }
    }

    string displayOutput()const {
        string s;
        for (size_t i = front; (i + 1) % capacity != (rear + 1) % capacity; i = (i + 1) % capacity) {
            s += arr[i];
        }
        return s;
    }

    void resize() {
        size_t new_capacity;
        if (size < capacity / 3)//shrink
        {
            // capacity /= 2; note sisze can't be changed at runtime
            new_capacity = capacity / 2;

        }
        else if (size == capacity)//increase
        {
            new_capacity = capacity * 2;
        }
        else return;
        T* new_arr = new T[new_capacity];
        for (size_t i = 0; i < size; i++)new_arr[i] = arr[(front + i) % capacity];
        delete[]arr;
        arr = new_arr;
        capacity = new_capacity;
        front = 0;
        rear = size;
    }

    T Front()
    {
        assert(!isEmpty());
        return arr[front];
    }

    T Rear()
    {
        assert(!isEmpty());
        return arr[rear];
    }

    size_t Search(T element) {
        if (isEmpty()) {
            cout << "Queue is empty ! " << endl;
            return -1;
        }
        else
        {
            for (size_t i = front; (i + 1) % capacity != (rear + 1) % capacity; i = (i + 1) % capacity)

                if (arr[i] == element)
                    return i - front;
            if (arr[rear] == element)
                return rear - front;

        }

        return -1;
    }

    ~Queue() {
        delete[] arr;
    }

private:
    T* arr;
    size_t size;
    size_t front;
    size_t rear;
    size_t capacity;
};
enum TreeTraverseOrder { pre_order, in_order, post_order, level_order };

template<typename T>
struct Node {
    T key;
    Node* left;
    Node* right;
    int height;
    Node(T key) :key(key), left(nullptr), right(nullptr), height(1) {}

    Node() {
        height = 1;
    }
};


template<typename T>
class AvlTree {
    Node<T>* root;
    size_t size;

    Node<T>* find(Node<T>* node, string key) {
        if (!node || node->key == key)
            return node;
        if ( node->key>key)
            return find(node->left, key);
        else if(node->key<key)
            return find(node->right, key);
        return nullptr;
    }

    void updateHeight(Node<T>* n) {

        if (n)  n->height = 1 + max(getHeight(n->left), getHeight(n->right));
    }

    int getHeight(Node<T>* n) {
        return (n) ? n->height : 0;
    }

    int getBalanceFactor(Node<T>* n) {
        return (n) ? getHeight(n->left) - getHeight(n->right) : 0;
    }

    Node<T>* insert(T val, Node<T>*& n) {
        if (!n) {
            return new Node<T>(val);
        }
        else if (val < n->key) {
            n->left = insert(val, n->left);
        }
        else if (val > n->key) {
            n->right = insert(val, n->right);
        }
        else return n;
        updateHeight(n);
        return rebalance(n);
    }

    void preOrderTraversal(Node<T>*n) {
        if (n) {
            cout << n->key << " ";
            preOrderTraversal(n->left);
            preOrderTraversal(n->right);
        }
    }

    void inOrderTraversal(Node<T>* n) {
        if (n) {
            inOrderTraversal(n->left);
            cout <<n->key << " ";
            inOrderTraversal(n->right);
        }
    }

    void postOrderTraversal(Node<T>* n) {
        if (n) {
            postOrderTraversal(n->left);
            postOrderTraversal(n->right);
            cout << n->key << " ";
        }
    }

    void printGivenLevel(Node<T>* n, int level) {
        if (n == nullptr)
            return;
        if (level == 1)
            cout << n->key << " ";
        else if (level > 1) {
            printGivenLevel(n->left, level - 1);
            printGivenLevel(n->right, level - 1);
        }
    }

    void levelOrderTraversal(Node<T>* n) {
        int height = getHeight(n);
        for (int i = 1; i <= height; i++) {
            printGivenLevel(n, i);
        }
    }

    void print(Node<T>*& n)//inorderTraversal
    {
        if (n) {
            print(n->left);
            cout << n->key << " ";
            print(n->right);
        }
    }

     Node<T>* getParent(Node<T>* node, T key) {
         if (!node || node->key == key) {
             return nullptr;//tree is a root only or no nodes
         }

         if ((node->left != nullptr && node->left->key == key) || (node->right != nullptr && node->right->key == key)) {
             return node;//this is the actual parent
         }
         Node<T>* l = getParent(node->left, key);
         if (l) {
             return l;
         }
         l = getParent(node->right, key);
         return l;
     }

     //successor
    Node<T>* Next(Node<T>* node) {
        if (node->right != nullptr)return leftDescendant(node->right);
        return rightAnsector(node);
    }

    Node<T>* leftDescendant(Node<T>* node) {
        if (!node->left)return node;
        return leftDescendant(node->left);
    }

    Node<T>* rightAnsector(Node<T>* node) {//backtracking
        Node<T>* curr = node;
        Node<T>* successor = nullptr;
        while (curr) {
            if (node->val > curr->val)curr = curr->right;
            else {
                successor = curr;
                curr = curr->left;
            }
        }
        return successor;
    }
    //update height and rebalance

    Node<T>* Delete(Node<T>* n, T data) {
        //if (!n->left||!n->right)return n;
        if (!n)return n;
        else if (data > n->key)n->right = Delete(n->right, data);
        else if (data < n->key)n->left = Delete(n->left, data);
        // we reached the specified node
        else {
            Node<T>* tmp = n;
            //case1 :no child->delete node simply
            if (!n->left && !n->right) {
                delete n;
                n = nullptr;
            }
            //case2:one child
            else if (!n->left) {
                Node<T>* tmp = n;
                n = n->right;
                delete tmp;
                tmp = nullptr;
                // return n;
            }
            else if (!n->right) {
                Node<T>* tmp = n;
                n = n->left;
                delete tmp;
                tmp = nullptr;
                // return n;
            }
            else {
                //case3:two children
                Node<T>* tmp = leftDescendant(n->right);//min value in the right subtrees//left descendat
                n->key = tmp->key;//copy
                n->right = Delete(n->right, tmp->key);

            }
            //   return n;
        }
        updateHeight(n);
        return rebalance(n);


    }

    Node<T>* rotateRight(Node<T>* n) {
        if (!n || !n->left) {
            return n;
        }
        Node<T>* tmp = n->left;
        n->left = tmp->right;
        tmp->right = n;

        updateHeight(n);
        updateHeight(tmp);

        return tmp;
    }

    Node<T>* rotateLeft(Node<T>* n) {
        if (!n || !n->right) {
            return n;
        }
        Node<T>* tmp = n->right;
        n->right = tmp->left;
        tmp->left = n;
        updateHeight(n);
        updateHeight(tmp);
        return tmp;

    }

    Node<T>* leftleftCase(Node<T>* n) {
        return rotateRight(n);
    }

    Node<T>* leftRightCase(Node<T>* n) {
        n->left = rotateLeft(n->left);
        return leftleftCase(n);
    }

    Node<T>* rightrightCase(Node<T>* n) {
        return rotateLeft(n);
    }

    Node<T>* rightLeftCase(Node<T>* n) {
        n->right = rotateRight(n->right);
        return rightrightCase(n);
    }

    Node<T>* rebalance(Node<T>* n) {
        int balance = getBalanceFactor(n);
        if (balance < -1) {//right skewed
            if (getBalanceFactor(n->left) <= 0)return leftleftCase(n);
            else return leftRightCase(n);
        }
        else if (balance > 1) {
            if (getBalanceFactor(n->right) >= 0)return rightrightCase(n);
            else return rightLeftCase(n);
        }
        return n;
    }
public:

    AvlTree() {
        root = nullptr;
    }

    Node<T>* find(string val) {
        return find(root, val);
    }

    void insert(T val) {
        root = insert(val, root);
    }

    void print() {///ask him if you want to print preorder,inorder,postorder
        print(root);
        cout << endl;
    }

    void Delete(T val) {
        root = Delete(root, val);
    }

     Node<T>* getParent(T key) {
         return getParent(root, key);
     }


     void traverse() {
         int choice;
         cout << "what kind of traversal do you want:(pre->1/in->2/post->3/level->4):(Enter your choice as a number ";
         cin >> choice;

         switch (choice) {
         case 1: preOrderTraversal(root); break;
         case 2:inOrderTraversal(root); break;
         case 3:postOrderTraversal(root); break;
         case 4:levelOrderTraversal(root); break;
         default:
             cout << "wrong choice" << endl;
         }
     }

};

template<typename T>
class Container {
public:

    T  find(string val) {
        return (tree.find(val))->key;
    }
    void insert(T val) {
        tree.insert(val);
    }

    void print() {
        tree.print();
    }
    Node<T>* getParent() {
        return tree.getParent();
    }
   void Delete(T val) {
        tree.Delete(val);
    }

    void traverse() {
        tree.traverse();
    }

private:
    AvlTree<T> tree;
};