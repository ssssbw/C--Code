#include <iostream>
#include <string>
using namespace std;

template <class T>
class Queue
{
private:
    int size;
    int capacity;
    int front, rear;
    T *element;
    bool ensureCapacity(){return ((rear + 1) % capacity) == front ? true : false;}
public:
    Queue(/* args */);
    ~Queue();
    Queue(const Queue&);
    bool empty();
    int getSize() const{return (rear - front + capacity) % capacity;}
    T getFront();
    T pop_front();
    void push_back(T element);

};

template <class T>
Queue<T>::Queue()
{
    this->size = 0;
    this->capacity = 100;
    this->front = 0;
    this->rear = 0;
    element = new T[capacity];
}

template <class T>
Queue<T>::~Queue()
{
}

template <class T>
Queue<T>::Queue(const Queue& queue)
{
    queue.front = this->front;
    queue.size = this->size;
    queue.capacity = this->capacity;
    for(int i = 0; i < capacity; i++)
    {
        queue.element[i] = this->element[i];
    }
}

template <class T>
bool Queue<T>::empty()
{
    return (rear == front)?true:false;
}

template <class T>
T Queue<T>::getFront()
{
    if(!empty()) exit(0);
    return element[front];
}

template <class T>
T Queue<T>::pop_front()
{
    if (empty()) exit(0);
    T ele = element[front];
    front = (front + 1) % capacity;
    return ele;
}

template <class T>
void Queue<T>::push_back(T ele)
{
    if (ensureCapacity()) return;
    element[rear] = ele;
    rear = (rear + 1) % capacity;
}

void testInt()
{
    Queue<int> queue;
    queue.push_back(1);
    queue.push_back(2);
    queue.push_back(3);
    queue.push_back(4);
    queue.push_back(5);
    queue.push_back(6);
    queue.push_back(7);
    queue.push_back(8);
    queue.push_back(9);
    queue.push_back(10);

    cout << "int queue pop_front :" << queue.pop_front() << endl;
    cout << "int queue pop_front :" << queue.pop_front() << endl;
    cout << "int queue pop_front :" << queue.pop_front() << endl;
    cout << "int queue pop_front :" << queue.pop_front() << endl;
    cout << "int queue pop_front :" << queue.pop_front() << endl;
    cout << "int queue pop_front :" << queue.pop_front() << endl;
    cout << "int queue pop_front :" << queue.pop_front() << endl;
}

void testChar()
{
    Queue<char> queue;
    queue.push_back('a');
    queue.push_back('b');
    queue.push_back('c');
    queue.push_back('d');
    queue.push_back('e');
    queue.push_back('f');
    queue.push_back('g');
    queue.push_back('h');
    queue.push_back('i');
    queue.push_back('j');

    cout << "char queue pop_front :" << queue.pop_front() << endl;
    cout << "char queue pop_front :" << queue.pop_front() << endl;
    cout << "char queue pop_front :" << queue.pop_front() << endl;
    cout << "char queue pop_front :" << queue.pop_front() << endl;
    cout << "char queue pop_front :" << queue.pop_front() << endl;
    cout << "char queue pop_front :" << queue.pop_front() << endl;
    cout << "char queue pop_front :" << queue.pop_front() << endl;
}

void testString()
{
    Queue<string> queue;
    queue.push_back("year2001");
    queue.push_back("year2002");
    queue.push_back("year2003");
    queue.push_back("year2004");
    queue.push_back("year2005");
    queue.push_back("year2006");
    queue.push_back("year2007");
    queue.push_back("year2008");
    queue.push_back("year2009");
    queue.push_back("year2010");

    cout << "string queue pop_front :" << queue.pop_front() << endl;
    cout << "string queue pop_front :" << queue.pop_front() << endl;
    cout << "string queue pop_front :" << queue.pop_front() << endl;
    cout << "string queue pop_front :" << queue.pop_front() << endl;
    cout << "string queue pop_front :" << queue.pop_front() << endl;
    cout << "string queue pop_front :" << queue.pop_front() << endl;
    cout << "string queue pop_front :" << queue.pop_front() << endl;
}
int main()
{
    testInt();
    testChar();
    testString();
    return 0;
}