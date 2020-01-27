set (OPENGL_GL_PREFERENCE LEGACY)
find_package(OpenGL REQUIRED COMPONENTS OpenGL)
find_package(OpenCL REQUIRED)

if (OpenCL_FOUND)
    message("OpenCL_FOUND")
    include_directories(${OpenCL_INCLUDE_DIR})
endif (OpenCL_FOUND)
if (OPENGL_FOUND)
    message("OpenGL_FOUND")
    
endif (OPENGL_FOUND)

add_executable(pg
    main.cc
)
target_link_libraries(pg ${CONAN_LIBS})
target_link_libraries(pg ${OpenCL_LIBRARY})
target_link_libraries(pg ${OPENGL_gl_LIBRARY})