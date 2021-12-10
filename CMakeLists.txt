cmake_minimum_required(VERSION 3.11)
project(dsa)

add_compile_options(-Wall -Wextra -Wpedantic -fmessage-length=80 -fno-diagnostics-show-option
        -fstack-protector-all -g -O3 -flto -std=c++17 -Walloc-zero -Walloca
        -Wctor-dtor-privacy -Wduplicated-cond -Wduplicated-branches
        -Werror -Wextra-semi -Wfatal-errors -Winit-self -Wlogical-op
        -Wold-style-cast -Wshadow -Wunused-const-variable=1
        -Wzero-as-null-pointer-constant)

add_executable(${PROJECT_NAME} main.cc)
