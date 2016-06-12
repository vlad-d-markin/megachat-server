cmake_minimum_required(VERSION 2.8.11)

project( megachat-server )

include_directories(${PROJECT_SOURCE_DIR }/lib/include)
add_library(mega-networklib STATIC IMPORTED)
set_target_properties(mega-networklib PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR }/lib/libmegachat-networklib.a)

# mega-networklib

add_subdirectory(src)

