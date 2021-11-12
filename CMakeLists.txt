cmake_minimum_required(VERSION 3.0)
project(Lutin)

set(CMAKE_C_STANDARD 99)
include_directories("${CMAKE_SOURCE_DIR}/project")



add_executable(Lutin "project/entetes.h"
        "project/TAD.c" "project/main.c" "project/fonctions.c" "project/gestionGrille.c")

configure_file(${CMAKE_CURRENT_SOURCE_DIR}/project/grille1.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)
configure_file(${CMAKE_CURRENT_SOURCE_DIR}/project/deplacementsLutin_grille1.txt
        ${CMAKE_CURRENT_BINARY_DIR} COPYONLY)