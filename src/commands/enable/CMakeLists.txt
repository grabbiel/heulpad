file(GLOB_RECURSE SOURCES_ENABLE "*.cpp")

add_executable(${PROJECT_NAME} ${SOURCES_ENABLE})

target_include_directories(heulpad-enable
  PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}
)

target_link_libraries(heulpad-enable
  PRIVATE
)
