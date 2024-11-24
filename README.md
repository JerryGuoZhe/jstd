# jstd
A repository for algorithms and data structure templates.

**Notice that** there might be some bugs. Please report if you find any of them.

## Docs

### jstd/basic
Here are some basic data structures.

#### vector.h

Initalize:
- `vector<type> name;`
- `vector<type> name(init size);`

Functions:
- `v.resize(int n)`: Resize the vector to the size of n. If n is less than the size of the vector, the elements after n will be removed.
- `v.add(type n)`: Add an element n to the end of the vector.
- `v.pop()`: Remove the last element, and return it.
- `v.size()`: Return the size.
- `v.max_size()`: The capacity. (If you're confused, look at the variable 'capacity' in class vector.)
- `v[x]`: Return the x-th element of the vector.
- `v.empty()`: Return 1 if the vector is empty; 0 otherwise.

#### stack.h

Initalize: `stack<type> name;`

Functions:
- `s.push(type n)`: Add an element n to the top of the stack.
- `s.pop()`: Remove the top of the stack, and return it.
- `s.size()`: Return the size of the stack.
- `s.empty()`: Return 1 if the stack is empty; 0 otherwise.

#### deque.h

Initalize: `deque<type> name;`

Functions:
- `q.push_front(type n)`: Add an element n to the front of the queue.
- `q.push_back(type n)`: Add an element n to the back of the queue.
- `q.pop_front()`: Remove the front of the queue, and return it.
- `q.pop_back()`: Remove the back of the queue, and return it.
- `q.front()`: Return the queue's front.
- `q.back()`: Return the queue's back.
- `q.size()`: Return the queue's size.
- `q.max_size()`: Return the queue's max size.
- `q.empty()`: Return 1 if the queue is empty; 0 otherwise.

#### queue.h

Initalize: `queue<type> name;`

Functions:
- `q.push(type n)`: Add an element n to the back of the queue.
- `q.pop()`: Remove the front of the queue, and riturn it.
- `q.front()`: Return the front of the queue.
- `q.back()`: Return the back of the queue.
- `q.size()`: Return the size of the queue.
- `q.empty()`: Return 1 if the queue is empty; 0 otherwise.

#### heap.h

Initalize: `heap<type, cmp> name;`, where cmp is a function that judges an element has the higher priority or not.

e.g.:
```cpp
bool cmp(int a, int b) {
    return a<b;
}
heap<int, cmp>h;
```
This creates a heap, where smaller elements have a higher priority.

Functions:
- `h.push(type n)`: Add an element n to the heap.
- `h.pop()`: Remove the top of the heap, and return it.
- `h.top()`: Return the top of the heap.
- `h.size()`: Return the size of the heap.
- `h.empty()`: Return 1 if the heap is empty; 0 otherwise.

