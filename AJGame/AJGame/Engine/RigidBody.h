#pragma once
#include "Components.h"

class RigidBody : Components
{
	Vec3 m_Pos;
    Vec3 m_Vel;
    Vec3 m_Accel; Vec3List m_Forces; Vec3List m_Impulses; 
	float m_Mass;
    void AddForce(const Vec3 &force) { m_Forces.push_back(force); }
void AddImpulse(const Vec3 &impulse)
{
	m_Impulses.push_back(impulse);
}
void OnUpdate(const float time);
};