# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles\\SPA4_autogen.dir\\AutogenUsed.txt"
  "CMakeFiles\\SPA4_autogen.dir\\ParseCache.txt"
  "SPA4_autogen"
  )
endif()
