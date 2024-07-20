# create executable for each file in directory

file( GLOB SRCS *.cpp SRC)

message (status ${PROJECT_SOURCE_DIR})

foreach(SRC ${SRCS})
  get_filename_component(FILENAME ${SRC} NAME)
  string(REGEX MATCH "^(.*)\\.[^.]*$" dummy ${FILENAME})
  set(BIN ${CMAKE_MATCH_1})
  add_executable (${BIN} ${SRC})
  message(STATUS "SRC=${SRC}")
endforeach()

