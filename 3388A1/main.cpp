import glfw
import OpenGL.GL as GL
import math

def read_data_from_file(file_path):
    with open(file_path) as file:
        lines = file.readlines()

    data = []
    for line in lines:
        line_data = line.strip().split(" ")
        for i in range(len(line_data)):
            line_data[i] = float(line_data[i])
        data += line_data
    return data

def draw_dog(data):
    GL.glBegin(GL.GL_LINE_STRIP)
    for i in range(0, len(data), 2):
        GL.glVertex2f(data[i], data[i + 1])
    GL.glEnd()

def main():
    # Initialize the GLFW library
    if not glfw.init():
        return

    # Create a GLFW window
    window = glfw.create_window(600, 600, "OpenGL", None, None)
    if not window:
        glfw.terminate()
        return

    # Make the context of the window current
    glfw.make_context_current(window)

    # Set the viewport
    GL.glViewport(0, 0, 1200, 1200)

    # Set the background color to white
    GL.glClearColor(1, 1, 1, 1)

    # Read data from the file
    data = read_data_from_file("dog.txt")

    while not glfw.window_should_close(window):
        GL.glClear(GL.GL_COLOR_BUFFER_BIT)

        GL.glMatrixMode(GL.GL_PROJECTION)
        GL.glLoadIdentity()
        GL.glOrtho(0, 60, 0, 60, -1, 1)

        GL.glMatrixMode(GL.GL_MODELVIEW)
        GL.glLoadIdentity()

        # Draw the dogs at 8 different points along the circle
        GL.glColor3f(0, 0, 0)
        for i in range(8):
            GL.glPushMatrix()
            GL.glTranslatef(30, 30, 0)
            GL.glRotatef(45 * i, 0, 0, 1)
            GL.glTranslatef(25, 0, 0)
            GL.glRotatef(-1 * (i * 45 + glfw.get_time() * 45), 0, 0, 1)
            draw_dog(data)
            GL.glPopMatrix()

        # Swap buffers
        glfw.swap_buffers(window)

        # Poll events
        glfw.poll_events()

    # Terminate GLFW
    glfw.terminate()

if __name__ == "__main__":
    main()
