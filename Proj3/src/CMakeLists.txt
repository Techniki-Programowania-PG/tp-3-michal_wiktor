

add_executable (proj3 "proj3.cpp" "proj3.h")
target_link_libraries(proj3 PUBLIC matplot)



if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET proj3 PROPERTY CXX_STANDARD 20)
endif()

