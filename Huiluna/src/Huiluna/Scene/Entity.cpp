#include "hlpch.h"
#include "Entity.h"

namespace Huiluna {

	Entity::Entity(entt::entity handle, Scene* scene)
		: m_EntityHandle(handle), m_Scene(scene)
	{
	}

}