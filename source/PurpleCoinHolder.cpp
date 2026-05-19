#include "PurpleCoinHolder.h"
#include "Game/MapObj/Coin.h"
#include "PurpleCoinStarter.h"
#include "Game/Scene/SceneObjHolder.h"
#include "Game/Util.h"

PurpleCoinHolder::PurpleCoinHolder() : DeriveActorGroup< Coin >("パープルコイン管理", 0x100) {
    mStarter = nullptr;
    MR::declarePowerStarCoin100();
    MR::createPurpleCoinCounter();
}

void PurpleCoinHolder::initAfterPlacement() {
    if (!mStarter) {
        MR::validatePurpleCoinCounter();
    }
}

void PurpleCoinHolder::start() {
    MR::validatePurpleCoinCounter();
}

namespace MR {
    void createPurpleCoinHolder() {
        MR::createSceneObj(SCENE_OBJ_PURPLE_COIN_HOLDER);
    }

    void addToPurpleCoinHolder(const NameObj* pObj, Coin* pCoin) {
        //MR::getSceneObj< PurpleCoinHolder >(SCENE_OBJ_PURPLE_COIN_HOLDER)->registerActor(pCoin);
        ((PurpleCoinHolder*)MR::getSceneObjHolder()->getObj(SCENE_OBJ_PURPLE_COIN_HOLDER))->registerActor(pCoin);
    }

    void registPurpleCoinStarter(PurpleCoinStarter* pStarter) {
        //PurpleCoinHolder* holder = MR::getSceneObj< PurpleCoinHolder >(SCENE_OBJ_PURPLE_COIN_HOLDER);
        PurpleCoinHolder* holder = (PurpleCoinHolder*)MR::getSceneObjHolder()->getObj(SCENE_OBJ_PURPLE_COIN_HOLDER);
        holder->mStarter = pStarter;
        pStarter->setHost(holder);
    }
};  // namespace MR

PurpleCoinHolder::~PurpleCoinHolder() {}