#include "scene_menu.h"
#include "../components/cmp_text.h"
#include "../drop_pod_game.h"
#include <SFML/Window/Keyboard.hpp>
#include <iostream>

using namespace std;
using namespace sf;



void MenuScene::Load() {
    {
        void MenuScene::Load() {
            cout << "Menu Load \n";
            {
                auto txt = makeEntity();
                auto t = txt->addComponent<TextComponent>(
                    "Drop Pod\nPress Space to Start");
            }
            setLoaded(true);
        }
        // Buttons with possition 
        // Title
        m_gameTitle.setString("Game Title");
        m_gameTitle.setOrigin(m_gameTitle.getLocalBounds().width / 2,
            m_gameTitle.getLocalBounds().height / 2);
        m_gameTitle.setPosition(m_context->m_window->getSize().x / 2,
            m_context->m_window->getSize().y / 2 - 150.f);

        // Play Button
        m_playButton.setString("Play");
        m_playButton.setOrigin(m_playButton.getLocalBounds().width / 2,
            m_playButton.getLocalBounds().height / 2);
        m_playButton.setPosition(m_context->m_window->getSize().x / 2,
            m_context->m_window->getSize().y / 2 - 25.f);
        m_playButton.setCharacterSize(25);

        // Exit Button
        m_exitButton.setString("Exit");
        m_exitButton.setOrigin(m_exitButton.getLocalBounds().width / 2,
            m_exitButton.getLocalBounds().height / 2);
        m_exitButton.setPosition(m_context->m_window->getSize().x / 2,
            m_context->m_window->getSize().y / 2 + 25.f);
        m_exitButton.setCharacterSize(25);

    }







void MenuScene::Update(sf::Time deltaTime) {
 

    {
        if (m_isPlayButtonSelected)
        {
            m_playButton.setFillColor(sf::Color::Black);
            m_exitButton.setFillColor(sf::Color::White);
        }
        else
        {
            m_exitButton.setFillColor(sf::Color::Black);
            m_playButton.setFillColor(sf::Color::White);
        }

        if (m_isPlayButtonPressed)
        {
            m_context->m_states->Add(std::make_unique<GamePlay>(m_context), true);
        }
        else if (m_isExitButtonPressed)
        {
            m_context->m_window->close();
        }

    }

  Scene::Update(dt);
}
