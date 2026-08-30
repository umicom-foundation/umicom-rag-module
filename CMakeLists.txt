#-----------------------------------------------------------------------------
# Umicom RAG Module
# File: CMakeLists.txt
#
# PURPOSE:
#   Build a thin C23 product composition over Framework-owned application
#   experience, runtime and workbench contracts.
#
# AUTHOR AND ORGANISATION:
#   Sammy Hegab
#   Umicom Foundation
#
# LICENCE:
#   MIT
#-----------------------------------------------------------------------------
cmake_minimum_required(VERSION 3.24)

project(
    RagModule
    VERSION 0.1.0
    DESCRIPTION "Thin Umicom RAG composition over Umicom Framework"
    LANGUAGES C
)

set(CMAKE_C_STANDARD 23)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

option(UMICOM_RAG_BUILD_CONSOLE
       "Build the native Umicom RAG verification console"
       ON)

include(CTest)
include(GNUInstallDirs)

if(NOT TARGET Umicom::Framework)
    find_package(UmicomFramework CONFIG REQUIRED)
endif()

if(NOT TARGET Umicom::application)
    message(FATAL_ERROR
        "Umicom RAG requires Framework target Umicom::application")
endif()

if(NOT COMMAND umicom_apply_warnings)
    function(umicom_apply_warnings target)
        if(MSVC)
            target_compile_options(${target} PRIVATE /W4)
        else()
            target_compile_options(${target} PRIVATE
                -Wall -Wextra -Wpedantic -Wconversion -Wshadow)
        endif()
    endfunction()
endif()

if(NOT COMMAND umicom_apply_sanitizers)
    function(umicom_apply_sanitizers target)
    endfunction()
endif()

add_library(umicom_rag_module STATIC
    src/application.c
    src/workspace.c
)
add_library(Umicom::rag_module ALIAS umicom_rag_module)

target_include_directories(umicom_rag_module PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:${CMAKE_INSTALL_INCLUDEDIR}>
)
target_link_libraries(umicom_rag_module PUBLIC
    Umicom::Framework
    Umicom::application
)
umicom_apply_warnings(umicom_rag_module)
umicom_apply_sanitizers(umicom_rag_module)

include(
    "${CMAKE_CURRENT_SOURCE_DIR}/../../framework/cmake/UmicomThinApplicationRuntime.cmake")
umicom_extend_thin_application_runtime(
    NAME "rag"
    TARGET "umicom_rag_module")

if(UMICOM_RAG_BUILD_CONSOLE)
    add_executable(umicom-rag-console
        src/console/main.c)
    target_link_libraries(umicom-rag-console PRIVATE Umicom::rag_module)
    umicom_apply_warnings(umicom-rag-console)
    umicom_apply_sanitizers(umicom-rag-console)
endif()

if(BUILD_TESTING)
    add_executable(rag-application-test
        tests/test_application.c)
    target_link_libraries(rag-application-test PRIVATE Umicom::rag_module)
    umicom_apply_warnings(rag-application-test)
    umicom_apply_sanitizers(rag-application-test)
    add_test(NAME rag.module.application
             COMMAND rag-application-test)

    add_executable(rag-workspace-test
        tests/test_workspace.c)
    target_link_libraries(rag-workspace-test PRIVATE Umicom::rag_module)
    umicom_apply_warnings(rag-workspace-test)
    umicom_apply_sanitizers(rag-workspace-test)
    add_test(NAME rag.module.workspace
             COMMAND rag-workspace-test)
endif()

install(TARGETS umicom_rag_module
    ARCHIVE DESTINATION ${CMAKE_INSTALL_LIBDIR}
    LIBRARY DESTINATION ${CMAKE_INSTALL_LIBDIR}
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
if(TARGET umicom-rag-console)
    install(TARGETS umicom-rag-console
        RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR})
endif()
install(DIRECTORY include/
    DESTINATION ${CMAKE_INSTALL_INCLUDEDIR})
install(FILES application.umicom.yaml
    DESTINATION ${CMAKE_INSTALL_DATADIR}/umicom/applications/rag)
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/LICENSE")
    install(FILES LICENSE
        DESTINATION ${CMAKE_INSTALL_DATADIR}/licenses/rag)
endif()

message(STATUS "Umicom RAG Module version: ${PROJECT_VERSION}")
message(STATUS "Umicom RAG uses Framework-owned application experience")

include(
    "${CMAKE_CURRENT_SOURCE_DIR}/../../framework/cmake/UmicomApplicationProductisationContribution.cmake")
umicom_add_application_productisation_contribution(
    NAME "rag"
    TARGET umicom_rag_productisation
    SOURCE "src/productisation_contribution.c"
    TEST_SOURCE "tests/test_productisation_contribution.c")
