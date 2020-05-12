#include "PlayState.h"

#include <exception>
#include "./Components/TransformComponent.h"
#include "./Components/SpriteComponent.h"
#include "./Components/GunComponent.h"
#include "./Components/KeyboardControlComponent.h"
#include "./Map.h"
//#include "./MenuState.h"
#include "./PauseMenuState.h"

using namespace sg;

PlayState PlayState::playState;
float PlayState::timeRunning;
EntityManager* PlayState::manager;
AssetManager* PlayState::assetManager;
SlimeSpawnManager* PlayState::slimeSpwnManager;
sf::RenderWindow* PlayState::window;


void PlayState::Initialize(GameEngine *game) {

    timeRunning = 0.0f;
    manager = new EntityManager();
    assetManager = new AssetManager();
    window = game->window;

    sf::Vector2f windowSize = window->getView().getSize();

    view = new sf::View(sf::FloatRect(0, 0, windowSize.x, windowSize.y));

    LoadLevel();

}

void PlayState::Update(GameEngine *game) {

    float deltaTime = timeLastFrame.restart().asSeconds();

    timeRunning += deltaTime;

    manager->Update(deltaTime);

    Entity* player = manager->GetEntity("player");
    view->setCenter(player->GetComponent<TransformComponent>()->GetCenter().x, player->GetComponent<TransformComponent>()->GetCenter().y);

    manager->CheckCollisions();

    slimeSpwnManager->Update(deltaTime);

}


void PlayState::Render(GameEngine *game) {


    game->window->setView(*view);

    manager->Render();

}
void PlayState::ProcessInput(GameEngine *game) {

    sf::Event event;

    game->window->pollEvent(event);

    if (event.type == sf::Event::KeyPressed) {
        if(event.key.code == sf::Keyboard::Escape) {
            game->PushState( PauseMenuState::Instance() );
        }
    }

}

void PlayState::LoadLevel() {

    view->zoom(0.5f);

    assetManager->AddTexture("map-texture", "./assets/tilemaps/map.png");

    assetManager->AddTexture("collision-texture", "./assets/collision-texture.png");

    assetManager->AddTexture("player_idle0", "./assets/player_character/Idle/Idle_idle_0.png");
    assetManager->AddTexture("player_idle1", "./assets/player_character/Idle/Idle_idle_1.png");
    assetManager->AddTexture("player_idle2", "./assets/player_character/Idle/Idle_idle_2.png");
    assetManager->AddTexture("player_run0", "./assets/player_character/Run/run_run_0.png");
    assetManager->AddTexture("player_run1", "./assets/player_character/Run/run_run_1.png");
    assetManager->AddTexture("player_run2", "./assets/player_character/Run/run_run_2.png");
    assetManager->AddTexture("player_run3", "./assets/player_character/Run/run_run_3.png");
    assetManager->AddTexture("player_run4", "./assets/player_character/Run/run_run_4.png");
    assetManager->AddTexture("player_run5", "./assets/player_character/Run/run_run_5.png");
    assetManager->AddTexture("player_run6", "./assets/player_character/Run/run_run_6.png");
    assetManager->AddTexture("player_run7", "./assets/player_character/Run/run_run_7.png");

    assetManager->AddTexture("gun", "./assets/player_character/Gun/Main_Gun/main gun_Gun_0.png");
    //assetManager->AddTexture("gun", "./assets/player_character/Gun/Shotgun/shotgun_shotgun_0.png");

    assetManager->AddTexture("projectile", "./assets/player_character/Gun/Bullet/bullet_projectile_0.png");
    assetManager->AddTexture("projectileOnHit0", "./assets/player_character/Gun/On_hit/on_hit_0.png");
    assetManager->AddTexture("projectileOnHit1", "./assets/player_character/Gun/On_hit/on_hit_1.png");
    assetManager->AddTexture("projectileOnHit2", "./assets/player_character/Gun/On_hit/on_hit_2.png");
    assetManager->AddTexture("muzzleFlash", "./assets/player_character/Gun/Muzzle_Flash/muzzle_flash.png");

    assetManager->AddTexture("slime_move0", "./assets/Slime_Sprite/slime move_blob_0.png");
    assetManager->AddTexture("slime_move1", "./assets/Slime_Sprite/slime move_blob_1.png");
    assetManager->AddTexture("slime_move2", "./assets/Slime_Sprite/slime move_blob_2.png");
    assetManager->AddTexture("slime_move3", "./assets/Slime_Sprite/slime move_blob_3.png");
    assetManager->AddTexture("slime_move4", "./assets/Slime_Sprite/slime move_blob_4.png");
    assetManager->AddTexture("slime_move5", "./assets/Slime_Sprite/slime move_blob_5.png");

    assetManager->AddTexture("slime_death0", "./assets/Slime_Sprite/death_blob death_00.png");
    assetManager->AddTexture("slime_death1", "./assets/Slime_Sprite/death_blob death_01.png");
    assetManager->AddTexture("slime_death2", "./assets/Slime_Sprite/death_blob death_02.png");
    assetManager->AddTexture("slime_death3", "./assets/Slime_Sprite/death_blob death_03.png");
    assetManager->AddTexture("slime_death4", "./assets/Slime_Sprite/death_blob death_04.png");
    assetManager->AddTexture("slime_death5", "./assets/Slime_Sprite/death_blob death_05.png");
    assetManager->AddTexture("slime_death6", "./assets/Slime_Sprite/death_blob death_06.png");
    assetManager->AddTexture("slime_death7", "./assets/Slime_Sprite/death_blob death_07.png");
    assetManager->AddTexture("slime_death8", "./assets/Slime_Sprite/death_blob death_08.png");
    assetManager->AddTexture("slime_death9", "./assets/Slime_Sprite/death_blob death_09.png");
    assetManager->AddTexture("slime_death10", "./assets/Slime_Sprite/death_blob death_10.png");
    assetManager->AddTexture("slime_death11", "./assets/Slime_Sprite/death_blob death_11.png");
    assetManager->AddTexture("slime_death12", "./assets/Slime_Sprite/death_blob death_12.png");

    assetManager->AddTexture("portalSpawner0", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_00.png");
    assetManager->AddTexture("portalSpawner1", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_01.png");
    assetManager->AddTexture("portalSpawner2", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_02.png");
    assetManager->AddTexture("portalSpawner3", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_03.png");
    assetManager->AddTexture("portalSpawner4", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_04.png");
    assetManager->AddTexture("portalSpawner5", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_05.png");
    assetManager->AddTexture("portalSpawner6", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_06.png");
    assetManager->AddTexture("portalSpawner7", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_07.png");
    assetManager->AddTexture("portalSpawner8", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_08.png");
    assetManager->AddTexture("portalSpawner9", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_09.png");
    assetManager->AddTexture("portalSpawner10", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_10.png");
    assetManager->AddTexture("portalSpawner11", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_11.png");
    assetManager->AddTexture("portalSpawner12", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_12.png");
    assetManager->AddTexture("portalSpawner13", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_13.png");
    assetManager->AddTexture("portalSpawner14", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_14.png");
    assetManager->AddTexture("portalSpawner15", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_15.png");
    assetManager->AddTexture("portalSpawner16", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_16.png");
    assetManager->AddTexture("portalSpawner17", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_17.png");
    assetManager->AddTexture("portalSpawner18", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_18.png");
    assetManager->AddTexture("portalSpawner19", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_19.png");
    assetManager->AddTexture("portalSpawner20", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_20.png");
    assetManager->AddTexture("portalSpawner21", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_21.png");
    assetManager->AddTexture("portalSpawner22", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_22.png");
    assetManager->AddTexture("portalSpawner23", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_23.png");
    assetManager->AddTexture("portalSpawner24", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_24.png");
    assetManager->AddTexture("portalSpawner25", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_25.png");
    assetManager->AddTexture("portalSpawner26", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_26.png");
    assetManager->AddTexture("portalSpawner27", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_27.png");
    assetManager->AddTexture("portalSpawner28", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_28.png");
    assetManager->AddTexture("portalSpawner29", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_29.png");
    assetManager->AddTexture("portalSpawner30", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_30.png");
    assetManager->AddTexture("portalSpawner31", "./assets/tilemaps/Portal_Spawner/portal animation_Animation 2_31.png");


    Entity& player = manager->AddEntity("player", PLAYER_LAYER);
    player.AddComponent<TransformComponent>(100, 100, 0, 0, 50, 50);
    player.AddComponent<SpriteComponent>(
        std::vector<std::vector<std::string>> {
            {
                "player_idle0",
                "player_idle1",
                "player_idle2",
            },
            {
                "player_run0",
                "player_run1",
                "player_run2",
                "player_run3",
                "player_run4",
                "player_run5",
                "player_run6",
                "player_run7"
            }
        },
        std::vector<std::string> {
            "IDLE",
            "RUN"
        },
        10,
        "IDLE"
    );
    player.AddComponent<GunComponent>("gun", 5, 5, 15, 0, 40, 40, 0.2);
    player.AddComponent<KeyboardControlComponent>();
    player.AddComponent<ColliderComponent>("player", 15, 12, 20, 25);


    Map map("map-texture", 16, 15);
    map.LoadMap("./assets/tilemaps/map.txt", 20, 20);

    PlayState::slimeSpwnManager = new SlimeSpawnManager(&player);
    *PlayState::slimeSpwnManager += sf::Vector2f(0,25);
    *PlayState::slimeSpwnManager += sf::Vector2f(100,25);
    *PlayState::slimeSpwnManager += sf::Vector2f(200,25);

    *PlayState::slimeSpwnManager += sf::Vector2f(0,75);
    *PlayState::slimeSpwnManager += sf::Vector2f(100,75);
    *PlayState::slimeSpwnManager += sf::Vector2f(200,75);

    *PlayState::slimeSpwnManager += sf::Vector2f(0,125);
    *PlayState::slimeSpwnManager += sf::Vector2f(100,125);
    *PlayState::slimeSpwnManager += sf::Vector2f(200,125);

    *PlayState::slimeSpwnManager += sf::Vector2f(0,175);
    *PlayState::slimeSpwnManager += sf::Vector2f(100,175);
    *PlayState::slimeSpwnManager += sf::Vector2f(200,175);

    *PlayState::slimeSpwnManager += sf::Vector2f(0,225);
    *PlayState::slimeSpwnManager += sf::Vector2f(100,225);
    *PlayState::slimeSpwnManager += sf::Vector2f(200,225);

    #ifdef DEBUG
    manager.ListAllEntities(true);
    #endif // DEBUG

}


void PlayState::Pause() {

}


void PlayState::Resume() {
    timeLastFrame.restart();
}
void PlayState::Cleanup() {
    window->setView(window->getDefaultView());
    delete view;
    delete manager;
    delete assetManager;
    delete slimeSpwnManager;
}

