#ifndef __CUSTOMTABELVIEWCELL_H__
#define __CUSTOMTABELVIEWCELL_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
USING_NS_CC_EXT;

class CustomTableViewCell : public cocos2d::extension::TableViewCell
{
public:
    static CustomTableViewCell *create(ssize_t idx);
    void init (ssize_t idx);
    void reset (ssize_t idx,cocos2d::ValueVector optionVec);
public:
    cocos2d::Sprite *sprite;
    cocos2d::Label *label;
};

#endif /* __CUSTOMTABELVIEWCELL_H__ */

