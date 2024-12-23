#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "../../../Header/Gameplay/Paddle/Paddle.h"

using namespace sf;

namespace Gameplay
{
	enum class BallState
	{
		Idle,
		Moving
	};

	class Ball
	{
	private:
		Texture pong_ball_texture;
		const std::string texture_path = "Assets/Textures/Ball.png";

		Sprite pong_ball_sprite;

		const float scale_x = 0.05f; // 20% of original size
		const float scale_y = 0.05f;

		const float radius = 10.0f;

		const float position_x = 615.0f;
		const float position_y = 335.0f;

		const float top_boundary = 20.0f;
		const float bottom_boundary = 700.0f;

		const float left_boundary = 0.0f;
		const float right_boundary = 1280.0f;

		//Center Position
		const float center_position_x = 615.0f;
		const float center_position_y = 325.0f;

		void loadTexture();
		void initializeVariables();

		//moving
		float ball_speed = 10.0f;
		Vector2f velocity = Vector2f(ball_speed, ball_speed);

		void move(TimeService* time_service);

		float speed_multiplier = 50.0f;

		void handlePaddleCollision(Paddle* player1, Paddle* player2);
		void handleBoudaryCollision();
		void handleOutofBoundCollision();


		void onCollision(Paddle* player1, Paddle* player2);

		//initial delay
		float elapsed_delay_time;
		float delay_duration;

		BallState current_state;

		void updateDelayTime(float delta_time);

	public:
		Ball();
		void reset();
		//void update();
		void update(Paddle* player1, Paddle* player2, TimeService* time_service);
		void render(RenderWindow* game_window);

	};
}