#include "audio_manager.hpp"

using namespace irrklang;

ISoundEngine *SoundEngine = createIrrKlangDevice();

AudioManager::AudioManager()
{
}

void AudioManager::play2D(const std::string& soundFilePath, GLboolean State)
{
	SoundEngine->play2D(soundFilePath.c_str(), State);
}

void AudioManager::play3D(const std::string& soundFilePath, irrklang::vec3df position)
{
	SoundEngine->play3D(soundFilePath.c_str(), position);
}

AudioManager::~AudioManager()
{
	SoundEngine->drop();
}
