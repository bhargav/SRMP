cmake_minimum_required(VERSION 2.8)
project(srmp-jni)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})

include_directories(src/main/cpp)

set(SRMP_JNI_SOURCES src/main/cpp/Options.cpp
        src/main/cpp/Energy.cpp
        src/main/cpp/srmp_SRMPJni.h)

add_library(srmp-jni SHARED ${SRMP_JNI_SOURCES})
target_link_libraries(srmp-jni ${JNI_LIBRARIES} srmp)

if(${UNIX})
    set(CMAKE_CXX_FLAGS "-fPIC")
    set_target_properties(srmp-jni PROPERTIES CMAKE_SHARED_LINKER_FLAGS "-fPIC")
elseif(${WINDOWS})
    set(CMAKE_CXX_FLAGS "/MP /EHsc")
endif(${UNIX})

# install
if(NOT DEFINED SRMP_INSTALL_LIB_DESTINATION)
    set(SRMP_INSTALL_LIB_DESTINATION lib)
endif(NOT DEFINED SRMP_INSTALL_LIB_DESTINATION)
if(NOT DEFINED SRMP_INSTALL_HEADER_DESTINATION)
    set(SRMP_INSTALL_HEADER_DESTINATION include)
endif(NOT DEFINED SRMP_INSTALL_HEADER_DESTINATION)
install(TARGETS srmp-jni DESTINATION ${SRMP_INSTALL_LIB_DESTINATION})
install(DIRECTORY src/main/cpp DESTINATION ${SRMP_INSTALL_HEADER_DESTINATION})
