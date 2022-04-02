## Cpp Notebook
使用Cpp做得一个Notebook软件



## Steps
### Default Directory Layout
root/files/default/
    /files/file1/
    /files/file2/
    * everything under files is a directory or file-directory
    * if there is a __config__.data file under the directory,then it is not a directory , but a 
root/data
root/share

#### Q: std::filesystem,
GCC 5.4.0 was released in June of 2016; over a year before the C++17 standard was adopted
不支持,

/Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/__config:848:58: note: 
      expanded from macro '_LIBCPP_BEGIN_NAMESPACE_FILESYSTEM'
  ...namespace __fs { namespace filesystem {
                                ^
./src/init.cpp:8:39: error: no member named 'directory_iterator' in
      namespace 'std::__1::__fs::filesystem'

error: no member named 'filesystem' in namespace 'std'

A: <filesystem>
```cpp
std::__fs::filesystem::directory_iterator(dir)
namespace fs = std::__fs::filesystem;

// 满足多平台下面的编译
// Support ancient versions of GCC still used in stubborn distros.
#if defined(__GNUC__) && !__has_include(<filesystem>)
    #include <experimental/filesystem>
    namespace fs = std::experimental::filesystem;
#else
    #include <filesystem>

    #ifdef __APPLE__
        namespace fs = std::__fs::filesystem;
    #else
        namespace fs = std::filesystem;
    #endif
#endif

```
#### 如何check file existence,
filesystem

#### 如何退出程序
<cstdlib>
exit(1), 找不到这个函数，编译可以通过，
还是使用本机的gcc, 
IntelliSense Configurations,g++, 和make路径一样就可以了！OK





1. 初始化本地目录结构
    添加目录
    添加文件
2. 检查本地文件
    如果没有默认的索引文件，则loop本地文件，自动生成
    如果有索引文件，则自动打开，并展示
3. 如果选择新的分类模版，则自动分类本地文件，重新生成
4. 对远端的文件服务器，生成自己的本地分类模版，
5. 