project('hellocpp', 'cpp')

message('hello du')

srcs = ['main.cpp']

subdir('lib')

incdir = ['lib']

zlib_dep = dependency('zlib')

executable('hellocpp',
    srcs,
    include_directories: incdir,
    link_with: greeter_lib,
    dependencies: zlib_dep)

