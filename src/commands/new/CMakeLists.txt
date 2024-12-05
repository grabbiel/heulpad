file(GLOB_RECURSE SOURCES_NEW "*.cpp")

add_executable(heulpad-new ${SOURCES_NEW})

target_include_directories(heulpad-new
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(heulpad-new
  PRIVATE
)
