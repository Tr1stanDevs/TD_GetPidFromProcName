add_library(TD_GetPidFromProcName STATIC
${CMAKE_CURRENT_LIST_DIR}/TD_GetPidFromProcName.cpp
${CMAKE_CURRENT_LIST_DIR}/TD_GetPidFromProcName.h
)

target_include_directories(TD_GetPidFromProcName PUBLIC ${CMAKE_CURRENT_LIST_DIR})

