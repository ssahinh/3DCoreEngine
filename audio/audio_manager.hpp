#ifndef AUDIO_MANAGER_HPP
#define AUDIO_MANAGER_HPP

#define GLEW_STATIC
#include <GL/glew.h>

#include <irrKlang.h>

#include <string>

class AudioManager
{
public:
	AudioManager();
	~AudioManager();

	void play2D(const std::string& soundFilePath, GLboolean State);
	void play3D(const std::string& soundFilePath, irrklang::vec3df position);
};

#endif