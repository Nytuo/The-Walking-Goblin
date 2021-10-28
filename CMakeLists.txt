cmake_minimum_required(VERSION 3.0)
project(Lutin C)

set(CMAKE_C_STANDARD 99)

include_directories(Lutin project)
add_executable(Lutin "project/entetes.c" "project/entetes.h" "project/entetesGestionGrille.c" "project/entetesGestionGrille.h"
        project/gestionGrille.a "project/TAD.c" "project/main.c")