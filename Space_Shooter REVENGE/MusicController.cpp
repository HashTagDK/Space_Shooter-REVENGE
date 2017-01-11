#include "MusicController.h"
#include<iostream>


MusicController::MusicController()
{
	if (!m_gameLoopMusicStage1.openFromFile("..\\\\music\\stage1.ogg"))
		std::cout << "Nie wczytano muci loop stage1";
	
	if (!m_fireTileShoot.openFromFile("..\\\\music\\SWAV_6.wav"))
		std::cout << "Nie wczytano muci loop fireTileShoot";
	
	if (!m_destroy.openFromFile("..\\\\music\\SWAV_11.wav"))
		std::cout << "Nie wczytano muci loop destroy";

	if (!m_collectCoin.openFromFile("..\\\\music\\SWAV_17.wav"))
		std::cout << "Nie wczytano muci loop collect Coin"; 
	if (!m_playerDamadge.openFromFile("..\\\\music\\SWAV_5.wav"))
		std::cout << "Nie wcztano music damadgePlayer";
	if (!m_dead.openFromFile("..\\\\music\\dead.wav"))
		std::cout << "Nie wcztano music dead";
}


MusicController::~MusicController()
{
} 

void MusicController::play_gameLoopMusicStage1(){
	m_gameLoopMusicStage1.setVolume(70);
	//m_gameLoopMusicStage1.setLoop(true);

	//m_gameLoopMusicStage1.play();
}

void MusicController::play_collectCoins() {
	m_collectCoin.setVolume(90); 
	//m_collectCoin.play();
} 

void MusicController::play_fireTileShoot() {
	m_fireTileShoot.setVolume(100); 
	//m_fireTileShoot.play();
}

void MusicController::play_destroy() {
	m_destroy.setVolume(90); 
	//m_destroy.play();
}

void MusicController::play_playerDamadge() {
	m_playerDamadge.setVolume(100); 
	//m_playerDamadge.play();
}

void MusicController::play_dead() {
	m_dead.setVolume(100); 
	//m_dead.play();
}
