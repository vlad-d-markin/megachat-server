aux_source_directory(. SRC_LIST)

include_directories(${PROJECT_SOURCE_DIR}/lib/include ${CMAKE_CURRENT_SOURCE_DIR}/headers)
add_library(mega-networklib STATIC IMPORTED)
set_target_properties(mega-networklib PROPERTIES IMPORTED_LOCATION ${PROJECT_SOURCE_DIR}/lib/libmegachat-networklib.a)

file(GLOB_RECURSE LibFiles "./headers/*.h")
add_custom_target(app_headers SOURCES ${LibFiles})

add_executable(${PROJECT_NAME} ${SRC_LIST} ${LibFiles})
target_link_libraries(${PROJECT_NAME} mega-networklib)
