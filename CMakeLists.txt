cmake_minimum_required(VERSION 3.0)
project(Lutin)

set(CMAKE_C_STANDARD 99)
include_directories("${CMAKE_SOURCE_DIR}/project")



add_executable(Lutin "project/include/entetes.h"
        "project/TAD.c" "project/main.c" "project/fonctions.c" "project/gestionGrille.c" project/TAD.c project/fonctions.c)

