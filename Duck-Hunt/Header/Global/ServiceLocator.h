#pragma once

#include "../Graphic/GraphicService.h"
#include "../Event/EventService.h"
#include "../Time/TimeService.h"
#include "../Gameplay/GameplayService.h"
#include "../Player/PlayerService.h"
#include "../Enemy/EnemyService.h"
#include "../Bullet/BulletService.h"



#include "../UI/UIService.h"

namespace Global {

    // ServiceLocator Class Summary: This class manages access to various services in the application.
    // include relevant s files
    class ServiceLocator
    {
    private:
        // Private Attributes:
        Graphic::GraphicService* graphicService;
        Event::EventService* eventService;
        Time::TimeService* timeService;
        Gameplay::GameplayService* gameplayService;
        Player::PlayerService* playerService;
        Enemy::EnemyService* enemyService;
        Bullet::BulletService* bulletService;


        UI::UIService* uiService;

        // Private Constructor and Destructor:

        // Constructor for initializing the ServiceLocator.
        ServiceLocator();

        // Destructor for cleaning up resources upon object deletion.
        ~ServiceLocator();

        // Private Methods:
        void CreateServices(); 			// Creates instances of all services.
        void ClearAllServices(); 		//	Deletes and deallocates memory for all services.

    public:
        // Public Methods:
        static ServiceLocator* GetInstance();  // Provides a method to access the unique ServiceLocator instance (object). We will discuss this later.

        void Initialize(); 			//	Initializes the ServiceLocator.
        void Update(); 				//	Updates all services.
        void Render(); 				//	Renders using the services.

        // Methods to Get Specific Services: 
        Graphic::GraphicService* GetGraphicService() const;   // Retrieve the GraphicService instance
        Event::EventService* GetEventService() const;   // Retrieve the EventService instance
        Time::TimeService* GetTimeService() const;   // Retrieve the TimeService instance
        Gameplay::GameplayService* GetGameplayService() const;   // Retrieve the GameplayService instance
        Player::PlayerService* GetPlayerService() const;   // Retrieve the PlayerService instance
        Enemy::EnemyService* GetEnemyService() const;   // Retrieve the EnemyService instance
        Bullet::BulletService* GetBulletService() const;   // Retrieve the BulletService instance


        UI::UIService* GetUIService() const;   // Retrieve the UIService instance

        void DeleteServiceLocator();
    };
}