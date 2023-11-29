cmake_minimum_required(VERSION 3.26)
project(sfmlTemplate)

set(CMAKE_CXX_STANDARD 17)

add_executable(sfmlTemplate main.cpp
        App.cpp
        App.h
        Input/Input.cpp
        Input/Input.h
        Layout/Layout.cpp
        Layout/Layout.h
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
        MouseEvents/MouseEvents.h
        Item/Item.cpp
        Item/Item.h
        Item/ItemList.cpp
        Item/ItemList.h
        Helper/HelperFunctions.cpp
        Helper/HelperFunctions.h
        Dropdown/Dropdown.cpp
        Dropdown/Dropdown.h
        SoundFX/SoundFX.cpp
        SoundFX/SoundFX.h
        Item/ItemStruct.h
        Layout/MainScreen/MainScreen.cpp
        Layout/MainScreen/MainScreen.h
        Layout/PokemonScreen/PokemonScreen.cpp
        Layout/PokemonScreen/PokemonScreen.h
        Layout/SearchInput/SearchInput.cpp
        Layout/SearchInput/SearchInput.h
        Layout/SideMenu/SideMenu.cpp
        Layout/SideMenu/SideMenu.h
        Images/Images.cpp
        Images/Images.h
        AnimatedSprite/AnimatedSprite.cpp
        AnimatedSprite/AnimatedSprite.h
        Layout/MainScreen/Views/GridView.cpp
        Layout/MainScreen/Views/GridView.h
        Button/GridButton.cpp
        Button/GridButton.h
        Button/TileButton.cpp
        Button/TileButton.h
        Layout/Logo/Logo.cpp
        Layout/Logo/Logo.h
        Components/ButtonInterface.h
        Layout/MainScreen/MainScreenButton/MainScreenButton.cpp
        Layout/MainScreen/MainScreenButton/MainScreenButton.h
        StateManager/PokemonManager.cpp
        StateManager/PokemonManager.h
        Data/PokemonStruct.h
        Data/PokemonList.cpp
        Data/PokemonList.h
        SFMLPokedex.cpp
        SFMLPokedex.h)
target_link_libraries(sfmlTemplate sfml-graphics sfml-audio)

find_package(SFML 2.5 COMPONENTS graphics audio REQUIRED)