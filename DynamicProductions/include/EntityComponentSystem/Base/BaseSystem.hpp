#pragma once
#include "Types.hpp"

namespace ECS {

	class BaseSystem {
	public:
		BaseSystem() = default;
		virtual ~BaseSystem() = default;

		// Removed an Entity from the System based off the EntityID
		void RemoveEntity(const EntityID entity) {
			m_Entities.erase(entity);
		}

		// Adds a new Entity to the System based off the EntityID
		void AddEntity(const EntityID entity) {
			m_Entities.insert(entity);
		}
		
		// Gets the Signature of the component
		const EntitySignature GetSignature() const { return m_Signature; }

		// Adds the Components Signature
		template<typename T>
		void AddComponentSignature() {
			m_Signature.insert(ComponentType<T>());
		}

		virtual void Start() {};
		virtual void Update() {};
		virtual void Destroy() {};

	protected:
		friend class EntityManager;
		EntitySignature m_Signature;
		std::set<EntityID> m_Entities;

	};
}