int main() {
    glfwSetErrorCallback(glfwErrorCallback);

    if (!glfwInit()) {
        std::cerr << "GLFW init failed\n";
        return -1;
    }

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);

    GLFWwindow* window = glfwCreateWindow(SCR_WIDTH, SCR_HEIGHT, "VoxelProject", nullptr, nullptr);
    if (!window) {
        std::cerr << "Window creation failed\n";
        glfwTerminate();
        return -1;
    }

    glfwMakeContextCurrent(window);
    glfwSetFramebufferSizeCallback(window, framebuffer_size_callback);

    glfwSetCursorPosCallback(window, mouse_callback);
    glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_DISABLED);

    if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
        std::cerr << "Failed to initialize GLAD\n";
        glfwTerminate();
        return -1;
    }

    glEnable(GL_DEPTH_TEST);

    GLuint program = makeProgram(VS, FS);

    ChunkManager world;
    world.ensureRadius({0,0,0}, 2);
    world.rebuildDirty();

    float lastTime = (float)glfwGetTime();

    while (!glfwWindowShouldClose(window)) {
        float now = (float)glfwGetTime();
        float dt = now - lastTime;
        lastTime = now;

        processInput(window);
        gCamera.processKeyboard(window, dt);


		// Rendering Process
        glClearColor(0.20f, 0.30f, 0.30f, 1.0f);
        glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

        glUseProgram(program);

        glm::mat4 proj = glm::perspective(glm::radians(75.0f), (float)SCR_WIDTH / (float)SCR_HEIGHT, 0.1f, 500.0f);
        glm::mat4 view = gCamera.view();

        glUniformMatrix4fv(glGetUniformLocation(program, "uProj"), 1, GL_FALSE, &proj[0][0]);
        glUniformMatrix4fv(glGetUniformLocation(program, "uView"), 1, GL_FALSE, &view[0][0]);

        world.drawAll();

        glfwSwapBuffers(window);
        glfwPollEvents();
    }

    glfwTerminate(); // Fixed recursive loop closing the program everytime!!!!
    return 0;
}
