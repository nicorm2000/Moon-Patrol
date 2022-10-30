#pragma once
namespace game
{
	void PlayerMovement();
	void ObstacleMovement();
	void MouseMovement();
	//void BackgroundMovement();
	//void BackgroundParallax();
	void Collisions();
	bool CheckCollisionRecRec(Vector2 r1, float r1w, float r1h, Vector2 r2, float r2w, float r2h);
	void PlayerCollision();
	void pauseIntputs();
	void RestartGame();
}
