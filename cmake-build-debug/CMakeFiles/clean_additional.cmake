# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/flood_it_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/flood_it_autogen.dir/ParseCache.txt"
  "CMakeFiles/test_console_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/test_console_autogen.dir/ParseCache.txt"
  "flood_it_autogen"
  "test_console_autogen"
  )
endif()
