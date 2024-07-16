// #include <glad/glad.h>
// #include <GLFW/glfw3.h>

// #include <iostream>

// void framebuffer_size_callback(GLFWwindow* window, int width, int height);
// void processInput(GLFWwindow *window);

// //setting
// const unsigned int SCR_WIDTH = 800;
// const unsigned int SCR_HEIGHT = 600;

// const char *vertexShaderSource = R"(
//     #version 330 core
//     layout (location = 0) in vec3 aPos;

//     void main()
//     {
//         gl_Position = vec4(aPos.x, aPos.y, aPos.z, 1.0f);
//     }
// )";

// const char *fragmentShaderSource = R"(
//     #version 330 core
//     out vec4 FragColor;

//     void main()
//     {
//         FragColor = vec4(1.0f, 1.0f, 0.0f, 1.0f);
//     }
// )";

// int main()
// {
//     //glfw: initialize and configure
//     glfwInit();
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
//     glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
//     glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

// #ifdef __APPLE__
//     glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE);
// #endif

//     //glfw window creation
//     //--------------------
//     GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "Learning OpenGL", NULL, NULL);
//     if(window == NULL)
//     {
//         std::cout << "Failed to create GLFW window" << std::endl;
//         glfwTerminate();
//         return -1;
//     }
//     glfwMakeContextCurrent(window);
//     glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

//     // glad: load all OpenGL function pointers
//     //----------------------------------------
//     if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress))
//     {
//         std::cout << "Failed to initialize GLAD" << std::endl;
//         return -1;
//     }


//     //build and compile our shader program
//     //--------------------------------------
//     //vertex shader
//     unsigned int vertexShader = glCreateShader(GL_VERTEX_SHADER);
//     glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
//     glCompileShader(vertexShader);
//     //check for shader compile errors
//     int success;
//     char infoLog[512];
//     glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
//     if (!success)
//     {
//         glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n";
//     }
//     //fragment shader
//     unsigned int fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
//     glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
//     glCompileShader(fragmentShader);
//     glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
//     if (!success)
//     {
//         glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n";
//     }
//     //link shader
//     unsigned int shaderProgram = glCreateProgram();
//     glAttachShader(shaderProgram, vertexShader);
//     glAttachShader(shaderProgram, fragmentShader);
//     glLinkProgram(shaderProgram);
//     //chec for linking errors
//     glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
//     if (!success)
//     {
//         glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
//         std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n";
//     }
//     glDeleteShader(vertexShader);
//     glDeleteShader(fragmentShader);

//     // set up vertex data (and buffer(s)) and configure vertex attributes
//     // ------------------------------------------------------------------
//     float vertices1[] = {
//          0.5f,  0.5f, 0.0f, //top right
//          0.5f, -0.5f, 0.0f, //bottom right
//         -0.5f,  0.5f, 0.0f,  //top left
//     };
//     float vertices2[] = {
//          0.5f, -0.5f, 0.0f, //bottom right
//         -0.5f, -0.5f, 0.0f, //bottom left
//         -0.5f,  0.5f, 0.0f  //top left
//     };
//     // unsigned int indices[] {
//     //     0, 1 ,3, //first triangle
//     //     1, 2, 3  //second triangle
//     // };

//     unsigned int VBOs[2], VAOs[2];
//     glGenVertexArrays(2, VAOs);
//     glGenBuffers(2, VBOs);

//     //bind the Vertex Array Object first, then bind and set vertex buffer(s), and then configure vertex attributes(s).
//     glBindVertexArray(VAOs[0]);

//     glBindBuffer(GL_ARRAY_BUFFER, VBOs[0]);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices1), vertices1, GL_STATIC_DRAW);
    
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);

//     //2nd

//     glBindVertexArray(VAOs[1]);

//     glBindBuffer(GL_ARRAY_BUFFER, VBOs[1]);
//     glBufferData(GL_ARRAY_BUFFER, sizeof(vertices2), vertices2, GL_STATIC_DRAW);
    
//     glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 3 * sizeof(float), (void*)0);
//     glEnableVertexAttribArray(0);

//     // You can unbind the VAO afterwards so other VAO calls won't accidentally modify this VAO, 
//     // but this rarely happens. Modifying other VAOs requires a call to glBindVertexArray anyways 
//     // so we generally don't unbind VAOs (nor VBOs) when it's not directly necessary.
//     glBindVertexArray(0); 

//     // uncomment this call to draw in wireframe polygons.
//     // glPolygonMode(GL_FRONT_AND_BACK, GL_LINE);

//     while (!glfwWindowShouldClose(window))
//     {
//         ///input
//         //------
//         processInput(window);

//         //render
//         //------
//         glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
//         glClear(GL_COLOR_BUFFER_BIT);

//         //draw our first triangle
//         glUseProgram(shaderProgram);
//         // glBindVertexArray(VAO1); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//         // glDrawArrays(GL_TRIANGLES, 0, 3);
//         // // glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
//         // glBindVertexArray(0); // no need to unbind it every time 
//         glBindVertexArray(VAOs[0]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//         glDrawArrays(GL_TRIANGLES, 0, 3);
//         glBindVertexArray(VAOs[1]); // seeing as we only have a single VAO there's no need to bind it every time, but we'll do so to keep things a bit more organized
//         glDrawArrays(GL_TRIANGLES, 0, 3);


//         //glfw: swap buffers and poll IO events (keys pressed/released, mouse moved etc.)
//         //-------------------------------------------------------------------------------
//         glfwSwapBuffers(window);
//         glfwPollEvents();
//     }
//     // optional: de-allocate all resources once they've outlived their purpose:
//     // ------------------------------------------------------------------------
//     glDeleteVertexArrays(2, VAOs);
//     glDeleteBuffers(2, VBOs);
//     glDeleteProgram(shaderProgram);
    
//     // glfw: terminate, clearing all previously allocated GLFW resources.
//     //------------------------------------------------------------------
//     glfwTerminate();
//     return 0;
// }

// // process all input: query GLFW whether relevant keys are pressed/released this frame and react accordingly.
// // ----------------------------------------------------------------------------------------------------------

// void processInput(GLFWwindow* window)
// {
//     if (glfwGetKey(window, GLFW_KEY_ESCAPE) == GLFW_PRESS)
//         glfwSetWindowShouldClose(window, true);
// }

// // glfw: whenever the window size changed (by OS or user resize) this callback function executes
// // ---------------------------------------------------------------------------------------------
// void framebuffer_size_callback(GLFWwindow* window, int width, int height)
// {
//     // make sure the viewport matches the new window dimensions; note that width and 
//     // height will be significantly larger than specified on retina displays.
//     glViewport(0, 0, width, height);
// }