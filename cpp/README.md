# Reference Books
<A Tour of C++ (Second edition)>

<Programming -- Principles and Practice Using C++>

<The Design and Evolution of C++>



CMessage
contents
folders

Folder
msgs

## INSTALL

```cpp
brew install boost
``
```

### cpplang
测试一些cpp的代码

## C++ Concurrency in Action, Practical Multithreading 2012
interprocess communication channels

- signals
- sockets
- files
- pipes

另一种方式是使用单process中的多个threads, light weight processs,
shared memory , shared address space,

Platform specific APIs to do so. 

- separation of concerns
- 背景运行, monitoring the filesystem for changes in a desktop search application, 
- 提高性能
    - 将任务拆分成子任务，并行执行，从而提高性能, parallelism；
    - 利用parallelism to solve bigger problems, data parallelism,

processing intensive applicaitn with a user-interface, DVD player, 
* read data from the disk;
* decode the images and sound ,send them to the graphic and sound hardware in a timely fashion
* take input from the user, pause, return to menu , quit, 
* one thread handle the user interface,
* another one handle the DVD playback,

Gives the illusion of responsiveness, user-interface thread respond immediately to a user request. 

new C++ thread library, 
Boost thread library, 
Abstraction Penality,
platform-specific facilities,

RAIL (Resource Acquisition Is Initialization Idiom)

trailing return, 

### static_cast
enum class , assignment, initialization , comparisons,


### stop
Don't panic! All will become clear in time;
You dont have to know every details of C++ to write good programs;
Focus on programming techniques, not on language features;

## Chap 3 抽象机制
1. concrete classes,
    resource handles, with carefully crafted interfaces, like vector and string;
    user-defined arithmetic type,
    complex& , industrial strength complex(like standard library one) is carefully implemented to do appropriate inlining.
    representation is part of their definition.
    abstract type, 抽象类型, 将用户与实现细节完全绝缘开来；为了实现这一点，我们将接口解耦出来，同时放弃genuine local variable, 本地变量。
    在这里Class头文件，成为了 interface的描述；虚函数的定义;


- container
    holding a collection of elements, abstract interface,
    vtbl, virtual function table, 
    **unique_ptr**, rather than a "naked pointer", smart pointer, 
    unique_ptr<Shape>{ new Circle()}; 当unique_ptr goes out of scope, 就会自动delete the object;
    copy, memberwise copy, 
    move, 不用copy, 提升效率, 
        - move constructor, Vector(Vector &&a); rvalue reference, 
        - move assignment, Vector & operator=(Vector &&a);
        - std::move(), 
    copy constructor,
    copy assignment,
    我们可以获得strong resource safety, 可以消除resource leaks, vectors holding memory, threads holding system threads, fstreams holding file handles.


2. abstract classes,

3. class hierarchy,


objec-oriented programming,

### templates, 参数，未定义参数,
generic programming, 
Template is a class or a function that parameterize with a set of type sor values. Very general from which to generate specific types and functions by specifying arguments.

vector-of-anything type, template is anything, 

```c++
template<typename T>

// Function Template
function object, a functor,

[&](const string&a){
    return a<s;
}
[&x] capture only x, 
[=x], capture a copy of x,
[&], capture all local names use by reference
[=], capture all local names used by value

template<typename T, typename ... Tail>
void f(T head, Tail ... tail)

```
variadic Templates,
接受任意数量的参数 ， 

## chap4 Containers and Algorithms

lib

- runtime language support
- C standard lib
- string and I/O streams
- a framework of containers (vector, map) algorithms (find, sort, merge), STL, 
- numerical computation, 
- regular expression matching,
- concurrent programming, threads, locks,
- template metaprogramming,, STL-style generic programming,
- smart pointers, for resource management, (unique_prt, shared_prt)
- special purpose containers, array, bitset, tuple,
- 

### iostream
cin, cout, cerr,

### 容器
- vector, vector<T>, 更适合顺序查找, 
- list, 双向链表, 
    - iterator, 
    - begin()
    - end()
- map, red black tree, key-value, associative array, dictionary, balanced binary tree,
- unordered_map, 使用了hashed lookup , 替代了comparison using an ordering function ， hashed containers 被称为unordered, 不需要任何的ordering function,
- forward_list, 单向链表
- deque<T> , 双向queue,
- set, 集合
- multiset, 一个值可以出现多次 
- map<K,V>, 
- multimap <K, V>, 一个key可以出现多次
- unordered_multimap<K,V>,
- unordered_set<T>
- unordered_multiset<T>
- stack, ? 

### 算法
- sort(),
- unique_copy(),
- back_inserter()
- iterator, 与algorithm捆绑，与container无关,
    - separation between data storage and algorithm,
    - ostream_iterator,
    - istream_iterator, <fstream>
- find(b,e,x), 
- find_if(b,e,f)
- count(b,e,x)
- count_if(b,e,f)
- replace(b,e,v,v2)
- replace_if(b,e,f,v2)
- copy(b,e,out)
- copy_if(b,e,out,f)
- unique_copy(b,e,out)
- sort(b,e)
- sort(b,e,f)
- equal_range(b,e, v)
- merge(b,e,b2,e2, out)

## chap5 Concurrency and Utilities
资源管理
- memory
- locks
- sockets
- thread handles
- file handles,

使用标准库的部件, basic language support for resource management, using constructor/destructor pairs,

Resource Acquisition Is Initialization, **RAII**,
- unique_ptr, <memory>, 不使用new, 使用智能指针，不使用raw pointer,
    - unique_ptr<X>{new X{i}}
    - 不要直接去使用 new, no naked new policy, 
- shared_ptr, **shared ownership**, copied rather than moved, 当最后一个引用销毁的话，就会被销毁,

```c
mutex m;
unique_lock<mutex> lck {m};

```

### Concurrency,
标准库的并发,
- threads
- mutex
- lock
    - unique_lock<mutex> lck {m1, defer_lock}
    - defer_lock, dont yet try to acquire the mutex, 同时获取多个locks
- packaged_task, launch tasks and connect up the mechanisms for returning a result,
    - get_future()
    - future.get(), get the result,
- future, promise, returning a value from a task spawned on a separate thread,
- async, launching of a task in a manner very similar to calling a function;
- condition_variable, 一个线程等待另一个线程完成, 
    - wait()
    - notify_one();
    - 线程通过queue来传送消息 

```c++
class Message{

}
queue<Message> mqueue;
condition_variable mcond;
mutex mmutex;
```

### 更高层次上的并行操作
建立在操作系统的API之上,

std::thread theObj(<CALLBACK>);
thread::get_id()
this_thread::get_id(),
    thread::detach(),
    ::joinable()

this_thread 就是当前的thread;

### 1. future, promise
在2个任务之间传送value, 而不使用lock, 将value放进promise, 这个值将出现在对应的future里。可以被task launcher读取。返回值，或者exception, 
### 2. packaged_task


### 3. async()

## Small Utility Components
### Time
std::chrono,

### Type Functions,
constexpr float min = numeric_limits<float>::min();

For compile-time computation , metaprogramming, template metaprogramming, 

### iterator_traits
forward_list, forward iterators,

decltype(*beg) // 获取参数的类型

tag dispatch, 

### type predicates,
<type_traits>,  std::is_arithmetic<T>::value;

consexpr, 参数值，返回值必须是字面值, 编译期常量,

### pair and tuple
par<,> // from <utility>

tuple // more than 2 elements, 

make_tuple()

## 正则表达式
<regex>

regex, smatch, regex_search(line, matches, pat)

## Math
<numeric>, sqrt(), pow(), 

<complex> 复数

<random> number

<valarray> // vector like template, 

<limits> // numeric limits, 

# Basic Facilities
C++ built-in types, 如何构造程序out of them. 

## ISO C++ 标准
implementation-defined

## Structure of Declarations,
- prefix specifiers, static, virtual, extern, constexpr, 
    - * , pointer,
    - *const, constant pointer,
    - *volatile, volatile pointer,
    - &, lvalue reference, reference, 
    - && , rvalue reference
    - auto

- vector<double> , const int,
- suffix function specifiers, const, noexcept,
    - [] , array
    - (), function,
    - -> , returns from function,
- optional initializer, function body

Scope
- Local scope, block, seciotn of code by {} pair,
- Class scope, 
- Namespace scope, 
- Global scope, ::x (refer to global x)
- Statement scope, for-, while-, if-, switch-
- Function scope, 

推理数据类型:
- auto, from its initializer,
- decltype(expr), expression,

## Chap 7
object, its address and type,

deferencing, indirection, 指针就是indirection, 

```c++
int *pi;         // pointer to integer
char** ppc;      // pointer to (pointer to char)
int* ap[15];     // 15 (pointer to int)
int (*fp)(char *)// pointer to function, which taking a char* argument ,returns an int
int* f(char*)    // returns a pointer to int
void*,  // pointer to an address, without type
        // void* 不能用于函数和类成员;
nullptr, //可以赋值于任何类型, 如address(0), 
R(""), // Raw string literal,
L"xx", // 
wchar_t [] // 
// Unicode Literals
// 6 character literals,
UTF-8  // 2bytes, 3bytes, 4bytes, u8'\0', u8R""
UTF-16 // u'\0' u"", uR"()"
UTF-32 // U'\0', U"", UR"()"


```
- static_cast<>

### Array
如果要传递指针，和size, 可以使用std:array, 或std::string, std::vector, vector完全可以代替array!!!

### Pointers和const
* constexpr: Evaluated at compile time,
* const: dont modify in this scope, interface specification;
* const pointer, make object const, not the pointer,
* char *const cp; 指针不可修改
* const char *const cpc; // 同时不可修改

### reference,
alias for an object,

rvalue reference, 
```
// rvalue reference, 实现一个 destructive read,
string&& rr2 {f()}
move() // instread of copy()
shrink_to_fit()
clear();
using ii = int &&;

```

enum class Warning:int { green, yellow}

## Statements,

# chap 9
statement,  

declarations , 

# chap 10, expressions, 
- assignment , is an expression,
- function call,
- construction of an object

token_stream
- token, pair, {number, 123.45}
- ts.get(), ts.current(), current token,



