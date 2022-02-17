message(STATUS "Fetching SFML...")

# No need to build audio and network modules
set(SFML_BUILD_AUDIO FALSE) # Problem with openAL
set(SFML_BUILD_NETWORK FALSE)

FetchContent_MakeAvailable(sfml)