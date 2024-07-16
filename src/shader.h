#ifndef SHADER_H
#define SHADER_H

#include <glad/glad.h> // include glad to get all the required OpenGL headers

#include <string>
#include <fstream>
#include <sstream>
#include <iostream>

class Shader
{
public:
    //the program ID
    unsigned int ID;

    //constructor read and build shader
    Shader(const char* vertexPath, const char* fragmentPath)
    {
        //1.retrieve the vertex/fragment source code from filePath
        std::string vertexCode;
        std::string fragmentCode;
        std::ifstream vShaderFile;
        std::ifstream fShaderFile;
        //ensure ifstream object can throw exceptions:
    }
    //use/activate the shader
    void use();
    //utility uniform functions
    void setBool(const std::string &name, bool value) const;//const = not modify attribute in object
    void setInt(const std::string &name, int value) const;   
    void setFloat(const std::string &name, float value) const;
};

#endif
