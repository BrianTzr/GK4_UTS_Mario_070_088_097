#include <freeglut.h>

void drawPixel(float x, float y, float r, float g, float b) {
    glColor3f(r, g, b); // Set color
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + 1.0f, y);
    glVertex2f(x + 1.0f, y + 1.0f);
    glVertex2f(x, y + 1.0f);
    glEnd();
}

void drawMario() {
    // Define the pixel data (row by row, from top to bottom)
    int mario[16][16] = {
        // 1 = red, 2 = orange (face), 3 = brown (hair/clothes), 0 = transparent, 4 = black (details)
        {0,0,0,0,0,1,1,1,1,1,0,0,0,0,0,0},
        {0,0,0,0,1,1,1,1,1,1,1,1,1,1,0,0},
        {0,0,0,0,3,3,3,2,2,2,4,2,0,0,0,0},
        {0,0,0,3,2,3,2,2,2,2,4,2,2,2,0,0},
        {0,0,0,3,2,3,3,2,2,2,2,4,2,2,2,0},
        {0,0,0,0,3,2,2,2,2,2,4,4,4,4,0,0},
        {0,0,0,0,0,2,2,2,2,2,2,2,0,0,0,0},
        {0,0,0,0,1,1,5,1,1,1,1,0,0,0,0,0},
        {0,0,0,1,1,1,5,1,1,5,1,1,1,0,0,0},
        {0,0,1,1,1,1,5,5,5,5,1,1,1,1,0,0},
        {0,0,2,2,1,5,6,5,5,6,5,1,2,2,0,0},
        {0,0,2,2,2,5,5,5,5,5,5,2,2,2,0,0},
        {0,0,2,2,5,5,5,5,5,5,5,5,2,2,0,0},
        {0,0,0,0,5,5,5,0,0,5,5,5,0,0,0,0},
        {0,0,0,3,3,3,0,0,0,0,3,3,3,0,0,0},
        {0,0,3,3,3,3,0,0,0,0,3,3,3,3,0,0},
    };

    // Draw pixels with corresponding colors
    for (int i = 0; i < 16; ++i) {
        for (int j = 0; j < 16; ++j) {
            float x = j - 8; // Centering the art
            float y = 8 - i; // Invert y for OpenGL's coordinate system
            if (mario[i][j] == 1) drawPixel(x, y, 1.0f, 0.0f, 0.0f); // Red
            else if (mario[i][j] == 2) drawPixel(x, y, 1.0f, 0.647f, 0.0f); // Orange
            else if (mario[i][j] == 3) drawPixel(x, y, 0.545f, 0.271f, 0.075f); // Brown
            else if (mario[i][j] == 4) drawPixel(x, y, 0.0f, 0.0f, 0.0f); // Black
            else if (mario[i][j] == 5) drawPixel(x, y, 0.0f, 0.0f, 1.0f); // Blue
            else if (mario[i][j] == 6) drawPixel(x, y, 1.0f, 1.0f, 0.0f); // Yellow
        }
    }
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawMario();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(640, 480);
    glutInitWindowPosition(100, 100);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutCreateWindow("Mario Pixel Art");

    // Set the background color to sky blue
    glClearColor(135.0 / 255.0f, 206.0 / 255.0f, 235.0 / 255.0f, 1.0f);
    gluOrtho2D(-40, 40, -40, 40);

    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}
