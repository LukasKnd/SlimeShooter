#include <iostream>
#include <string.h>

#define CATCH_CONFIG_MAIN
#include "./catch.hpp"
#include "./PlayState.h"
#include "./Entity.h"
#include "./Components/TransformComponent.h"
#include "./Components/SpriteComponent.h"
#include "./Map.h"

using namespace sg;

/*
TEST_CASE("Game class test", "[Game]") {

	Game *game = new Game();

    bool caught = false;

    try {
        game->Initialize(-5, 20);
    } catch (std::logic_error &error) {
        caught = true;
        REQUIRE(strcmp(error.what(), "width or height cannot be less than or equal to zero") == 0);
    }

    REQUIRE(caught == true);

}
*/


TEST_CASE("Entity class test", "[Entity]") {

	EntityManager manager;
	Entity entity(manager);

	entity.AddComponent<TransformComponent>(5,5,5,5,5,5);

	REQUIRE(entity.HasComponent<TransformComponent>() == true);
    REQUIRE(entity.HasComponent<SpriteComponent>() == false);
    REQUIRE(typeid(*entity.GetComponent<TransformComponent>()) == typeid(TransformComponent));


}

TEST_CASE("EntityManager class test", "[EntityManager]") {

	EntityManager manager;
	Entity& newEntity = manager.AddEntity("newEntity", PLAYER_LAYER);

	REQUIRE(manager.GetEntities().size() == 1);
    REQUIRE(manager.GetEntitiesByLayer(PLAYER_LAYER).size() == 1);
    REQUIRE(manager.GetEntitiesWithComponent<TransformComponent>().size() == 0);
    REQUIRE(manager.HasNoEntities() == false);

}


TEST_CASE("TransformComponent class test", "[Entity]") {

	TransformComponent component(5,5,5,5,5,5);

	REQUIRE(component.GetWidth() == 5);

	SECTION("Position settters & getters") {
        REQUIRE(component.GetPosition().x == 5);
        REQUIRE(component.GetPosition().y == 5);

        component.SetPosition(sf::Vector2f(10,10));

        REQUIRE(component.GetPosition().x == 10);
        REQUIRE(component.GetPosition().y == 10);
	}

	SECTION("Velocity setters & getters") {
        REQUIRE(component.GetVelocity().x == 5);
        REQUIRE(component.GetVelocity().y == 5);

        component.SetVelocityX(10);
        component.SetVelocityY(10);

        REQUIRE(component.GetVelocity().x == 10);
        REQUIRE(component.GetVelocity().y == 10);


	}

}


TEST_CASE("Map class test", "[Map]") {
    Map m("Test", 50, 50);
    Map t("Test2", 40, 40);

    std::stringstream stream;
    stream << m;
    stream >> t;

    REQUIRE(m.toString() == t.toString());

}








