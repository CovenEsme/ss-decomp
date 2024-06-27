#include <common.h>

#include <d/a/obj/d_a_obj_clef.h>


SPECIAL_ACTOR_PROFILE(OBJ_CLEF, dAcOClef_c, fProfile::OBJ_CLEF, 0x02D, 0, 7);

STATE_DEFINE(dAcOClef_c, WaitPhantom);
STATE_DEFINE(dAcOClef_c, Wait);
STATE_DEFINE(dAcOClef_c, WaitPathMove);
STATE_DEFINE(dAcOClef_c, MoveTowardPath);
STATE_DEFINE(dAcOClef_c, PathMove);
STATE_DEFINE(dAcOClef_c, Gravitate);
STATE_DEFINE(dAcOClef_c, Die);

// 80ea8c80
int dAcOClef_c::create() {
    return 1;
}

// 80ea94c0
int dAcOClef_c::draw() {
    return 1;
}

// 80ea8b20
bool dAcOClef_c::createHeap() {
    return 1;
}

// 80ea9630
float dAcOClef_c::get0x6f0() {
    return m0x6f0;
}

// 80ea9640
float dAcOClef_c::get0x6f4() {
    return m0x6f4;
}

// 80ea9650
dAcOClefID_e dAcOClef_c::getClefSubtype() {
    return mClefSubtype;
}

// 80ea9660
int dAcOClef_c::get0x704() {
    return m0x704;
}

// 80ea9670
float dAcOClef_c::getUnkFloat() {
    return 10.0;
}

// 80ea9680
char *dAcOClef_c::getTadtoneArcName() {
    return "Onp";
}

// 80ea9690
void dAcOClef_c::set0x6f0(float f) {
    m0x6f0 = f;
}

// 80ea96a0
void dAcOClef_c::set0x6f4(float f) {
    m0x6f4 = f;
}

// 80ea96b0
void dAcOClef_c::setClefSubtype(dAcOClefID_e i) {
    mClefSubtype = i;
}

// 80ea96c0
void dAcOClef_c::set0x704(int i) {
    m0x704 = i;
}

// 80ea96d0
void dAcOClef_c::linkClefMgr(dTgClefManager_c *mgr) {
    // clef->mLinkToClefMgr.link(mgr);
}

// 80ea96e0
void dAcOClef_c::updatePosMaybe(Vec3f *vec) {}

// 80ea9830
void dAcOClef_c::checkCollisionMaybe() {}

// 80ea9940
bool dAcOClef_c::updateTadtoneParticleEffectColor() {
    return true;
}


// 80ea9b00
void initializeState_WaitPhantom() {};
// 80ea9b10
void executeState_WaitPhantom() {};
// 80ea9b80
void finalizeState_WaitPhantom() {};

// 80ea9b90
void initializeState_Wait() {};
// 80ea9ba0
void executeState_Wait() {};
// 80eaa2b0
void unkCollisionFunc() {};
// 80eaa300
void finalizeState_Wait() {};

// 80eaa310
void initializeState_WaitPathMove() {};
// 80eaa320
void executeState_WaitPathMove() {};
// 80eaa3b0
void finalizeState_WaitPathMove() {};

// 80eaa3c0
void initializeState_MoveTowardPath() {};
// 80eaa410
void executeState_MoveTowardPath() {};
// 80eaa960
void finalizeState_MoveTowardPath() {};

// 80eaa970
void initializeState_PathMove() {};
// 80eaa980
void executeState_PathMove() {};
// 80eab170
void finalizeState_PathMove() {};

// 80eab180
void initializeState_Gravitate() {};
// 80eab190
void executeState_Gravitate() {};
// 80eab600
void finalizeState_Gravitate() {};

// 80eab610
void initializeState_Die() {};
// 80eab620
void executeState_Die() {};
// 80eab630
void finalizeState_Die() {};


// 80eab640
fLiNdBa_c *dAcOClef_c::getLinkToClefMgr() {
    return &mLinkToClefMgr;
}

// 80eab650
float dAcOClef_c::getUnkFloat2() {
    return 400.0;
}

// 80eab660
float dAcOClef_c::getUnkFloat3() {
    return 520.0;
}

// 80eab670
float dAcOClef_c::getSomeDefaultY1() {
    return -45.0;
}

// 80eab680
float dAcOClef_c::getSomeDefaultY2() {
    return -240.0;
}

// 80eab690
int dAcOClef_c::getUnkInt() {
    return 0x96;
}

// 80eab6a0
float dAcOClef_c::getTadtoneSpeedMaybe() {
    return 1.0;
}

// 80eab6b0
float dAcOClef_c::getDowsingTargetOffset_x() {
    return 0.0;
}
// 80eab6c0
float dAcOClef_c::getDowsingTargetOffset_y() {
    return 25.0;
}
// 80eab6d0
float dAcOClef_c::getDowsingTargetOffset_z() {
    return 0.0;
}

// 80eab6e0
void dAcOClef_c::setPointIndex(int pntIdx) {
    pointIndex = pntIdx;
}

// 80eab6f0
void dAcOClef_c::set0x708(int i) {
    m0x708 = i;
}

// 80eab700
void dAcOClef_c::setUncollectableTimer(int time) {
    uncollectableTimer = time;
}

// 80eab710
void dAcOClef_c::setJiggleStateOn() {
    jiggleState = true;
}

// 80eab720
void dAcOClef_c::setJiggleStateOff() {
    jiggleState = false;
}

// 80eab730
void dAcOClef_c::unkVirtFunc_0x6C() {
    objectActorFlags &= ~1;
}

// 80eab740
dTgClefManager_c *dAcOClef_c::getClefMgr() {
    return (dTgClefManager_c *)mLinkToClefMgr.p_owner;
}

// 80eab750
void dAcOClef_c::getDowsingTargetOffset(Vec3f *vec) {
    vec->x = getDowsingTargetOffset_x();
    vec->y = getDowsingTargetOffset_y();
    vec->z = getDowsingTargetOffset_z();
}

// 80eab7b0
void dAcOClef_c::moveAlongRailPath() {}

// 80eab8c0
void dAcOClef_c::initPointIndex() {}

// 80eab920
bool dAcOClef_c::hasTadtoneDowsing() {
    return true;
}

// 80eab970
void dAcOClef_c::setUncollectableTimerToMax() {
    setUncollectableTimer(0x40);
}

// 80eab980
void dAcOClef_c::updateUncollectableTimer() {
    if (!isCollectable()) {
        setUncollectableTimer(uncollectableTimer + 1);
        if (uncollectableTimer > 0x3c) {
            setUncollectableTimerToMax();
        }
    }
}

// 80eab9e0
bool dAcOClef_c::isCollectable() {
    return uncollectableTimer >> 6 & 1;
}

// 80eab9f0
void dAcOClef_c::updateStamina() {}

// 80eaba00
int dAcOClef_c::getModelSubtype() {
    return params & 7;
}

// 80eaba10
dAcOClefID_e dAcOClef_c::getClefSubtypeFromParams() {
    return (dAcOClefID_e)(params >> 8 & 7);
}

// 80eaba20
s8 dAcOClef_c::getPathIndex() {
    return (s8)rotation.x;
}


// TODO: figure out where this actually belongs
// Some of the tadtones code is in main.dol for some reason
// 80194e60
int getTadtoneGroup(dAcOClef_c *clef) {
    return clef->params >> 3 & 0x1f;
}
