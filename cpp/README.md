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


