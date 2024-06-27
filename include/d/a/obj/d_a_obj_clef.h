#ifndef D_A_OBJ_CLEF_H
#define D_A_OBJ_CLEF_H

#include "d/a/obj/d_a_obj_base.h"
#include <s/s_State.hpp>
#include <s/s_StateMgr.hpp>
#include <d/tg/d_t_clef_manager.h>

enum dAcOClefID_e {
    STATIONARY = 0,
    EVADE = 1,
    ON_PATH = 2,
};

class dAcOClef_c : public dAcObjBase_c {
public:
    dAcOClef_c();
    virtual int create() override;
    virtual int draw() override;
    virtual bool createHeap() override;
    virtual int actorExecute() override;
    virtual void unkVirtFunc_0x6C() override;

    float get0x6f0();
    float get0x6f4();
    dAcOClefID_e getClefSubtype();
    int get0x704();

    static float getUnkFloat();
    static char *getTadtoneArcName();

    void set0x6f0(float);
    void set0x6f4(float);
    void setClefSubtype(dAcOClefID_e);
    void set0x704(int);
    void linkClefMgr(dTgClefManager_c *);
    void updatePosMaybe(Vec3f *);
    void checkCollisionMaybe();
    bool updateTadtoneParticleEffectColor();

    void unkCollisionFunc();
    STATE_FUNC_DECLARE(dAcOClef_c, WaitPhantom);
    STATE_FUNC_DECLARE(dAcOClef_c, Wait);
    STATE_FUNC_DECLARE(dAcOClef_c, WaitPathMove);
    STATE_FUNC_DECLARE(dAcOClef_c, MoveTowardPath);
    STATE_FUNC_DECLARE(dAcOClef_c, PathMove);
    STATE_FUNC_DECLARE(dAcOClef_c, Gravitate);
    STATE_FUNC_DECLARE(dAcOClef_c, Die);
    
    fLiNdBa_c *getLinkToClefMgr();
    
    static float getUnkFloat2();
    static float getUnkFloat3();
    static float getSomeDefaultY1();
    static float getSomeDefaultY2();
    static int getUnkInt();
    static float getTadtoneSpeedMaybe();
    static float getDowsingTargetOffset_x();
    static float getDowsingTargetOffset_y();
    static float getDowsingTargetOffset_z();

    void setPointIndex(int);
    void set0x708(int);
    void setUncollectableTimer(int);
    void setJiggleStateOn();
    void setJiggleStateOff();
    dTgClefManager_c *getClefMgr();
    void getDowsingTargetOffset(Vec3f *);
    void moveAlongRailPath();
    void initPointIndex();
    bool hasTadtoneDowsing();
    void setUncollectableTimerToMax();
    void updateUncollectableTimer();
    bool isCollectable();
    void updateStamina();
    int getModelSubtype();
    dAcOClefID_e getClefSubtypeFromParams();
    s8 getPathIndex();

    // TODO: find where this actually belongs in main.dol
    static int getTadtoneGroup(dAcOClef_c *);
private:
    u8 mdlAnmChr[0x70];
    STATE_MGR_DECLARE(dAcOClef_c);
    u8 unkCollider1[0x160];
    u8 unkCollider2[0x160];
    cListMg_c colliderLinkedList;
    ActorOnRail mRail;
    u8 dowsingTarget[0x20];
    fLiNdBa_c mLinkToClefMgr;
    fLiNdBa_c mLinkFromClefMgr;
    float m0x6f0;
    float m0x6f4;
    float m0x6f8;
    dAcOClefID_e mClefSubtype;
    int pointIndex;
    int m0x704;
    int m0x708;
    int m0x70c;
    s8 uncollectableTimer;
    bool jiggleState;

};

#endif
