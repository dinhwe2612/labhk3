cmake_minimum_required(VERSION 2.6)
project(myproject)

# Set version information in a config.h file
set(myproject_VERSION_MAJOR 1)
set(myproject_VERSION_MINOR 0)
configure_file(
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )
include_directories("${PROJECT_BINARY_DIR}")

# Define sources and executable
set(EXECUTABLE_NAME "myproject")
add_executable(${EXECUTABLE_NAME} main.cpp)
include_directories(Function)
add_subdirectory(SFML-2.5.1)
add_subdirectory(Function)
add_subdirectory(UI)

target_include_directories(${PROJECT_NAME} 
    PUBLIC SFML-2.5.1
    PUBLIC UI
    PUBLIC Function
)

link_directories(${PROJECT_NAME} 
    PRIVATE SFML-2.5.1/include/SFML
    PRIVATE Function
    PRIVATE UI
)

target_link_libraries(${PROJECT_NAME} 
    SFML_LIBRARIES
    Func
    UI
)

# Detect and add SFML
set(CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/cmake_modules" ${CMAKE_MODULE_PATH})
find_package(SFML 2.5.1 COMPONENTS system window graphics audio network REQUIRED)
target_link_libraries(${EXECUTABLE_NAME} ${SFML_LIBRARIES})


# Install target
install(TARGETS ${EXECUTABLE_NAME} DESTINATION bin)


# CPack packaging
include(InstallRequiredSystemLibraries)
# set(CPACK_RESOURCE_FILE_LICENSE "${CMAKE_SOURCE_DIR}/COPYING")
set(CPACK_PACKAGE_VERSION_MAJOR "${myproject_VERSION_MAJOR}")
set(CPACK_PACKAGE_VERSION_MINOR "${myproject_VERSION_MINOR}")
include(CPack)