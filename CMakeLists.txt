cmake_minimum_required(VERSION 3.0)
project(Numkinch)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} "${PROJECT_SOURCE_DIR}/cmake-build-debug")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}")

if (APPLE)
    set(CMAKE_CXX_FLAGS "-framework SDL2")
    set(SDL2_INCLUDE_DIR /Library/Frameworks/SDL2.framework/Headers)
    set(SDL2_IMAGE_LIBRARY /Library/Frameworks/SDL2.framework)

    set(SDL2_IMAGE_INCLUDE_DIR /Library/Frameworks/SDL2_image.framework/Headers)
    set(SDL2_IMAGE_LIBRARY /Library/Frameworks/SDL2_image.framework)

    set(SDL2_TTF_INCLUDE_DIR /Library/Frameworks/SDL2_ttf.framework/Headers)
    set(SDL2_TTF_LIBRARY /Library/Frameworks/SDL2_ttf.framework)
else(APPLE)
    find_package(SDL2 REQUIRED)
    find_package(SDL2_image REQUIRED)
    find_package(SDL2_ttf REQUIRED)
endif (APPLE)

set(SOURCE_FILES Main.cpp Core/GameEngine.cpp Core/GameEngine.h Core/GameState.h Core/MainMenuState.cpp
        Core/MainMenuState.h Core/GameStateManager.cpp Core/GameStateManager.h GUI/Element.h GUI/Element.cpp
        GUI/Button.cpp GUI/Button.h GUI/Background.cpp GUI/Background.h Core/ChooseCharactersState.cpp
        Core/ChooseCharactersState.h PlayerLogic/CharacterFactory.cpp PlayerLogic/CharacterFactory.h
        PlayerLogic/Race.cpp PlayerLogic/Race.h PlayerLogic/Class.cpp PlayerLogic/Class.h PlayerLogic/Elf.cpp
        PlayerLogic/Elf.h PlayerLogic/Skill.cpp PlayerLogic/Skill.h PlayerLogic/Dwarf.cpp PlayerLogic/Dwarf.h
        PlayerLogic/Assassin.cpp PlayerLogic/Assassin.h PlayerLogic/Paladin.cpp PlayerLogic/Paladin.h Core/PlayState.cpp
        Core/PlayState.h GUI/Tile.cpp GUI/Tile.h GUI/GUIConstants.h PlayerLogic/Races.h PlayerLogic/Classes.h
        PlayerLogic/PlayerLogicConstants.h GUI/IHandleable.h
        PlayerLogic/Skills.h PlayerLogic/Barbarian.cpp PlayerLogic/Barbarian.h
        PlayerLogic/Human.cpp PlayerLogic/Human.h PlayerLogic/Thief.cpp PlayerLogic/Thief.h PlayerLogic/Priest.cpp
        PlayerLogic/Priest.h GUI/Text.cpp GUI/Text.h GUI/CharacterCard.cpp GUI/CharacterCard.h PlayerLogic/Names.h
        GUI/StatCard.cpp GUI/StatCard.h WorldLogic/Dungeon.cpp WorldLogic/Dungeon.h WorldLogic/Room.cpp
        WorldLogic/Room.h WorldLogic/Card.cpp WorldLogic/Card.h WorldLogic/Entities.h WorldLogic/Monster.cpp
        WorldLogic/Monster.h WorldLogic/Trap.cpp WorldLogic/Trap.h WorldLogic/Treasure.cpp WorldLogic/Trap.h
        WorldLogic/BigCard.cpp WorldLogic/BigCard.h GUI/IDisplayable.h)

add_executable(Numkinch ${SOURCE_FILES})

include_directories(${SDL2_INCLUDE_DIR} ${SDL2_IMAGE_INCLUDE_DIR} ${SDL2_TTF_INCLUDE_DIR})
target_link_libraries(Numkinch ${SDL2_LIBRARY} ${SDL2_IMAGE_LIBRARY} ${SDL2_TTF_LIBRARY})