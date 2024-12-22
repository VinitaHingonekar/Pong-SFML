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

		const float scale_x = 0.05f; // 20% of original size
		const float scale_y = 0.05f;

		CircleShape ball_sprite;

		const float radius = 10.0f;
		const float position_x = 615.0f;
		const float position_y = 335.0f;

		void loadTexture();
		void initializeVariables();

		//moving
		float ball_speed = 0.5f;
		Vector2f velocity = Vector2f(ball_speed, ball_speed);

		void move();

	public:
		Ball();
		void update();
		void render(RenderWindow* game_window);

	};
}