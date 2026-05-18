#pragma once
#include "Syati.h"
#include "Game/MapObj/PurpleCoinStarter.h"

class PurpleCoinHolder : public DeriveActorGroup< Coin > {
public:
    PurpleCoinHolder();

    virtual ~PurpleCoinHolder();
    virtual void initAfterPlacement();

    void start();

    PurpleCoinStarter* mStarter;  // 0x18
};

namespace MR {
    void createPurpleCoinHolder();
    void addToPurpleCoinHolder(const NameObj*, Coin*);
    void registPurpleCoinStarter(PurpleCoinStarter*);
};  // namespace MR