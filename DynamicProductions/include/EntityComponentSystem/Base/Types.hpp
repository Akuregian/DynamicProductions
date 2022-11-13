#pragma once
#include <set>

namespace ECS {

	class System;
	class Component;

	// constants
	const size_t MAX_ENTITY_COUNT = 5000;
	const size_t MAX_COMPONENT_COUNT = 32;

	// custom types
	typedef size_t EntityID;
	typedef size_t SystemTypeID;
	typedef size_t ComponentTypeID;
	typedef std::set<ComponentTypeID> EntitySignature;

	// return a component runtime typeID
	inline static const ComponentTypeID GetRuntimeComponentTypeID() {
		static ComponentTypeID typeID = 0u;
		return typeID++;
	}

	// return a system runtime typeID
	inline static const SystemTypeID GetRuntimeSystemTypeID() {
		static SystemTypeID typeID = 0u;
		return typeID++;
	}

	// attach type id to component class and return it
	template<typename T>
	inline static const ComponentTypeID ComponentType() noexcept {
		static_assert((std::is_base_of<Component, T>::value && !std::is_same<Component, T>::value), "INVALID TEMPLATE TYPE");
		static const ComponentTypeID typeID = GetRuntimeComponentTypeID();
		return typeID;
	}

	// attach type id to system class and return it
	template<typename T>
	inline static const SystemTypeID SystemType() noexcept {
		static_assert((std::is_base_of<System, T>::value && !std::is_same<System, T>::value), "INVALID TEMPLATE TYPE");
		static const SystemTypeID typeID = GetRuntimeSystemTypeID();
		return typeID;
	}

}
