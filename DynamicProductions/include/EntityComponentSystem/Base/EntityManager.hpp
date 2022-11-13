/*
In charge of connecting the Entities with the Component and System
i.e. If an Entity has the same Signature as the System, Then it will couple the Entity and the System Together
or It can add Components to entities.
*/

#pragma once

#include <map>
#include <queue>
#include <memory>

#include "Types.hpp"
#include "BaseSystem.hpp"
#include "BaseComponent.hpp"
#include "ComponentList.hpp"

namespace ECS {
	class EntityManager {
	public:
		EntityManager() : m_EntityCount(0) {
			for (EntityID entity = 0u; entity < MAX_ENTITY_COUNT; entity++) {
				m_availableEntities.push(entity);
			}
		}

		~EntityManager(){ }

		const EntityID AddNewEntity() {
			const EntityID entityID = m_availableEntities.front();
			m_availableEntities.pop();
			m_EntityCount++;
			return entityID;
		}

		void DestroyEntity(const EntityID entity) {
			assert(entity < MAX_COMPONENT_COUNT && "EntityID is out of range!");
			m_EntitySignatures.erase(entity);

			for (auto& list : m_ComponentsList) {
				list.second->Erase(entity);
			}

			for (auto& system : m_RegisteredSystems) {
				system.second->RemoveEntity(entity);
			}

			m_EntityCount--;
			m_availableEntities.push(entity);
		}

	private:
		EntityID m_EntityCount;
		std::queue<EntityID> m_availableEntities;
		std::map<EntityID, EntitySignature> m_EntitySignatures;
		std::map<SystemTypeID, std::unique_ptr<BaseSystem>> m_RegisteredSystems;
		std::map<ComponentTypeID, std::shared_ptr<IComponentList>> m_ComponentsList;
	};
}