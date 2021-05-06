project(cg)
cmake_minimum_required(VERSION 2.4)

SET(VRLIB_INCLUDE_DIR /usr/include)
SET(VRLIB_LIBRARY /usr/lib/libvrlib.a)

add_executable(cg impl/rendervisitor.cpp impl/visitor.cpp impl/texture.cpp impl/material.cpp impl/reader.cpp impl/scenegraph.cpp impl/color.cpp impl/geometry.cpp impl/group.cpp impl/transform.cpp impl/node.cpp impl/mainfile.cpp)
find_package(OpenGL REQUIRED)
find_package(GLUT REQUIRED)
find_package(PNG REQUIRED)
find_package(ZLIB REQUIRED)

include_directories( ${OPENGL_INCLUDE_DIRS}  ${GLUT_INCLUDE_DIRS} ${PNG_INCLUDE_DIR} ${ZLIB_INCLUDE_DIR} ${VRLIB_INCLUDE_DIR} )

target_link_libraries(cg ${OPENGL_LIBRARIES} ${GLUT_LIBRARY} ${PNG_LIBRARY} ${ZLIB_DIR} ${VRLIB_LIBRARY} )
install(TARGETS cg RUNTIME DESTINATION bin)

add_subdirectory(headers)
add_subdirectory(impl)