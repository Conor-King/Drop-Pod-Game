#include "cmp_text.h"
#include <system_renderer.h>
#include <system_resources.h>

void TextComponent::update(double dt) {}

void TextComponent::render() { Renderer::queue(&_text); }

TextComponent::TextComponent(Entity* const p, float x, float y, const std::string& str)
    : Component(p), _string(str) { 
    _text.setString(_string);
    // https://en.sfml-dev.org/forums/index.php?topic=15875.0 //
    _font = Resources::get<sf::Font>("RobotoMono-Regular.ttf");
    _text.setFont(*_font);
    _text.setCharacterSize(50);
    _text.setPosition(sf::Vector2f(x, y));
    _text.setOrigin(_text.getLocalBounds().width / 2.0f, _text.getLocalBounds().height / 2.0f);
}

void TextComponent::SetText(const std::string& str) {
    _string = str;
    _text.setString(_string);
}