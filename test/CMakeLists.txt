enable_testing()
INCLUDE(CTest)

LINK_DIRECTORIES(${MAINFOLDER}/lib)
SET (test_LIBS ${SDL2_LIBRARY} ${SDL2IMAGE_LIBRARY} ${SDL2TTF_LIBRARY} ${SDL2MIXER_LIBRARY} ${PROJECT_NAME} m)

SET( test_SRCS
	SplashTest
	SplashWindowTest
)

foreach(next_ITEM ${test_SRCS})
   ADD_EXECUTABLE(${next_ITEM} ${next_ITEM}.c)
   TARGET_LINK_LIBRARIES(${next_ITEM} ${test_LIBS})
   add_test(NAME ${next_ITEM} COMMAND ${next_ITEM})
endforeach(next_ITEM ${test_SRCS})