# ketsup@asura\matthew

set(SOURCES
    modules/contact.cpp
    modules/contact_manager.cpp
    modules/file_io.cpp
    modules/ui.cpp
)

add_executable(termContacts main.cpp ${SOURCES})

target_include_directories(termContacts PRIVATE ${CMAKE_SOURCE_DIR}/include)

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}../bin)
