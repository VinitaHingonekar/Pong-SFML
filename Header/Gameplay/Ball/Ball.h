#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;

namespace Gameplay
{
	class Ball
	{
	private:
		Texture pong_ball_texture;
		const std::string texture_path = "Assets/Textures/Ball.png";

		Sprite pong_ball_sprite;

		const float scale_x = 0.2f; // 20% of original size
		const float scale_y = 0.2f;

		CircleShape ball_sprite;

		const float radius = 10.0f;
		const float position_x = 615.0f;
		const float position_y = 335.0f;

		void loadTexture();
		void initializeVariables();

	public:
		Ball();
		void update();
		void render(RenderWindow* game_window);

	};
}