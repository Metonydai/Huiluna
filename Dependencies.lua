-- Huiluna Dependencies

VULKAN_SDK = os.getenv("VULKAN_SDK")

IncludeDir = {}
IncludeDir["stb_image"] = "%{wks.location}/Huiluna/vendor/stb_image"
IncludeDir["yaml_cpp"] = "%{wks.location}/Huiluna/vendor/yaml-cpp/include"
IncludeDir["Box2D"] = "%{wks.location}/Huiluna/vendor/Box2D/include"
IncludeDir["GLFW"] = "%{wks.location}/Huiluna/vendor/GLFW/include"
IncludeDir["Glad"] = "%{wks.location}/Huiluna/vendor/Glad/include"
IncludeDir["ImGui"] = "%{wks.location}/Huiluna/vendor/ImGui"
IncludeDir["ImGuizmo"] = "%{wks.location}/Huiluna/vendor/ImGuizmo"
IncludeDir["glm"] = "%{wks.location}/Huiluna/vendor/glm"
IncludeDir["entt"] = "%{wks.location}/Huiluna/vendor/entt/include"
IncludeDir["mono"] = "%{wks.location}/Huiluna/vendor/mono/include"
--IncludeDir["shaderc"] = "%{wks.location}/Huiluna/vendor/shaderc/include"
--IncludeDir["SPIRV_Cross"] = "%{wks.location}/Huiluna/vendor/SPIRV-Cross"
IncludeDir["shaderc"] = "%{VULKAN_SDK}/Include/shaderc"
IncludeDir["SPIRV_Cross"] = "%{VULKAN_SDK}/Include/spirv_cross"
IncludeDir["VulkanSDK"] = "%{VULKAN_SDK}/Include"

LibraryDir = {}

LibraryDir["mono"] = "%{wks.location}/Huiluna/vendor/mono/lib/%{cfg.buildcfg}"
LibraryDir["VulkanSDK"] = "%{VULKAN_SDK}/Lib"
LibraryDir["VulkanSDK_Debug"] = "%{VULKAN_SDK}/Lib"

Library = {}
Library["mono"] = "%{LibraryDir.mono}/libmono-static-sgen.lib"

Library["Vulkan"] = "%{LibraryDir.VulkanSDK}/vulkan-1.lib"
Library["VulkanUtils"] = "%{LibraryDir.VulkanSDK}/VkLayer_utils.lib"

Library["ShaderC_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/shaderc_sharedd.lib"
Library["SPIRV_Cross_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-cored.lib"
Library["SPIRV_Cross_GLSL_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/spirv-cross-glsld.lib"
Library["SPIRV_Tools_Debug"] = "%{LibraryDir.VulkanSDK_Debug}/SPIRV-Toolsd.lib"

Library["ShaderC_Release"] = "%{LibraryDir.VulkanSDK}/shaderc_shared.lib"
Library["SPIRV_Cross_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-core.lib"
Library["SPIRV_Cross_GLSL_Release"] = "%{LibraryDir.VulkanSDK}/spirv-cross-glsl.lib"

-- Windows --
Library["WinSock"] = "Ws2_32.lib"
Library["WinMM"] = "Winmm.lib"
Library["WinVersion"] = "Version.lib"
Library["BCrypt"] = "Bcrypt.lib"
