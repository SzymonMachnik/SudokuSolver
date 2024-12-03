cmake_minimum_required(VERSION 3.10)

project(SudokuSolver)

# Określenie standardu C++
set(CMAKE_CXX_STANDARD 11)

# Dodanie ścieżek do nagłówków
include_directories(imgui)

# Dodanie źródeł
file(GLOB SOURCES
    main.cpp
    sudokuHelperFunctions/sudoku.cpp
    imgui/*.cpp
)

# Skopiowanie czcionki do katalogu roboczego (katalogu build/Debug)
file(COPY ${CMAKE_SOURCE_DIR}/fonts/Roboto-Medium.ttf DESTINATION ${CMAKE_BINARY_DIR}/Debug/fonts)

# Określenie pliku wykonywalnego
add_executable(SudokuSolver ${SOURCES})

# Linkowanie z wymaganymi bibliotekami
target_link_libraries(SudokuSolver
    d3d9
    dwmapi
    gdi32
)