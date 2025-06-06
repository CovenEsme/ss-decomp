#include "toBeSorted/counters/counter.h"

#include "d/flag/itemflag_manager.h"

/* 8016cc40 */ s32 Counter::checkedAdd(s32 num) {
    s32 uncommitted = getUncommittedValue();
    s32 max = getMax();
    s32 result = uncommitted + num;
    if (result < 0) {
        setValue(0);
    } else if (result < max) {
        setValue(result);
    } else {
        setValue(max);
    }

    if (result < 0) {
        return result;
    }

    return result <= max ? 0 : (result - max);
}

/* 8016cd30 */ u16 Counter::getCommittedValue() const {
    return ItemflagManager::sInstance->getItemCounterOrFlag(counterId);
}

/* 8016cd50 */ u16 Counter::getUncommittedValue() const {
    return ItemflagManager::sInstance->getUncommittedItemValue(counterId);
}

/* 8016cd70 */ void Counter::setValue(u16 num) {
    ItemflagManager::sInstance->setItemFlagOrCounterToValue(counterId, num);
}
