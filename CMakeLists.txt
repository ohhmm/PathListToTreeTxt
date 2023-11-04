cmake_minimum_required (VERSION 3.6)

enable_language(CXX)
set (CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

option(OPENMIND_MATH_USE_LEVELDB_CACHE "Use Google LevelDB library to cache solutions" OFF)
option(OPENMIND_BUILD_TESTS "Enable OpenMind tests" OFF)

# Find some Git
find_package(Git QUIET)
if(NOT GIT_EXECUTABLE)
    find_program(GIT_EXECUTABLE git PATHS
        "$ENV{ProgramFiles}/Microsoft Visual Studio/*/*/Common7/IDE/CommonExtensions/Microsoft/TeamFoundation/Team Explorer/Git/cmd/"
        )
    find_package(Git)
endif()

include(FetchContent)
FetchContent_Declare(openmind 
	GIT_REPOSITORY https://github.com/ohhmm/openmind.git
	GIT_TAG main
	)
FetchContent_MakeAvailable(openmind)

exe()
