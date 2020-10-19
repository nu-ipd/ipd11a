# Configuration for building example C programs.
cmake_minimum_required(VERSION 3.10)
project(ipd11a C)
include(.ipd/cmake/CMakeLists.txt)

add_c_program(limits src/limits.c)
add_c_program(types src/types.c)

# Adds targets named ${name} and ${name}.opt, both built from
# source file src/${name}.c. The difference between the two
# targets is that ${name}.opt is optimized and ${name} is not.
function(add_ub_example name)
    add_c_program(${name}              src/${name}.c)
    add_c_program(${name}.opt          src/${name}.c)
    target_compile_options(${name}     PRIVATE -O0)
    target_compile_options(${name}.opt PRIVATE -O2)
endfunction(add_ub_example)

add_ub_example(int_max)
add_ub_example(array)
add_ub_example(alias)

add_c_program(ipd11a-1 exercise/ipd11a-1.c)
target_compile_options(ipd11a-1 PRIVATE -O0)

add_c_program(ipd11a-1.opt exercise/ipd11a-1.c)
target_compile_options(ipd11a-1 PRIVATE -O2)
