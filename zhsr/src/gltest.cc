#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <glad/glad.h> 
#include <GLFW/glfw3.h>
#include <glad.c>

void framebuffer_size_callback(GLFWwindow* window, int width, int height) {
	glViewport(0, 0, width, height);
	printf("width %i\nheight %i\n", width, height);
} 

int main(int argc, char** argv) {

	glfwInit();
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3); // opengl 3.3
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_OPENGL_FORWARD_COMPAT, GL_TRUE); // apparently macos needs this, fuck macos x 999

    GLFWwindow* window = glfwCreateWindow(640, 480, "zhsr-gltest", NULL, NULL);
    glfwSetWindowSizeLimits(window, 640, 480, 640, 480);
    //glfwSetWindowAspectRatio(window, 4, 3); // implement later, determine ratio from window size

    if (!window) {
    	printf("Could not create GLFW window\n");
    	glfwTerminate();
    	return 1;
	}

	glfwMakeContextCurrent(window);

	if (!gladLoadGLLoader((GLADloadproc)glfwGetProcAddress)) {
    	printf("Could not load GLAD\n");
    	return -1;
	}    

	glViewport(0, 0, 640, 480);

	glfwSetFramebufferSizeCallback(window, framebuffer_size_callback); // run when resized

	while(!glfwWindowShouldClose(window)) {
		glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // you can make a fucking translucent window what the fuck
		glEnable( GL_SCISSOR_TEST );
		glScissor( 5, 5, 12, 12 ); // position of pixel
		glClearColor( 1.0f, 1.0f, 1.0f, 0.0f ); // color of pixel
		glClear(GL_COLOR_BUFFER_BIT);
		glDisable( GL_SCISSOR_TEST );
		glClearColor(0.0f, 0.0f, 0.0f, 0.5f); // you can make a fucking translucent window what the fuck
		

    	glfwSwapBuffers(window); // replace al_flip_display with this
    	glfwPollEvents(); // handle keyboard, mouse, etc i guess
	}

	glfwTerminate(); // app ended

	printf("reached end\n");
	return 0;
}
