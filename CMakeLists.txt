set(CMAKE_CXX_STANDARD 17)
find_package(Curses REQUIRED)
add_executable(game.out main.cpp Field/Field.cpp Field/Cell.cpp Items/Flask.cpp Inventory.cpp Items/Item.cpp Player.cpp Items/PowerPotion.cpp  MovementManager.cpp Events/DefaultEvent.cpp Events/TreatEvent.cpp Events/TrapEvent.cpp Events/TeleportEvent.cpp Field/FieldCreator.cpp Game/GameManager.cpp Input/Input.cpp)

target_include_directories(game.out PRIVATE ${CURSES_INCLUDE_DIR})
target_link_libraries(game.out PRIVATE ${CURSES_LIBRARIES})