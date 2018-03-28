#ifndef GameObject_h
#define GameObject_h

#include "Components/Transform/Transform.h"
#include "Components/Renderer/Mesh.h"
#include "Listener.h"
#include "Components.h"
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <stdio.h>



class GameObject : public Listener
{
public:
	GameObject(int uniqueID) : m_UniqueID(uniqueID), m_Parent(NULL) { }
	~GameObject() {}
	int GetObjectID() const { return m_UniqueID; }
	void HandleEvent(Event* msg);

	void AddComponent(Components* component);

	void SetParent(GameObject& p) { m_Parent = &p; }
	void AddChild(GameObject* s);

	void Update(float msec);
	void Awake();
	void Start();
	void LateUpdate(float msec);

	virtual void			draw(sf::RenderTarget& target) const;
public:
	Transform* transform;

	Mesh* mesh;

private:

	
	int m_UniqueID;
	std::vector<Components*> m_Components;
	GameObject* m_Parent;
	sf::Transform worldTransform;
	std::vector<GameObject*> m_Children;
};
#endif /* GameObject_h */