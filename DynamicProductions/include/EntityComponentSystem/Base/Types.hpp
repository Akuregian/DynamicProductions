/* 
- Types of Components are just integer values i.e. 0, 1, 2, 3 
- EntitySignature is a set (cannot have duplicate values in set) of these values which determine who it belongs too.
*/

#pragma once
#include <set>

namespace ECS {

	// BaseSystem and BaseComponent Class
	class BaseSystem;
	struct BaseComponent;

	// Constants
	const size_t MAX_ENTITY_COUNT = 5000;
	const size_t MAX_COMPONENT_COUNT = 32;

	// Custom Types
	typedef size_t EntityID;
	typedef size_t SystemTypeID;
	typedef size_t ComponentTypeID;
	typedef std::set<ComponentTypeID> EntitySignature;

	// Return a Component TypeID at Runtime 
	inline static const ComponentTypeID GetRuntimeComponentTypeID() {
		static ComponentTypeID typeID = 0u;
		return typeID++;
	}

	// Return a System TypeID at Runtime 
	inline static const SystemTypeID GetRuntimeSystemTypeID() {
		static SystemTypeID typeID = 0u;
		return typeID++;
	}

	// Attach TypeID To Component and Return It
	template<typename T>
	inline static const ComponentTypeID ComponentType() noexcept {
		// Check if: T is derived from Component && is not the base class 'Component' itself
		static_assert((std::is_base_of<BaseComponent, T>::value && !std::is_same<BaseComponent, T>::value), "INVALID TEMPLATE TYPE");
		static const ComponentTypeID typeID = GetRuntimeComponentTypeID();
		return typeID;
	}

	// Attach TypeID To System and Return It
	template<typename T>
	inline static const SystemTypeID SystemType() noexcept {
		// Check if: T is derived from System && is not the base class 'System' itself
		static_assert((std::is_base_of<BaseSystem, T>::value && !std::is_same<BaseSystem, T>::value), "INVALID TEMPLATE TYPE");
		static const SystemTypeID typeID = GetRuntimeSystemTypeID();
		return typeID;
	}

}
