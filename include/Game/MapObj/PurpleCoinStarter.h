#pragma once
#include "Syati.h"
#include "Game/MapObj/PurpleCoinHolder.h"

class PurpleCoinStarter : public NameObj {
public:
    PurpleCoinStarter(const char*);

    virtual ~PurpleCoinStarter();
    virtual void init(const JMapInfoIter&);

    void setHost(PurpleCoinHolder*);
    void start();

    PurpleCoinHolder* mCoinHolder;  // 0xC
    StageSwitchCtrl* mSwitchCtrl;   // 0x10
};