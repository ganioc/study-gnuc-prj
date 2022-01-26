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















