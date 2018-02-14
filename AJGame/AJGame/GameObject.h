
#include<vector>

class GameObject 
{
protected:
	GameObject* parent;
	
	std::vector<GameObject*> children;
};