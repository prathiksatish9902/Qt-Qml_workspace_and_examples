# Additional clean files
cmake_minimum_required(VERSION 3.16)

if("${CONFIG}" STREQUAL "" OR "${CONFIG}" STREQUAL "Debug")
  file(REMOVE_RECURSE
  "CMakeFiles/appApplication3D_autogen.dir/AutogenUsed.txt"
  "CMakeFiles/appApplication3D_autogen.dir/ParseCache.txt"
  "appApplication3D_autogen"
  )
endif()
