#ifndef ACTOR_ON_RAIL_H
#define ACTOR_ON_RAIL_H

#include <common.h>

class ActorOnRail {
private:
    void *mpPathPtr;
    int mRoomIndex;
    u8 mPathSubtype;

public:
    /* 800A6690 */
    ActorOnRail();
    /* 800A66D0 */
    virtual ~ActorOnRail();

    /* 800A6D90 */
    int init(int pathIndex, int roomId, int pathSubtype);
    /* 800A68B0 */
    mVec3_c *getPntPosForIndex(int index);
    u32 FUN_800a7c80(f32, int, mVec3_c *);
    double FUN_800a8280(f32, int);
    u32 FUN_800a8510(f32, int, mVec3_c *);
};

#endif
