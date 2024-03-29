#pragma once

#include <SFML/Graphics.hpp>
#include <fstream>
#include "MainMenu.h"
#include "Snake.h"
#include "State.h"

#define SHOP_ELEMENTS 4

class Shop : public State {
public:
    explicit Shop(std::shared_ptr<Param> param);

    void update(const sf::Time &deltaTime) override;

    void draw() override;

    void input() override;

private:
    void loadBought();

    void loadCurrency();

    void buySnakeColor(int colorIndex, int price);

    void saveBought();

    void saveData();

    void moveUp();

    void moveDown();

    void print(std::unique_ptr<sf::RenderWindow> &window);//-

    void drawExtra(std::unique_ptr<sf::RenderWindow> &window);

    void handleKeyInput(sf::Keyboard::Key keyCode);

    void returnToMainMenu();

    void handleShopSelection();

    std::shared_ptr<Param> mParam;
    sf::Sprite mBgImage;
    sf::Texture mBackground;
    sf::Font mFont;
    sf::Text mMainText[SHOP_ELEMENTS];
    sf::Text mTextChild[SHOP_ELEMENTS];
    sf::Text mAltText[SHOP_ELEMENTS];
    sf::Text mExtraText[2];
    const sf::Color mFillColor = sf::Color(255, 204, 153);
    int mShopSelect;
    int mMainTextFontSize = 35;
    int mTextChildFontSize = 20;

    int mShopCurrency;
    int mEquipped;
};
