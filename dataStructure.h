#pragma once
#include <iostream>
#include <thread>
#include <chrono>
#include<vector>
using namespace std;
struct Node {
    string key;
    Node* next;
    Node()
    {
        next = nullptr;
    }
    Node(string  k) :key(k), next(nullptr)
    {

    }
    string& operator*() {//*top
        return key;
    }

    friend std::ostream& operator<<(std::ostream& os, const Node& n) {//cout<<*top
        os << n.key;
        return os;
    }
};

class Stack {
public:

    Stack() {
        top = nullptr;
        size = 0;
    }

    //Stack(const Stack<T>& s) = default;/*{
      //  copy(s);
   // }*/

    ~Stack() {
       // makeEmpty();
    }

    void push(string  val) {
        Node* newNode = new Node;
        newNode->key = val;
        if (isEmpty()) {
            top = newNode;
            top->next = nullptr;
        }
        else {
            newNode->next = top;
            top = newNode;
        }
        size++;
    }

    string  pop() {
        if (!isEmpty()) {
            Node* curr = top;
            string  element = top->key;
            if (size > 1) top = top->next;
            delete curr;
            size--;
            return element;
        }
        else throw std::underflow_error(" Empty stack can't remove elements");
    }

    void display() {
        Node* curr = top;
        while (curr) {          
            cout << curr->key << " ";
            curr = curr->next;
        }
    }

    string& peek()
    {
        if (isEmpty())throw std::underflow_error("stack is empty");
        return top->key;
    }

    bool isEmpty() {
        return /*top == nullptr*/!size;
    }

    size_t Size() {
        return size;
    }

    void print() {
        Stack newStack;
        while (top) {
            cout << *top << " ";
            // newStack.push(*top); //*********************why not working
            newStack.push(top->key);
            pop();
        }
        //return them again 
        /*while (newStack.top) {
            push((newStack.top->key));
            newStack.pop();
        }*/
    }

    void copy(const Stack& ss) {
        Node* curr = ss.top;
        if (curr == nullptr) {
            makeEmpty();
            return;
        }
        Stack auxilary;
        while (curr) {
            auxilary.push(curr->key);
            curr = curr->next;
        }
        Node* curr2 = auxilary.top;
        while (curr2) {
            push(curr2->key);
            curr2 = curr2->next;
        }
    }

    friend ostream& operator<<(ostream& os, const Stack& s) {
        //deleteStack();
        //Stack<T> tempStack;//(s); 
        //tempStack.copy(s);//it is copied in reversed order
        //while (!tempStack.isEmpty()) {
        //    os << tempStack.peek() << " ";
        //    tempStack.pop();
        //}
        //return os;
        Node* curr = s.top;
        while (curr) {
            os << curr->key << " ";
            curr = curr->next;
        }
        return os;
    }

    void makeEmpty() {
        while (!isEmpty()) {
            pop();
        }
        top = nullptr;
    }

    void operator =(string  element) {
        Node* curr = top;
        while (curr) {
            curr->key = element;
            curr = curr->next;
        }
    }

    void operator =(const Stack& t) {
        copy(t);
    }

private:
    Node* top;
    size_t size;

};

template<typename T>
class IefficientLinkedList
{
    virtual void push(T element) = 0;
    virtual  T pop() = 0;
    virtual void display() = 0;
    virtual T getFirstElement() = 0;
    virtual T getLastElement() = 0;
    virtual size_t Size() = 0;
    virtual bool isEmpty() = 0;
    virtual  bool isFull() = 0;
    virtual void makeEmpty() = 0;
    virtual int search(T) = 0;
    virtual void balance() = 0;
};
template<typename T>

struct node {
    T* arr;
    size_t size;
    size_t capacity;
    size_t front;
    size_t rear;
    node* next;
    node* prev;

    node() {
        capacity = 3;
        size = 0;
        next = nullptr;
        prev = nullptr;
        arr = new T[capacity];
        front = rear = -1;
    }

    void push(T element);
    T pop();
    void display();
    T getFirstElement();
    T getLastElement();
    size_t Size();
    bool isEmpty();
    bool isFull();
    void makeEmpty();
    int search(T Element);
    void balance();

    vector<T> showStoredElements() {
        vector<T> v;
        for (size_t i = 0; i <= rear; i++) {
            v.push_back(arr[i]);
        }
        return v;
    }

    /*void operator=(node<T>curr) {//node<T>*curr=head
        capacity = curr.capacity;
        size = curr.size;
        front = curr.front;
        rear = curr.rear;
        for (size_t i = curr.front; (i + 1) % capacity != (rear + 1) % capacity; i = (i + 1) % capacity) {
            this->arr[i] = curr.arr[i];
        }
        operation = curr.operation;

    }*/

    ~node() {
        delete[]arr;
    }
};

template<typename T>
void node<T>::push(T element) {
    if (size == 0)front=0;
    if (isFull()) {
        throw overflow_error("full queue can't add more elements");
    }
    rear = (rear + 1);//rear=0
    arr[rear] = element;
    size++;
}

template<typename T>
T node<T>::pop() {
    if (size == 0)throw underflow_error("empty queue can't move any elements ");
    T element = arr[front];
    front = (front + 1);
    balance();
    size--;
    return element;
}

template<typename T>
void node<T>::display() {
    //if (isEmpty()) throw runtime_error("can't access an empty queue");
       // for (size_t i = front; (i + 1) % capacity != (rear + 1) % capacity; i = (i + 1) % capacity) {
    if (!isEmpty())
        for (size_t i = 0; i <= rear; i++) {
        if constexpr (is_pointer_v<T>) {
            cout << *(arr[i]) << " ";
        }
        else
        cout << arr[i] << " ";
    }
}

template<typename T>
T node<T>::getFirstElement() {
    return arr[front];
}

template<typename T>
T node<T>::getLastElement() {
    return arr[rear];
}

template<typename T>
size_t node<T>::Size() {
    return size;
}

template<typename T>
bool node<T>::isEmpty() {
    return size == 0;
}

template<typename T>
void  node<T>::makeEmpty() {
    delete[]arr;
}

template<typename T>
bool  node<T>::isFull() {
    return size == capacity;
}

template<typename T>
int  node<T>::search(T element) {
    int pos = -1;
    if (isEmpty())throw runtime_error("can't search in an empty array ");
    // for (size_t i = front; (i + 1) % capacity != (rear + 1) % capacity; i = (i + 1) % capacity)
    for (int i = 0; i <= rear; i++)
        if (arr[i] == element) return i;
    return -1;
}

template<typename T>
void node<T>::balance() {
    for (size_t i = 0; i < size - 1; i++)arr[i] = arr[i + 1];
    front--;
    rear--;
}

template<typename T>
class SuplinkedList {
public:

    SuplinkedList()
    {
        head = tail = nullptr;
        numOfElements = 0;
        size = 0;//number of nodes
    }
    void push(T prod);
    T pop();
    T getFirstElement();
    T getLastElement() {
        tail->getLastElement();
    }
    bool isEmpty() {
        return size==0;
    }
    size_t Size() {
        return size;
    }
    size_t NumOfProducts() {
        return numOfElements;
    }

    void balance();
    void display();
    vector<T> showStoredElements();
    ~SuplinkedList() {
        makeEmpty();
    }
    void makeEmpty() {

        node<T>* curr = head;
        while (curr) {
            curr = curr->next;
            delete head;           
            head = curr;
        }

        head = tail = nullptr;
    }
    bool search(T product) {
        node<T>* curr = head;
        int c;
        while (curr) {
            c = curr->search(product);
            if (c == -1) {
                curr = curr->next;
            }
            else {
                return 1;
            }
        }
        return 0;
    }
    void resize(node<T>*& curr) {
        node<T>* temp = new node<T>;
        curr->next = temp;
        temp->prev = curr;
        curr = temp;
        size++;//increment number of nodes
    }
private:
    node<T>* head;
    node<T>* tail;
    size_t size;//number of nodes
    size_t numOfElements;//number of products
};


template<typename T>
void SuplinkedList<T>::push(T prod) {
    if (head== nullptr/*size == 0*/) {
        head = new node<T>;
        tail = head;
        size=1;//number of nodes
    }
    else if (tail->isFull()) {
        resize(tail);
    }

    tail->push(prod);
    numOfElements++;
}

template<typename T>
T SuplinkedList<T>::pop() {
    if (numOfElements == 0 || head == nullptr)throw underflow_error("can't remove elements from empty sublinked list");
    T element = T{};
    if (!head->isEmpty()) {
        element = head->pop();
        balance();
        numOfElements--;

    }
    return element;
}

template<typename T>
void SuplinkedList<T> ::balance() {
    node<T>* curr = head;
    while (curr->next) {
        curr->push(curr->next->pop());
        curr = curr->next;
    }
    if (tail->isEmpty()) {
        if (head != tail) {
            curr = curr->prev;
            delete tail;
            curr->next = nullptr;
            tail = curr;

        }
        else delete tail;
        size--;
    }
}


template<typename T>
T SuplinkedList<T>::getFirstElement() {
    return head->getFirstElement();
}

template<typename T>
void SuplinkedList<T>::display() {
    node<T>* curr = head;
    while (curr) {
        curr->display();
        cout << endl;
        curr = curr->next;
    }
}

template<typename T>
vector<T> SuplinkedList<T>::showStoredElements() {
    node<T>* curr = head;
    vector<T> v;
    while (curr) {
       // v.insert(v.end(), curr->showStoredElements().begin(), curr->showStoredElements().end());/causes exception iterators in range are from different containers
        for (const auto& element : curr->showStoredElements()) {
            v.push_back(element);
        }
        curr = curr->next;
    }
    return v;
}
template<typename T>
struct nodeLinkedList {
    SuplinkedList<T>q;
    nodeLinkedList<T>* next;
    nodeLinkedList<T>* prev;
    string operation;
    nodeLinkedList() {
        prev = next = nullptr;
    }
    nodeLinkedList(string op) :nodeLinkedList() {
        operation = op;
    }
    void resize(node<T>*& curr) {
        q.resize(curr);
    }
    void push(T prod) {
        q.push(prod);
    }
    T pop() {
        return q.pop();
    }
    T getLastElement() {
        return  q.getProduct();
    }
    bool isEmpty() {
        return q.isEmpty();
    }
    size_t Size() {
        return q.Size();
    }
    size_t NumOfElements() {
        return q.NumOfProducts();
    }
    void balance() {
        q.balance();
    }
    void display() {
        q.display();
    }
   vector<T> showStoredElements() {
      return   q.showStoredElements();
    }
    void makeEmpty() {
        q.makeEmpty();
    }

    bool  search(T prod) {
        return q.search(prod);
    }
    string getOperation() {
        return operation;
    }
    ~nodeLinkedList() {
        q.makeEmpty();
    }
};

template<typename T>
class SpaceEfficientlinkedList {
public:

    SpaceEfficientlinkedList()
    {
        numOfNodes=0;
        numOfElements = 0;
        head = tail = nullptr;
    }

    void push(T prod) {
        head->push(prod);
        numOfElements++;
    }

    void pushNode(string op) {
        nodeLinkedList<T>* n = new nodeLinkedList<T>(op);
        if (head == nullptr)head = tail = n;
        else {
            tail->next = n;
            n->prev = tail;
            tail = n;
        }
        numOfNodes++;
    }

    string popNode() {
        string element;
        if (!head) {
            throw runtime_error("Can't pop from an empty list");
        }
        element = tail->getOperation();
        if (tail != head) {
            tail = tail->prev;
            delete tail->next;
            tail->next = nullptr; 
        }
        else {
            delete tail;
            head = tail = nullptr; 
        }

        numOfNodes--;

        return element;
    }
    T pop()
    {
        numOfElements--;
        return tail->pop();
    }

    T getLastElement()
    {
        return tail->getLastElement();
    }

   T moveToNextNode() {
       if (head == nullptr) {
            throw std::runtime_error("Empty list can't move to next operation");
        }
       nodeLinkedList<T>* curr = head;
       while (curr->isEmpty())curr = curr->next;
       if (curr == tail) {
           T element = curr->pop();
           resultedElements.push_back(element);
          // cout << "Resulted element " << element << endl;
           return T{};
       }
       else curr = curr->next;//else empty
        T element = T{};
        
            while (curr) {
                curr->push(curr->prev->pop());
                if (curr->NumOfElements()==1)  break;    
                else  if (curr == tail) {
                    element = curr->pop();
                    resultedElements.push_back(element);
                   // cout << "Resulted element " << element << endl;
                    numOfElements--;
                }
                curr = curr->next;
            }
            ///////////////
            /*if (head->isEmpty()) {
                if (head->next) {
                    curr = head;
                    head = head->next;
                }
                //popNode();
                delete curr;
                numOfNodes--;
            }*/
        
        return element;       
    }
    


    void moveToPreviousNode(T product) {//if not completed
        nodeLinkedList<T>* curr = head->next;
        while (curr) {
            if (curr->search(product)) {  //it must be the last element
                curr->prev->push(curr->pop());
                return;
            }
            curr = curr->next;
        }
        cout << "Elemnet not found" << endl;
    }

    void defineSize(size_t n) {
        while (n--) {
           string op;
            cout << "Enter operation name: ";
            cin >> op;
            cout << "adding operation " << op << "...." << endl;
            pushNode(op);
            cout << "Operation " << op << " added successfully" << endl;
        }
    }

    size_t Size() {
        return numOfElements;
    }
    bool isEmpty() {
        return !numOfElements;
    }
    size_t numNodes() {
        return numOfNodes;
    }

    bool search(T element) {
        nodeLinkedList<T>* curr = head;
        while (curr) {
            if (curr->search(element))return true;
            curr = curr->next;
        }
        return false;
    }
    void display() {
        nodeLinkedList<T>* curr = head;
        if (!curr)cout << "Empty list can't display elements" << endl;
        int i = 1;
        while (curr) {
            cout << "operation " << i++ << endl;
            curr->display();
            curr = curr->next;
        }
    }


    vector<T> showStoredElements() {
        nodeLinkedList<T>* curr = head;
        vector<T> v;
        while (curr) {
           // v.insert(v.end(), curr->showStoredElements().begin(), curr->showStoredElements().end());
            for (const auto& element : curr->showStoredElements()) {
                v.push_back(element);
            }
            curr = curr->next;
        }
        return v;
    }
    vector<T> preparedElements() {
        return resultedElements;
    }
private:
    nodeLinkedList<T>* head;
    nodeLinkedList<T>* tail;
    size_t numOfNodes;
    size_t numOfElements;
    vector<T>resultedElements;
};
template<typename T>
class Container
{
public:

    void push(T prod) {
        container.push(prod);
    }

    void pushNode(string op) {
        container.pushNode(op);
    }

    string popNode() {
        container.popNode();
    }
    T pop() {
        return  container.pop();
    }

    T getLastElement() {
        return container.getLastElement();
    }

  T /*vector<T>*/ moveToNextNode() {
       return container.moveToNextNode();
    }


    void moveToPreviousNode(T product) {
        container.moveToPreviousNode(product);
    }

    void defineSize(size_t n) {
        container.defineSize(n);
    }

    size_t Size() {
        return container.Size();
    }

    bool isEmpty() {
        return container.isEmpty();
    }

    size_t numNodes() {
        return container.numNodes();
    }

    bool search(T element) {
        return container.search(element);
    }
    void display() {
        container.display();
    }

    vector<T>showStoredElements() {
       return container.showStoredElements();
    }

    vector<T> preparedElements() {
        return container.preparedElements();
    }
private:
    SpaceEfficientlinkedList<T> container;
};


