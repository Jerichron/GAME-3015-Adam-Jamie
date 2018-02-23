#include "SFML/Graphics/Transform.hpp"
#include "Components.h"
#include  <vector>
#include "Components/Transform.h"

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

private:

	int m_UniqueID;

	std::vector<Components*> m_Components;

	GameObject* m_Parent;
	
	sf::Transform worldTransform;

	std::vector<GameObject*> m_Children;
};
