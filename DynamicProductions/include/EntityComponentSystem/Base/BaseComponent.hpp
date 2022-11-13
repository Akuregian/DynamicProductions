#pragma once
#include "Types.hpp"

namespace ECS {
	struct BaseComponent {
		BaseComponent() : m_EntityID() { }
		virtual ~BaseComponent() { };
		inline const EntityID GetID() const { return m_EntityID; };

	private:
		friend class EntityManager;
		EntityID m_EntityID;
	};


}
