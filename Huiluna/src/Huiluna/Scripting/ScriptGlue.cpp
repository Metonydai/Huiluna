#include "hlpch.h"
#include "ScriptGlue.h"
#include "ScriptEngine.h"

#include "Huiluna/Core/UUID.h"
#include "Huiluna/Core/KeyCodes.h"
#include "Huiluna/Core/Input.h"
#include "Huiluna/Scene/Scene.h"
#include "Huiluna/Scene/Entity.h"

#include "mono/metadata/object.h"

namespace Huiluna {

#define HL_ADD_INTERNAL_CALL(Name) mono_add_internal_call("Huiluna.InternalCalls::" #Name, Name)

	static void NativeLog(MonoString* string, int parameter)
	{
		char* cStr = mono_string_to_utf8(string);
		std::string str(cStr);
		mono_free(cStr);
		std::cout << str << ", " << parameter << std::endl;;
	}

	static void NativeLog_Vector(glm::vec3* parameter, glm::vec3* outResult)
	{
		HL_CORE_INFO("Value: {0}", *parameter);

		*outResult = glm::normalize(*parameter);
	}

	static float NativeLog_VectorDot(glm::vec3* parameter)
	{
		HL_CORE_INFO("NativeLog_VectorDot: {0}", *parameter);

		return glm::dot(*parameter, *parameter);
	}

	static void Entity_GetTranslation(UUID entityID, glm::vec3* outTranslation)
	{
		Scene* scene = ScriptEngine::GetSceneContext();

		Entity entity = scene->GetEntityByUUID(entityID);
		*outTranslation = entity.GetComponent<TransformComponent>().Translation;
	}

	static void Entity_SetTranslation(UUID entityID, glm::vec3* translation)
	{
		Scene* scene = ScriptEngine::GetSceneContext();

		Entity entity = scene->GetEntityByUUID(entityID);
		entity.GetComponent<TransformComponent>().Translation = *translation;
	}

	static bool Input_IsKeyDown(KeyCode keycode)
	{
		return Input::IsKeyPressed(keycode);
	}

	void ScriptGlue::RegisterFunctions()
	{
		HL_ADD_INTERNAL_CALL(NativeLog);
		HL_ADD_INTERNAL_CALL(NativeLog_Vector);
		HL_ADD_INTERNAL_CALL(NativeLog_VectorDot);


		HL_ADD_INTERNAL_CALL(Entity_GetTranslation);
		HL_ADD_INTERNAL_CALL(Entity_SetTranslation);
		HL_ADD_INTERNAL_CALL(Input_IsKeyDown);
	}
}