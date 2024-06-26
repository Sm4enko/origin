cmake_minimum_required(VERSION 3.20)

project(Table)

set(BOOST_ROOT "C:/Boost")
set(Boost_USE_STATIC_LIBS ON)
set(OPENSSL_ROOT_DIR "C:/Program Files/OpenSSL-Win64")
set(OPENSSL_USE_STATIC_LIBS TRUE)
set(Boost_USE_STATIC_LIBS ON)
find_package(Boost REQUIRED COMPONENTS system locale)

set(PostgreSQL_ADDITIONAL_VERSIONS "16")

add_subdirectory("D:/Finder/libpqxx-7.9.1" libpqxx-build)
set(OPENSSL_INCLUDE_DIR "C:/Program Files/OpenSSL-Win64/include")
set(OPENSSL_CRYPTO_LIBRARY "C:/Program Files/OpenSSL-Win64/lib/VC/x64/MTd/libcrypto.lib")
set(OPENSSL_SSL_LIBRARY "C:/Program Files/OpenSSL-Win64/lib/VC/x64/MTd/libssl.lib")

add_executable(Spider main.cpp Spider.cpp Table.cpp)

target_compile_features(Spider PRIVATE cxx_std_20)

target_link_libraries(Spider PRIVATE Boost::system Boost::locale ${OPENSSL_SSL_LIBRARY} ${OPENSSL_CRYPTO_LIBRARY} pqxx)
target_link_libraries(Spider PRIVATE Boost::system)

include_directories(${Boost_INCLUDE_DIRS})
include_directories(${OPENSSL_INCLUDE_DIR})
