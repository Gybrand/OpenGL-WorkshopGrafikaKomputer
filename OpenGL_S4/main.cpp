
//INSTALIZATION
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
int main(void)
{
	GLFWwindow *window;
	//initialize he GLFW
	if (!glfwInit()) {
		return -1;
	}
	//create a windowed mode and its OpenGL context
	window = glfwCreateWindow(640, 480, "OpenGL Project Tutorial", NULL, NULL);
	if (!window) {
		glfwTerminate();
		return -1;
	}
	//make the windows context current
	//loop until the user coses the window
	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		//render the OpenGL
		//sweap front and back buffers
		glfwSwapBuffers(window);
		//poll for and process events
		glfwPollEvents();
	}
	glfwTerminate();
}
*/

/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {
	if (!glfwInit()) {
		fprintf(stderr, "ERROR : could not start GLFW\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);
	if (!window) {
		fprintf(stderr, "ERROR : could not open windows with GLFW3\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float points[] = {
		0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f,
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader ="#version 400\n""in vec3 vp;""void main() {""gl_Position = vec4(vp, 1.0);""}";

	const char* fragment_shader ="#version 400\n""out ver4 frag_colour;""void main() {""frag_colour = vec4(0, 1.0, 0, 1.0)""}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);
		glBindVertexArray(vao);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		glPointSize(15.0);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
*/

/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main() {

	if (!glfwInit()) {
		fprintf(stderr, "ERROR : courld not start GLFW3\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);

	if (!window) {
		fprintf(stderr, "ERROR : could not open windows with GLFW3\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Render : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float points[] = {
		0.0f, 0.5f, 0.0f, 0.5f, -0.5f, 0.0f, -0.5f, -0.5f, 0.0f,
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader = "#vesion 400\n""invet3 vp:""void main(){""gl_position = vec4(vp, 1.0""}";

	const char* fragment_shader = "#version 400\n""out vec4 frag_colour;""void main() {""frag_colour = vec4(0, 1.0, 0, 1.0);""}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_progamme = glCreateProgram();
	glAttachShader(shader_progamme, fs);
	glAttachShader(shader_progamme, vs);
	glLinkProgram(shader_progamme);


	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_progamme);
		glBindVertexArray(vao);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		glPointSize(15.0);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
*/

//PRIMITIVE DRAWING
//1 : THE TRIANGLES
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main()
{
	if (!glfwInit()) {
		fprintf(stderr, "ERROR : could start GLFW3\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);

	if (!window) {
		fprintf(stderr, "ERROR : could not open windows with GLFW3\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float points[] = {
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main() {"
		"   gl_Position = vec4(vp, 1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main() {"
		"   frag_colour = vec4(0.0, 1.0, 0.0, 1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);
		glBindVertexArray(vao);

		glDrawArrays(GL_TRIANGLES, 0, 3);
		glPointSize(15.0);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
*/

//2 : THE POINTS
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main()
{
	GLFWwindow* window;
	if (!glfwInit()) {
		fprintf(stderr, "ERROR : could start GLFW3\n");
		return -1;
	}

	window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);

	if (!window) {
		fprintf(stderr, "ERROR : could not open windows with GLFW3\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float points[] = {
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main() {"
		"   gl_Position = vec4(vp, 1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main() {"
		"   frag_colour = vec4(0.5, 0.0, 0.5, 1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);
		glBindVertexArray(vao);

		glDrawArrays(GL_POINTS, 0, 3);
		glPointSize(20.0);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
*/

//3 : KEYBOARD HANDLER FUNCTION
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glViewport(0.0f, 0.0f, screenWidth, screenHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		std::cout << "Space Key Pressed" << std::endl;
	}
}
*/

// 4 : MOUSE HANDLER FUNCTION
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos);

int main(void) {

	GLFWwindow* window;

	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);
	glfwSetCursorPosCallback(window, cursorPositionCallback);
	glfwSetInputMode(window, GLFW_CURSOR, GLFW_CURSOR_NORMAL);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);
		double xpos, ypos;
		glfwGetCursorPos(window, &xpos, &ypos);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

static void cursorPositionCallback(GLFWwindow* window, double xpos, double ypos) {
	std::cout << xpos << " : " << ypos << std::endl;
}
*/

//5 : MOUSE ENTER CALLBACK
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void cursorEnterCallback(GLFWwindow* window, int entered);

int main(void) {

	GLFWwindow* window;

	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	glfwSetCursorEnterCallback(window, cursorEnterCallback);


	unsigned char pixels[16 * 16 * 4];
	memset(pixels, 0xff, sizeof(pixels));
	GLFWimage image;
	image.width = 16;
	image.height = 16;
	image.pixels = pixels;
	GLFWcursor* cursor = glfwCreateCursor(&image, 0, 0);
	glfwSetCursor(window, cursor);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

static void cursorEnterCallback(GLFWwindow* window, int entered) {
	if (entered)
	{
		std::cout << "Entered Window" << std::endl;
	}
	else
	{
		std::cout << "Left Window" << std::endl;
	}
}
*/

//Assignment 1 (1)
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main()
{
	GLFWwindow* window;
	if (!glfwInit()) {
		fprintf(stderr, "ERROR : could start GLFW3\n");
		return -1;
	}

	window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);

	if (!window) {
		fprintf(stderr, "ERROR : could not open windows with GLFW3\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float points[] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main() {"
		"   gl_Position = vec4(vp, 1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main() {"
		"   frag_colour = vec4(0.0, 1.0, 0.0, 1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);
		glBindVertexArray(vao);

		glDrawArrays(GL_LINES, 0, 8);
		glPointSize(30.0);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
*/

//Assignment 1 (2)
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>

int main()
{
	GLFWwindow* window;
	if (!glfwInit()) {
		fprintf(stderr, "ERROR : could start GLFW3\n");
		return -1;
	}

	window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);

	if (!window) {
		fprintf(stderr, "ERROR : could not open windows with GLFW3\n");
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float points[] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, 0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main() {"
		"   gl_Position = vec4(vp, 1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main() {"
		"   frag_colour = vec4(0.0, 1.0, 0.0, 1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);
		glBindVertexArray(vao);

		glDrawArrays(GL_LINE_LOOP, 0, 4);

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
*/

//Assignment 2 (1)
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glViewport(0.0f, 0.0f, screenWidth, screenHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_SPACE && action == GLFW_REPEAT)
	{
		std::cout << "Space Key Pressed" << std::endl;
	}
}
*/

//Assignment 2 (2)
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void keyCallbackL(GLFWwindow* window, int key, int scancode, int action, int mods);

int main()
{
	GLFWwindow* window;

	if (!glfwInit()) {
		return -1;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	int screenWidth, screenHeight;
	glfwGetFramebufferSize(window, &screenWidth, &screenHeight);

	if (!window) {
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, keyCallbackL);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glViewport(0.0f, 0.0f, screenWidth, screenHeight);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT);
		glfwSwapBuffers(window);
		glfwPollEvents();
	}
	glfwTerminate();
	return 0;
}

void keyCallbackL(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_L && action == GLFW_REPEAT) {
		std::cout << "L Key Pressed" << std::endl;
	}
}
*/

//Assignment 3 (1)
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods);

int main(void) {

	GLFWwindow* window;

	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	glfwSetMouseButtonCallback(window, mouseButtonCallback);
	glfwSetInputMode(window, GLFW_STICKY_MOUSE_BUTTONS, GLFW_TRUE);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();

	return 0;
}

static void mouseButtonCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_RIGHT && action == GLFW_PRESS)
	{
		std::cout << "Right Button Pressed" << std::endl;
	}
	if (button == GLFW_MOUSE_BUTTON_LEFT && action == GLFW_PRESS)
	{
		std::cout << "Left Button Pressed" << std::endl;
	}
}
*/

//Assignment 3 (2)
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <math.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void scrollCallback(GLFWwindow* window, double xoffset, double yoffset);

int main(void) {

	GLFWwindow* window;

	if (!glfwInit())
	{
		return -1;
	}

	window = glfwCreateWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "Hello World", NULL, NULL);

	glfwSetScrollCallback(window, scrollCallback);

	while (!glfwWindowShouldClose(window))
	{
		glClear(GL_COLOR_BUFFER_BIT);

		glfwSwapBuffers(window);

		glfwPollEvents();
	}

	glfwTerminate();
	return 0;
}

static void scrollCallback(GLFWwindow* window, double xoffset, double yoffset) {
	if (yoffset < 0)
	{
		yoffset = -1;
		std::cout << xoffset << ":" << yoffset << std::endl;
	}
	else
	{
		yoffset = 1;
		std::cout << xoffset << ":" << yoffset << std::endl;
	}
}
*/

//include GLM
//TRANSLATION
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

int main(void)
{
	glm::vec4 vec(1.0f, 0.0f, 1.0f, 1.0f);
	glm::mat4 trans;
	trans = glm::translate(trans, glm::vec3(2.0f, 2.0f, 1.0f));
	vec = trans * vec;

	printf("%f\n", vec.x);
	printf("%f\n", vec.y);
	printf("%f\n", vec.z);
}
*/

//SCALING
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

int main(void)
{
	glm::vec4 vec(5.0f, 2.0f, 0.0f, 1.0f);
	glm::mat4 trans;
	trans = glm::scale(trans, glm::vec3(0.0, 0.1, 0.0));
	vec = trans * vec;

	printf("%f\n", vec.x);
	printf("%f\n", vec.y);
	printf("%f\n", vec.z);
}
*/

//Apply 1
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

int main(void)
{
	glm::vec4 vec(5.0f, 2.0f, 0.0f, 1.0f);
	glm::mat4 trans;
	trans = glm::scale(trans, glm::vec3(0.0, 0.0, 1.0));
	vec = trans * vec;

	printf("%f\n", vec.x);
	printf("%f\n", vec.y);
	printf("%f\n", vec.z);
}
*/
/*
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

int main() {
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize glfw\n");
		return 1;
	}

	// Open a window and create its OpenGL context
	GLFWwindow* window;// (In the accompanying source code, this variable is global forsimplicity)
	window = glfwCreateWindow(640, 480, "Assigment", NULL, NULL);
	if (!window) {
		fprintf(stderr, "Failed to open GLFW window. If you have an Intel GPU, they arenot 3.3 compatible. Try the 2.1 version of the tutorials.\n");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);// Initialize GLEW
	glewExperimental = GL_TRUE;// Needed in core profile
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float titik[] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
	};

	glm::vec4 vec1(titik[0], titik[1], titik[2], 1.0f);
	glm::vec4 vec2(titik[3], titik[4], titik[5], 1.0f);
	glm::vec4 vec3(titik[6], titik[7], titik[8], 1.0f);
	glm::vec4 vec4(titik[9], titik[10], titik[11], 1.0f);
	glm::mat4 trans;
	trans = glm::scale(trans, glm::vec3(0.5, 0.2, 0.0));
	vec1 = trans * vec1;
	vec2 = trans * vec2;
	vec3 = trans * vec3;
	vec4 = trans * vec4;
	float titikk[] = {
			vec1[0], vec1[1], vec1[2],
			vec2[0], vec2[1], vec2[2],
			vec3[0], vec3[1], vec3[2],
			vec4[0], vec4[1], vec4[2],
	};

	printf("%f\n", titikk[7]);

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(titikk), titikk, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main(){"
		"gl_Position=vec4(vp,1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main(){"
		"frag_colour=vec4(1.0,1.0,1.0,1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);
		glBindVertexArray(vao);
		glDrawArrays(GL_POLYGON, 0, 4);
		glPointSize(15.0);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
*/

//Apply 2
/*
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

int main(void)
{
	glm::vec4 vec(5.0f, 2.0f, 0.0f, 1.0f);
	glm::mat4 trans;
	trans = glm::rotate(trans, 90.0f, glm::vec3(0.0, 1.0, 0.0));
	vec = trans * vec;

	printf("%f\n", vec.x);
	printf("%f\n", vec.y);
	printf("%f\n", vec.z);
}
*/
/*
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

int main() {
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize glfw\n");
		return 1;
	}
	GLFWwindow* window;

	window = glfwCreateWindow(640, 480, "Assigment", NULL, NULL);
	if (!window) {
		fprintf(stderr, "Failed to open GLFW window.\n");
		glfwTerminate(); return 1;
	}
	glfwMakeContextCurrent(window);
	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float titik[] = {
		0.5f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
		-0.5f, 0.5f, 0.0f,
	};

	glm::vec4 vec1(titik[0], titik[1], titik[2], 1.0f);
	glm::vec4 vec2(titik[3], titik[4], titik[5], 1.0f);
	glm::vec4 vec3(titik[6], titik[7], titik[8], 1.0f);
	glm::vec4 vec4(titik[9], titik[10], titik[11], 1.0f);
	glm::mat4 trans; trans = glm::rotate(trans, 90.0f, glm::vec3(1.0, 1.0, 1.0));
	vec1 = trans * vec1;
	vec2 = trans * vec2;
	vec3 = trans * vec3;
	vec4 = trans * vec4;
	float titikk[] = {
		vec1[0], vec1[1], vec1[2],
		vec2[0], vec2[1], vec2[2],
		vec3[0], vec3[1], vec3[2],
		vec4[0], vec4[1], vec4[2],
	};

	//printf("%f\n", titikk[7]);

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(titikk), titikk, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main(){"
		"gl_Position=vec4(vp,1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main(){"
		"frag_colour=vec4(1.0,0.5,1.0,1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);
		glBindVertexArray(vao);
		glDrawArrays(GL_POLYGON, 0, 4);
		glPointSize(15.0); glfwPollEvents();
		glfwSwapBuffers(window);
	}
}
*/

//Assignment
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <math.h>
#include <iostream>

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main(void) {

	if(!glfwInit()) {
		fprintf(stderr, "ERROR : could start GLFW3\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Hello Triangle", NULL, NULL);

	glfwMakeContextCurrent(window);


	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);

	glViewport(0.0f, 0.0f, SCREEN_WIDTH, SCREEN_HEIGHT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(0, SCREEN_WIDTH, 0, SCREEN_HEIGHT, 0, 1);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glewExperimental = GL_TRUE;
	glewInit();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float points[] = {
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
	};

	GLuint vbo;
	glGenBuffers(1, &vbo);

	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main() {"
		"   gl_Position = vec4(vp, 1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main() {"
		"   frag_colour = vec4(0.0, 1.0, 0.0, 1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);
		glBindVertexArray(vao);

		glDrawArrays(GL_LINE_LOOP, 0, 3);
		glPointSize(15.0);

		glfwPollEvents();
		glfwSwapBuffers(window);

	
	}
	glfwDestroyWindow(window);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		std::cout << "Space Key Pressed" << std::endl;
	}
	else if (key == GLFW_KEY_D && action == GLFW_PRESS) {
		std::cout << "D Key Pressed" << std::endl;
	}
	else if (key == GLFW_KEY_U && action == GLFW_PRESS) {
		std::cout << "U Key Pressed" << std::endl;
	}
	else if (key == GLFW_KEY_R && action == GLFW_PRESS) {
		std::cout << "R Key Pressed" << std::endl;
	}
}
*/
/*
#include <iostream>
#include <stdio.h>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>
using namespace glm;

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods);

int main() {
	if (!glfwInit()) {
		fprintf(stderr, "Failed to initialize glfw\n");
		return 1;
	}// Open a window and create its OpenGL context

	GLFWwindow* window;// (In the accompanying source code, this variable is global forsimplicity)
	window = glfwCreateWindow(640, 480, "assigment", NULL, NULL);
	if (!window) {
		fprintf(stderr, "Failed to open GLFW window. \n");
		glfwTerminate();
		return 1;
	}
	glfwMakeContextCurrent(window);// Initialize GLEW
	glewExperimental = GL_TRUE;// Needed in core profile
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	float titik[] = {
		0.0f, 0.5f, 0.0f,
		0.5f, -0.5f, 0.0f,
		-0.5f, -0.5f, 0.0f,
	};

	glfwSetKeyCallback(window, keyCallback);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	GLuint vbo;
	glGenBuffers(1, &vbo);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);

	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main(){"
		"gl_Position=vec4((vp.x-0.583),(vp.y+0.6875),vp.z,1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main(){"
		"frag_colour=vec4(0.5,1.0,1.0,1.0);"
		"}";

	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);

	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_programme = glCreateProgram();
	glAttachShader(shader_programme, fs);
	glAttachShader(shader_programme, vs);
	glLinkProgram(shader_programme);

	while (!glfwWindowShouldClose(window)) {
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_programme);

		glBindVertexArray(vao);
		glDrawArrays(GL_LINE_LOOP, 0, 3);
		glPointSize(15.0);
		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods) {
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS) {
		std::cout << "Space Key Pressed" << std::endl;
		glfwMakeContextCurrent(window);// Initialize GLEW
		glewExperimental = GL_TRUE;// Needed in core profile
		glewInit();
		const GLubyte* renderer = glGetString(GL_RENDERER);
		const GLubyte* version = glGetString(GL_VERSION);
		glEnable(GL_DEPTH_TEST); glDepthFunc(GL_LESS);
		float titik[] = {
			0.0f, 0.5f, 0.0f,
			0.5f, -0.5f, 0.0f,
			-0.5f, -0.5f, 0.0f,
		};

		GLuint vbo;
		glGenBuffers(1, &vbo);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glBufferData(GL_ARRAY_BUFFER, sizeof(titik), titik, GL_STATIC_DRAW);

		GLuint vao = 0;
		glGenVertexArrays(1, &vao);
		glBindVertexArray(vao);
		glEnableVertexAttribArray(0);
		glBindBuffer(GL_ARRAY_BUFFER, vbo);
		glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);

		const char* vertex_shader =
			"#version 400\n""in vec3 vp;"
			"void main(){"
			"gl_Position=vec4((vp.x-0.921875),(vp.y+0.79167),vp.z,1.0);"
			"}";

		const char* fragment_shader =
			"#version 400\n"
			"out vec4 frag_colour;"
			"void main(){"
			"frag_colour=vec4(1.0,1.0,1.0,1.0);"
			"}";

		GLuint vs = glCreateShader(GL_VERTEX_SHADER);
		glShaderSource(vs, 1, &vertex_shader, NULL);
		glCompileShader(vs);

		GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
		glShaderSource(fs, 1, &fragment_shader, NULL);
		glCompileShader(fs);

		GLuint shader_programme = glCreateProgram();
		glAttachShader(shader_programme, fs);
		glAttachShader(shader_programme, vs);
		glLinkProgram(shader_programme);

		while (!glfwWindowShouldClose(window)) {
			glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
			glUseProgram(shader_programme);
			glBindVertexArray(vao);
			glDrawArrays(GL_LINE_LOOP, 0, 3);
			glPointSize(15.0);
			glfwPollEvents();
			glfwSwapBuffers(window);
		}
		glfwDestroyWindow(window);
	}
}
*/
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
using namespace glm;

void keyCheck(GLFWwindow* window, int key, int scancode, int action, int mods);



int main() {
	//start GL context and OS Windows using GLFW lib
	if (!glfwInit()) {
		fprintf(stderr, "ERROR : could not start GLFW3\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Tugas 2", NULL, NULL);
	if (!window) {
		fprintf(stderr, "ERROR : could not open windows with GLFW3\n");
		return 1;
	}
	glfwMakeContextCurrent(window);

	glfwSetKeyCallback(window, keyCheck);
	glfwSetInputMode(window, GLFW_STICKY_KEYS, 1);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();

	//start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	//get version info
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf_s("Renderer : %s\n", renderer);
	printf_s("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);


	glfwMakeContextCurrent(window);

	//create vector buffer object
	GLuint vbo;
	glGenBuffers(1, &vbo);

	float points[] = {
			0.3f, 0.5f, 0.0f,
			0.5f, 0.1f, 0.0f,
			0.1f, 0.1f, 0.0f,
	};

	//allocate space and upload from CPU to GPU
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glBufferData(GL_ARRAY_BUFFER, sizeof(points), points, GL_STATIC_DRAW);

	//VAO setting
	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	//RECALL SHADERS
	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main() {"
		"gl_Position = transform * vec4(vp, 1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main() {"
		"frag_colour = vec4(1.0, 0.0, 0.1, 1.0);"
		"}";

	//shaders attach
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_progamme = glCreateProgram();
	glAttachShader(shader_progamme, fs);
	glAttachShader(shader_progamme, vs);
	glLinkProgram(shader_progamme);


	while (!glfwWindowShouldClose(window))
	{
		//wipe drawing or clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_progamme);
		glBindVertexArray(vao);
		//draw point
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glPointSize(15.0);
		//update event
		glfwPollEvents();
		//put drawing
		glfwSwapBuffers(window);
	}

}

void keyCheck(GLFWwindow* window, int key, int scancode, int action, int mods) {


	float points[] = {
			0.3f, 0.5f, 0.0f,
			0.5f, 0.1f, 0.0f,
			0.1f, 0.1f, 0.0f,
	};
	glm::vec4 a(points[0], points[1], points[2], 1.0f);
	glm::vec4 b(points[3], points[4], points[5], 1.0f);
	glm::vec4 c(points[6], points[7], points[8], 1.0f);

	glm::mat4 trans;

	if (key == GLFW_KEY_SPACE && action == GLFW_REPEAT) {
		trans = glm::translate(trans, glm::vec3(-0.075, -0.05, 0.0));

	}
	else if (key == GLFW_KEY_D && action == GLFW_REPEAT) {
		trans = glm::scale(trans, glm::vec3(0.5, 0.5, 0.0));
	}
	else if (key == GLFW_KEY_U && action == GLFW_REPEAT) {
		trans = glm::scale(trans, glm::vec3(2.0, 2.0, 0.0));
	}
	else if (key == GLFW_KEY_R && action == GLFW_REPEAT) {
		trans = glm::rotate(trans, 120.0f, glm::vec3(1.0, 0.0, 0.0));
	}
	a = trans * a;
	b = trans * b;
	c = trans * c;

	float pointsAfter[] = {
	a[0], a[1], a[2],
	b[0], b[1], b[2],
	c[0], c[1], c[2],
	};
	//start GLEW extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);


	glfwMakeContextCurrent(window);

	//create vector buffer object
	GLuint vbo;
	glGenBuffers(1, &vbo);

	//allocate space and upload from CPU to GPU
	glBindBuffer(GL_ARRAY_BUFFER, vbo);


	//VAO setting
	GLuint vao = 0;
	glGenVertexArrays(1, &vao);
	glBindVertexArray(vao);
	glEnableVertexAttribArray(0);
	glBindBuffer(GL_ARRAY_BUFFER, vbo);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, NULL);
	//RECALL SHADERS
	const char* vertex_shader =
		"#version 400\n"
		"in vec3 vp;"
		"void main() {"
		"gl_Position = transform * vec4(vp, 1.0);"
		"}";

	const char* fragment_shader =
		"#version 400\n"
		"out vec4 frag_colour;"
		"void main() {"
		"frag_colour = vec4(1.0, 0.0, 0.1, 1.0);"
		"}";

	//shaders attach
	GLuint vs = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vs, 1, &vertex_shader, NULL);
	glCompileShader(vs);
	GLuint fs = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fs, 1, &fragment_shader, NULL);
	glCompileShader(fs);

	GLuint shader_progamme = glCreateProgram();
	glAttachShader(shader_progamme, fs);
	glAttachShader(shader_progamme, vs);
	glLinkProgram(shader_progamme);

	glBufferData(GL_ARRAY_BUFFER, sizeof(pointsAfter), pointsAfter, GL_STATIC_DRAW);
	while (!glfwWindowShouldClose(window))
	{
		//wipe drawing or clear
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glUseProgram(shader_progamme);
		glBindVertexArray(vao);
		//draw point
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glPointSize(15.0);
		//update event
		glfwPollEvents();
		//put drawing
		glfwSwapBuffers(window);
	}
}
*/

//MATH FUNCTION

//APPLY 1
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

void create_red_vao(GLuint& vao);
void create_dots_vao(GLuint& vao);
void Circlin(float radius, int a);

float i = 0;

void setup_viewport(GLFWwindow* window) {
	//setting viewports size, projection etc
	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-22, 22, -17, 17, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main() {
	//start GL context and OS windows using GLFW Lib
	if (!glfwInit()) {
		fprintf(stderr, "ERROR : could not start GLFW3\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Circle", NULL, NULL);
	if (!window) {
		fprintf(stderr, "ERROR : could not open windows GLFW3\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	//start GLEW Extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	//get version info
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(window)) {
		setup_viewport(window);

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3ub(255, 255, 0);
		Circlin(3, 360);
		glPushMatrix();

		glfwPollEvents();
		//put drawing
		glfwSwapBuffers(window);
	}
}

void Circlin(float radius, int a) {

	glBegin(GL_POLYGON);
	int dots = 360;
	int x_mid = 0;
	int y_mid = 0;
	int angle, i;

	glVertex2f(x_mid, y_mid);

	for (i = 0; i <= a; i++) {
		float angle = i * (2 * 3.14 / dots);
		float x = x_mid + radius * cos(angle);
		float y = y_mid + radius * sin(angle);
		glVertex2f(x, y);
	}
	glVertex2f(x_mid, y_mid);
	glEnd();
}
*/

//Apply This Program 2
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace glm;

void create_red_vao(GLuint& vao);
void create_dots_vao(GLuint& vao);
void Circlin(float radius, int a);
void counters();

float i = 0;
int counter = 0;

void setup_viewport(GLFWwindow* window) {
	//setting viewports size, projection etc
	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-22, 22, -17, 17, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main() {
	//start GL context and OS windows using GLFW Lib
	if (!glfwInit()) {
		fprintf(stderr, "ERROR : could not start GLFW3\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Circle", NULL, NULL);
	if (!window) {
		fprintf(stderr, "ERROR : could not open windows GLFW3\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	//start GLEW Extension handler
	glewExperimental = GL_TRUE;
	glewInit();

	//get version info
	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(window)) {
		setup_viewport(window);
		counters();
		vec4 vec(11.0, 0.0, 0.0, 0.0);
		mat4 trans;
		trans = rotate(trans, i, vec3(0.0, 0.0, 1.0));
		vec = vec * trans;

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3ub(255, 255, 0);
		Circlin(3, 360);
		glPushMatrix();
		glColor3ub(20, 0, 240);
		glTranslatef(vec.x, vec.y, vec.z);
		Circlin(1, 360);
		glPopMatrix();

		glfwPollEvents();
		//put drawing
		glfwSwapBuffers(window);
	}
}

void Circlin(float radius, int a) {

	glBegin(GL_POLYGON);
	int dots = 360;
	int x_mid = 0;
	int y_mid = 0;
	int angle, i;

	glVertex2f(x_mid, y_mid);

	for (i = 0; i <= a; i++) {
		float angle = i * (2 * 3.14 / dots);
		float x = x_mid + radius * cos(angle);
		float y = y_mid + radius * sin(angle);
		glVertex2f(x, y);
	}
	glVertex2f(x_mid, y_mid);
	glEnd();
}

void counters() {
	if (counter > 500) {
		if (i > 360.0f)
			i = 0.0f;
		else i = i + 1.0f;
		counter = 0;
	}
	counter++;
}
*/

//Assignment
/*
#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

void create_red_vao(GLuint& vao);
void create_dots_vao(GLuint& vao);
void Circlin(float radius, int a);
void Sinus(int amplitudo, int degree);
void counters();

float i = 0;
float sinx = 0;
float siny = 0;
int counter = 0;

void setup_viewport(GLFWwindow* window) {
	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-22, 22, -17, 17, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

int main()
{
	if (!glfwInit())
	{
		fprintf(stderr, "ERROR : Could not start GLFW3\n");
		return 1;
	}

	GLFWwindow* window = glfwCreateWindow(640, 480, "Circle", NULL, NULL);
	if (!window)
	{
		fprintf(stderr, "ERROR : could not open windows with GLFW3\n");
		glfwTerminate();
		return 1;
	}

	glfwMakeContextCurrent(window);

	glewExperimental = GL_TRUE;
	glewInit();

	const GLubyte* renderer = glGetString(GL_RENDERER);
	const GLubyte* version = glGetString(GL_VERSION);
	printf("Renderer : %s\n", renderer);
	printf("OpenGL version supported %s\n", version);

	glEnable(GL_DEPTH_TEST);
	glDepthFunc(GL_LESS);

	while (!glfwWindowShouldClose(window))
	{
		setup_viewport(window);
		counters();

		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glColor3ub(255, 255, 0);
		Sinus(8, i);
		glPushMatrix();
		glColor3ub(i, i, 0);
		glTranslatef(sinx, siny, 0);
		Circlin(1, 360);
		glPopMatrix();

		glfwPollEvents();
		glfwSwapBuffers(window);
	}
}

void Sinus(int amplitudo, int degree) {
	glBegin(GL_POINTS);
	int i = 0;
	int endy = 0;

	for (i = 0; i <= degree; i++) {
		float angle = (float)i;
		sinx = -20 + angle / 10;
		siny = amplitudo * sin(angle * 3.14 / 180);
		endy = siny;
		glVertex2f(sinx, siny);
	}
	glEnd();
}

void Circlin(float radius, int a) {
	glBegin(GL_POLYGON);
	int dots = 360;
	int x_mid = 0;
	int y_mid = 0;
	int angle, i;

	glVertex2f(x_mid, y_mid);

	for (i = 0; i <= a; i++)
	{
		float angle = i * (2 * 3.14 / dots);
		float x = x_mid + radius * cos(angle);
		float y = y_mid + radius * sin(angle);
		glVertex2f(x, y);
	}
	glVertex2f(x_mid, y_mid);
	glEnd();
}

void counters() {
	if (counter > 10)
	{
		if (i > 360.0f) i = 0.0f;
		else i = i + 1.0f;
		counter = 0;
	}
	counter++;
}
*/

//PROJECT FIX
/*
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <iostream>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>

using namespace std;
using namespace glm;

float x = 0, y = 0, i = 360, j = 0;
int counter = 0;
int kondisi_hari = 0;
int kondisi_rotasi = 0;


static void key_callback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	// close window using ENTER key
	if (key == GLFW_KEY_ENTER && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
	if (key == GLFW_KEY_D && action == GLFW_PRESS) {
		cout << "D Button Clicked, Hari Berganti" << endl;
		if (kondisi_hari == 0) {
			kondisi_hari = 1;
		}
		else if (kondisi_hari == 1) {
			kondisi_hari = 0;
		}
	}
	else if (key == GLFW_KEY_N && action == GLFW_PRESS) {
		cout << "N Button Clicked, Matahari / Bulan Berotasi" << endl;
		if (kondisi_rotasi == 0) {
			kondisi_rotasi = 1;
		}
		else if (kondisi_rotasi == 1) {
			kondisi_rotasi = 0;
		}
	}

}

int counters_half() {
	if (counter > 1) {
		if (i < 180.0f) i = 360.0f;
		else i = i - 1.0f;
		counter = 0;
	}
	return counter++;
}


void setup_viewport(GLFWwindow* window)
{
	// setting viewports size, projection etc
	float ratio;
	int width, height;
	glfwGetFramebufferSize(window, &width, &height);
	ratio = width / (float)height;
	glViewport(0, 0, width, height);

	glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(-17, 17, -16, 16, 1.f, -1.f);
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
}

void kotak(float panjang, float lebar) {
	panjang /= 2;
	lebar /= 2;
	glBegin(GL_POLYGON);
	glVertex2f(-panjang, lebar);
	glVertex2f(-panjang, -lebar);
	glVertex2f(panjang, -lebar);
	glVertex2f(panjang, lebar);
	glEnd();
}

void rectangle(float horizontal, float vertical)
{
	horizontal /= 2;
	vertical /= 2;
	glBegin(GL_POLYGON);
	glVertex2f(-horizontal, vertical);
	glVertex2f(-horizontal, -vertical);
	glVertex2f(horizontal, -vertical);
	glVertex2f(horizontal, vertical);
	glEnd();
}

void Circlin(float radius, int a) {
	glBegin(GL_POLYGON);
	int dots = 360;
	int x_mid = 0;
	int y_mid = 0;
	int angle, i;
	glVertex2f(x_mid, y_mid);

	for (i = 0; i <= a; i++) {
		float angle = i * (2 * 3.14 / dots);
		float x = x_mid + radius * cos(angle);
		float y = y_mid + radius * sin(angle);
		glVertex2f(x, y);
	}
	glVertex2f(x_mid, y_mid);
	glEnd();
}

void segitiga(float alas, float tinggi) {
	glBegin(GL_TRIANGLES);
	glVertex2f(-0.5 * alas, 0);
	glVertex2f(0, tinggi);
	glVertex2f(0.5 * alas, 0);
	glEnd();
}

void jajargenjang1(float horizontal, float vertical, float miring)
{
	horizontal /= 2;
	vertical /= 2;
	glBegin(GL_POLYGON);
	glVertex2f(-horizontal - miring, vertical);
	glVertex2f(-horizontal, -vertical - miring);
	glVertex2f(horizontal + miring, -vertical);
	glVertex2f(horizontal, vertical + miring);
	glEnd();
}

void jajargenjang2(float horizontal, float vertical, float miring)
{
	horizontal /= 2;
	vertical /= 2;
	glBegin(GL_POLYGON);
	glVertex2f(-horizontal, vertical);
	glVertex2f(-horizontal, -vertical - miring);
	glVertex2f(horizontal, -vertical);
	glVertex2f(horizontal, vertical + miring);
	glEnd();
}

void rumah()
{
	//Dinding Miring (Kanan)
	glTranslatef(4, -7, 0);
	glColor3ub(239, 206, 76);
	jajargenjang2(8, 0.6, 4.28);

	//Atap Miring (Kanan)
	glTranslatef(-1, 5, 0);
	glColor3ub(129, 19, 0);
	jajargenjang1(4, 2, 3.6);

	//Dinding Depan
	glTranslatef(-5.8, -7.1, 0);
	glColor3ub(220, 205, 125);
	kotak(6, 5);

	//Pintu
	glTranslatef(0, -1, 0);
	glColor3ub(180, 180, 180);
	kotak(2, 3);

	//Atap Depan
	glTranslatef(0.2, 3.6, 0);
	glColor3ub(153, 19, 0);
	segitiga(8, 5.5);

	//Jendela (Kanan)
	glTranslatef(7.5, -0.5, 0);
	glColor3ub(102, 87, 87);
	jajargenjang2(3, 1, 1.6);
}

void latar()
{
	//Tanah
	glTranslatef(-15, -10, 0);
	glColor3ub(200, 104, 0);
	kotak(40, 20);

	//Daun Pohon Lapis 1
	glTranslatef(-12, 9, 0);
	glColor3ub(0, 100, 0);
	segitiga(4, 3);

	//Daun Pohon Lapis 2
	glTranslatef(0, -1.8, 0);
	glColor3ub(0, 100, 0);
	segitiga(5.5, 3);

	//Daun Pohon Lapis 3
	glTranslatef(0, -2, 0);
	glColor3ub(0, 100, 0);
	segitiga(7, 4);

	//Batang Pohon
	glTranslatef(0, -2, 0);
	glColor3ub(122, 68, 0);
	kotak(1.5, 4);

	//Daun Pohon 2 Lapis 1
	glTranslatef(23, 3, 0);
	glColor3ub(0, 100, 0);
	segitiga(7.5, 5.5);

	//Daun Pohon 2 Lapis 1
	glTranslatef(0, -2.5, 0);
	glColor3ub(0, 100, 0);
	segitiga(8.5, 6);

	//Daun Pohon 2 Lapis 1
	glTranslatef(0, -2, 0);
	glColor3ub(0, 100, 0);
	segitiga(9, 6);

	//Batang Pohon 2
	glTranslatef(0, -3, 0);
	glColor3ub(122, 68, 0);
	kotak(2, 6);
}
void gunung() {
	//Gunung Belakang
	glTranslatef(-17, 11, 0);
	glColor3ub(92, 92, 92);
	segitiga(9, 7);
	//Gunung Depan
	glTranslatef(4, 0, 0);
	glColor3ub(116, 116, 116);
	segitiga(10, 8);
}

void langit_pagi() {
	glColor3ub(85, 166, 250);
	rectangle(80, 80);
}

void langit_malam() {
	glColor3ub(6, 14, 33);
	rectangle(80, 80);
	glTranslatef(0, -2, 0);
}

void matahari()
{
	glTranslatef(15, 2, 0);
	glColor3ub(255, 255, 0);
	Circlin(2.2, 360);
}

void bintang() {
	glTranslatef(-15, 5, 0);
	glTranslatef(5, 0, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.1, 360);
	glTranslatef(-5, 0, 0);
	glTranslatef(-7, 3, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.2, 360);
	glTranslatef(7, -3, 0);
	glTranslatef(10, -7, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.3, 360);
	glTranslatef(-10, 7, 0);
	glTranslatef(14, -18, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.2, 360);
	glTranslatef(-14, 18, 0);
	glTranslatef(2, 6, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.2, 360);
	glTranslatef(-2, -6, 0);
	glTranslatef(-10, 3, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.2, 360);
	glTranslatef(10, -3, 0);
	glTranslatef(-12, 5, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.2, 360);
	glTranslatef(12, -5, 0);
	glTranslatef(12, 5, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.2, 360);
	glTranslatef(-12, -5, 0);
	glTranslatef(16, 1, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.3, 360);
	glTranslatef(-16, -1, 0);
	glTranslatef(-32, 5, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.2, 360);
	glTranslatef(32, -5, 0);
	glTranslatef(42, 5, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.2, 360);
	glTranslatef(-42, -5, 0);
	glTranslatef(36, 1, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.3, 360);
	glTranslatef(-36, -1, 0);
	glTranslatef(15, -5, 0);

}

void bulan()
{
	glTranslatef(4.5, 0, 0);
	glColor3ub(255, 255, 0);
	Circlin(3, 360);
	glTranslatef(1.5, 0, 0);
	glColor3ub(6, 14, 33);
	Circlin(2.5, 360);
	//bintang();
}

void awan() {
	glTranslatef(5, 15, 0);
	glColor3ub(255, 255, 255);
	Circlin(1, 360);

	glTranslatef(1.5, 0.5, 0);
	glColor3ub(255, 255, 255);
	Circlin(0.8, 360);

	glTranslatef(1.5, 0, 0);
	glColor3ub(255, 255, 225);
	Circlin(1.5, 360);

	glTranslatef(1.5, -0.5, 0);
	glColor3ub(255, 255, 255);
	Circlin(1.3, 360);

	glTranslatef(-1.5, -0.5, 0);
	glColor3ub(255, 255, 255);
	Circlin(1.3, 360);

	glTranslatef(-1.5, 0, 0);
	glColor3ub(255, 255, 255);
	Circlin(1.3, 360);
}

int main(void) {
	GLFWwindow* window;
	if (!glfwInit()) exit(EXIT_FAILURE);

	window = glfwCreateWindow(800, 600, "KELOMPOK 1 (NRP 31,39,42,48) Every day in my village", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		exit(EXIT_FAILURE);
	}

	glfwMakeContextCurrent(window);
	glfwSwapInterval(1);
	glfwSetKeyCallback(window, key_callback);

	//Enable Alpha
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	//Enable Antialiasing
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
	glEnable(GL_LINE_SMOOTH);
	glEnable(GL_POLYGON_SMOOTH);
	glEnable(GL_POINT_SMOOTH);

	while (!glfwWindowShouldClose(window))
	{
		setup_viewport(window);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		vec4 vec(16.0, 0.0, 0.0, 0.0);
		mat4 trans;
		trans = rotate(trans, i, vec3(0.0, 0.0, 1.0));
		vec = vec * trans;
		counters_half();
		if (kondisi_hari == 0) {
			if (kondisi_rotasi == 1) {
				glTranslatef(-14, -3, 0);
				glPushMatrix();
				langit_pagi();
				glTranslatef(vec.x, vec.y, vec.z);
				matahari();
				glPopMatrix();
				glTranslatef(29, 5, 0);
				latar();
				gunung();
				rumah();
				awan();
			}
			else {
				langit_pagi();
				glTranslatef(2, -2, 0);
				matahari();
				glTranslatef(-2, 2, 0);
				latar();
				gunung();
				rumah();
				awan();
			}
		}
		else {
			if (kondisi_rotasi == 1) {
				glTranslatef(-14, -3, 0);
				glPushMatrix();
				langit_malam();
				glTranslatef(vec.x, vec.y, vec.z);
				glTranslatef(12, 0, 0);
				bulan();
				glPopMatrix();
				glTranslatef(29, 5, 0);
				bintang();
				latar();
				gunung();
				rumah();
			}
			else {
				langit_malam();
				glTranslatef(-3, 12, 0);
				bulan();
				glTranslatef(12, -8, 0);
				bintang();
				latar();
				gunung();
				rumah();
			}
		}
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwDestroyWindow(window);
	glfwTerminate();
	exit(EXIT_SUCCESS);
}
*/

//Texture Shading
//Percobaan 1 Memberi Kombinasi Warna pada Segitiga
/*
#include <stdio.h>
#include <iostream>
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <glm/glm.hpp>
#include <glm/gtc/type_ptr.hpp>
#include <glm/gtc/matrix_transform.hpp>

using namespace glm;

// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
// Shaders
const GLchar* vertexShaderSource = "#version 330 core\n"
"layout (location = 0) in vec3 position;\n"
"layout (location = 1) in vec3 color;\n"
"out vec3 ourColor;\n"
"uniform mat4 transform;\n"
"void main()\n"
"{\n"
"gl_Position = transform * vec4(position, 1.0f);\n"
"ourColor = color;\n"
"}\0";
const GLchar* fragmentShaderSource = "#version 330 core\n"
"in vec3 ourColor;\n"
"out vec4 color;\n"
"void main()\n"
"{\n"
"color = vec4(ourColor, 1.0f);\n"
"}\n\0";
// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "TRIANGLE", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	// Vertex shader
	GLuint vertexShader = glCreateShader(GL_VERTEX_SHADER);
	glShaderSource(vertexShader, 1, &vertexShaderSource, NULL);
	glCompileShader(vertexShader);
	// Check for compile time errors
	GLint success;
	GLchar infoLog[512];
	glGetShaderiv(vertexShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(vertexShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::VERTEX::COMPILATION_FAILED\n" << infoLog <<
			std::endl;
	}
	// Fragment shader
	GLuint fragmentShader = glCreateShader(GL_FRAGMENT_SHADER);
	glShaderSource(fragmentShader, 1, &fragmentShaderSource, NULL);
	glCompileShader(fragmentShader);
	// Check for compile time errors
	glGetShaderiv(fragmentShader, GL_COMPILE_STATUS, &success);
	if (!success)
	{
		glGetShaderInfoLog(fragmentShader, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::FRAGMENT::COMPILATION_FAILED\n" << infoLog <<
			std::endl;
	}
	// Link shaders
	GLuint shaderProgram = glCreateProgram();
	glAttachShader(shaderProgram, vertexShader);
	glAttachShader(shaderProgram, fragmentShader);
	glLinkProgram(shaderProgram);
	// Check for linking errors
	glGetProgramiv(shaderProgram, GL_LINK_STATUS, &success);
	if (!success) {
		glGetProgramInfoLog(shaderProgram, 512, NULL, infoLog);
		std::cout << "ERROR::SHADER::PROGRAM::LINKING_FAILED\n" << infoLog << std::endl;
	}
	glDeleteShader(vertexShader);
	glDeleteShader(fragmentShader);
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions // Colors
		0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // Bottom Left
		0.0f, 0.5f, 0.0f, 0.0f, 0.0f, 1.0f // Top 
	};
	glm::mat4 trans;
	trans = glm::rotate(trans, 90.0f, glm::vec3(0.0, 0.0, 1.0));
	GLuint VBO, VAO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0); // Unbind VAO
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// Draw the triangle
		glUseProgram(shaderProgram);
		glm::mat4 transform;
		//transform=glm::translate(transform, glm::vec3(0.5f,-0.5f,0.0f));
		transform = glm::rotate(transform, 0.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		GLint transformLoc = glGetUniformLocation(shaderProgram, "transform");
		glUniformMatrix4fv(transformLoc, 1, GL_FALSE, glm::value_ptr(transform));
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
*/

//Percobaan 2 Install Texture dan Shader
/*
#include <iostream>
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// Other Libs
#include <SOIL.h>
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// Other includes
#include "myshader.h"
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
void create_texture(const char get_file[14], GLuint& texture);
void triangle(GLuint& VAO, GLuint& VBO); //GLuint& EBO
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Hello Triangle",nullptr, nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointersand extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	Shader ourShader("vertex.vs", "fragment.frag");
	// Set GL Array and handle with Shader Class
	GLuint VAO, VBO;
	triangle(VAO, VBO);
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		// Render
		// Clear the color buffer
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// Activate shader
		ourShader.Use();
		//Transformation
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		model = glm::rotate(model, 0.0f, glm::vec3(0.0f, 0.0f, 1.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, 0.0f));
		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT,0.1f, 100.0f);
		// Get their uniform location
		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
		// Pass them to the shaders
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		// Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		glUniformMatrix4fv(projLoc, 1, GL_FALSE,glm::value_ptr(projection));
		// Draw container
		glBindVertexArray(VAO);
		glDrawArrays(GL_TRIANGLES, 0, 3);
		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}
void triangle(GLuint& VAO, GLuint& VBO) //GLuint &EBO
{
	GLfloat vertices[] = {
		// Positions //Colors
		0.5f,-0.5f, 0.0f, 1.0f, 1.0f, 0.0f, //Left
		-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 1.0f, //Right
		0.0f, 0.5f, 0.0f, 1.0f, 0.0f, 1.0f //Top
	};
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	// glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),(GLvoid*)0);
	glEnableVertexAttribArray(0);
	//Color Attrib
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),(GLvoid*)(3 *sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0); // Unbind VAO
}
// Function that can create texture
void create_texture(const char get_file[14], GLuint& texture) {
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT); // Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	// Load, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image(get_file, &width, &height, 0,SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,GL_UNSIGNED_BYTE,image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
*/

//Percobaan 3 Texture Dan Shader
/*
#include <iostream>
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// Other Libs
#include <SOIL.h>
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// Other includes
#include "myshader.h"
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointers and extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	Shader ourShader("vertex.vs", "fragment.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions // Colors // Texture Coords
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // Top Left 
	};
	GLuint indices[] = { // Note that we start from 0!
	0, 1, 3, // First Triangle
	1, 2, 3 // Second Triangle
	};
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 * sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0); // Unbind VAO
	// Load and create a texture 
	GLuint texture;
	glGenTextures(1, &texture);
	glBindTexture(GL_TEXTURE_2D, texture); // All upcoming GL_TEXTURE_2D operations now have effect on this texture object
	// Set the texture wrapping parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT(usually basic wrapping method)
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load image, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image("container.jpg", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// Bind Texture
		glBindTexture(GL_TEXTURE_2D, texture);
		// Activate shader
		ourShader.Use();

		// Draw container
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
*/

//Percobaan 4 Menambahkan 2 Gambar
/*
#include <iostream>
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// Other Libs
#include <SOIL.h>
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// Other includes
#include "myshader.h"
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr,nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointersand extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	Shader ourShader("vertex.vs", "fragment.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions // Colors // Texture Coords
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // Top Left 
	};
	GLuint indices[] = { // Note that we start from 0!
	0, 1, 3, // First Triangle
	1, 2, 3 // Second Triangle
	};
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(3 *sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat), (GLvoid*)(6 *sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0); // Unbind VAO
	// Load and create a texture 
	GLuint texture1;
	GLuint texture2;
	// ====================
	// Texture 1
	// ====================
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); // Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image("container.jpg", &width, &height, 0,SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE,image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	// ===================
	// Texture 2
	// ===================
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	// Load, create texture and generate mipmaps
	image = SOIL_load_image("awesomeface.png", &width, &height, 0, SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE,image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		// Activate shader
		ourShader.Use();
		// Bind Textures using texture units
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture2"), 1);


		// Draw container
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
*/

//TUGAS 3
//KTP & Smartcard
/*
#include <iostream>
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
// Other Libs
#include <SOIL.h>
// GLM Mathematics
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// Other includes
#include "myshader.h"
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Window dimensions
const GLuint WIDTH = 900, HEIGHT = 500;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointersand extensionsglewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	Shader ourShader("vertex.vs", "fragment.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions // Colors // Texture Coords
		0.5f, 0.5f, 0.0f, 1.0f, 0.0f, 0.0f, 1.0f, 1.0f, // Top Right
		0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, 1.0f, 0.0f, // Bottom Right
		-0.5f, -0.5f, 0.0f, 0.0f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Left
		-0.5f, 0.5f, 0.0f, 1.0f, 1.0f, 0.0f, 0.0f, 1.0f // Top Left
	};
	GLuint indices[] = { // Note that we start from 0!
	0, 1, 3, // First Triangle
	1, 2, 3 // Second Triangle
	};
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices,GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),(GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),(GLvoid*)(3 *sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	// TexCoord attribute
	glVertexAttribPointer(2, 2, GL_FLOAT, GL_FALSE, 8 * sizeof(GLfloat),(GLvoid*)(6 *sizeof(GLfloat)));
	glEnableVertexAttribArray(2);
	glBindVertexArray(0); // Unbind VAO
	// Load and create a texture
	GLuint texture1;
	GLuint texture2;
	// ====================
	// Texture 1
	// ====================
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1); // All upcoming GL_TEXTURE_2D operations now have effect on our texture object
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S,GL_REPEAT); // Set texture wrapping to GL_REPEAT
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T,GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	// Load, create texture and generate mipmaps
	int width, height;
	unsigned char* image = SOIL_load_image("ktp1.jpg", &width, &height, 0,SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,GL_UNSIGNED_BYTE,image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0); // Unbind texture when done, so we won't accidentily mess up our texture.
	// ===================
	// Texture 2
	// ===================
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	// Set our texture parameters
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	// Set texture filtering
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER,GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER,GL_LINEAR);
	// Load, create texture and generate mipmaps
	image = SOIL_load_image("smartcard1.jpg", &width, &height, 0,SOIL_LOAD_RGB);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB,GL_UNSIGNED_BYTE,image);
	glGenerateMipmap(GL_TEXTURE_2D);
	SOIL_free_image_data(image);
	glBindTexture(GL_TEXTURE_2D, 0);
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		// Render
		// Clear the colorbuffer
		glClearColor(0.2f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// Activate shader
		ourShader.Use();
		// Bind Textures using texture units
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture2"), 1);
		// Draw container
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS) glfwSetWindowShouldClose(window, GL_TRUE);
}
*/

//3D OBJECT
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <iostream>
#include "myshader.h"
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "3D OBJECT FIKLI (39)", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointersand extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	// Vertex shader
	Shader ourShader("vertex.vs", "fragment.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
	0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan (segitiga)
	-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan (segitiga)
	0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
	0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri (segitiga) 
	0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang (segitiga)
	-0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
	0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,//bawah (persegi)
	-0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
	0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
	0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f
	};
	GLuint indices[] = {
	0, 1, 2,
	3, 4, 5,
	6, 7, 8,
	9, 10, 11,
	12, 13, 14,
	14, 15, 12
	};

	glEnable(GL_DEPTH_TEST);
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),(GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),(GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
	GLuint texture1;
	GLuint texture2;
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		// glClearColor(0.4f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
		ourShader.Use();
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		model = glm::rotate(model, 90.0f, glm::vec3(1.0f, 0.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.2f, -3.0f));
		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT,0.1f, 100.0f);
		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
*/

//COORDINATE SYSTEM
//1
/*
#include <iostream>
// GLEW
#include <GL/glew.h>
// GLFW
#include <GLFW/glfw3.h>
#include <SOIL.h>
//GLM Libraries
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtc/type_ptr.hpp>
// Other includes
#include "myshader.h"
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
	glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
	glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
	glfwWindowHint(GLFW_RESIZABLE, GL_FALSE);
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", NULL, NULL);
	glfwMakeContextCurrent(window);// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointersand extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	Shader ourShader("CS.vs", "CS.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
		// Positions // Colors
		0.8f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f, // Bottom Right
		-0.8f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f, // Bottom Left
		0.0f, 0.8f, 0.0f, 0.0f, 0.0f, 1.0f // Top 
	};


	GLuint indices[] = { // Note that we start from 0!
	 0, 1, 2, // First Triangle
	 //1, 2, 3 // Second Triangle
	};
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	// Bind the Vertex Array Object first, then bind and set vertex buffer(s) and attribute pointer(s).
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	// Position attribute
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	// Color attribute
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *
		sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0); // Unbind VAO
	// Game loop
	while (!glfwWindowShouldClose(window))
	{
		// Check if any events have been activiated (key pressed, mouse moved etc.) and call corresponding response functions
		glfwPollEvents();
		// Render
		// Clear the colorbuffer
		glClearColor(0.0f, 0.3f, 0.3f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);
		// Bind Textures using texture units
		glActiveTexture(GL_TEXTURE0);
		//glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture1"), 0);
		glActiveTexture(GL_TEXTURE1);
		//glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "ourTexture2"), 1);
		// Draw the triangle
		ourShader.Use();
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		glm::ortho(0.0f, 800.0f, 0.0f, 600.0f, 0.1f, 100.0f);
		model = glm::rotate(model, 60.0f, glm::vec3(0.0f, 1.0f, 0.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.0f, -3.0f));
		projection = glm::perspective(50.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f,100.0f);



		// Get their uniform location
		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		// Note: currently we set the projection matrix each frame, but since the projection matrix rarely changes it's often best practice to set it outside the main loop only once.
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		// Swap the screen buffers
		glfwSwapBuffers(window);
	}
	// Properly de-allocate all resources once they've outlived their purpose
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	// Terminate GLFW, clearing any resources allocated by GLFW.
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
*/

//3D OBJECT & CAMERA VIEW
//1
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <iostream>
#include "myshader.h"
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "LearnOpenGL", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointersand extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	// Vertex shader
	Shader ourShader("CS.vs", "CS.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
	0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
	-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
	0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
	0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
	0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
	-0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
	0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
	-0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
	0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
	0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f
	};
	GLuint indices[] = {
	0, 1, 2,
	3, 4, 5,
	6, 7, 8,
	9, 10, 11,
	12, 13, 14,
	14, 15, 12
	};
	glEnable(GL_DEPTH_TEST);
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),(GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),(GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
	GLuint texture1;
	GLuint texture2;
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		// glClearColor(0.4f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
		ourShader.Use();
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		model = glm::rotate(model, 315.0f, glm::vec3(1.0f, 1.0f, 1.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.2f, -3.0f));
		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT,0.1f, 100.0f);
		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
*/

//2
/*
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <iostream>
#include "myshader.h"
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "TUGAS 1 (39)", nullptr, nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointersand extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	// Vertex shader
	Shader ourShader("CS.vs", "CS.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
	0.25f, -1.25f, 0.0f, 1.0f, 0.0f, 0.0f, //kubus depan 
	-0.25, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f,
	-0.25f, -0.75f, 0.0f, 1.0f, 1.0f, 1.0f,
	0.25f, -0.75f, 0.0f, 1.0f, 0.0f, 0.0f,
	0.25f, -1.25f, -0.5f, 1.0f, 0.0f, 0.0f, //kubus kanan 
	0.25f, -1.25f, 0.0f,  1.0f, 1.0f, 1.0f,
	0.25f, -0.75f, 0.0f,  1.0f, 1.0f, 1.0f,
	0.25f, -0.75f, -0.5f, 1.0f, 0.0f, 0.0f,
	-0.25, -1.25f, 0.0f,  1.0f, 0.0f, 0.0f, //kubus kiri 
	-0.25f, -1.25f, -0.5f, 1.0f, 1.0f, 1.0f,
	-0.25f, -0.75f, -0.5f, 1.0f, 1.0f, 1.0f,
	-0.25f, -0.75f, 0.0f, 1.0f, 0.0f, 0.0f,
	-0.25, -1.25f, 0.0f,  1.0f, 1.0f, 1.0f, //kubus belakang 
	0.25f, -1.25f, -0.5f, 0.5f, 1.0f, 1.0f,
	0.25f, -0.75f, -0.5f, 0.5f, 1.0f, 1.0f,
	-0.25f, -0.75f, 0.0f, 1.0f, 1.0f, 1.0f,
	0.25f, -0.75f, 0.0f, 0.36f, 0.36f, 0.36f, //kubus atas 
	-0.25f, -0.75f, 0.0f, 0.36f, 0.36f, 0.36f,
	-0.25f, -0.75f, -0.5f, 0.36f, 0.36f, 0.36f,
	0.25f, -0.75f, -0.5f, 0.36f, 0.36f, 0.36f,
	0.25f, -1.25f, 0.0f, 1.0f, 0.0f, 0.0f, //kubus bawah 
	-0.25, -1.25f, 0.0f, 1.0f, 1.0f, 1.0f,
	-0.25f, -1.25f, -0.5f, 1.0f, 1.0f, 1.0f,
	0.25f, -1.25f, -0.5f, 1.0f, 0.0f, 0.0f,

	0.125f, -0.75f, -0.125f, 0.38f, 0.16f, 0.06f, //balok depan 
	-0.125, -0.75f, -0.125f, 0.30f, 0.16f, 0.06f,
	-0.125f, 0.5f, -0.125f, 0.30f, 0.16f, 0.06f,
	0.125f, 0.5f, -0.125f, 0.38f, 0.16f, 0.06f,
	0.125f, -0.75f, -0.375f, 0.38f, 0.16f, 0.06f, //balok kanan 
	0.125f, -0.75f, -0.125f, 0.30f, 0.16f, 0.06f,
	0.125f, 0.5f, -0.125f, 0.30f, 0.16f, 0.06f,
	0.125f, 0.5f, -0.375f, 0.38f, 0.16f, 0.06f,
	-0.125f, -0.75f, -0.125f, 0.38f, 0.16f, 0.06f, //balok kiri 
	-0.125f, -0.75f, -0.375f, 0.30f, 0.16f, 0.06f,
	-0.125f, 0.5f, -0.375f, 0.30f, 0.16f, 0.06f,
	-0.125f, 0.5f, -0.125f, 0.38f, 0.16f, 0.06f,
	0.125f, -0.75f, -0.375f, 0.38f, 0.16f, 0.06f, //balok belakang 
	-0.125, -0.75f, -0.375f, 0.30f, 0.16f, 0.06f,
	-0.125f, 0.5f, -0.375f, 0.30f, 0.16f, 0.06f,
	0.125f, 0.5f, -0.375f, 0.38f, 0.16f, 0.06f,

	0.5f, -0.25f, 0.25f, 0.0f, 0.4f, 0.0f,//Prisma1 depan (segitiga)
	-0.5f, -0.25f, 0.25f, 0.0f, 0.6f, 0.0f,
	0.0f, 0.5f, -0.25f, 0.0f, 0.8f, 0.0f,
	0.5f, -0.25f, -0.75f, 0.0f, 0.4f, 0.0f,//Prisma1 kanan (segitiga)
	0.5f, -0.25f, 0.25f, 0.0f, 0.6f, 0.0f,
	0.0f, 0.5f, -0.25f, 0.0f, 0.8f, 0.0f,
	-0.5f, -0.25f, -0.75f, 0.0f, 0.4f, 0.0f,//Prisma1 belakang (segitiga) 
	0.5f, -0.25f, -0.75f, 0.0f, 0.6f, 0.0f,
	0.0f, 0.5f, -0.25f, 0.0f, 0.8f, 0.0f,
	-0.5f, -0.25f, 0.25f, 0.0f, 0.4f, 0.0f,//Prisma1 kiri (segitiga)
	-0.5f, -0.25f, -0.75f, 0.0f, 0.6f, 0.0f,
	0.0f, 0.5f, -0.25f, 0.0f, 0.8f, 0.0f,
	0.5f, -0.25f, 0.25f, 0.0f, 0.3f, 0.0f,//Prisma1 bawah (persegi)
	-0.5f, -0.25f, 0.25f, 0.0f, 0.3f, 0.0f,
	-0.5f, -0.25f, -0.75f, 0.0f, 0.3f, 0.0f,
	0.5f, -0.25f, -0.75f, 0.0f, 0.3f, 0.0f,

	0.5f, 0.125f, 0.25f, 0.0f, 0.7f, 0.0f,//Prisma2 depan (segitiga)
	-0.5f, 0.125f, 0.25f, 0.0f, 0.82f, 0.0f,
	0.0f, 1.0f, -0.25f, 0.0f, 0.92f, 0.0f,
	0.5f, 0.125f, -0.75f, 0.0f, 0.7f, 0.0f,//Prisma2 kanan (segitiga)
	0.5f, 0.125f, 0.25f, 0.0f, 0.82f, 0.0f,
	0.0f, 1.0f, -0.25f, 0.0f, 0.92f, 0.0f,
	-0.5f, 0.125f, -0.75f, 0.0f, 0.7f, 0.0f,//Prisma2 belakang (segitiga) 
	0.5f, 0.125f, -0.75f, 0.0f, 0.82f, 0.0f,
	0.0f, 1.0f, -0.25f, 0.0f, 0.92f, 0.0f,
	-0.5f, 0.125f, 0.25f, 0.0f, 0.7f, 0.0f,//Prisma2 kiri (segitiga)
	-0.5f, 0.125f, -0.75f, 0.0f, 0.82f, 0.0f,
	0.0f, 1.0f, -0.25f, 0.0f, 0.92f, 0.0f,
	0.5f, 0.125f, 0.25f, 0.0f, 0.6f, 0.0f,//Prisma2 bawah (persegi)
	-0.5f, 0.125f, 0.25f, 0.0f, 0.6f, 0.0f,
	-0.5f, 0.125f, -0.75f, 0.0f, 0.6f, 0.0f,
	0.5f, 0.125f, -0.75f, 0.0f, 0.6f, 0.0f,

	};
	GLuint indices[] = {
	0, 1, 2, //kubus depan
	2, 3, 0,
	4, 5, 6, //kubus kanan
	6, 7, 4,
	8, 9, 10, //kubus kiri
	10, 11, 8,
	12, 13, 14, //kubus belakang
	14, 15, 12,
	16, 17, 18, //kubus atas
	18, 19, 16,
	20, 21, 22, //kubus bawah
	22, 23, 20,
	24, 25, 26, // balok depan
	26, 27, 24,
	28, 29, 30, // balok kanan
	30, 31, 28,
	32, 33, 34, // balok kiri
	34, 35, 32,
	36, 37, 38, // balok belakang
	38, 39, 36,
	40, 41, 42, //Prisma1 depan
	43, 44, 45, //Prisma1 kanan
	46, 47, 48, //Prisma1 belakang
	49, 50, 51, //Prisma1 kiri
	52, 53, 54, //Prisma1 bawah (persegi)
	54, 55, 52,
	56, 57, 58, //Prisma2 depan
	59, 60, 61, //Prisma2 kanan
	62, 63, 64, //Prisma2 belakang
	65, 66, 67, //Prisma2 kiri
	68, 69, 70, //Prisma2 bawah (persegi)
	70, 71, 68
	};
	glEnable(GL_DEPTH_TEST);
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices,GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),(GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat),(GLvoid*)(3 * sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
	GLuint texture1;
	GLuint texture2;
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		// glClearColor(0.4f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
		ourShader.Use();
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		model = glm::rotate(model, 315.0f, glm::vec3(1.0f, 1.0f, 1.0f));
		view = glm::translate(view, glm::vec3(0.0f, 0.2f, -3.0f));
		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT,0.1f, 100.0f);
		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 100, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}
*/

//3
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <stdio.h>
#include <glm\glm.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include <glm\gtc\type_ptr.hpp>
#include <iostream>
#include "myshader.h"
// Function prototypes
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode);
// Window dimensions
const GLuint WIDTH = 800, HEIGHT = 600;
// The MAIN function, from here we start the application and run the game loop
int main()
{
	// Init GLFW
	glfwInit();
	// Set all the required options for GLFW
	// Create a GLFWwindow object that we can use for GLFW's functions
	GLFWwindow* window = glfwCreateWindow(WIDTH, HEIGHT, "Pyramid OpenGL", nullptr,nullptr);
	glfwMakeContextCurrent(window);
	// Set the required callback functions
	glfwSetKeyCallback(window, key_callback);
	// Set this to true so GLEW knows to use a modern approach to retrieving function pointersand extensions
	glewExperimental = GL_TRUE;
	// Initialize GLEW to setup the OpenGL Function pointers
	glewInit();
	// Define the viewport dimensions
	glViewport(0, 0, WIDTH, HEIGHT);
	// Build and compile our shader program
	// Vertex shader
	Shader ourShader("CV.vs", "CV.frag");
	// Set up vertex data (and buffer(s)) and attribute pointers
	GLfloat vertices[] = {
	0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,//depan
	-0.5f, -0.5f, 0.0f, 1.0f, 0.0f, 0.0f,
	0.0f, 0.5f, -0.5f, 1.0f, 0.0f, 0.0f,
	0.5f, -0.5f, 0.0f, 1.0f, 1.0f, 0.0f,//kanan
	0.0f, 0.5f, -0.5f, 1.0f, 1.0f, 0.0f,
	0.5f, -0.5f, -1.0f, 1.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, 0.0f, 0.0f, 1.0f, 0.0f,//kiri
	0.0f, 0.5f, -0.5f, 0.0f, 1.0f, 0.0f,
	-0.5f, -0.5f, -1.0f, 0.0f, 1.0f, 0.0f,
	0.0f, 0.5f, -0.5f, 0.0f, 0.0f, 1.0f,//belakang
	-0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
	0.5f, -0.5f, -1.0f, 0.0f, 0.0f, 1.0f,
	-0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f,
	-0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
	0.5f, -0.5f, 0.0f, 0.5f, 0.0f, 0.8f,
	0.5f, -0.5f, -1.0f, 0.5f, 0.0f, 0.8f //alas
	};
	GLuint indices[] = {
	0, 1, 2,
	3, 4, 5,
	6, 7, 8,
	9, 10, 11,
	12, 13, 14,
	14, 15, 12
	};
	glEnable(GL_DEPTH_TEST);
	GLuint VBO, VAO, EBO;
	glGenVertexArrays(1, &VAO);
	glGenBuffers(1, &VBO);
	glGenBuffers(1, &EBO);
	glBindVertexArray(VAO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, EBO);
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeof(indices), indices, GL_STATIC_DRAW);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)0);
	glEnableVertexAttribArray(0);
	glVertexAttribPointer(1, 3, GL_FLOAT, GL_FALSE, 6 * sizeof(GLfloat), (GLvoid*)(3 *sizeof(GLfloat)));
	glEnableVertexAttribArray(1);
	glBindVertexArray(0);
	GLuint texture1;
	GLuint texture2;
	glGenTextures(1, &texture1);
	glBindTexture(GL_TEXTURE_2D, texture1);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int width, height;
	glGenerateMipmap(GL_TEXTURE_2D);
	glBindTexture(GL_TEXTURE_2D, 0);
	glGenTextures(1, &texture2);
	glBindTexture(GL_TEXTURE_2D, texture2);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	glBindTexture(GL_TEXTURE_2D, 0);
	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		glActiveTexture(GL_TEXTURE0);
		glBindTexture(GL_TEXTURE_2D, texture1);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture1"), 0);
		glActiveTexture(GL_TEXTURE1);
		glBindTexture(GL_TEXTURE_2D, texture2);
		glUniform1i(glGetUniformLocation(ourShader.Program, "texture2"), 1);
		ourShader.Use();
		glm::mat4 model;
		glm::mat4 view;
		glm::mat4 projection;
		GLfloat radius = 3.0f;
		GLfloat camX = float(0) * radius;
		GLfloat camY = float(-0.7) * radius;
		GLfloat camZ = float(0.7) * radius;
		view =	glm::lookAt(glm::vec3(camX, camY, camZ),
				glm::vec3(0.0, 0.0, 0.0),
				glm::vec3(0.0, 1.0, 0.0));
		projection = glm::perspective(45.0f, (GLfloat)WIDTH / (GLfloat)HEIGHT, 0.1f,100.0f);
		GLint modelLoc = glGetUniformLocation(ourShader.Program, "model");
		GLint viewLoc = glGetUniformLocation(ourShader.Program, "view");
		GLint projLoc = glGetUniformLocation(ourShader.Program, "projection");
		glUniformMatrix4fv(modelLoc, 1, GL_FALSE, glm::value_ptr(model));
		glUniformMatrix4fv(viewLoc, 1, GL_FALSE, glm::value_ptr(view));
		glUniformMatrix4fv(projLoc, 1, GL_FALSE, glm::value_ptr(projection));
		glBindVertexArray(VAO);
		glDrawElements(GL_TRIANGLES, 18, GL_UNSIGNED_INT, 0);
		glBindVertexArray(0);
		glfwSwapBuffers(window);
	}
	glDeleteVertexArrays(1, &VAO);
	glDeleteBuffers(1, &VBO);
	glDeleteBuffers(1, &EBO);
	glfwTerminate();
	return 0;
}
// Is called whenever a key is pressed/released via GLFW
void key_callback(GLFWwindow* window, int key, int scancode, int action, int mode)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
		glfwSetWindowShouldClose(window, GL_TRUE);
}