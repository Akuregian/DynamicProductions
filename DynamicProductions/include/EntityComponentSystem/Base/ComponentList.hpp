#pragma once
#include<vector>
#include <assert.h>
#include "Types.hpp"

namespace ECS {

	class IComponentList {
	public:
		IComponentList() = default;
		virtual ~IComponentList() = default;
		virtual void Erase(const EntityID entity) { }
	};

	template<typename T>
	class ComponentList : public IComponentList {
	public:
		ComponentList() = default;
		~ComponentList() = default;

		void Insert(const T& component) {
			auto comp = std::find_if(m_Data.begin(), m_Data.end(), [&](const T& c) { return c.GetID() == component.GetID(); });
			if (comp != m_Data.end()) {
				m_Data.push_back(component);
			}
		}

		T& Get(const EntityID entity) {
			auto comp = std::find_if(m_Data.begin(), m_Data.end(), [&](const T& c) { return c.GetID() == entity;  });
			assert(comp != m_Data.end() && "Trying to get a non-existing component");
			return *comp;
		}

		void Erase(const EntityID entity) override final {
			auto comp = std::find_if(m_Data.begin(), m_Data.end(), [&](const T& c) { return c.GetID() == entity; });
			if (comp != m_Data.end()) {
				m_Data.erase(comp);
			}
		}
		
		std::vector<T> m_Data;
	};
}