#pragma once

#include <SFML/Graphics.hpp>
#include "Ente.h"

class Entidade : public Ente {
protected:
    sf::Sprite sprite;
    int x, y;
    bool isVisible;

public:
    Entidade() : x(0), y(0), isVisible(true) {}
    Entidade(int x, int y) : x(x), y(y), isVisible(true) {}
    virtual ~Entidade() {}

    // These override the base Ente methods
    void draw(sf::RenderTarget& target, sf::RenderStates states) const override {
        target.draw(sprite, states);
    }

    void render(sf::RenderWindow& window) override {
        if (isVisible)
            window.draw(sprite);
    }

    // Must be overridden in derived classes
    virtual void update(float deltaTime) override = 0;
    virtual void handleCollision(Entidade& other) = 0;

    // Position accessors
    int getX() const { return x; }
    int getY() const { return y; }
    void setX(int newX) { x = newX; }
    void setY(int newY) { y = newY; }

    void setSprite(const sf::Texture& texture) {
        sprite.setTexture(texture);
    }
};
