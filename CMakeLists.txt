cmake_minimum_required(VERSION 3.0)
project(Lutin C)

set(CMAKE_C_STANDARD 99)

add_executable(Lutin "project/entetes.c" "project/entetes.h" "project/entetesGestionGrille.c"
        "project/entetesGestionGrille.h"
         "project/TAD.c" "project/main.c")
include_directories(Lutin project/)
link_directories(Lutin project/)

target_link_libraries(Lutin project/ m)