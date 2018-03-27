#ifndef GameObject_h
#define GameObject_h

#include "Components/Transform/Transform.h"
#include "Components/Renderer/Mesh.h"
#include "Components/Messages.h"
#include "Components.h"
#include <iostream>
#include <vector>
#include <list>
#include <iterator>
#include <stdio.h>



class GameObject 
{
public:
	GameObject(int uniqueID) : m_UniqueID(uniqueID), m_Parent(NULL) { }
	~GameObject() {}
	int GetObjectID() const { return m_UniqueID; }
	bool SendMessage(Messages* msg);

	void AddComponent(Components* component);

	void SetParent(GameObject& p) { m_Parent = &p; }
	void AddChild(GameObject* s);

	void Update(float msec);
	void Awake();
	void Start();
	void LateUpdate(float msec);

	virtual void			draw(sf::RenderTarget& target) const;

private:
	bool PassMessageToComponents(Messages* msg);
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