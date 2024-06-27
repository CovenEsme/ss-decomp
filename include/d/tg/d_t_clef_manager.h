#ifndef D_T_CLEF_MGR_H
#define D_T_CLEF_MGR_H

#include <toBeSorted/actor_on_rail.h>

class dTgClefManager_c : public dAcBase_c {
public:
    dTgClefManager_c();
    virtual ~dTgClefManager_c();
    virtual int actorCreate() override;
    virtual int actorPostCreate() override;
    virtual int actorExecute() override;

private:
    void removeClefFromList(cListNd_c *);
    int getTadtoneMgrGroup();
    int getPathIndex();

    cListMg_c clefList;
    ActorOnRail mRail;
    float mUnkFloat;
    u8 mUnkByte;
    bool mUnkBool;
};

#endif
