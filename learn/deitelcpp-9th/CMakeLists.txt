cmake_minimum_required (VERSION 3.20)
project (deitelcpp-9th)

file(GLOB SUBDIRS  "*")

# adds chapter directory paths with CMakeLists.txt file.
foreach(SUBDIR ${SUBDIRS})
  if(IS_DIRECTORY ${SUBDIR} AND EXISTS ${SUBDIR}/CMakeLists.txt)
    add_subdirectory(${SUBDIR})
  endif()
endforeach()
