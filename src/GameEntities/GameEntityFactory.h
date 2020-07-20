#ifndef GAME_ENTITY_FACTORY_H
#define GAME_ENTITY_FACTORY_H
#include <string>

class MovableEntity;

class Sender;

class GameMap;

class GameEntityContainer;

// Factory de entidades del juego.

class GameEntityFactory{
    private:
        Sender& game;
        GameMap& map;
        GameEntityContainer& entities;
        
    public:
        GameEntityFactory(Sender& game, GameMap& map, 
                        GameEntityContainer& entities);
        MovableEntity* getPlayer(int x, int y, int entityId, std::string& race, std::string& type);
        MovableEntity* getZombie(int x, int y, int entityId, int level);
        MovableEntity* getMerchant(int x, int y, int entityId);
        MovableEntity* getHealer(int x, int y, int entityId);

};

#endif
