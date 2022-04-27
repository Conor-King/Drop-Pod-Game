#pragma once

#include "ecm.h"
#include <SFML/Graphics/Shape.hpp>
#include <SFML/Graphics/Sprite.hpp>

class SpriteComponent : public Component {
protected:
	std::shared_ptr<sf::Sprite> _sprite;
	std::shared_ptr<sf::Texture> _texture;
public:
	SpriteComponent() = delete;

	explicit SpriteComponent(Entity* p);
	void update(double dt) override;
	void render() override;

	sf::Sprite& getSprite() const;

	void setTexture(std::shared_ptr<sf::Texture> tex);
	void setTextureRect(sf::IntRect rect);
};

class ShapeComponent : public Component {
protected:
	std::shared_ptr<sf::Shape> _shape;
	// sf::Shape _shape;

public:
	ShapeComponent() = delete;

	explicit ShapeComponent(Entity* p);

	void update(double dt) override;
	void render() override;
	sf::Shape& getShape() const;
	template <typename T, typename... Targs> void setShape(Targs... params) {
		_shape.reset(new T(params...));
	}
};

struct Frame {
	sf::IntRect rect;
	double duration;
};

class AnimationComponent : public Component {
	friend struct Frame;
protected:
	std::vector<Frame> frames;
	double totalLength;
	double totalProgress;
	sf::Sprite* target;
public:

	AnimationComponent() = delete;

	explicit AnimationComponent(Entity* p);

	void update(double dt) override;
	void addFrame(Frame& frame);
	void render();

	void setAnimation(int i, float duration, std::string path);
};