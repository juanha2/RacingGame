#pragma once
#include "Module.h"
#include "p2DynArray.h"
#include "Globals.h"#include "Timer.h"

class Primitive;
class  PhysBody3D;

class ModuleSceneIntro : public Module
{
public:
	ModuleSceneIntro(bool start_enabled = true);
	~ModuleSceneIntro();

	bool Start();
	update_status Update(float dt) override;
	update_status PostUpdate(float dt) override;

	void OnCollision(PhysBody3D* body1, PhysBody3D* body2) override;

	bool CleanUp();

	void CalculateBestLap(Timer* lap_time);


public:
	Timer lap_time;
	float best_lap_time=0.0f;

private:
	void HandleDebugInput();
	void DebugSpawnPrimitive(Primitive* p);

	bool victory_played = false;
	p2DynArray<Primitive*> primitives;
};
