cmake_minimum_required(VERSION 3.6)
project(c-skeleton/build)

# This is the project root
set(PROJECT_SOURCE_DIR "${CMAKE_SOURCE_DIR}/build")

# This is for the C compiler
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Werror")

# Set CMAKE_Generator
set(CMAKE_GENERATOR "Unix Makefiles")
message("generator is set to ${CMAKE_GENERATOR}")

# Set Header folder and dataFolder
set(INCLUDE_DIR ../include)
set(INCLUDE_DATA_DIR ../include/data)
set(INCLUDE_SORTING_DIR ../include/sorting)
set(INCLUDE_SEARCH_DIR ../include/search)
set(INCLUDE_LINKEDLIST_DIR ../include/linkedList)
set(INCLUDE_DOUBLY_LINKED_LIST ../include/doublyLinkedList)
set(INCLUDE_STACK_LINKED_LIST ../include/stackLinkedList)
set(INCLUDE_CONVERTER ../include/converter)
set(INCLUDE_DATA_STRUCTURE ../include/dataStructure)

# Set link directories
# yaml
#link_directories(../link/libyaml-master)

#JSMN (JSON)
link_directories(../link/jsmn-master)

# This will bring the headers such as cJSON.h into the project
include_directories(${INCLUDE_DIR})
include_directories(${INCLUDE_DATA_DIR})
include_directories(${INCLUDE_SORTING_DIR})
include_directories(${INCLUDE_LINKEDLIST_DIR})
include_directories(${INCLUDE_DOUBLY_LINKED_LIST})
include_directories(${INCLUDE_STACK_LINKED_LIST})
include_directories(${INCLUDE_CONVERTER})
include_directories(${INCLUDE_DATA_STRUCTURE})

# Sets the program sources
set(testProject_SOURCES
    #../src/main.c
        #../src/test.c
    #../src/insertionsort.c
    #../src/selectionsort.c
    #../src/gettinginput.c
    #../src/triplesum.c
    #../src/arrayoperations.c
    #../src/loopoperations.c
    #../src/heapsort.c
        ../src/openAddressing.c
    #../src/bubblesort.c
    #../src/binarySearchTree.c
    #../src/yaml.c
    #../src/json.c
    #../src/client.c
    #../src/searchtree.c
	#../src/linkedList.c
    #../src/stackLinkedList.c
    #../src/converter.c
    #../src/binaryTree.c
    #../src/doublyLinkedList.c
    #../include/data/read.txt
    #../include/data/write.txt
	../include/dbg.h)

# link the libraries to the executable


# Make sources executable
add_executable(testProjectExecutable ${testProject_SOURCES})

# link yaml to executable
#target_link_libraries(testProjectExecutable yaml)

# link json to executable
target_link_libraries(testProjectExecutable jsmn)


