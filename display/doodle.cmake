# This will be called from the top-level doodle CMakeLists.txt
# it will be called using "include" and will be provided:
# PLATFORM_NAME
# PROJECT_NAME
# PROJECT_CMAKE_DIR
# PROJECT_SOURCE_DIR

function(build_project)
    # link blank.c to PROJECT_NAME executable, which has already been defined
    target_sources(${PROJECT_NAME} PRIVATE ${DOODLE_PROJECT_ROOT_DIR}/src/app.c)
    message(STATUS "Linking doodle library")
    set(CMAKE_BUILD_TYPE Debug) # set the build type to Debug
endfunction()