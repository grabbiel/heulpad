file(GLOB_RECURSE SOURCES_ENABLE "*.cpp")

add_executable(heulpad-enable ${SOURCES_ENABLE})

target_include_directories(heulpad-enable
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(heulpad-enable
  PRIVATE
)
