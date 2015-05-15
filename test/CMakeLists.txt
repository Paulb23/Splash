enable_testing()
INCLUDE(CTest)

LINK_DIRECTORIES(${MAINFOLDER}/lib)

set(OPENGL "")
if(WIN32)
	set(OPENGL "opengl32")
endif(WIN32)

SET (test_LIBS ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY} ${SDL2TTF_LIBRARY} ${SDL2MIXER_LIBRARY} ${LUA_LIBRARIES} ${GLEW_LIBRARY} ${OPENGL} ${PROJECT_NAME} m)

SET( test_SRCS
	SplashTest
	SplashWindowTest
	SplashListTest
	SplashHashmapTest
	SplashStateTest
	SplashRendererTest
	SplashCamreaTest
	SplashTextureTest
)

foreach(next_ITEM ${test_SRCS})
   ADD_EXECUTABLE(${next_ITEM} ${next_ITEM}.c)
   TARGET_LINK_LIBRARIES(${next_ITEM} ${test_LIBS})
   add_test(NAME ${next_ITEM} COMMAND ${next_ITEM})
endforeach(next_ITEM ${test_SRCS})