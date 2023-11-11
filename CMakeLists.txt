cmake_minimum_required(VERSION 3.26)
project(sfmlTemplate)

set(CMAKE_CXX_STANDARD 17)

add_executable(sfmlTemplate main.cpp
        App.cpp
        App.h
        Input/Input.cpp
        Input/Input.h
        Screen.cpp
        Screen.h
        Font/Font.cpp
        Font/Font.h
        Components/Component.h
        Components/EventHandable.h
        Components/Updateable.h
        MultiText/MultiText.cpp
        Letter/Letter.cpp
        Letter/Letter.h
        MultiText/MultiTextIterator.cpp
        MultiText/MultiTextIterator.h
        Typing/Typing.h
        Typing/Typing.cpp
        TextInput/TextInput.cpp
        TextInput/TextInput.h)
target_link_libraries(sfmlTemplate sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)