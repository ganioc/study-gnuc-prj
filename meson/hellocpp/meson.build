project('hellocpp', 'cpp')

message('hello du')

srcs = ['main.cpp']

subdir('lib')

incdir = ['lib']

executable('hellocpp',
    srcs,
    include_directories: incdir,
    link_with: greeter_lib)

