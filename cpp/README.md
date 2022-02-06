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
<<<<<<< HEAD
- condition_variable, 
    - wait()
    - notify_one();

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
=======

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

P265,
error, <errno.h>
perror()?
error 让程序以一种非常明显、完全不可能无视的方式报错，提醒用户“有某个地方出错了”

## isspace,

**A Desk Calculator**,

space (0x20, ' ')
form feed (0x0c, '\f')
line feed (0x0a, '\n')
carriage return (0x0d, '\r')
horizontal tab (0x09, '\t')
vertical tab (0x0b, '\v')

- isdigit()
- isalpha()
- isalnum()

Separate error detection from error recovery.

extern "C"

解释:

BNF格式, 

* ts.get(), 返回一个token, 
* primary, 包含了 ->
    * number
    * name  // name is an identifier
    * name=expression
    * -primary //   取负值 
    * left parensis, right parensis, (expr)
* term:
    * primary
    * term/primary
    * term*primary
* expression:
    * expression+term
    * expression-term
    * term
* expr_list:
    * expression print
    * expression print expr_list
* program:
    * end
    * expr_list end, 用一个循环来处理expr_list, 

ts.get(), 获取下一个; ts.current(), 获取当前的token,
## evaluate from command-line
istringstream, , get our TokenStream to read from an appropriate istringstream.

stream 从string读取，称为。 库为<sstream>

single step 调试:
- 

vector.push_back(), 添加

## Operator Summary, 操作符归纳,
class-name,

decltype(expr), 

noexcept specifier, 

typeid(type|expr)

dynamic_cast<type>(expr)

static_cast<type>(expr)

reinterpret_cast<type>(expr)

const_cast<type>(expr)

sizeof(type)

alignof(type)

delete

delete[] pointer

<< | >>

{expr-list}

throw expr

higher precedence, 优先级,

Max Munch rule,

preprocessor notation, #, ##,

P274,
代码的层次太清晰了。足见设计的简单，清晰。功力非常！就是根据前面的BNF设计的。

sizeof, size_t, <cstddef>, 

pointer subtraction, signed integral type, ptrdiff_t, <cstddef>

### 运算的优先级别
short-circuit evaluation, 

```
== 的优先级高于 &
临时对象, temporary objects,
c_str(),  <string>, 
```

## Constant Expression, 常量表达式,
constexpr, Evaluate at compile time, 

named constant,
evaluation is done at compile time, there can be no data races on that object in a multi-threaded system.

evaluating something once at compile time gives isgnificatnly better performance than doing so a million times at run time.

Symbolic Constants, Symnbolic names, 

const与constepxr的不同，const可以被一个不是const的值初始化; 

literal type, class with a constexpr constructor,

## Implicit Type conversion
narrowing conversion, 

promotions, implicit conversions that preserve values ,

integral promotion, 生成int out of shorter integer types,
- char, signed char, unsigned char, short int, unsigned short int, converted to int
- char16_t, char32_t, wchar_t, 可以转换成下面的: int, unsigned int, long, unsigned long, unsigned long long,
- bit-field converted to int, unsigend int, 
- bool, converted to int, 0, 1,

floating point promotion, doubles out of floats,

bring operands to the natural size for arithmetic operations,

{}, initializer syntax prevent narrowing,  narrow_cast<>()

throw std::runtime_error{"int to char check failed"};

# chap11, Select Operations, 选择操作
free store 会带来的问题，有3类:
* Leaked objects,  使用了new, 忘记delete,
* Premature deletion, delete, 后面又使用指针
* Double deletion, 删除了2次，触发两次destructur,

如何避免这些问题:
* 不要将对象放在free store上, prefer scoped variables;
* 使用manager object, (handle, 带有destructor,),如string, vector, RAII (Resource Acquisition Is Initialization)从而避免resource leaks, handling using exceptions simple and safe.
* unique_ptr, shared_ptr,manager object作为一个scoped variable, 

## Array of objects:
new, delete, <new> header, 

new[], delete[],

new operator不会保证成功，不会throw error, upon memory exhaustion; 

placement syntax, size_t as 1st argument,

nothrow new,
- int *p = new(nothrow) int[n], operator delete(nothrow,p)
- nothrow, nothrow_t, 
- bad_alloc, nullptr,

## Lists,
T{...}, initialized by , initializer_list, 

- qualified lists,
- unqualified lists, 
    - function argument
    - return value
    - right hand operand of an assignment operator
    - subscript

numeric_limits<int>::lowest();

## lambda Expressions,
* [], possibly empty capture list, 
* (), optional parameter list, 
* mutable specifier, 改变copies of variables captured,
* optional noexcept specifier,
* -> , optional return type 
* body, code to be executed, 
* [&], 引用
* [=], 拷贝
& reference, 否则就只是一个 copy, 

closure object, or simply a closure, 

lifetime, to outlive its caller, make sure taht all local information is copied into the closure object, 
- namespace variable, 不需要 capture, 
- this, members are accessed through this, this和=是不兼容的,

## 显式的类型转换
* const_cast, getting write access to sth. declared const
    * between const and volatile qualifiers
* static_cast, reversing a well-defined implicit conversion, you know the type to be casted; with truncated value, 
    * same class hierarchy, 
* reinterpret_cast, changing the meaning of bit patterns, for C style conversion, Named Casts,
    * reinterpret_cast<IO_device*>(0xff00);
    * between unrelated types, 不做任何保证, 
    * 对函数指针操作, 
* dynamic_cast, dynamically checked class hierarchy navigation, run-time checked, 
    * run-time checking version, in a class hierarchy,
* narrow_cast, 改变2个标量, will throw error,

static_assert() // 

using Print=int *;

# chap12 Functions
Break computational tasks into comprehensible chunks. represented as functions an dclasses
函数, structuring mechanism, 

member function be required:
- virtual, can be overridden in a derived class,
- override, must be overriding a virtual function from a base class,
- final, can not be overrided in a derived class
- static, not associated with a particular object,
- const, may not modify its object

[noreturn] virtual inline auto f(const unsigned long int *const) ->
    void const noexcept;

declaration,

definition,

decltype, 

* constexpr, at compile time, evaluated, pure function, allows
    recursion and conditional expressions, 
* std::initializer_list<T>,
* overload,
    * Exact match, same name, array name to pointer,
    * Match using promotions, bool to int, char to int, float to double,
    * Match using standard conversions, int to double, 
    * Match using user-defined conversions, double to complex<double>
    * Match using ellipsis ...,

caller,
implementer,

宏, macro, ##
    #, 参数的名称，参数,
    __VA_ARGS__, 表示了arguments, passed as a string, 

Predefined Macros:
    __cplusplus, 201103L,
    __DATE__j
    __TIME__,
    __FILE__
    __LINE__,
    __FUNC__, current funciton, 
    __STDC_HOSTED__,
    __STDC__,
    __STDC_MB_MIGHT_NEQ_WC__, 1, wchar_t, 
    __STDCPP_STRICT_POINTER_SAFETY__, 1,
    __STDCPP_THREAADS__, 1,

# chap 13 Exception Handling




