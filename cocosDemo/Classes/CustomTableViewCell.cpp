#include "CustomTableViewCell.h"

USING_NS_CC;

CustomTableViewCell *CustomTableViewCell::create(ssize_t idx) {
    CustomTableViewCell *cell = new CustomTableViewCell();
    cell->init(idx);
    cell->autorelease();
    return cell;
}
void CustomTableViewCell::init(ssize_t idx) {
    sprite = Sprite::create("right_tip.png");
    sprite->setAnchorPoint(Vec2::ZERO);
    sprite->setPosition(Vec2(0, 0));
    this->addChild(sprite);
    
    label = Label::createWithSystemFont("string", "Helvetica", 20.0);
    label->setPosition(Vec2::ZERO);
    label->setAnchorPoint(Vec2::ZERO);
    this->addChild(label);
}
void CustomTableViewCell::reset(ssize_t idx, cocos2d::ValueVector optionVec) {
    ValueMap vec_map_0 = optionVec.at(idx).asValueMap();
    std::string vec_0 = vec_map_0.at("img").asString();
    label->setString(vec_0);
    std::string img = vec_map_0.at("content").asString();

    Texture2D *tt = TextureCache::sharedTextureCache()->addImage(img);
    sprite->setTexture(tt);
    
}
