cmake_minimum_required(VERSION 3.0)
project(Lutin)

set(CMAKE_C_STANDARD 99)
include_directories("${CMAKE_SOURCE_DIR}/project")


add_library(hagride STATIC IMPORTED)
set_target_properties(hagride PROPERTIES IMPORTED_LOCATION "${CMAKE_SOURCE_DIR}/project/lib/gestionGrille.a" INTERFACE_INCLUDE_DIRECTORY "${CMAKE_SOURCE_DIR}/project/include/")

add_executable(Lutin "project/entetes.c" "project/include/entetes.h" "project/entetesGestionGrille.c"
        "project/include/entetesGestionGrille.h"
        "project/TAD.c" "project/main.c")

target_link_libraries(Lutin hagride)