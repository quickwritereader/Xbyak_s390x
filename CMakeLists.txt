cmake_minimum_required (VERSION 3.8)

# Enable Hot Reload for MSVC compilers if supported.
if (POLICY CMP0141)
  cmake_policy(SET CMP0141 NEW)
  set(CMAKE_MSVC_DEBUG_INFORMATION_FORMAT "$<IF:$<AND:$<C_COMPILER_ID:MSVC>,$<CXX_COMPILER_ID:MSVC>>,$<$<CONFIG:Debug,RelWithDebInfo>:EditAndContinue>,$<$<CONFIG:Debug,RelWithDebInfo>:ProgramDatabase>>")
endif()

project ("xbyak_example")

add_executable (xbyak_example "xbyak_example.cpp" )
target_include_directories(xbyak_example PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/xbyak_s390x")

if (CMAKE_VERSION VERSION_GREATER 3.12)
  set_property(TARGET xbyak_example PROPERTY CXX_STANDARD 20)
endif()

