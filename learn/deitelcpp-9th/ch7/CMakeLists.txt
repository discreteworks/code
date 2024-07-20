# create executable for each file in directory

file( GLOB SRCS *.cpp *.h )

foreach(SRC ${SRCS})
  get_filename_component(BIN ${SRC} NAME)
  add_executable (${BIN} ${SRC})
  message(STATUS "SRC=${SRC}")
endforeach()

