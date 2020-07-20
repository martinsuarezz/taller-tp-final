#include "SFXGenerator.h"
#include "Screen.h"
#include "AssetsLoader.h"
#include "Sound.h"
#include "Texture.h"
#include "Effect.h"
#include "Animation/Animation.h"
#include "RandomGenerator.h"
#include "Constants.h"
#include <string>
#include <list>

SFXGenerator::SFXGenerator(Screen& screen, AssetsLoader& assets):
                            screen(screen), assets(assets), time(0){}

void SFXGenerator::render(int timeElapsed){
    time += timeElapsed;

    std::list<Effect>::iterator it;
    for (it = effects.begin(); it != effects.end(); it++){
        it->render(timeElapsed, screen.getPositionX(), screen.getPositionY());
    }
    /*
    if (time > 2 * MICROS_IN_SECOND){
        time = 0;
        std::list<Effect> tmp;
        for (it = effects.begin(); it != effects.end(); it++){
            it->render(timeElapsed);

            if (!it->hasFinished()){
                tmp.push_back(*it);
            }
            
        }
        effects.swap(tmp);
    }
    */
}

void SFXGenerator::addLevelUpEffect(){
    Sound& sound = assets.getSound("level_up");
    sound.play(0);
}

void SFXGenerator::addMerchantEffect(){
    RandomGenerator& random = RandomGenerator::getInstance();
    Sound& sound = assets.getSound("merchant" + std::to_string(random(1, 10)));
    sound.play(0);
}

void SFXGenerator::addPlayerDeathEffect(){
    Sound& sound = assets.getSound("player_death");
    sound.play(0);
}

void SFXGenerator::addPlayerReviveEffect(){
    Sound& sound = assets.getSound("player_revive");
    sound.play(0);
}

void SFXGenerator::addAttackEffect(int weapon, int x, int y, int duration){
    if (weapon == HANDS_ID || (MELEE_FIRST <= weapon && weapon <= MELEE_LAST))
        addMeleeEffect(weapon, duration);
    else if (STAFF_FIRST <= weapon && weapon <= STAFF_LAST)
        addStaffEffect(weapon, x, y, duration);
    else if (BOW_FIRST <= weapon && weapon <= BOW_LAST)
        addBowEffect(weapon, duration);
}

void SFXGenerator::addStaffEffect(int weapon, int x, int y, int duration){
    std::string assetName = "item" + std::to_string(weapon) + "_attack";

    Sound& sound = assets.getSound(assetName);
    sound.play(0);
    Texture& texture = assets.getTexture(assetName);
    Animation animation(texture, assets.getAnimationFrames(assetName), duration);
    effects.emplace_back(std::move(Effect(std::move(animation), x, y, duration))); 
}

void SFXGenerator::addMeleeEffect(int weapon, int duration){
    std::string assetName = "item" + std::to_string(weapon) + "_attack";

    Sound& sound = assets.getSound(assetName);
    sound.play(0);
}

void SFXGenerator::addBowEffect(int weapon, int duration){
    std::string assetName = "item" + std::to_string(weapon) + "_attack";

    Sound& sound = assets.getSound(assetName);
    sound.play(0);
}