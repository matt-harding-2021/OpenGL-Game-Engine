/**\ file shader.h */
#pragma once

#include <fstream>
#include <array>

#include <glm/glm.hpp>

namespace Engine {
	class Shader
	{
	private: uint32_t m_OpenGL_ID;
	public:
		static Shader* create(const char* arg_VerFilepath, const char* arg_FragFilepath);
		static Shader* create(const char* arg_Filepath);
		~Shader() = default;

		/**\ API AGNOSTIC SHADER CLASS */
		virtual uint32_t getID() const = 0;

		virtual void uploadInt(const char* arg_Name, int arg_Value) = 0;
		virtual void uploadFloat(const char* arg_Name, float arg_Value) = 0;
		virtual void uploadFloat2(const char* arg_Name, const glm::vec2& arg_Value) = 0; // Should it need glm if its API agnostic?
		virtual void uploadFloat3(const char* arg_Name, const glm::vec3& arg_Value) = 0;
		virtual void uploadFloat4(const char* arg_Name, const glm::vec4& arg_Value) = 0;
		virtual void uploadMat4(const char* arg_Name, const glm::mat4& arg_Value) = 0;
	};
}