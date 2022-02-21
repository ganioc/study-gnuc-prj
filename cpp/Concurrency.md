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
- 背景运行, monitoring the filesystem for changes in a desktop searching application, 
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

一共337页，看起来比较好学一些。

## 为什么使用Concurrency,
Separation of concerns, 
For performance,  concurrency, 
### 什么时候不使用concurrency? 并发,
benefit is not worth the cost, 
multi-threaded code, 难以理解，additional complexity, 
thread-pool,

C++的多线程历史, 
1998 C++没有threads, 
Boost, ACE,支持多线程; 
RAIL (Resource Acquisition Is Initialization Idiom) with locks to ensure that mutexes are unlocked when relevant scope is exited.

thread-aware memory model , 
新的C++0x标准，支持:
- C++ standard library 增加了管理线程的类
- 保护共享数据
- 线程间的同步
- low level atomic operations,

Boost thread library, new library is based,
C++ Thread Library的效率, the cost is Abstraction Penalty,
platform-specific assembly language, new standard types more portable, easier to maintain,
和平台有关的facilities:
- native_handle() member function, underlying implementation, 

<thread>

# chap 2 Managing threads, 线程的管理

