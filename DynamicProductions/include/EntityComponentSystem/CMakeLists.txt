add_library( EntityComponentSystem STATIC 
			"ECS.hpp" 
			"Base/Types.hpp" 
			"Base/BaseComponent.hpp" 
			"Base/BaseSystem.hpp" 
			"Base/ComponentList.hpp" 
			"Base/EntityManager.hpp" 
)

set_target_properties(EntityComponentSystem PROPERTIES LINKER_LANGUAGE CXX)

