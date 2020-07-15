#ifndef GAME_ENTITY_FACTORY_H
#define GAME_ENTITY_FACTORY_H

class MovableEntity;

class Sender;

class GameMap;

class GameEntityContainer;

class GameEntityFactory{
    private:
        Sender& game;
        GameMap& map;
        GameEntityContainer& entities;
        
    public:
        GameEntityFactory(Sender& game, GameMap& map, GameEntityContainer& entities);
        MovableEntity* getPlayer(int x, int y, int entityId);
        MovableEntity* getZombie(int x, int y, int entityId);

};

#endif
