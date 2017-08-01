#pragma once
#include<SFML/Audio.hpp>
class MusicController
{
public:
	MusicController();
	~MusicController(); 

	void play_gameLoopMusicStage1(); 
	void play_fireTileShoot();
	void play_destroy();
	void play_playerDamadge(); 
	void play_collectCoins(); 
	void play_dead();
private: 
	sf::Music m_gameLoopMusicStage1; 
	sf::Music m_fireTileShoot; 
	sf::Music m_destroy; 
	sf::Music m_playerDamadge; 
	sf::Music m_collectCoin;
	sf::Music m_dead;
};

