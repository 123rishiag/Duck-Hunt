#include "../../Header/Global/ServiceLocator.h"
#include "../../Header/Main/GameService.h"

namespace Global {
    using namespace Graphic;
    using namespace Event;
    using namespace Time;
    using namespace Gameplay;
    using namespace Player;
    using namespace Enemy;
    using namespace Bullet;



    using namespace UI;

    using namespace Main;

    // Constructor for initializing the ServiceLocator.
    ServiceLocator::ServiceLocator() {
        graphicService = nullptr; // Initialize graphicService to null
        eventService = nullptr; // Initialize eventService to null
        timeService = nullptr; // Initialize timeService to null
        gameplayService = nullptr; // Initialize gameplayService to null
        playerService = nullptr; // Initialize playerService to null
        enemyService = nullptr; // Initialize enemyService to null
        bulletService = nullptr; // Initialize bulletService to null


        uiService = nullptr; // Initialize uiService to null

        CreateServices(); // Call CreateServices to instantiate services
    }

    // Destructor for cleaning up resources upon object deletion.
    ServiceLocator::~ServiceLocator() {
        ClearAllServices(); // Call ClearAllServices to delete any allocated services	
    }

    // Creates instances of all services.
    void ServiceLocator::CreateServices() {
        graphicService = new GraphicService(); // Dynamically create a GraphicService instance
        eventService = new EventService(); // Dynamically create a EventService instance
        timeService = new TimeService(); // Dynamically create a TimeService instance
        gameplayService = new GameplayService(); // Dynamically create a GameplayService instance
        playerService = new PlayerService(); // Dynamically create a PlayerService instance
        enemyService = new EnemyService(); // Dynamically create a EnemyService instance
        bulletService = new BulletService(); // Dynamically create a bulletService instance


        uiService = new UIService(); // Dynamically create a UIService instance
    }

    // Deletes and deallocates memory for all services.
    void ServiceLocator::ClearAllServices() {
        delete(graphicService); // Delete the graphicService instance
        delete(eventService); // Delete the eventService instance
        delete(timeService); // Delete the timeService instance
        delete(gameplayService); // Delete the gameplayService instance
        delete(playerService); // Delete the playerService instance
        delete(enemyService); // Delete the enemyService instance
        delete(bulletService); // Delete the bulletService instance


        delete(uiService); // Delete the uiService instance
    }

    // Provides a method to access the unique ServiceLocator instance (object).
    ServiceLocator* ServiceLocator::GetInstance() {
        static ServiceLocator instance; // we will discuss what 'static' means at a later time.
        return &instance; // Return address of the instance
    }

    // Initializes the ServiceLocator.
    void ServiceLocator::Initialize() {
        graphicService->Initialize(); // Initialize graphic service
        eventService->Initialize(); // Initialize event service
        timeService->Initialize(); // Initialize time service
        gameplayService->Initialize(); // Initialize gameplay service
        playerService->Initialize(); // Initialize player service
        enemyService->Initialize(); // Initialize enemy service
        bulletService->Initialize(); // Initialize bullet service


        uiService->Initialize(); // Initialize ui service
    }

    // Updates all services.
    void ServiceLocator::Update() {
        graphicService->Update(); // Update graphic service
        eventService->Update(); // Update event service
        timeService->Update(); // Update time service
        if (GameService::GetGameState() == GameState::GAMEPLAY)
        {
            gameplayService->Update(); // Update gameplay service
            playerService->Update(); // Update player service
            enemyService->Update(); // Update enemy service
            bulletService->Update(); // Update bullet service
        }


        uiService->Update(); // Update ui service
    }

    // Renders using the services.
    void ServiceLocator::Render() {
        graphicService->Render(); // Render graphic service
        // no event service because nothing to render
        // no time service because nothing to render
        if (GameService::GetGameState() == GameState::GAMEPLAY)
        {
            gameplayService->Render(); // Update gameplay service
            playerService->Render(); // Render player service
            enemyService->Render(); // Render enemy service
            bulletService->Render(); // Render bullet service
        }


        uiService->Render(); // Render ui service
    }

    // Methods to Get Specific Services:

    // Retrieve the GraphicService instance
    GraphicService* ServiceLocator::GetGraphicService() const {
        return graphicService;
    }
    // Retrieve the EventService instance
        EventService * ServiceLocator::GetEventService() const {
        return eventService;
    }
    // Retrieve the TimeService instance
    TimeService* ServiceLocator::GetTimeService() const {
        return timeService;
    }
    // Retrieve the GameplayService instance
    GameplayService* ServiceLocator::GetGameplayService() const {
        return gameplayService;
    }
    // Retrieve the PlayerService instance
    PlayerService* ServiceLocator::GetPlayerService() const {
        return playerService;
    }
    // Retrieve the EnemyService instance
    EnemyService* ServiceLocator::GetEnemyService() const {
        return enemyService;
    }
    // Retrieve the BulletService instance
    BulletService* ServiceLocator::GetBulletService() const {
        return bulletService;
    }



    // Retrieve the UIService instance
    UIService* ServiceLocator::GetUIService() const {
        return uiService;
    }

    void ServiceLocator::DeleteServiceLocator()
    {
        delete(this);
    }
}