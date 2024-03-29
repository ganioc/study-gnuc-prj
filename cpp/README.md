# Reference Books

<A Tour of C++ (Second edition)>

<Programming -- Principles and Practice Using C++>

<The Design and Evolution of C++>

一些c++项目的例子:

- <https://github.com/DeadSix27/waifu2x-converter-cpp>
  - 支持多平台，使用CMake, CMakeList.txt,
  -

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

- read data from the disk;
- decode the images and sound ,send them to the graphic and sound hardware in a timely fashion
- take input from the user, pause, return to menu , quit,
- one thread handle the user interface,
- another one handle the DVD playback,

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

### templates, 参数，未定义参数

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

### Concurrency

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

this_thread 就是当前的thread
=======

### 1. future, promise

在2个任务之间传送value, 而不使用lock, 将value放进promise, 这个值将出现在对应的future里。可以被task launcher读取。返回值，或者exception,

### 2. packaged_task

### 3. async()

## Small Utility Components

### Time

std::chrono,

### Type Functions

constexpr float min = numeric_limits<float>::min();

For compile-time computation , metaprogramming, template metaprogramming,

### iterator_traits

forward_list, forward iterators,

decltype(*beg) // 获取参数的类型

tag dispatch,

### type predicates

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

## Structure of Declarations

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

- constexpr: Evaluated at compile time,

- const: dont modify in this scope, interface specification;
- const pointer, make object const, not the pointer,
- char *const cp; 指针不可修改
- const char *const cpc; // 同时不可修改

### reference

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

## Statements

# chap 9

statement,  

declarations ,

# chap 10, expressions

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

## isspace

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

- ts.get(), 返回一个token,
- primary, 包含了 ->
  - number
  - name  // name is an identifier
  - name=expression
  - -primary //   取负值
  - left parensis, right parensis, (expr)
- term:
  - primary
  - term/primary
  - term*primary
- expression:
  - expression+term
  - expression-term
  - term
- expr_list:
  - expression print
  - expression print expr_list
- program:
  - end
  - expr_list end, 用一个循环来处理expr_list,

ts.get(), 获取下一个; ts.current(), 获取当前的token,

## evaluate from command-line

istringstream, , get our TokenStream to read from an appropriate istringstream.

stream 从string读取，称为。 库为<sstream>

single step 调试
-

vector.push_back(), 添加

## Operator Summary, 操作符归纳

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

## Constant Expression, 常量表达式

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

- Leaked objects,  使用了new, 忘记delete,
- Premature deletion, delete, 后面又使用指针
- Double deletion, 删除了2次，触发两次destructur,

如何避免这些问题:

- 不要将对象放在free store上, prefer scoped variables;
- 使用manager object, (handle, 带有destructor,),如string, vector, RAII (Resource Acquisition Is Initialization)从而避免resource leaks, handling using exceptions simple and safe.
- unique_ptr, shared_ptr,manager object作为一个scoped variable,

## Array of objects

new, delete, <new> header,

new[], delete[],

new operator不会保证成功，不会throw error, upon memory exhaustion;

placement syntax, size_t as 1st argument,

nothrow new,

- int *p = new(nothrow) int[n], operator delete(nothrow,p)
- nothrow, nothrow_t,
- bad_alloc, nullptr,

## Lists

T{...}, initialized by , initializer_list,

- qualified lists,
- unqualified lists,
  - function argument
  - return value
  - right hand operand of an assignment operator
  - subscript

numeric_limits<int>::lowest();

## lambda Expressions

- [], possibly empty capture list,

- (), optional parameter list,
- mutable specifier, 改变copies of variables captured,
- optional noexcept specifier,
- -> , optional return type
- body, code to be executed,
- [&], 引用
- [=], 拷贝
& reference, 否则就只是一个 copy,

closure object, or simply a closure,

lifetime, to outlive its caller, make sure taht all local information is copied into the closure object,

- namespace variable, 不需要 capture,
- this, members are accessed through this, this和=是不兼容的,

## 显式的类型转换

- const_cast, getting write access to sth. declared const
  - between const and volatile qualifiers

- static_cast, reversing a well-defined implicit conversion, you know the type to be casted; with truncated value,
  - same class hierarchy,
- reinterpret_cast, changing the meaning of bit patterns, for C style conversion, Named Casts,
  - reinterpret_cast<IO_device*>(0xff00);
  - between unrelated types, 不做任何保证,
  - 对函数指针操作,
- dynamic_cast, dynamically checked class hierarchy navigation, run-time checked,
  - run-time checking version, in a class hierarchy,
- narrow_cast, 改变2个标量, will throw error,

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

- constexpr, at compile time, evaluated, pure function, allows
    recursion and conditional expressions,
- std::initializer_list<T>,
- overload,
  - Exact match, same name, array name to pointer,
  - Match using promotions, bool to int, char to int, float to double,
  - Match using standard conversions, int to double,
  - Match using user-defined conversions, double to complex<double>
  - Match using ellipsis ...,

caller,
implementer,

宏, macro, ##
    #, 参数的名称，参数,
    **VA_ARGS**, 表示了arguments, passed as a string,

Predefined Macros:
    __cplusplus, 201103L,
    __DATE__j
    **TIME**,
    **FILE**
    **LINE**,
    **FUNC**, current funciton,
    **STDC_HOSTED**,
    **STDC**,
    **STDC_MB_MIGHT_NEQ_WC**, 1, wchar_t,
    **STDCPP_STRICT_POINTER_SAFETY**, 1,
    **STDCPP_THREAADS**, 1,

# chap 13 Exception Handling

Error Handling,
错误的处理不是local的,  error-handling into different parts of a program,
library, 房子库里面, a library designer can not know什么程序会调用,
库作者可以检测错误，但是不知道应该怎么处理,
库的使用者知道如何处理运行时错误，但是不知道如何检测错误,

alternative:    传统的处理方式
    *终止程序, exit(1); abort();
    * 返回一个错误代码 ， error value,
    *返回一个legal value, leave program in error state,如 C的errno,
    * 调用一个错误处理函数, error-hanlder function, 弹出对话框等,
complete: handle all errores deteted by ordinary code,
将错误处理代码和正常代码分开:
more rugular style of error handling,

exception是一个对象，thrown to represent an error,
use only user-defined types

Asynchronous Events, 异步事件,
    不是exceptions, signals, 来处理异步事件, system-dependent,

不能使用exception的场景:
    time-critical component,
    a large old program , naked pointers,

Hierarchical Error Handling:
    *fault-tolerant systems, are multilevel,
    * noexcept 提供了一个简单的escape for errors,

关于效率，

- C语言不用exception throwing,
- new , bad_alloc, atexit(), qsort(),

exception safe,
    *basic guarantee for all operations,
    * strong guarantee, push_back(), insert(), uninitialized_copy(),
    * nothrow guarantee, swap(), pop_back()

避免resource leaks,
    *出了问题时, 回到well-defined states, 保证所有的资源释放,然后throw exception
    * 任何从系统的另一个部分获取的东西都是资源，需要进行释放,
    * Files, locks, network conn, threads, mutex,

RAII, Resource Acquisiiton Is Initialization, $13.3,
    using loal objects,
    实际上发生错误时，假定会有上层的程序来处理,
    std::unique_lock,
    unique_ptr,
    shared_ptr, to avoid leaks,

finally,
    对类添加了一层包裹,

preconditions failure,
    assertion, assert(), <cassert>,
    NDEBUG, at run time,
    static_assert(A, message), at compile time,

destrutor should not throw,
stack unwinding, 向上传,

std::runtime_error,

noexcept,
    std::terminate()
    std::bad_alloc
    定义函数为noexcept的

rethrown, 就是throw, 不用任何的operand,

什么时候终止程序呢？terminate()
    *no suitable handler found, for the thrown exception,
    * a noexcept funciton tries to exit with a throw
    *a destrcutor invoked during stak unwiding
    * statically allocated or thread-local object try to exit with throw
    *a function, atexit()
    * std::set_terminate(), <exception>,

thread, exception没有捕捉，就会退出。
    packaged_task, 来处理user code 's exception,

### A simple vector

数理天地，数学月报, 中学生数学,
explicit, 不能进行隐式的类型转换,
=delete, // no copy operations
T&& // 这个是什么意思呢？右值饮用拷贝,
std::uninitialized_fill()
std::uninitialized_fill_n()
std::uninitialized_copy()
swap(), transfer ownership of any memory allocated for elements,
copy(),
destroy(),

assignment,  old value must be taken care of,

### change vector's size

v.push_back(), 不但添加到尾部，而且改变vector的大小;
reserve(), 增加capacity(, ), 增加容量，然后切换owner,
resize(),

# chap 14 Namespaces

namespace XXX {

}
XXX::Text_lib,  namespace-name::member-name, notation,
先定义，
然后再分开来实现 ； P408,
::f(), 表示global function,
classes也是namespace,
using std::string;

ADL, argument-dependent lookup,
namespace是开放的，可以放在不同的文件里面，

c++， c code， linkage and pointers to functions,

- typedef, C++ linkage,
- extern "C" {}, C linkage,

Header Files,

- Single-Header organization,
- using 只是方便在.cpp文件里面使用,
- 在头文件里面定义extern 变量，这样避免重复包含在.cpp文件中,
- 在大项目中，单头文件方法，in conventional file-based development environment, 就不适用了
  - 公共的头文件里的一点变化会导致整个项目的编译，触发，
  - 有可能会带来错误，引发错误，
- multiple-Header organization, 多头文件的组织方式,
  - 每个逻辑模块,logical module, 有自己的头文件定义,
  - .cpp文件包含自己的.h文件，和其它模块的.h文件, 从其它模块需要什么呢?

初始化，非重入的,
建议使用constant expressions,
using expressions without side effects,
single-threaded startup phase of computation
use some form of mutual exclusion,

program termination,

- returning from main(),
- exit(), local variables of calling function and its caller will not have detructors invoked,
  - without giving caller a chance to deal with the problem,
- abort()
- throwing an uncaught exception,  local objects are properly destroyed, 这个是推荐的,
- noexcept, violating noexcept,
- quick_exit(), does not invoke any destructors, at_quick_exit(), <cstdlib>,

C标准库的atexit()提供了在程序退出时，执行一些代码。做cleanup.
C language workaround,

# Part III , Abstraction Mechanisms

如何定义和使用新的类型, new types, object-oriented programming, generic programing, 用了14章来阐述这个问题

# Chap 16 Classes

abstract, concrete; 抽象，具体;

- A class is a user-defined type,
- consists of a set of members, data, functions,
- member functions, define meaning of initialization, copy, move, cleanup(destruction)
- . , -> , +, !, [],
- struct is a class, members are default public,

data memebers last to emphasize the functions providing the public user interface,

P473,
初始化{}
explicit constructor, 不能进行隐式转换, direct initialization,
default arguments,
in-class definition,

const object
cost T&, 引用，不可改变，
()const, // 表明不会改变类的状态
const(), // 表明返回值不可被改变
physical constness,
logical constness,
const_cast, 强制转换,
mutable member variable;
const 对于成员的指针或引用无效,
self reference, return *this; XXX &
this 是一个 rvalue,
member class, nested class,

concrete types,
concrete classes, 与builtin type类似，不带类继承的类, value types, value-oriented programming,
    To do a single, relatively simple thing, well and efficiently,
    not to display run-time polymorphic behavior,

static_cast<XXX>m,
overloaded operators, 操作符重载,

# chap 17 Construction, Cleanup, Copy and Move

construction,
copy constructor, &,
move constructor,  &&,
destructor of strings,
X()
X(const X&)
X(X&&), move
X& operator= (const X&) // copy assignment , clean up target and copy
X& operator = (X&&), // move , clean up target and move
~X(), // destructor, clean up,

## object的5种情况

- source of an assignment
- object initializer,
- function argument,
- function return value
- an exception

P498,
讨论对象的生命周期,

安装Boost库,
sudo apt install libboost-all-dev
ostream_iterator was not declared in this scope!
    #include <iterator>
O_EXCL was not declared in this scope,

copy,source , dest 都在,
move,  sourcing will not be used again,

clog是什么呢？
cerr,
P484, pagd 484, $25.2.5.1,

constructor, 和class同名,
    失败的话, std::bad_alloc(), thrown by new,
这种资源管理方式被称为RAIL (Resource Acquisition Is Initialization)
需要判断一个类, 的对象是否可以被copy or move
placement new, new(p) X{a}
为了使destructor不能被随便, =delete, or private,
virtual Destructors, for a class with a virtual function,
Buf buf2{}; // {}是一个initializer,
    memberwise initialization, or initializer-list initialization
    constructor initialization, (),
default constructor, ()空的构造函数,
copy constructor,

<initializer_list>
std::initializer_list,

direct initialization,
copy initialization,
Member and Base Initialization,
delegating constructor,
forwarding constructor,
in-class initializers,
static member initialization, definition outside the class;
static const int c1 = 7;
constexpr,

copy constructor: X(const X&)
copy assignment:  X& operator=(const X&)

move constructor:
uninitialized_copy(),
swap(tmp,*this); // swap representation with this's

copy is Equivalence and Independence;
shallow-copy, copy pointers,
deep-copy, copy the complete state of an object,
更好的做法是使用move,
shared_ptr<int>p; // garbage collection,
copy-on-write,
Doesn't need indepencdence until a shared state is written to.
slicing: only copy base class, 如何避免呢?
    - delete the copy operations,
    - make the base class a private or protected base,
move , std::move(), swap(a, b), rvalue reference to x,
pair()
unique_ptr()
insert()
push_back(), // versions take rvalue references,
不要假设moved-from pointer , set to nullptr 自动的;
throw std::runtime_error("unequal Matrix sizes")

default operations:
X();
X(const X&); // copy constructor,
X& operator=(const X&); // copy assignment
X(X&&) // move constructor
X& operator=(X&&) // move assignment,
destructor, ~X();

Explicit Defaults:
getting back a default,  =default,
Default Operations: P520

Resource Invariants,
Partially specified Invariants,
deleted Functions, =delete, 不使用默认的copy, move, defined meanings be deleted.

## 18 Operator Overloading

b.operator+(c), 操作符的重载,
sizeof()
alignof()
typeid, type_info() of an object,
syntactic subterfuge,
draconian, 残忍的,
unary, single operand,
binary,
ternary, ? :

operator=, [], (), -> 必须是non-static functions,
&&, ||, 也可以自己定义,
P531

你能在字里行间内感觉到他的那种游刃有余, 处理各种情况，易如反掌．
举手投足间，以轻驭重，化腐朽为神奇的能力．
C++让你觉得这是一門本质上非常简单的语言，只是你对他的使用要随心所欲，才能
发挥出这门武器的真正威力．

Arguments, Pass-by-value,
    Pass-by-reference, (larger objects),

如果不想constructor()进行隐式的转换，则定义为explicit,

throw Bad_range();
throw Invalid_unique_ptr{};
user define operator;
user defined conversion;

## Chap 19 Special Operators

[]
(),
->, arrow operator, unary post-fix operator, dereferencing operator,
    ->()
    for creating smart pointers,
    unique_ptr, shared_ptr(),
    提供了一个clean, direct, efficient way of representing indirection in a program.
++,
--,
new,
    calling operator new(),

delete,
    operator delete(),

map,
unordered_map, associative array with less naive implementations,
function call,
function call operator, application operator?
function-like object, function object,
for_each(vec.begin(), vec.end(), Add{2,3}), the last argument , applies () to

```cpp
template <typename Iter, typename Fct>
Fct for_each(Iter b, Iter e, Fct f){
    while(b!=e) f(*b++);
    return f;
}

```

operator()() must be a non-static member function,

User-defined Literals:
123,
1.2,
1.2F,
'a',
1ULL
0xD0,
"as",

literal operator,
operator""

```c++
// compile-time evaluation,
constexpr complex<double> operator""i(long double d){
    return {0,d};
}
std::string operator""s(const char*p, size_t n){
    return string{p, n}; 
}
```

用户可使用的literal:
interger literal,
floating point literal,
string literal,
character literal, char , wchar_t, char16_t, char32_t,

template literal operator,
template<char...>
constexpr int operator""_b3();
variadic template techniques,
在编译时，分配nonstandard meanings to digits,

class String,
Return C style string , c_str(),
String grows by doubling its allocation,
capacity() is the amount of space available,
throw std::out_of_range("String::at()")
copy_from()
move_from()
anonymous union,
3 ancillary funcitons,  less duplication of code, better design, improved maintainability.
    *char* epxand(const char*prt, int n),不会访问String representation里的任何东西，所以不会make it a member,
    * void String::copy_from(), 根据大小，增加存储空间，返回
    * String::move_from(String &x), 使用x的存储, x本身回收掉
memcpy();
成员函数:
    - =
    - move_from, copy_from,
Helper Functions:
    - stream I/O, <<,  
        ostream& operator <<(ostream&os, const String&s)
    - is>>ws; // skip whitespace, is.get(ch), isspace(ch), char ch='';
    - range-for loops, 增加.begin(), .end(), x.c_str(),
    - comparison, ==, !=, compare byte by byte,
    - concatenation,
    - _s as a string literal suffix,

member function的３个特性:
    1. 可以访问private part of the class declaration,
    2. function is in the scope of the class,
    3. must be invoked on an object, has a this pointer,

static, 有1., 2.,
friend, 只有1., guaranteed to access it's private member functions,
    定义时，使用了namespace N{ class C2{}; void f2(){} },
    判断member function的作用范围? Does it really need access?
    Member functions can only be invoked for objects of their class;

## chap 20 Derived Classes

类的继承, 派生类, 从Simula学习了类和类的派生的概念,
表示Class之间的关系,
    共同点,commonality,
    Implementation inheritance, 实现承
    Interface inheritance,  run time polymorphism, dynamic polymorphism,
    templates, compile time polymorphism, or static polymorphism,

### Derived Classes

P594
Superclass, Subclass,(holds more data and provides more functions)
static_cast<> // brute force,
dynamic_cast<> //
确定pointer of type Base*的指向的方法:
    - Ensure only objects of a single type are pointed to,
    - Place a type field in the base class for the functions to inspect,
    - Use dynamic_case
    - Use virtual functions,
To build heterogeneous lists, lists of objects of several different types.
type-field , typically best avoided, 我以前就是这么去做的;
    缺点，不能被compiler来检查,
    增加新的派生类，需要修改基类，添加新的类型
    基类存储了太多的信息，undersirable, global variables of the hierarchy,
    For clean design and simpler maintenance, keep separate issues spearate, avoid mutual dependencies,
virtual functions, compiler and linker will guarantee correct correspondence,
    between objects and functions applied to them,
    选择most appropriate for the object for which it is called,
    A degree of stability to an evolving program,
    polymorphism, a type with virtual functions, -> polymorphic type, run-time polymorphic type,
    当直接操作一个对象的话，extact type is known by compiler,
    virtual, override,
    To call the right version of the virtual function , a pointer, virtual funciton table,
    vtbl,
    * virtual, maybe overrided the function,
    *=0, must be virtual and must be overridden,
    * override, the function is meant to override something in a base class, contextual keyword,
    * final, not meant to be overridden, 不能再派生了,

非常容易的生成一个interface class, struct Node{}, virtual xx x()=0;
using Base::f; // bring all fs from Base,
covariant return rule,
    smart pointers, such as unique_str,
abstract class,
Using classes as building blocks,
Access Control:
    private,
    protected,
    public,
 nullptr, ->*, .*, name stored in a pointer to member,
indirectly refer to, member function pointer,
    using Pst_mem= void (Std_interface::*)();
    Pst_mem s = & Std_interface::suspend;
    p->*s(); // call through pointer to member,
        offset, 不依赖于object的location in memory,
    static memmber, 是ordinary function pointer,
    using Pm = const char*C::*; // pointer to char* data member of C
contravariance,
    可以将基类成员的指针赋给派生类成员的指针 ，不能反过来弄,

## Chap 21 Class Hierarchies

Abstraction is selective ignorance,
Implementation inheritance,
Interface Inheritance,
    UI systems should hide implementation detail from users,
    lval_box class contain no data,

```
1. lval_box as a pure interface,
class lval_box {
public:
    virtual int get_value()=0;
    virtual ~lval_box(){}
}
// The data is gone , simplistic implementations of the member functions, gone,
a virtual destructor to ensure proper cleanup of the data, 

```

being explicit can help minimize confusion,
C++ is a heavy sword. Very powerful.
2.abstract class design,
application-oriented conceptual hierarchy,
这种解决方法是: 展现给用户的是一个系统, a hierarchy of abstract classes, classical hierarchy,

- 使用abstract class来支持interface inheritance,
- 使用base classes with implementations of virtual functions to support implementation inheritance,
生成对象的类, 这个被称为factory, 它的函数被称为virtual constructor, (生成对象的方法必须使用implementation-specific names, 我们希望减少使用特殊的命名，所以一个简单的方法就是再次使用indirection,)
接口函数接受一个派生类，虽然定义时用的是基类，会自动调用派生类的构造函数;

### 多重继承, Multiple Inheritance

- shared interfaces, leading to less replication of code using classes, run-time polymorphism or interface inheritance,
- shared implementation, less code, more uniform implementation code, impoementation inheritance,

combining and accessing features from multiple base classes,
虚拟函数, virtual function的应用 ，
使用多重继承来将两个不相关的类glue在一起，作为第3个类的实现,
A technique doesn't have to be clever to be useful??
2个基类的同名virtual functions,
    Explicit disambiguation is messy,
    virtual的作用是有同样的effect,不论使用interface,来寻找function,
    Use qualified name, Telstar::draw,
Virtual 基类,
    holds no data of its own,
    [1] Make the data nonlocal, outside the class as a global or namespace variable,
    [2] Put the ata in a base class,
    [3] Allocate an object somewhere and give eahc of the two classes a pointer,
Virtual Base,
    constructing virtual bases, 只被执行一次，  
    描述了一下如何初始化,各层的基类，父类,
interface,
implementation,
mixin class, 只实现了部分virtual base class的implementation,

## chap 22 Run-Time Type Information

class lattice, class hierarchy,  
how to get information about , the interface provided by a base class,
在系统和应用之间, commonly referred to as widgets or controls,
we lose informaiton about the type of objects passed to the system and later returned to us,
a pointer or fererence of a suitabl etype for the object.

dynamic_cast<T*>(p); or nullptr,
downcast, 向派生类方向，
upcast, 向基类方向,
P660,
只能使用pointer,
bad_cast exception is thrown,
可以使用dynamic referencer cast吗?
从多态virtual base class to a derived class or a sibling class, run-tyime checked,
static_cast<>(); // 不会检查the object it casts from, so it can not,

在非polymorphic object是不存在这些类型信息的, to find the objects for which it represents a base.
run time type identification includes the information needed to implement the dynamic_cast,
    Asking an object if it provides a given interface, virtual function 给对象提供了一个可以使用，操作的接口;抽象类实际上是一个操作用的接口,
const_cast<>();
reinterpret_cast<>();
unique_prt<lo_obj> p {get_obj(ss)};
using Io_circle=Io<Circle>;
这里构造了一个object I/O system, 使用了RTTI,
typeid();
dynamic dispatch;

如何增加virtual function to class hierarchy, without modifying the base classes that provides the interface, ?
在vectors, graphs, pointers to objects of polymorphic types, 一个对象的实际类型贺卡以通过观察base class提供的接口来确定．

### Double Dispatch

选择对象的合适的函数，
Shape的例子，需要修改所有的类，才能够正确处理intersect()
double dispatch method is highly intrusive,
bounding box,
Stroustrup, 1994,
Strustroup,

### Visitors pattern

To the exponential growth of virtual fucntions and overriders and the unpleasent intrusiveness of the simple double-dispatch technique.
寻找正确的操作方法对应正确的节点,
Solodkyy, 2012?

### Type Identification

typeid(expr);  throw std::bad_typeid,
type_index{typeid(*p)}
<typeinfo>
type_index,是一个标准库, for comparing and hashiong type_info objects,
push_back();
pop_back();
template, template argument, enables static type checking,

## chap 23 Templates

generic programming, using types as parameters,
C++ template  
mechanism,
允许一个type, value, to be 参数，在定义class, function, type alias的时候,
genral concepts, simple way to combine them,
可以匹配，多种情况, general code, in run-time efficiency, space efficiency,
with flexible and type-safe initialization, subscription and submatrices,

### 23.1 Type Equivalence

通过模板，我们可以模板参数来生成类型。

### Simple String Template

Template Instantiation,
Type Checking,
Container<T>(), 必须含有, [], size(), value_type,
C is a strongly type, weakly checked language,
Template argument requirements is checked in the compilation process,
using uchar=unsigned char;
Error Detection,
the first point of instantiation,

### 23.4 Class Template Members

Data members,
Member functions,
Member type aliases,  using ,or typedef,  to provide common names for types in different classes, and class templates with common semantics. associated types, value_type, iterator,
static Members,
Member types,
Member Templates,

A member template can not be virtual.
Use of Nesting,

Avoid nested types in templates. 除非确实依赖于template parameter,

Friends,
<>说明这是一个template function,
如同member function, a friend function is instantiated only if it is used,
class templates 可以designate other classes as friends,
代表了一个small clusters of closely related concepts, 如果太复杂的话，那么肯定是犯了一些设计上的错误,

### 函数模板, Function Templates

vector, continuous memory location, can change size, like aary,
    fast to add to end, remove from head or middle,
    thread-safe, synchronized,
    只需从尾部添加，删除较慢
list, non-contiguous memory,
    not thread-safe, not synchronized,
    add to middle and head, very fast,
    删除会非常迅速,
map, dictionary like order,

std::sort()
std::swap()
std::reverse()
iterators, unidirection, bidirection,  forward, backward,

一个排序算法, Shell sort , Knuth, Vol 3, pg, 84,

### 23.5.1 Function Template Arguments

### 23.5.3 Function Template Overloading

### Reference Deduction

T&& r, move r into ,
& , pointer to ,

incomplete type is not allowed  C/C++(70);
include <sstream>

make_unique() is not part of the standard library,

几条原则:
[1] 优先考虑参与重载的函数模板, template参数, 如果没有其它的函数模板，或同名函数的话;
[2] 如果２个函数模板可以被调用的话，如果1个比另一个更专门的话，则采用更专门的函数模板;
[3] 重载判断, 上述函数，再加上普通函数．如果一个函数模板的参数也使用了模板参数推导，这个参数不能够同时包含promotions, 标准的类型转换，或者用户定义的类型转换．参数无需转换的函数模板优先级高于需要转换的函数模板;
[4] 如果一个函数和一个specialization同时满足的话,优先选取函数, 而不是模板特化;
[5] 如果无法找到对应模板的话，调用报错．如果同时有２个或多个同样的匹配的函数模板的话，调用含糊，也会报错;

Explicit specialization of the template,

#### Argument Substitution Failure

SFINAE (Substitution Failure Is Not An Error)

Template Aliases,
using syntax,
typedef syntax,

using Cvec=vector<char>;

#### 23.5.3.3 Overloading and Derivation

### Source Code Organization

使用模板来组织源代码,

### 33.1.2 Iterator Categories

5 kinds of iterators:

- Input iterator,
- Output iterator,
- Forward iterator,
- bidirectional iterator, list, map, set
- random-access iterator, vector,

## 33.2 Iterator Adaptors

- reverse_iterator
- back_insert_iterator
- front_insert_iterator
- insert_iterator
- move_iterator
- raw_storage_iterator,

```cpp
iterator<Iterator_category<Iter>,
        Value_type<Iter>,
        Difference_type<Iter>,
        Pointer<Iter>,
        Reference<Iter>>
// Every Iterator will define 5 properties
```

P962,

## 33.2 Iterator Adaptors

$ [b:e) $ ,  $&*(reverse_iterator(p))==&*(p-1$

v.rbegin(), 指向最后一个元素, v[v.size() - 1]

end()是最后一个虚拟的元素,

**decltype,**

编译时类型推导， 类似于auto, 不是通过变量声明的初始化表达式来获得变量类型，而是以一个普通表达式来作为参数。C++11的新类型。

### 33.2.2 Insert Iterators

### 33.2.3 Move Iterator

## 33.3 Range Access Functions

## 33.4 Function Objects

- predicates, 逻辑运算
- Arithmetic, 算术运算

## 33.5 Function Adaptors

bind(), arguments binding, placeholders: _1,_2, _3 ...

mem_fn(), 生成一个函数对象,

not1()

not2()

reference_wrapper<T>

ref(), pass references,

function<R(Argtypes...)>,
    allocator_arg_t,
    nullptr_t,
    nullptr,

# Chap 34 Memory and Resources

Almost Containers,

- T[N], Built-in array, fixed-size,
- array<T,N> , sixed size continuously allocated sequence of N elems
- bitset<N>, fixed size of N bits,
- vector<bool> , sequence of bits,
- pair<T,U>, Two elements of type T and U
- tuple<T...>, a sequence of arbitrary number of elements of arbitrary types,
- basic_string<C>, a sequence fo characters of type C,提供string operations
- valarray<T>, array of numeric values of type T, 提供数值操作 ，

标准库为什么提供这些containers?呢,

### 34.2.1 array

fixed-size sequence of elements, given type, number of elements specified at compile time.

constexpr, 在编译时是常量,

array 更加不灵活，简单，与vector相比的话。这使它的性能会好一些。

```
tuple_size<array<T,N>>::value,
tuple_element<S, array<T,N>>::type,

```

noexcept: 表明函数中不会发生异常，也就是不会throw,

decltype(a),

### 34.2.2 bitset

bitset<N>, on a sequence of N bits [0:N), N is known at compile time,
set, bit-field?

array of N bits. <bitsets>, fixed size,

size(), ==, I/O,

### 34.2.3 vector<bool>

可以改变大小。

### 34.2.4 Tuples

grouping values of arbitrary types into a single object,

- pair, holds two values
- tuple , hold zero or more values,

定义一个class, 再定义一堆关于类的Helper函数,

make_pair()

### 34.2.4.2 tuple

template<typename... Types>

## 34.3 Resource Management Pointers

pointer, does not indicate who owns the object.
Have no idea who is supposed to delete the object pointed to.

<memory>, smart pointers, to express ownership.

- unique_ptr,  represent exclusive ownership, can not copy, can be moved,
    提供了exception safety, for dynamically allocated memory,
    passing ownership of 动态分配的内存,
    storing pointers in containers,
- shared_ptr, shared ownership,
- weak_ptr,  break loops in circular shared data structures,

page 990

weak_ptr, 允许访问其它人拥有的对象, lock(),

sp , shared pointer,

## 34.4 Allocators

STL containers, string, 是资源的句柄, allocators, de-allocator,

### 34.4.2 Allocator Traits

allocator_traits, type aliases, allocator functions,

### 34.4.3 Pointer Traits

pointer_traits, 确定properties of pointers and proxy types for pointers.

### 34.4.4 Scoped Allocators

using containers, and user-defined allocators,

vector, string,

## 34.5 The Garbage Collection Interface

Recycling of unreferenced regions of memory, as a panacea.

Examples: file handles, thread handles, locks. I see garbage collection as a convenient last resort after the usual techniques for preventing leaks hae been exhausted.

- resource handles, string, vector, unordered_map, thread, lock_guard ...
- unique_ptr,
- shared_ptr,

从最基本的哲学上来讲，C++可以不需l垃圾回收。垃h回收需要显示地安装和激活。
But good free and commercial collectors are available.

safely derived pointer, disguised pointers,

declare no pointers() 可以使b变得非常高效，声明很多内存无需考虑垃圾回收。

class pointer_safety,

## 34.6 Uninitialized Memroy

writing memory allocators, implementing containers, dealing directly with hardware, direct use of uninitialized memory, known as raw memory,

<memory>, fill* family of functions, reserve(),resize(),

### 34.6.1 Temporary Buffers

temporary space best allocated in one operatoin but not initialized until a particular location is actually needed.

get_temporary_buffer() is low-level and likely to be optimized for managing temporary buffers.

new, allocator::allocate(), for obtaining longer-term storage.

### 34.6.2 raw_storage_iterator

# 35 Utilities

The time you enjoy wasting is not wasted time. - Bertrand Russell

## 35.1 Introduction

标准库提供了很多Utility components, not easily classified as part of some major standard-library component.

## 35.2 Time

<chrono>, dealing with time durations and time points.
std::chrono, 标准库mutexes, locks, 提供option for thread to wait for a period of time, a duration or to wait until a given point in time, time_point,

- system_clock
- steady_clock
- high_resolution_clock,

auto t = steady_clock::now()

<ratio>, siN implementation-defined signed integer type of at least N bits.

### 35.2.3 Clocks

ultimately obtained from hardware clocks. class system_clock{}, real-time clock;

steady_clock, time moves steadily forward, time does not go backward , time between clock ticks is constant,

high_resolution_clock, A clock with the shortest time increment on a system.

### 35.2.4 Time Traits

time traits, floating point, or integral,

duration_values<Rep>,

## 35.3 Compile-Time Rational Arithmetic

## 35.4 Type Functions

<type_traits>,  used at compile time to support simple, not so simple metaprogramming.

### 35.4.1 Type Traits

## 35.5 Minor Utilities

move(), rvalue(), a cast to an rvalue, to steal the representation of an object with a move operation, marks x for destruction so that move(x) should be used with car.

forward(), 生成一个rvalue from an rvalue, perfect forwarding of an argument from one function to another, forward(x) is safe,

remove_reference<T>& t,

static_cast<T &&>(t),

swap(), <utility>,

### 35.5.3 Relational Operators

std::rel_ops,

### 35.5.4 Comparing and Hashing type_info

<typeindexe>, type_index,

hash_code()?

name(),

# 36 Strings

标准库提供了字符 classification 操作<cctype>
    辨别字符, isspace(),islower(), isalnum(), iscntrl(),isgraph(), not space,

<cwctype>

<string>， struct char_traits<char>,
    char, char16_t, char32_t, wchar_t,

<regex> 正则表达式 ，

<cstring> C-style strings,

locale, 不同的字符集，编码，conventions,

POD, plain old data, 直接与C库二进制交互的类型 ，

## 36.3 Strings, basic_string

char_traits, allocator<C>, 将所有的数据类型定义统一的接口。

wchar,

### 36.3.1 string vs. C-Style Strings

### 36.3.2 Constructors

allocator,

string::npos, end to string,

substring notation, (position, length),

### 36.3.3 Fundamental Operations

std::length_error,

### 36.3.4 String I/O

### 36.3.5 Numeric Conversions

string, wstring,

stoi(), stol(), stoul(), stoll(), stoull()

### 36.3.6 STL-like Operations

find, string::npos, not a position,

substrings, s.substr(pos, n);

# 37 Regular Expressions, 正则表达式

regex_match()

regex_search()

regex_replace()

regex_iterator(), over matches and submatches,

regex_token_iterator, over non-matches,

compilation state machine, at run time,

regex library, ECMA standard, ECMAScript,  the syntax of regular expressions, based on characters with special meaning.

Page 1069,

ECMA-262 reg rules,

POSIX sed notation,

## 37.3 Regular Expression Functions

regex_search(), regex_replace(),
$&, for the match

$2, for the second submatch,

## 37.4 Regular Expression Iterators

regex_iterator, bidirectional iterator,

### 37.4.2 regex_token_iterator

iterates over submatches of the match_results found,

### 37.5 regex_traits

# 38 I/O Streams

I/O stream, File streams, String stream, Error Handling, I/O operations,

Input Operations, Output Operations , Manipulators, Stream State, Formatting,

Stream Iterators,

Buffering, Output streams, Buffers, Input Streams and Buffers, Buffer Iterators

## 38.1 Intro

I/O stream library, 提供了格式化，和g格式化的带缓冲的I/O, 包含了文本数据、二进制数据。<istream>, <ostream>, 一个是输入、一个是输出。

istream, 将格式化的数据放在stream buffer里转换成其它的数据，file, memory, device,

ostream, 也是处理格式化的数据，也就是包含数x信息的数据格式，

iostream,

I/O stream operations:

- type safe and type sensitive,
- extensible, 可扩展性, 设计新的类型，匹配I/O stream的操作。
- locale sensitive
- efficient,
- interoperable with C-style stdio,
- include formatted, unformatted, character-level operations,

标准I/O stream:

- cout,
- cin,
- cerr,  unbuffered,
- clog,  buffered, character error output,

wcin, wcout, wcerr, wclog,

<iosfwd>, forward declarations for stream types and stream objects,

### 38.2.1 File Streams

fstream, 有6种

- ifstream,
- wifstream,
- ofstream
- wofstream
- fstream
- wfstream

打开文件的模式, mode:

- ios_base::app, append to the end of the file,
- ios_base::ate, at end,
- ::binary,
- ::in, only for reading
- ::out, for writing,
- ::trunc,  truncate the file to 0 length,

bad() state,

### 38.2.2 String Streams

<sstream>, to and from a string,

- istringstreams, reading from a string,
- ostringstream,
- stringstream, read and write to a string

## 38.3 Error Handling

状态basic_ios, <ios>,

Stream States:

- good(), previous iostream operations succeeded,
- eof(),
- fail(), unexpected happended,
- bad(), something serious happended, disk read error,

Use exceptions to handle iostream errors. dont expect to be able to recover from. bad() exceptions.

## 38.4 I/O operations

### 38.4.1 Input Operations

cin>>x,

cin.operator>>(x), operator>>(cin,x), 必须是定义过的类型;

cin>>pf, pf(cin), pf是a function,

noskipws, skipping of whitespace,

#### 38.4.1.2 Unformatted Input

- in.get(c)
- in.getline(p, n, t),
- in.putback(c),
- in.unget(), back up in's stream buffer by one,
- in.ignore(n,d)

### 34.8.2 Output Operations

<ostream>, 除了writing out a string, in <string>,

#### 34.8.2.1 Virtual Output Functions

double dispatch,

manipulator,

### 38.4 Stream State

basic_ios:

- mapping between a stream and its buffers
- formatting options
- use of locale
- Error Handling,
- Connections to other streams and stdio,

这个类是标准库里最复杂的类　, class,

class ios_base,
    *fmtflags, // all bitmask types, bitwise logical operations
        &, |, int, bitset,
    * iostate,
    *openmode,
    * seekdir
    *class failure,
    * class Init, initialize standard iostreams,

iostate, member constants,
    *badbit,
    * failbit,
    *eofbit, we hit end-of-input, end-of-file,
    * goodbit,

ios_base Mode, openmode,
    *app,
    * ate
    *binary,
    * in
    *out
    * trunc,

### 38.4.5

formating of stream I/O, a combination of object type,
    *stream state,
    * format state,
    *locale information,
    * explicit operations, manipulators,

#### 38.4.5.2 Standard Manipulators

manipulators, varoius format states, state changes, 标准的manipulators, <ios> <istream> <iomanip>,

- boolalpha, true, false
- noboolalpha
- showbase, 0, 0x,
- noshowbase
- showpoint, show decimal point,
- noshowpoint, ios_base::showpoint,
- showpos, show + for positive numbers,
- uppercase,
- unitbuf, flush after each output operation,
- nounitbuf,
- internal, pad where marked in formatting pattern,
- left, pad after value
- right
- dec
- hex
- oct
- fixed, dddd.dd
- scientific, d.ddddEdd
- hexfloat
- defaultfloat
- skipws, skip whitespace,
- noskipws,

os<<endl; os<<ends;  os << flush;

#### 38.4.5.3 User Defined Manipulators

Formatting controlled by a confusing multitude of separate functions.

## 38.5 Stream Iterators

<iterator> allow input , output streams to be viewed as sequences , input-begin: end-of-input,

## 38.6 Buffering

output stream puts characters into a buffer.  <streambuf>,

不同的streambuf, 实现了不同的buffering 策略。一般情况下, streambuf在一个队列里存储字符，当overflow时，强制将字符写入真正的目的地。

istream 与之类似。只不过方向不同;

非缓冲的I/O, 不会将字符放入缓冲区,

basic_streambuf,

- overflow()
- underflow()
- unflow(),

### 38.6.1 Output Streams and Buffers

basic_ostream,

### 38.6.2 Input Streams and Buffers

istream,

pos_type,

### 38.6.3 Buffer Iterators

<iterator>, istreambuf_iterator, ostreambuf_iterator, iterate over the contents of a stream buffer,

# 39 Locales

处理Cultural Differences,

locale, 邮政编码,电话号码, 控制写入ostream的信息，从istream读出的数据的格式,

facet,  control individual aspects,
    character used for punctuation, in the output of floating-point value,
    locale::facet,
    locale as a container of facets,

locale影响I/O stream,

internationalization, 多个国家的文字，国际化, 在多个国家使用,

localization, adaptation of a program to local conditions,

switch is ugly and hard to maintain.

use_facet<Facet>(loc) notation,

facet categories:

- collate,
- ctype
- numeric, num_put, num_get, numpunct,
- monetary, money_put, money_get, moneypunct,
- time, time_put, time_get,
- messages, messages,

每一个istream, ostream都有自己的locale, by default 为global locale,

设置locale of stream, imbue() 操作,

拷贝locale of stream, getloc(), 操作,

### 39.2.1 Named locale

所有的操作系统都有方法来设置program的缺省的locale, 通常是通过环境变量来设置的，

- LC_ALL
- LC_COLLATE
- LANG,

locale name string,

在Linux系统里，保存locales in 目录/usr/share/locale,

生成新的locales,

There is no way of modifying a locale. locale is immutable.

### 39.2.2 比较字符串

根据locale, 来比较两个字符串,

## 39.3 Class facet

locale is a collection of facets.

- how a number is represented on output,num_put,
- how a date is read from input, time_get,
- how characters are stored in a file, codecvt,

标准库的facets, std::locale::facet, <locale>

```
f=use_facet<F>(loc)
has_facet<F>(loc)
facet::id

```

### 39.3.3 Uses of locales and facets

### 39,4,1 string Comparison

### 39.4.2 Numeric Formatting

num_put,

num_get,

numpunct facet, numerical punctuation,

- decimal_point()
- thousands_sep()
- grouping()
- truename()
- falsename()

ostreambuf_iterator<C>,

sentry_guard()

- badbit,
- eofbit,
- failbit,

sentry, to ensure that the stream's prefix and suffix operations are performed.

### 39.4.3 Money Formatting

frac_digits(),Number of digits ater ".",

money_get(), money_put(),

Moneypunct,

symbol, space, sign, none, value,

ISO-4217, 货币的三个字符的标准,

### 39.4.4 Date and Time Formatting

time_put(), strftime() format,

- dateorder
- weekday
- monthname,

tm, year zero for 1900, +1900,

### 39.4.5 Character Classification

字符类别，不同的character sets, He is Danish.

ctype_base,

### 39.4.6 Character Code Conversion

codecvt facet,

JIS <=> Unicode,

ok, partial, error, noconv,

### 39.4.7 Messages

#### 39.4.7.1 Using Messages from Other facets

## 39.5 Convenience Interfaces

locale facilites can be complicated to use. 简化notation, 减少mistakes.

### 39.5.4 Buffer Conversions

# 40 Numerics

## 40.1 Introduction

C++不是为了数值计算而设计的。然而在某些应用中，C++非常吸引人。

- database access
- networking
- instrument control
- graphics
- simulation
- financial analysis

数值方法，numerical methods,

<limits>, numeric_limits template,

constants, constexpr functions,

mantissa? 尾数,

### 40.2.1 Limit Macros

<climits>, Integer Limit Macros,

```
CHAR_BIT
CHAR_MIN
CHAR_MAX
INT_MIN
LONG_MAX
```

<cfloat>, <float.h>

```
FLT_MIN
FLT_MAX
FLOT_DIG  // Number of decimal digits of precision of a float
FLT_MAX_10_EXP
DBL_MIN
DBL_MAX
DBL_EPSILON
```

## 40.3 Standard Mathematical Functions

<cstdlib>, <cmath>,

## 40.4 Complex Numbers

complex<float>, complex<double>, complex<long double>,

## 40.5 Numerical Array: valarray

single-dimensional vectos of floating point values,

For high-performance machine architecture, libraries relying on such vectors are in wide use. very aggresive optimization of code.

slice

gslice, generalized slice,

## 40.6 Generalized Numerical Algorithms

<numeric>,  <algorithm>,  general versions of common operations on sequences of numerical values,

page 1177

- accumulate
- reduce
- reduction,
- fold

inner_product()

partial_sum(),

adjacent_difference(),

iota(),

## 40.7 Random Numbers

<random>, unguessable , truly random numbers, radio active decay, solar radiation. a random_device,

- uniform random number generator, equal probability,
- random number engine,  E{}, seed E{s} with a state, 状态,
- random number engine adaptor (an adaptor), with different randomness properties
- random number distribution,

随机数产生器,engine + distribution,  normal distribution -> default_random_engien,  生成一个正则分布。

用于sampling algorithms, 采样算法，从一个更大的样本群中选择一g规模的样本，抽样吧。　algorithm R,

[b,e),

### 40.7.2 Random Device

d=rd.entropy(),

D::result_type, D::param_type,

- Bernoulli Distribution, {true,false}
- binomial Distribution,  [0:无穷),
- geometric Distribution,
- negative binomial distribution,

Poisson distribution, 柏松分布,

### 40.7.4 C-style Random Numbers

<cstdlib>, <stdlib.h>,

srand(s), start a new sequence of random numbers from the seed ,s ,在实际，为了使程序不可预测，seed通常选取环境中的一个变量，比如实时时钟，will make a good seed, 再加上温度，等等传感器的数据。

# chap 41 Concurrency

并行。 同时运行多个任务, widely used to imporve throughput. 使用多个处理器进行一个计算。提高响应的敏捷性，允许程序的一部分运行，另一部分等待响应。

thread.

所有的线程访问memroy, in a sensible manner. 标准库支持的并行包括:

- memory model, 保证同时访问memory不会出问题;
- programming without locks, fine-grained low-level mechanisms for avoiding data races
- thread library, 支持传统的threads-and-locks-style system level concurrent programming, 包括: thread ,condition_variable, mutex,
- task support library: task-level concurrent programming:
  - future
  - promise,
  - packaged_task
  - async()

对于程序员来说, prefer a future over a mutex for exchanging informaiton ,

prefer muxtex over atomic for anything but simple counters ,

尽可能地使用标准库来处理复杂性,

processes, thread of execution in their own address spaces and communicating through inter-process communication.

local data, don't pass pointers of local data to other threads.

deal with concurrency at the system level,
standard提供的concurrent facilities,
介绍基本使用, threads-and-locks level

没有介绍relaxed memory model, lock-free programming,
advanced concurrent programming and design techniques,

与POSIX threads相比，标准库的实现是
type-safe: mess around with macros or void**, pass information among threads.

futures 可以传送exceptions.

type safety, standard exception-based error-handling strategy,

## 41.2 Memory Model

## 41.3 Atomics

Lock free programming是一些不使用explicit locks来编写concurrent programs的技巧。 依赖机器的原始操作来避免数据竞争,

Atomic operations,不会有数据竞争问题, data races,

lock-free technqiues 会比 lock-based alternatives快很多。

依赖于汇编语言，或system-specific primitives.

同步操作： thread sees the effects of another thread, 在同步操作之间，编译器和处理器可以自由地 reorder code.同步操作可以是一个consume, acquire, release, .

- acquire, other processors will see its effect before any subsequent operation's effect,
- release, other processors will see every preceding operations' effect before the effect of the operation itself,
- consume, weaker form of acquire,

enum memory_order,
    memory_order_relaxed,
    memory_order_consume,
    memroy_order_acquire,
    memory_order_release,
    memory_order_acq_rel,
    memory_order_seq_cst, sequentially consistent,

[[carries_dependency]], for transmitting memory order dependencies across function calls.

C++ memory model,

### 41.3.1 atomic Types

atomic template, performed by a single thread without interference from other threads.

操作: load, store, swapping, incrementing, on a simple object, usually a single memory location.

compare-and-exchange operation,

compare-and-swap loop, CAS operation? Compare and Swap,

ABA problem? subtle and hard to detect,  subtleties of lock-free programming.

they use compare-and-swap hardware operations;

double-checked locking idiom.

- optimisitc design
- transactional memory,

or atomic increment,

RAII? Resource Management,

double-checked locking idiom, once_flag, call_once(), 标准库支持atomic 指针。

### 41.3.2 Flags and Fences

标准库提供了两个低级的同步方法: atomic flags and fences.

lowest-level atomic facilites, spinlocks, atomic types.

Only lock-free mechanisms , 保证支持所有的实现，implementation, 虽然所有的大的平台都支持atomic types.

 与machine architects有关的额才会使用flags、fences.

atomic_flag, a single bit of information, 其它的atomic类型都可以用atomic_flag来实现。

ATOMIC_FLAG_INIT是唯一的可移植的、可靠的方法来初始化一个atomic_flag, 可以理解为一个非常简单的spin lock;

fence, 是memory barrier, that restricts operation erordering according to some specified memory ordering. 限制操作的重新顺序改变。slowing down a program to a safe speed, allowing a memroy hierarchy to reach a reasonably well-defined state.

atomic_thread_fence(order)

atomic_signal_fence(order),

## 41.4 volatile

to indicate that an object can be modified by something external to the thread of control.

volatile const long clock_register;

Not to optimize away apparently redundant reads and writes.

只在底层的代码，直接与硬件打交道的部分使用volatile.

# 42 Threads and Tasks

Threads, avoiding data races, task-based concurrency,

## 42.1 intro

concurrency, 同时执行多个任务，用来提高throughput, 使用多个处理器来进行一个计算，或允许程序的一部分运行，另一部分在等待响应，从而提高响应能力。

A thread可以执行一个任务, task. thread可以和其它的thread来共享地址空间。一个地址空间的所有threads都可以访问同样的内存位置。并行系统的的中心问题在于，确保threads可以一种可控的方式来访问内存。

All threads 运行在同样的地址空间。如果需要hardware protection against data races, 使用了notion of a process. Stacks are not shared between threads, local variables are not subject to data races.

blocked, asleep, 当thread无法执行时。

this_thread

```
id, // 唯一的标识符,t.get_id(),
native_handle_type,
t=move(t2)
t.swap(t2)
t.joinable()
t.join()
t.detach), 
x=t.get_id(), 
x=t.native_handle(), 
n=hardware_concurrency(), n is the number of hardware processing units, 0, don't know
swap(t,t2)
```

thread 代表了一个系统资源，a system thread, possibly even with dedicated hardware.
thread可以被移动，但是不能被拷贝。

作者使用two-core laptop, reports four hardware threads. using what is called hypter-threading.

after detach(), 系统thread还是有一个id, hash<thread::id>,

生成多个task, link together, communicate through message queues.

- queue, put(), get(), 实现without data races,
- Consumer, Producer,
- worker[i] = move(worker_tmp)

### 42.2.4 join()

t.join() will block the current thread execution.

struct guarded_thread,

system thread, daemon, t.detach(),

将thread作为程序的一个main module, access them through unique_ptr, shared_ptr, or place them in a container, vector<thread>, to avoid losing track of them.

Dont pass a pointer to a local object out of its scope.

### 42.2.6 Namespace this_thread

- get_id()
- yield()
- sleep_until(tp), put the current thread to sleep until time_point tp
- sleep_for(d), put the current thread to sleep for duration d,

这里又涉及到了操作系统的接口调用。

timed_mutex,

### 42.2.7 Killing a thread

### 42.2.8 thread_local data

objects local, on the stack, is preferable to having them shared.

thread storage duration,

each thread has its own copy of its thread_local variables. destroyed on thread exit.

nonlocal memory is a problem for concurrent programming, often nontrivial to determine if it is shared , a possible source of data races.

static, one-per-class values used to be popular. 包括了default values, use counters, caches, free lists, answers to frequently asked questions, many obscure uses.

## 42.3 避免Data Races

Avoiding attempts to simultaneously access data. dont require locking and lead to maximally efficient programs. 然而lots of data needs to be shared, use some form of locking:

- Mutexes, mutual exclusion variable, acquire, access, release,
- Condition variables,  used by a thread to wait for an event generated by another thread or a timer,

条件变量并不能防止data races, 只是使我们避免引入共享变量.

### 42.3.1 Mutexes

- mutex,
- recursive_mutex, repeatedly acquired by a single thread,
- timed_mutex, a nonrecursive mutex with operations to try to acquire the mutex for only a specified time
- recursive_timed_mutex,
- lock_guard<M>, a guard for mutex M
- unique_lock<M>, a lock for mutex M,

critical section, a section of code protected by  lock,

为了使代码运行，不受， free of problems related to locking, 最好减少critical section的范围，

标准库的mutexes, 提供了exclusive ownership semantics.

lock, try_lock, unlock, m.native_handle(), system handle for the mutex m,

mutex不能被拷贝和移动，转换所有权, 是资源，而不是资源的句柄.

死锁，deadlock, 等待一个永远不会被释放的锁。

lock_guard, 这个会处理mutex的unlock, in it's destructor, a resource handler,

unique_lock, carries a small cost,

### 42.3.2 Multiple Locks

获取2个locks, 会带来死锁,

### 42.3.3 call_once()

call_once(fl, f, args),

once_flag fl {}

### 42.3.4 Condition Variables

threads之间的通讯, wait block on a condition_value, until some event, happen.

```
cv.notify_one()
cv.notify_all()
cv.wait(lck), lck must be owned by the calling thread, atomically calls lck.unlock() and blocks,
cv.wait_until(lck, tp), 

```

## 42.4 Task-Based Concurrency

## 41.3 Atomics

Lock free programming是一些不使用explicit locks来编写concurrent programs的技巧。 依赖机器的原始操作来避免数据竞争,

Atomic operations,不会有数据竞争问题, data races,

lock-free technqiues 会比 lock-based alternatives快很多。

依赖于汇编语言，或system-specific primitives.

同步操作： thread sees the effects of another thread, 在同步操作之间，编译器和处理器可以自由地 reorder code.同步操作可以是一个consume, acquire, release, .

- acquire, other processors will see its effect before any subsequent operation's effect,
- release, other processors will see every preceding operations' effect before the effect of the operation itself,
- consume, weaker form of acquire,

enum memory_order,
    memory_order_relaxed,
    memory_order_consume,
    memroy_order_acquire,
    memory_order_release,
    memory_order_acq_rel,
    memory_order_seq_cst, sequentially consistent,

[[carries_dependency]], for transmitting memory order dependencies across function calls.

C++ memory model,

ISO C++ standard, contract between implementers and programmers to ensure that 一般的大众程序员、也就是编程语言的使用者不必去思考现代计算机硬件的细节。内存中对一个对象的操作，并不是直接作用于内存，而是register, 寄存器、缓存之上。

### 41.2.1 Memroy Location

Bit-fields give access to parts of a word. 除s使f非常昂贵的locking,

A memory location是数字类d对象z指针，最大的sequence fo adjacent bit-fields all having非零的宽度。

Instruction Reordering,

Memory Order,

sequentially consistent, memory order,

atomic operation, a consistent view of a memory location,  a simple read or write does not impose an order,

### 41.3.1 atomic Types

atomic template, performed by a single thread without interference from other threads.

操作: load, store, swapping, incrementing, on a simple object, usually a single memory location.

compare-and-exchange operation,

compare-and-swap loop, CAS operation? Compare and Swap,

ABA problem? subtle and hard to detect,  subtleties of lock-free programming.

they use compare-and-swap hardware operations;

double-checked locking idiom.

- optimisitc design
- transactional memory,

or atomic increment,

RAII? Resource Management,

double-checked locking idiom, once_flag, call_once(), 标准库支持atomic 指针。

### 41.3.2 Flags and Fences

标准库提供了两个低级的同步方法: atomic flags and fences.

lowest-level atomic facilites, spinlocks, atomic types.

Only lock-free mechanisms , 保证支持所有的实现，implementation, 虽然所有的大的平台都支持atomic types.

 与machine architects有关的额才会使用flags、fences.

atomic_flag, a single bit of information, 其它的atomic类型都可以用atomic_flag来实现。

ATOMIC_FLAG_INIT是唯一的可移植的、可靠的方法来初始化一个atomic_flag, 可以理解为一个非常简单的spin lock;

fence, 是memory barrier, that restricts operation erordering according to some specified memory ordering. 限制操作的重新顺序改变。slowing down a program to a safe speed, allowing a memroy hierarchy to reach a reasonably well-defined state.

atomic_thread_fence(order)

atomic_signal_fence(order),

## 41.4 volatile

to indicate that an object can be modified by something external to the thread of control.

volatile const long clock_register;

Not to optimize away apparently redundant reads and writes.

只在底层的代码，直接与硬件打交道的部分使用volatile.

# 42 Threads and Tasks

Threads, avoiding data races, task-based concurrency,

## 42.1 intro

concurrency, 同时执行多个任务，用来提高throughput, 使用多个处理器来进行一个计算，或允许程序的一部分运行，另一部分在等待响应，从而提高响应能力。

A thread可以执行一个任务, task. thread可以和其它的thread来共享地址空间。一个地址空间的所有threads都可以访问同样的内存位置。并行系统的的中心问题在于，确保threads可以一种可控的方式来访问内存。

All threads 运行在同样的地址空间。如果需要hardware protection against data races, 使用了notion of a process. Stacks are not shared between threads, local variables are not subject to data races.

blocked, asleep, 当thread无法执行时。

this_thread

```
id, // 唯一的标识符,t.get_id(),
native_handle_type,
t=move(t2)
t.swap(t2)
t.joinable()
t.join()
t.detach), 
x=t.get_id(), 
x=t.native_handle(), 
n=hardware_concurrency(), n is the number of hardware processing units, 0, don't know
swap(t,t2)
```

thread 代表了一个系统资源，a system thread, possibly even with dedicated hardware.
thread可以被移动，但是不能被拷贝。

作者使用two-core laptop, reports four hardware threads. using what is called hypter-threading.

after detach(), 系统thread还是有一个id, hash<thread::id>,

生成多个task, link together, communicate through message queues.

- queue, put(), get(), 实现without data races,
- Consumer, Producer,
- worker[i] = move(worker_tmp)

### 42.2.4 join()

t.join() will block the current thread execution.

struct guarded_thread,

system thread, daemon, t.detach(),

将thread作为程序的一个main module, access them through unique_ptr, shared_ptr, or place them in a container, vector<thread>, to avoid losing track of them.

Dont pass a pointer to a local object out of its scope.

### 42.2.6 Namespace this_thread

- get_id()
- yield()
- sleep_until(tp), put the current thread to sleep until time_point tp
- sleep_for(d), put the current thread to sleep for duration d,

这里又涉及到了操作系统的接口调用。

timed_mutex,

### 42.2.7 Killing a thread

### 42.2.8 thread_local data

objects local, on the stack, is preferable to having them shared.

thread storage duration,

each thread has its own copy of its thread_local variables. destroyed on thread exit.

nonlocal memory is a problem for concurrent programming, often nontrivial to determine if it is shared , a possible source of data races.

static, one-per-class values used to be popular. 包括了default values, use counters, caches, free lists, answers to frequently asked questions, many obscure uses.

## 42.3 避免Data Races

Avoiding attempts to simultaneously access data. dont require locking and lead to maximally efficient programs. 然而lots of data needs to be shared, use some form of locking:

- Mutexes, mutual exclusion variable, acquire, access, release,
- Condition variables,  used by a thread to wait for an event generated by another thread or a timer,

条件变量并不能防止data races, 只是使我们避免引入共享变量.

### 42.3.1 Mutexes

- mutex,
- recursive_mutex, repeatedly acquired by a single thread,
- timed_mutex, a nonrecursive mutex with operations to try to acquire the mutex for only a specified time
- recursive_timed_mutex,
- lock_guard<M>, a guard for mutex M
- unique_lock<M>, a lock for mutex M,

critical section, a section of code protected by  lock,

为了使代码运行，不受， free of problems related to locking, 最好减少critical section的范围，

标准库的mutexes, 提供了exclusive ownership semantics.

lock, try_lock, unlock, m.native_handle(), system handle for the mutex m,

mutex不能被拷贝和移动，转换所有权, 是资源，而不是资源的句柄.

死锁，deadlock, 等待一个永远不会被释放的锁。

lock_guard, 这个会处理mutex的unlock, in it's destructor, a resource handler,

unique_lock, carries a small cost,

### 42.3.2 Multiple Locks

获取2个locks, 会带来死锁,

### 42.3.3 call_once()

call_once(fl, f, args),

once_flag fl {}

### 42.3.4 Condition Variables

threads之间的通讯, wait block on a condition_value, until some event, happen.

```
cv.notify_one()
cv.notify_all()
cv.wait(lck), lck must be owned by the calling thread, atomically calls lck.unlock() and blocks,
cv.wait_until(lck, tp), 

```

## 42.4 Task-Based Concurrency

<<<<<<< HEAD
Task Support,

```
packaged_task<F>, package a callable object of type F to run as task
promise<T>, a type of object to put one result of type T,
future<T>, a type of object from which to move one result of type T,
shared_future<T>, a future from which to read a result of type T several times,
x = async(policy, f, args), launch f(args)
x = async(f, args), launch with default policy, 
```

Simplicity to programmer.

并行的版本, auto handle=async(task, args);
    res = handle.get(), 什么时候会回来呢？

tasks之间的通讯使用future/promise pair, 一个任务将结果放入promise, 另一个任务通过future来获得结果result,

value, shared state, 包含了信息，使两个线程可以安全地交换信息。
- value of appropriate type or an exception,
- ready bit,
- launched by async() with the lauch policy deferred,
- use count, shared state can be destroyed  when and only when its last potential user relinquishes access.
- some mutual exclusion data to enable unblocking of any thread that might be waiting, condition_variable,

实现将 take actions on 共享状态:
- Construct, 使用用户提供的allocator,
- Make ready, 设置ready bit, unblock any waiting threads,
- Release, decrease user count, destroy the shared state if it's the last user,
- Abandon, it becomes impossible for a value or exception to be put into the shared state by a promise, a future_error exception with the error condition broken_promise is stored in the shared state.

### 42.4.2 promise

promise is the handle to a shared state. 可以将结果result, deposit to future.

```
promise pr{}

pr.set_value(x)
pr.set_value()
pr.set_exception(p),
pr.set_value_at_thread_exit(x)
pr.set_exception_at_thread_exit(p)
pr.get_future(), 

```

no copy operations for a promise. future_error, 结果result moved into and out of the shared state,而不是拷贝，这样我们可以廉价地传递一组对象。

### 42.4.3 packaged_task

package_task, future可以在不同的thread里面。

### 42.4.4 future

task可以检索、取回promise放入的结果result.

```
future fu{}
fu.get(), // can only be called once, 要读出多次的话，使用shared_future,
fu.valid()
fu.wait(), block until a value arrives,
fs=fu.wait_for(d), fs tells if a value is ready, a timeout occurred, execution is deferred,
fs=fu.wait_until(tp), 
```

future_errc::no_state,

wait_for_all(args), until every future in args has a value,
wait_for_any(args), wait until one future in args has a value,

steady_clock::duration,

### 42.4.5 shared_future

shared_future, 可以被多个reader读取,

Without too much worrying about threads. a thread is something you give a task to run. 我们还是需要考虑要使用多少个线程thread, 当前的任务是运行在当前thread,还是其它thread.



launching polices:

- async, execute the task as if a new thread was created to do so
- deferred, execute the task at the point of a get() for the task's future,

recycled thread, a thread from a collection of threads( a thread pool)

system threads, can drastically lower the cost of executing a task on a thread,

[=], pass by value, capture by value, not by reference,

### 42.4.7 Parallel find(）例子

[1] Create a number of tasks to run
[2] Run tasks in parallel
[3] Merge the results

map-reduce,

# 43 The C standard library

C语z证明z自己在各种上下q情况d的能力，如low-level programming.

Kernighan and Ritchie's C textnook,

## 43.2 Files

<stdio>,  fopen(s,m), flcose(f), close file stream,

printf(), iostreams, type-safe and extensible,

C style String,

## 43.6 Date and Time

<ctime>, 
clock_t, arithmetic type for holding short time intervals, a few minutes,

time_t, an arithmetic type for holding long time intervals, centuries,

tm, a struct holding the time of a date, since year 1900

t = clock(), 返回clock_t

t = time(pt), t is current calendar time, pt is time_t 或nullptr, pull null uull, bull,

p=asctime(ptm), time_t, asc格式的字符串, 

ctime(t), =asctime(localtime(t)),

localtime(pt), pt==nullptr, 

strftime(p,max,fmt,ptm), 

<chrono>, 

获取运行时间间隔, clock()-clock(),  double(t2 - t1)/CLOCKS_PER_SEC,


## 43.7 Etc.
<cstdlib>, 

```

```


# 44 Compatibility

C++ 11 Extensions,

standard c++, ISO/IEC 14882-2011, 11 c++,

ISO/IEC 14882-1998

standard C , ISO/IEC 9899-2011,

2014,

2017, => this one,

2020, 不知道添加s什么新的特性?

建议使xb版本，建y依赖标准库，使用classes, templates, exceptions,

2023年应s使n哪个版d的C++呢？

使用Boost library,

RTTI, Runtime Type Identification,

extern "C" link to C code,

__cplusplus, macro,

<tgmath.h>, _Copmplex, <complex.h>, <complex>

<stdbool.h>, _Bool, bool,

