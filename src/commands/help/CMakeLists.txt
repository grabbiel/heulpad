file(GLOB_RECURSE SOURCES_ENABLE "*.cpp")

add_executable(heulpad-help ${SOURCES_ENABLE})

target_include_directories(heulpad-help
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(heulpad-help
  PRIVATE
)
