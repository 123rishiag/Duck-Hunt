# Duck Hunt Game

## Overview
Welcome to the modern twist on the classic Duck Hunt game! This project is a culmination of my journey in game development, leveraging C++, SFML, and a well-structured architecture to create an engaging and fun gaming experience. Dive into a world where you shoot ducks, manage ammo, and progress through increasingly difficult waves.

## Features
- **Wave System:** Progress through waves with increasing difficulty.
- **Player Mechanics:** Health, score, and ammo management.
- **Duck Behavior:** Different duck types with unique speeds, points, and movement patterns.
- **Shooting Mechanics:** Two bullet types - area bullet and point-and-click bullet.
- **Sound Effects:** Bullet shooting sound and duck death sounds.
- **User Interface:** Display player health, score, and ammo.

## Learning Outcomes
- **Architecture Design:** Implemented a structured architecture for scalable and maintainable code.
- **Animation and Graphics:** Integrated smooth animations and high-quality graphics.
- **Event Handling:** Responsive and intuitive controls.
- **Object-Oriented Design:** Strengthened understanding of OOP concepts.
- **Game Loop and State Management:** Ensured smooth transitions and gameplay.
- **UI/UX Design:** Created intuitive and engaging user interfaces.

## Project Structure

### Services and Their Model, View, and Controllers
- **GraphicService:** Manages game window and rendering operations.
- **EventService:** Handles user input and game events.
- **TimeService:** Provides timing and delta-time calculations.
- **GameplayService:** Manages core gameplay mechanics.
  - Includes: `GameplayController`, `GameplayView`
- **WaveService:** Manages wave logic.
  - Includes: `WaveController`, `WaveConfig`
- **PlayerService:** Manages player-related logic.
  - Includes: `PlayerController`, `PlayerModel`, `PlayerView`
- **EnemyService:** Manages enemy-related logic.
  - Includes: `EnemyController`, `EnemyModel`, `EnemyView`, `EnemyConfig`
  - Sub Controllers: `DuckController`, `PowerDuckController`
- **BulletService:** Manages bullet-related logic.
  - Includes: `BulletController`, `BulletModel`, `BulletConfig`
  - Sub Controllers: `AreaBulletController`, `PointBulletController`
  - Interfaces: `IProjectile`
- **UIService:** Manages UI components.
  - UI Controllers: `GameplayUIController`, `InstructionUIController`, `MainMenuUIController`, `SplashScreenUIController`
  - UI Elements: `AnimatedImageView`, `ButtonView`, `ImageView`, `TextView`, `UIView`
  - Interfaces: `IUIController`
- **AnimationService:** Manages animations.
  - Includes: `AnimationConfig`, `AnimationController`
- **SoundService:** Manages sound effects and music playback.

### Additional Core Components
- **Main:** Entry point of the game.
- **GameService:** Core service for game initialization and management.
  - Declares and manages all game states.
  - Manages the initialization, updating, and rendering of Service Locator.
- **ServiceLocator:** Manages the initialization, updating, and rendering of all the above-mentioned services, ensuring smooth communication and coordination among them.
- **Config:** Holds texture file locations for all assets, including sounds, animations, sprite textures, and fonts.
- **Utility:** Utility functions used throughout the game.

## How to Play

1. Clone the repository:
    ```bash
    git clone https://github.com/123rishiag/Duck-Hunt.git
    ```

2. Build the project using your preferred C++ compiler.

3. Make sure you have SFML installed. You can install SFML using your package manager or from [SFML's official website](https://www.sfml-dev.org/).

4. Run the executable to start the game.

5. Use the keyboard and mouse to control your spaceship, shoot enemies, and collect power-ups.