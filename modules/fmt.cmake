if(NOT TARGET fmt)

  # Module includes
  include_directories("fmt")

  # Module library
  file(GLOB SOURCE_FILES "fmt/fmt/*.cc")
  if(CMAKE_MAKE_PROGRAM MATCHES "(MSBuild|devenv|msdev|nmake)")
    # C4127: conditional expression is constant
    # C4702: unreachable code
    set_source_files_properties(${SOURCE_FILES} PROPERTIES COMPILE_FLAGS "${COMMON_COMPILE_FLAGS} /wd4127 /wd4702")
  else()
    set_source_files_properties(${SOURCE_FILES} PROPERTIES COMPILE_FLAGS "${COMMON_COMPILE_FLAGS}")
  endif()
  add_library(fmt ${SOURCE_FILES} ${ASSEMBLER_FILES})
  target_link_libraries(fmt)

  # Module folder
  set_target_properties(fmt PROPERTIES FOLDER modules/fmt)

endif()