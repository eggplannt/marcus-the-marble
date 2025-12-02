project(src)


set(SOURCES 
    main.cpp
)

add_executable(marcus ${SOURCES})
set_target_properties(marcus PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR})
target_compile_definitions(marcus PUBLIC
      $<$<CONFIG:Debug>:_DEBUG>
      $<$<CONFIG:RelWithDebInfo>:_DEBUG>
      $<$<CONFIG:Release>:_RELEASE>
      $<$<CONFIG:MinSizeRel>:_RELEASE>
)
