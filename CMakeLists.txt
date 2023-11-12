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
        Components/GUIComponent.h
        Components/EventHandler.h
        MultiText/MultiText.cpp
        Letter/Letter.cpp
        Letter/Letter.h
        MultiText/MultiTextIterator.cpp
        MultiText/MultiTextIterator.h
        Typing/Typing.h
        Typing/Typing.cpp
        TextInput/TextInput.cpp
        TextInput/TextInput.h
        History/HistoryNode.h
        History/History.cpp
        History/History.h
        Snapshot/Snapshot.cpp
        Snapshot/Snapshot.h
        Label/Label.cpp
        Label/Label.h
        States/States.cpp
        States/States.h
        States/statesEnum.h
        KeyShortcuts/KeyShortcuts.cpp
        KeyShortcuts/KeyShortcuts.h
        MouseEvents/MouseEvents.cpp
        MouseEvents/MouseEvents.h)
target_link_libraries(sfmlTemplate sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)