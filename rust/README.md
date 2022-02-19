books:
<Beginning Rust from novice to professional 2018 Apress>

## How to learn rust?
rustc 1.55.0

case sensiti e, 

## 标准库
str::len()

编译器会将一些指令插入执行文件，因此会产生abortion, 而不会产生一个segmentation violation trap, panic, panicking, 

- array, let mut x = [4.; 5000]; // 多个元素
- vector, vec!["this", "is"] // .push(), x.len(), ["";0] // 空array, {:?}打印结构, 用于debug,

## primitive types
cross platform, 
- isize,
- usize, 
- i16, u16, f64, f32, 
- as, 转换, 
- bool, char, 
- constatnt, defined at compile time, no more changeable at runtime
- enum,

Page 96,

match 

## chap 8 data structure
tuple, ()

## 函数定义
body前的是 signature of the function

fn double(x: f64) -> f64 { x*2. }

reference &mut,

## generic functions and Struct
Option, result,

## chap 11 内存分配
- in processor registers
    - 不会直接使用,
- static, determined at compile time,
    - let uses stack allocation
    - explicit spec of the type,
    - immutable,
    - 只包含大写字母, separated by underscore,
    - executable binary code, 和string literals,
- in the stack, let分配在stack上,
    - stack for every thread, 
    - quite limited size, a few megabytes,
    - objects size known at compilation type, 
    - 自动分配，自动释放, allocate deallocate, 不可能是vector, 动态增加
- in the heap, 
    - Box<[u8;SIZE]> { Box::new([0u8; SIZE])}
    - reserved, used, 
    - free, unused, 

P165.

vs code, codeLLDB plugin,

## chap12 Data Implementation, 数据的实现
use std::mem;

- discourage accessing the interanl representation of objects,
- vector, allocation , at the heap; stack-allocated fixed-size header
- 

## chap13 Defining Closures, 闭包
can't capture dynamic environment in a fn item

const, static, 

inline anonymous function, with type inference, a single expression as body, capture of any valid variable,

dyn, ?

## chap14, Using Changeable Strings,
&str, reference to stringk

expected `str`, found `&str`;  Rust has no string terminators.

&&str, 

str type, [u8; N] type, 

String type, Vec<u8> type, 动态的字符串, 

dynamic strings, String, "he".to_string()

- let s1 = String::new()
- String::from("")
- "".to_string()
- "".to_owned()
- format!("")

string concatenation:
- str1.push_str(" ")
- +=, 

## chap15 Ranges and Slices,

## chap16 Iterators
as_bytes() , bytes(),  

iterator is a type specification, that has a next method returning an Option<T> value.

mutating iterator, iter_mut()

iterator adapter: filter, map, any, all, count, sum, min, max, collect, 

# chap17 I/O and Error Handling
std::env::args()

std::process:exit(107); // 回到launching process ,

环境变量: std::env::vars()

Reading from the console, std::io::stdin().read_line(&mut line)

错误处理, Result type, match statement,



输出: std::io.Write(), use std::io::Write;

# chap 18 Traits,
 (number as f64).sqrt() as i64
f64::sqrt, 可以, traits 对不同的type，调用不同的接口函数,
trait, impl, 

- self,
- Self,
- std::fmt::Display standard library trait,
- type, 

# chap 19 OOP, Object Oriented Programming
Stru,
    - namespace containing, Stru::f1()
    - instance,

struct Stru{}
impl Stru{}

fn new() -> Number { }
fn from()

composition instead of inheritance, 

# chap 20, Standard Library Collections,
measure the time spent,
collections,
    * arrays,
    * vectors, index based, push,pop,
    * structs,
    * tuple-structs,
    * tuples,
    * enums,
    * VecDeque<T>, push_front, push_back, pop_front, pop_back
    * LinkedList<T>, 频繁地插入删除, 
    * BinaryHeap<T>, 可以有优先级, priority_queue   
    * BTreeSet<T>,无重复, sorted, 
    * BTreeMap<K,V>, Dictionary sorted, 
    * HashSet<T>, 无重复, unsorted,
    * HashMap<K,V>,

detour,
use std::time::Instant;

performance comparision:
- 0.033382 479.957913 97.185783 , linear vec, 
-  , insert and remove at index 0, 

vector-like double-ended queue, 

# chap21 Drops moves and copies
ownership of objects

Boxed objects, Box::new, 
deallocation, 自动发生，无须处理 ， 
- 临时表达式，statement ends,
- varialbes, arrays, scope ends,
- function, closure arguments, block ends,
- Boxed objects, declarations ends,
- chars, removed from the string,
- itmes removed from collection,

c++ heap deallocation, deterministic, explicit,
rust, ownership,

vector, header, data buffer, 
rust, 每一个对象任何时刻都只能有一个owner,
destructors, 
    Drop,drop, 
assignment语义,
    share semantics, 只复制header, Java, gc languages,
    copy semantics, C++, v1.clone();
    move semantics, v1 cannot be used any more, Rust, 
Box::new();

cloneable,
copyable,

enum, struct, tuple,默认不支持copy或clone,

# chap22 Borrowing and Lifetimes
borrow checker,
- borrowing,
- mutable borrowing,
- immmutable borrowing, 
- signature of the function is valid,
- body of the function is valid,

lifetime specifiers, returning references,
- scope, to compile-time variables, not runtime objects
- runtime bojects, named lifetime, 
- decoration of a funciton signature , 允许borrow checker,

referable mulit, own only;

use after change by an Alias,
use after drop,

temporary mutable borrowing, 

function invocation and lifetime,
- 在函数内，只能访问object owned by arguments,
- local variables,
- temporary objects, dynamic string expression,
- static objects,
- borrowed by arguments,

返回时，不能索引
- argument,
- local variable,
- temporary object,

<'a>, lifetime specifier is sued, prefixed single quote,

# chap 23 More About Lifetimes,
lifetime specifiers needed for structs , tuple-stucts, enums,

lifetime elision, 省略,

OK, 总算读过一遍了。





