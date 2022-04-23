
#include "cmp_sprite.h"
#include "system_renderer.h"

using namespace std;
using namespace sf;

void SpriteComponent::setTexure(shared_ptr<Texture> tex)
{
  _texture = tex;
  _sprite->setTexture(*_texture);
}


SpriteComponent::SpriteComponent(Entity* p)
    : Component(p), _sprite(make_shared<Sprite>()) {}

void SpriteComponent::update(double dt) {
  _sprite->setPosition(_parent->getPosition());
  _sprite->setRotation(deg2rad(_parent->getRotation()));
}

void SpriteComponent::render() { Renderer::queue(_sprite.get()); }

void ShapeComponent::update(double dt) {
  _shape->setPosition(_parent->getPosition());
  _shape->setRotation(deg2rad(_parent->getRotation()));
}

void ShapeComponent::render() { Renderer::queue(_shape.get()); }

Shape& ShapeComponent::getShape() const { return *_shape; }

ShapeComponent::ShapeComponent(Entity* p)
    : Component(p), _shape(make_shared<CircleShape>()) {}

Sprite& SpriteComponent::getSprite() const { return *_sprite; }

vector<Frame> frames;
double totalLength;
double totalProgress;
Sprite* target;

AnimationComponent::AnimationComponent(Entity* p, Sprite& target) : Component(p){
    this->target = &target;
    totalProgress = 0.f;
    //totalLength = 0.f;
}

void AnimationComponent::addFrame(Frame& frame) {
    frames.push_back(move(frame));
    totalLength += frame.duration;
}

void AnimationComponent::update(double dt) {
    totalProgress += dt;
    double progress = totalProgress;
    for (auto frame : frames)
    {
        progress -= frame.duration;

        // This seems to be the problem. Something to do with reseting the total progress or activating the next frame....
        if (progress <= 0.0 || &(frame) == &frames.back()) {
            target->setTextureRect((frame).rect);
            break;
        }
    }
}

void AnimationComponent::render() {}

