#include <d/tg/d_t_clef_manager.h>
#include <d/a/obj/d_a_obj_clef.h>
#include <f/f_profile_name.h>
#include "d/d_player.h"

SPECIAL_ACTOR_PROFILE(TAG_CLEF_MANAGER, dTgClefManager_c, fProfile::TAG_CLEF_MANAGER, 0x02a0, 0, 0);

dTgClefManager_c::dTgClefManager_c() {
    mUnkFloat = dAcOClef_c::getUnkFloat();
    mUnkByte = 0;
    mUnkBool = false;
}

dTgClefManager_c::~dTgClefManager_c() {
    clefList.clear();
}

// 80ea7a20
int dTgClefManager_c::actorCreate() {
    int pathIndex = getPathIndex();

    if (mRail.init(pathIndex, roomid, 0)) {
        return SUCCEEDED;
    } else {
        return FAILED;
    }
}

// 80ea7a80
int dTgClefManager_c::actorPostCreate() {
    dAcOClef_c *tadtone = nullptr;
    for (tadtone = (dAcOClef_c *)fManager_c::searchBaseByProfName(fProfile::OBJ_CLEF, nullptr);
        tadtone != nullptr;
        tadtone = (dAcOClef_c *)fManager_c::searchBaseByProfName(fProfile::OBJ_CLEF, tadtone)) {
            u32 tadtoneGroup = dAcOClef_c::getTadtoneGroup(tadtone);
            u32 mgrGroup = getTadtoneMgrGroup();

            if (mgrGroup == tadtoneGroup) {
                fLiNdBa_c *clefMgrLink = tadtone->getLinkToClefMgr();
                clefList.append(clefMgrLink);
                tadtone->linkClefMgr(this);
            }
    }

    return SUCCEEDED;
}

// 80ea7b30
int dTgClefManager_c::actorExecute() {
    cListNd_c *prev = clefList.getFirst();
    if (prev == nullptr) {
        deleteRequest();
        return 1;
    }

    if (mUnkByte == 0) {
        if (mUnkBool == false) {
            cListNd_c *next = clefList.getLast();
            bool stillSearching = true;
            dAcOClef_c *currentClef = nullptr;

            while (stillSearching && next != nullptr) {
                currentClef = (dAcOClef_c *)next;

                if ((currentClef->objectActorFlags & 0x200) != 0) {
                    next = next->getPrev();
                }
                if ((currentClef->objectActorFlags & 0x200) == 0) {
                    stillSearching = false;
                }
            }

            if (stillSearching == false) {
                deleteRequest();
                return 1;
            }

            float v0x6f4 = currentClef->get0x6f4();
            int v0x704 = currentClef->get0x704();
            mVec3_c vec1;
            mRail.FUN_800a7c80(v0x6f4, v0x704, &vec1);

            v0x6f4 = currentClef->get0x6f4();
            v0x704 = currentClef->get0x704();
            double d = mRail.FUN_800a8280(v0x6f4, v0x704);

            // mVec3_c vec2;
            // if (0.0 == d) {
            //     vec2 = vec1;
            // } else {
            //     v0x6f4 = currentClef->get0x6f4();
            //     v0x704 = currentClef->get0x704();
            //     mVec3_c vec3;
            //     mVec3_c vec4;
            //     mRail.FUN_800a8510(v0x6f4, v0x704, &vec3);
                
            //     v0x6f4 = 1.0 - d;
            //     vec4 = (vec1 * v0x6f4) + (vec3 * d);
            //     vec2 = vec4;
            // }

            // mVec3_c *pVec = &vec2;
            // pVec->normalise();
            // if (pVec != nullptr) {
            //     mVec3_c vec5 = dPlayer::LINK->position - currentClef->position;
            //     vec5.dot(vec5);
            //     (&vec5)->normalise();
            //     if ((vec5.x + vec5.y + vec5.z < 25000.0) && ((vec5.z * vec2.z) + (vec5.x * vec2.x) + (vec5.y * vec2.y) > 0.866)) {
            //         mUnkBool = true;
            //         mUnkByte = 0x3c;
            //     }
            // }
        } else {
            
        }

    } else {
        mUnkByte -= 1;
    }

    if (mUnkBool == false) {
        float unkFloat = dAcOClef_c::getUnkFloat();
    }
}

// 80ea8280
void dTgClefManager_c::removeClefFromList(cListNd_c *clef) {
    clefList.remove(clef);
}

// 80ea8290
int dTgClefManager_c::getTadtoneMgrGroup() {
    return params & 0xFF;
}

// 80ea82a0
int dTgClefManager_c::getPathIndex() {
    return params >> 8 & 0xFF;
}
