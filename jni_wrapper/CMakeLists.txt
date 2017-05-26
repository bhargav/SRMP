cmake_minimum_required(VERSION 2.8)

project(srmp-jni)

find_package(JNI REQUIRED)
include_directories(${JNI_INCLUDE_DIRS})
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../JniHelpers/src/main/cpp)

set(SRMP_JNI_SOURCES src/main/cpp/HelloJNI.cpp)

add_library(srmp-jni SHARED ${SRMP_JNI_SOURCES})

target_include_directories (srmp-jni PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/include)

target_link_libraries(srmp-jni srmp)
target_link_libraries(srmp-jni JniHelpers)

# build example
#add_executable (srmpJniTest hello.cpp)
# link srmp library
#target_link_libraries (srmpJniTest LINK_PUBLIC srmp-jni)

if(${UNIX})
    set(CMAKE_CXX_FLAGS "-fPIC")
    set_target_properties(srmp-jni PROPERTIES CMAKE_SHARED_LINKER_FLAGS "-fPIC")
elseif(${WINDOWS})
    set(CMAKE_CXX_FLAGS "/MP /EHsc")
endif(${UNIX})
