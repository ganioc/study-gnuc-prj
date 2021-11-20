# 21st century C language
$ gcc -O0 test.c -std=c99

## 测试宏
打印宏， 
```
echo "" | clang -dM -E -xc -
STDC_VERSION__ 201112L, // 也就是C11
不支持C标准thread.h, 可以使用POSIX线程， OpenMP fork ,,
```

### 宏的使用

```
#pragma once

gcc -O3 testmacro.c -o macro -std=c99 -g -Wall

_Bool

libiberty , -liberty
asprintf()


```
## string字符串, oO, c
gcc teststring.c -o str -g -O3 -Wall -std=c99

