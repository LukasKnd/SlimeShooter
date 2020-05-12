
	

	
#Kompiliatorius
CXX = g++
#Parametrai (flags) kompiliavimui
CXXFLAGS = -std=c++14 -DSFML_STATIC -I ./deps/SFML/include -L ./deps/SFML/lib -lsfml-graphics-s -lsfml-window-s -lsfml-system-s -lopengl32 -lwinmm -lgdi32 -lfreetype 


run : Demo.exe
	Demo
	
test : Test.exe
	Test.exe 
	
rebuild : clean build

build : Demo.exe Test.exe

debug : CXXFLAGS += -DDEBUG
debug : clean Test.exe
	Test


	
#executables
Demo.exe : src/main.cpp GameEngine.o Menu.o MenuState.o PlayState.o PauseMenuState.o Anim.o AssetManager.o Entity.o EntityManager.o Map.o SlimeSpawnManager.o Sprite.o ColliderComponent.o GunComponent.o KeyboardControlComponent.o SlimeControlComponent.o SlimeSpawnControlComponent.o SpriteComponent.o TileComponent.o TransformComponent.o
	$(CXX) src/main.cpp GameEngine.o Menu.o MenuState.o PlayState.o PauseMenuState.o Anim.o AssetManager.o Entity.o EntityManager.o Map.o SlimeSpawnManager.o Sprite.o ColliderComponent.o GunComponent.o KeyboardControlComponent.o SlimeControlComponent.o SlimeSpawnControlComponent.o SpriteComponent.o TileComponent.o TransformComponent.o $(CXXFLAGS) -o Demo.exe

Test.exe : src/test.cpp GameEngine.o Menu.o MenuState.o PlayState.o PauseMenuState.o Anim.o AssetManager.o Entity.o EntityManager.o Map.o SlimeSpawnManager.o Sprite.o ColliderComponent.o GunComponent.o KeyboardControlComponent.o SlimeControlComponent.o SlimeSpawnControlComponent.o SpriteComponent.o TileComponent.o TransformComponent.o
	$(CXX) src/test.cpp GameEngine.o Menu.o MenuState.o PlayState.o PauseMenuState.o Anim.o AssetManager.o Entity.o EntityManager.o Map.o SlimeSpawnManager.o Sprite.o ColliderComponent.o GunComponent.o KeyboardControlComponent.o SlimeControlComponent.o SlimeSpawnControlComponent.o SpriteComponent.o TileComponent.o TransformComponent.o $(CXXFLAGS) -o Test.exe

#object files for the classes	
PlayState.o: src/PlayState.cpp
	$(CXX) -c src/PlayState.cpp $(CXXFLAGS)
PauseMenuState.o: src/PauseMenuState.cpp
	$(CXX) -c src/PauseMenuState.cpp $(CXXFLAGS)
MenuState.o: src/MenuState.cpp
	$(CXX) -c src/MenuState.cpp $(CXXFLAGS)
Menu.o: src/Menu.cpp
	$(CXX) -c src/Menu.cpp $(CXXFLAGS)
GameEngine.o: src/GameEngine.cpp
	$(CXX) -c src/GameEngine.cpp $(CXXFLAGS)
Anim.o: src/Anim.cpp
	$(CXX) -c src/Anim.cpp $(CXXFLAGS)
AssetManager.o: src/AssetManager.cpp
	$(CXX) -c src/AssetManager.cpp $(CXXFLAGS)
Entity.o: src/Entity.cpp
	$(CXX) -c src/Entity.cpp $(CXXFLAGS)
EntityManager.o: src/EntityManager.cpp
	$(CXX) -c src/EntityManager.cpp $(CXXFLAGS)
Map.o: src/Map.cpp
	$(CXX) -c src/Map.cpp $(CXXFLAGS)
SlimeSpawnManager.o: src/SlimeSpawnManager.cpp
	$(CXX) -c src/SlimeSpawnManager.cpp $(CXXFLAGS)
Sprite.o: src/Sprite.cpp
	$(CXX) -c src/Sprite.cpp $(CXXFLAGS)
ColliderComponent.o: src/Components/ColliderComponent.cpp
	$(CXX) -c src/Components/ColliderComponent.cpp $(CXXFLAGS)
GunComponent.o: src/Components/GunComponent.cpp
	$(CXX) -c src/Components/GunComponent.cpp $(CXXFLAGS)
KeyboardControlComponent.o: src/Components/KeyboardControlComponent.cpp
	$(CXX) -c src/Components/KeyboardControlComponent.cpp $(CXXFLAGS)
SlimeControlComponent.o: src/Components/SlimeControlComponent.cpp
	$(CXX) -c src/Components/SlimeControlComponent.cpp $(CXXFLAGS)
SlimeSpawnControlComponent.o: src/Components/SlimeSpawnControlComponent.cpp
	$(CXX) -c src/Components/SlimeSpawnControlComponent.cpp $(CXXFLAGS)
SpriteComponent.o: src/Components/SpriteComponent.cpp
	$(CXX) -c src/Components/SpriteComponent.cpp $(CXXFLAGS)
TileComponent.o: src/Components/TileComponent.cpp
	$(CXX) -c src/Components/TileComponent.cpp $(CXXFLAGS)
TransformComponent.o: src/Components/TransformComponent.cpp
	$(CXX) -c src/Components/TransformComponent.cpp $(CXXFLAGS)


clean:
	rm *.o *.exe
	
	
	
	