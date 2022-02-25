#include "shader.h"

namespace ethyl::graphics {
    Shader::Shader(const char* vertPath, const char* fragPath)
        : m_vertPath(vertPath), m_fragPath(fragPath)
    {
        m_shaderId = load();
    }

    Shader::~Shader()
    {
        glDeleteProgram(m_shaderId);
    }
   
    GLuint Shader::load()
    {
        uint program = glCreateProgram();
        uint vertex = glCreateShader(GL_VERTEX_SHADER);
        uint fragment = glCreateShader(GL_FRAGMENT_SHADER);

        std::string vertSourceString = read_file(m_vertPath);
        std::string fragSourceString = read_file(m_fragPath);
        const char* vertSource = vertSourceString.c_str();
        const char* fragSource = fragSourceString.c_str();

        glShaderSource(vertex, 1, &vertSource, NULL);
        glCompileShader(vertex);

        int result;
        glGetShaderiv(vertex, GL_COMPILE_STATUS, &result);
        //glShaderSource(vertex, 1, &vertSource, NULL);
        if (result == GL_FALSE)
        {
            int length;
            glGetShaderiv(vertex, GL_INFO_LOG_LENGTH, &length);
            std::vector<char> error(length);
            glGetShaderInfoLog(vertex, length, &length, &error[0]);
            LOG("Failed to compile vertex shader: " << m_vertPath);
            LOG(&error[0]);
            glDeleteShader(vertex);
            return 0;
        }

        glShaderSource(fragment, 1, &fragSource, NULL);
        glCompileShader(fragment);

        glGetShaderiv(fragment, GL_COMPILE_STATUS, &result);
        //glShaderSource(fragment, 1, &fragSource, NULL);
        if (result == GL_FALSE)
        {
            int length;
            glGetShaderiv(fragment, GL_INFO_LOG_LENGTH, &length);
            std::vector<char> error(length);
            glGetShaderInfoLog(fragment, length, &length, &error[0]);
            LOG("Failed to compile fragment shader: " << m_fragPath);
            LOG(&error[0]);
            glDeleteShader(fragment);
            return 0;
        }

        glAttachShader(program, vertex);
        glAttachShader(program, fragment);

        glLinkProgram(program);
        glValidateProgram(program);

        glDeleteShader(vertex);
        glDeleteShader(fragment);

        return program;
    }

    void Shader::enable() const
    {
        glUseProgram(m_shaderId);
    }

    void Shader::disable() const
    {
        glUseProgram(0);
    }
}