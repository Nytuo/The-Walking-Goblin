cmake_minimum_required(VERSION 3.0)
project(Lutin)

set(CMAKE_C_STANDARD 99)
include_directories("${CMAKE_SOURCE_DIR}/project")


add_library(hagride STATIC IMPORTED)
set_target_properties(hagride PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/project/lib/gestionGrille.a" INTERFACE_INCLUDE_DIRECTORY "${CMAKE_SOURCE_DIR}/project/include/")

add_executable(Lutin "project/include/gestionGrille.h"
        "project/TAD.c" "project/main.c" "project/fonctions.c" "project/gestionGrille.c")

target_link_libraries(Lutin hagride)