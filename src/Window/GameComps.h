#pragma once
namespace game
{
	void MouseMovement();
	void Update();
	void ObstacleMovement();
	void Collisions();
	bool CheckCollisionRecRec(Vector2 r1, float r1w, float r1h, Vector2 r2, float r2w, float r2h);
	void PlayerCollision();
	void PlayerMovement();
	void PlayerJump();
	void BackgroundMovement();
	void pauseIntputs();
	void RestartGame();
}
