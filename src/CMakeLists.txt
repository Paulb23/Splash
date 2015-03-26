FILE (GLOB_RECURSE project_SRCS *.cpp *.cxx *.cc *.C *.c *.h *.hpp)
SET (project_LIBS ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY} ${SDL2TTF_LIBRARY} ${SDL2MIXER_LIBRARY} ${GLEW_LIBRARY} ${LUA_LIBRARIES} m)
SET (project_BIN ${PROJECT_NAME})

add_library(Splash SHARED ${project_SRCS})
add_library(Splash_static STATIC ${project_SRCS})

TARGET_LINK_LIBRARIES(Splash ${project_LIBS})
TARGET_LINK_LIBRARIES(Splash_static ${project_LIBS})

if (WIN32)
add_custom_command(TARGET Splash POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy ${MAINFOLDER}/lib/${CMAKE_SYSTEM_NAME}/libSplash.dll  ${MAINFOLDER}/bin) 
endif(WIN32)