cmake_minimum_required(VERSION 3.23)
project(TrabalhoP)

set(CMAKE_CXX_STANDARD 20)

add_executable(TrabalhoP main.cpp Reserva.cpp Reserva.h Animais.cpp Animais.h Function.cpp header.h Alimentos.h Terminal.cpp Terminal.h )

target_link_libraries(${PROJECT_NAME} C:/PDCurses-3.9/wincon/pdcurses.a)
