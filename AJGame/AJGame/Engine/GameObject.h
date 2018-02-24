#ifndef GameObject_h
#define GameObject_h

#include "Components.h"
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <stdio.h>
#include "Components/Transform/Transform.h"


class GameObject 
{
public:
	GameObject(int uniqueID) : m_UniqueID(uniqueID), m_Parent(NULL) {}

	int GetObjectID() const { return m_UniqueID; }

	Transform transform;

	void SetParent(GameObject& p) { m_Parent = &p; }
	void AddChild(GameObject* s);
	void AddComponent(Components* component);

	void Update(float msec);
	void Awake();
	void Start();
	void LateUpdate(float msec);
	void draw(sf::RenderTarget& target, sf::RenderStates state);

private:

	int m_UniqueID;
	std::vector<Components*> m_Components;
	GameObject* m_Parent;
	sf::Transform worldTransform;
	std::vector<GameObject*> m_Children;
};
#endif /* GameObject_h */