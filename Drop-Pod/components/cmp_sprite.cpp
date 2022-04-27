
#include "cmp_sprite.h"
#include "system_renderer.h"

using namespace std;
using namespace sf;

void SpriteComponent::setTexture(shared_ptr<Texture> tex)
{
  _texture = tex;
  _sprite->setTexture(*_texture);
}

void SpriteComponent::setTextureRect(sf::IntRect rect)
{
    _sprite->setTextureRect(rect);
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
int frameCount;
Sprite* target;

AnimationComponent::AnimationComponent(Entity* p) : Component(p){
    totalProgress = 0.f;
    totalLength = 0.f;
    frameCount = 0;

}

void AnimationComponent::addFrame(Frame& frame) {
    frames.push_back(move(frame));
    totalLength += frame.duration;
}

void AnimationComponent::setAnimation(int size, float duration, string path)
{
    auto temp = make_shared<Texture>();
    if (!temp->loadFromFile(path)) {
        printf("Animation texture problem.");
    }

    _parent->GetCompatibleComponent<SpriteComponent>()[0]->setTexture(temp);

    for (auto i = 0; i < size; i++)
    {
        Frame tempFrame;
        tempFrame.rect = IntRect(Vector2i(150 * i, 0), Vector2i(150, 150));
        tempFrame.duration = duration;
        addFrame(tempFrame);
    }
}


void AnimationComponent::update(double dt) {
    totalProgress += dt;
    if (totalProgress >= totalLength / frames.size())
    {
        frameCount++;

        if (frameCount >= frames.size()) {
            frameCount = 0;
        }

        _parent->GetCompatibleComponent<SpriteComponent>()[0]->setTextureRect(frames[frameCount].rect);
        totalProgress = 0.f;
    }
}

void AnimationComponent::render() {}

