#include <windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <cmath>
#include <ctime>

using namespace std;

// Game States
enum GameState { STATE_MENU, STATE_PLAYING, STATE_GAMEOVER };
GameState currentState = STATE_MENU;

// Difficulty Modes
enum Difficulty { EASY = 0, MEDIUM = 1, HARD = 2 };
Difficulty currentDifficulty = EASY;

// Target Character Structure
struct TargetChar {
    float x, y;
    char symbol;
    float life;
    float maxLife;
    bool active;
    float r, g, b;
};

// Visual Effect Particles
struct Particle {
    float x, y;
    float vx, vy;
    float life;
    float r, g, b;
};

const int MAX_TARGETS = 5;
TargetChar targets[MAX_TARGETS];
vector<Particle> particles;

// Game Stats
int score = 0;
int combo = 0;
int lives = 5;
float spawnTimer = 0.0f;
float spawnInterval = 60.0f;

// Character Pools
string easyPool = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
string mediumPool = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,./;-=";
string hardPool = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789,./;-=!@#$%^&*()_+{}|:\"<>?~";

// Helper Function: Stringstream to convert numbers to string (C++98 compatible)
string intToString(int val) {
    stringstream ss;
    ss << val;
    return ss.str();
}

// Render Text
void drawText(string text, float x, float y, void* font = GLUT_BITMAP_HELVETICA_18, float r = 1.0f, float g = 1.0f, float b = 1.0f) {
    glColor3f(r, g, b);
    glRasterPos2f(x, y);
    for (size_t i = 0; i < text.length(); i++) {
        glutBitmapCharacter(font, text[i]);
    }
}

// Render Filled Rectangle
void drawRect(float x, float y, float w, float h, float r, float g, float b, float a = 1.0f) {
    glColor4f(r, g, b, a);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + w, y);
    glVertex2f(x + w, y + h);
    glVertex2f(x, y + h);
    glEnd();
}

// Create Hit Particle Effects
void addParticles(float x, float y, float r, float g, float b) {
    for (int i = 0; i < 12; i++) {
        Particle p;
        p.x = x;
        p.y = y;
        p.vx = ((rand() % 100) / 50.0f - 1.0f) * 3.0f;
        p.vy = ((rand() % 100) / 50.0f - 1.0f) * 3.0f;
        p.life = 1.0f;
        p.r = r; p.g = g; p.b = b;
        particles.push_back(p);
    }
}

// Spawn a new random character
void spawnTarget() {
    for (int i = 0; i < MAX_TARGETS; i++) {
        if (!targets[i].active) {
            targets[i].x = -200 + (rand() % 400);
            targets[i].y = -150 + (rand() % 300);

            // Select character from pool
            string pool = easyPool;
            if (currentDifficulty == MEDIUM) pool = mediumPool;
            if (currentDifficulty == HARD) pool = hardPool;

            targets[i].symbol = pool[rand() % pool.length()];

            // Adjust speed according to difficulty
            if (currentDifficulty == EASY) targets[i].maxLife = 180.0f;
            else if (currentDifficulty == MEDIUM) targets[i].maxLife = 140.0f;
            else targets[i].maxLife = 100.0f;

            targets[i].life = targets[i].maxLife;
            targets[i].active = true;

            // Stylish colors
            int c = rand() % 3;
            if (c == 0) { targets[i].r = 0.0f; targets[i].g = 0.9f; targets[i].b = 1.0f; }      // Cyan
            else if (c == 1) { targets[i].r = 1.0f; targets[i].g = 0.4f; targets[i].b = 0.7f; } // Pink
            else { targets[i].r = 1.0f; targets[i].g = 0.8f; targets[i].b = 0.2f; }             // Gold

            break;
        }
    }
}

// Start / Reset Game
void resetGame() {
    score = 0;
    combo = 0;
    lives = 5;
    spawnTimer = 0.0f;
    particles.clear();

    for (int i = 0; i < MAX_TARGETS; i++) {
        targets[i].active = false;
    }
    spawnTarget();
}

// --- DISPLAY: MENU ---
void drawMenu() {
    // Title Box
    drawRect(-180, 100, 360, 80, 0.15f, 0.15f, 0.25f);
    drawText("PRO TYPING & CHARACTER CATCHER", -160, 140, GLUT_BITMAP_HELVETICA_18, 0.0f, 0.9f, 1.0f);
    drawText("Select Difficulty to Start", -90, 115, GLUT_BITMAP_HELVETICA_12, 0.8f, 0.8f, 0.8f);

    // Mode Buttons
    // Easy
    drawRect(-150, 20, 300, 45, 0.1f, 0.6f, 0.3f);
    drawText("Press '1' for EASY MODE (Alphabets & Numbers)", -140, 35, GLUT_BITMAP_HELVETICA_12, 1.0f, 1.0f, 1.0f);

    // Medium
    drawRect(-150, -40, 300, 45, 0.8f, 0.5f, 0.1f);
    drawText("Press '2' for MEDIUM MODE (+ Punctuation)", -135, -25, GLUT_BITMAP_HELVETICA_12, 1.0f, 1.0f, 1.0f);

    // Hard
    drawRect(-150, -100, 300, 45, 0.8f, 0.1f, 0.2f);
    drawText("Press '3' for HARD MODE (+ Special Symbols)", -135, -85, GLUT_BITMAP_HELVETICA_12, 1.0f, 1.0f, 1.0f);

    drawText("Press ESC to Exit", -60, -180, GLUT_BITMAP_HELVETICA_12, 0.5f, 0.5f, 0.5f);
}

// --- DISPLAY: PLAYING ---
void drawGame() {
    // Top HUD Bar
    drawRect(-250, 200, 500, 50, 0.12f, 0.12f, 0.18f);

    // Draw Stats
    drawText("Score: " + intToString(score), -230, 220, GLUT_BITMAP_HELVETICA_18, 1.0f, 1.0f, 1.0f);
    drawText("Combo: x" + intToString(combo), -100, 220, GLUT_BITMAP_HELVETICA_18, 0.0f, 0.9f, 1.0f);

    // Health / Lives
    drawText("Lives: ", 90, 220, GLUT_BITMAP_HELVETICA_18, 1.0f, 0.3f, 0.3f);
    for (int i = 0; i < lives; i++) {
        drawRect(150 + (i * 15), 218, 10, 15, 1.0f, 0.2f, 0.3f);
    }

    // Active Targets Drawing
    for (int i = 0; i < MAX_TARGETS; i++) {
        if (targets[i].active) {
            // Background Card for Character
            float cardSize = 40.0f;
            drawRect(targets[i].x - cardSize/2, targets[i].y - cardSize/2, cardSize, cardSize, 0.18f, 0.18f, 0.24f);

            // Life Progress Bar under Card
            float lifeRatio = targets[i].life / targets[i].maxLife;
            drawRect(targets[i].x - cardSize/2, targets[i].y - cardSize/2 - 6, cardSize * lifeRatio, 4, targets[i].r, targets[i].g, targets[i].b);

            // Render Character Symbol inside Card
            string charStr = "";
            charStr += targets[i].symbol;
            drawText(charStr, targets[i].x - 6, targets[i].y - 6, GLUT_BITMAP_TIMES_ROMAN_24, targets[i].r, targets[i].g, targets[i].b);
        }
    }

    // Render Hit Particles
    for (size_t i = 0; i < particles.size(); i++) {
        drawRect(particles[i].x, particles[i].y, 4, 4, particles[i].r, particles[i].g, particles[i].b, particles[i].life);
    }
}

// --- DISPLAY: GAME OVER ---
void drawGameOver() {
    drawRect(-160, -80, 320, 180, 0.15f, 0.15f, 0.22f);

    drawText("GAME OVER", -75, 50, GLUT_BITMAP_TIMES_ROMAN_24, 1.0f, 0.2f, 0.2f);
    drawText("Final Score: " + intToString(score), -60, 10, GLUT_BITMAP_HELVETICA_18, 1.0f, 1.0f, 1.0f);

    drawText("Press 'R' to Restart", -65, -30, GLUT_BITMAP_HELVETICA_12, 0.0f, 0.9f, 1.0f);
    drawText("Press 'M' for Main Menu", -70, -55, GLUT_BITMAP_HELVETICA_12, 0.8f, 0.8f, 0.8f);
}

// Main Display Loop
void display() {
    glClearColor(0.08f, 0.08f, 0.12f, 1.0f); // Dark Minimalist Background
    glClear(GL_COLOR_BUFFER_BIT);

    if (currentState == STATE_MENU) drawMenu();
    else if (currentState == STATE_PLAYING) drawGame();
    else if (currentState == STATE_GAMEOVER) drawGameOver();

    glFlush();
}

// Game Logic Update (~60 FPS)
void timer(int val) {
    if (currentState == STATE_PLAYING) {
        // Spawn Timer Logic
        spawnTimer += 1.0f;
        if (spawnTimer >= spawnInterval) {
            spawnTarget();
            spawnTimer = 0.0f;
        }

        // Update Targets Life
        for (int i = 0; i < MAX_TARGETS; i++) {
            if (targets[i].active) {
                targets[i].life -= 1.0f;

                // Target Expired (Missed)
                if (targets[i].life <= 0) {
                    targets[i].active = false;
                    combo = 0;
                    lives--;

                    if (lives <= 0) {
                        currentState = STATE_GAMEOVER;
                    }
                }
            }
        }

        // Update Particle Physics
        for (size_t i = 0; i < particles.size(); i++) {
            particles[i].x += particles[i].vx;
            particles[i].y += particles[i].vy;
            particles[i].life -= 0.05f;

            if (particles[i].life <= 0) {
                particles.erase(particles.begin() + i);
                i--;
            }
        }
    }

    glutPostRedisplay();
    glutTimerFunc(16, timer, 0);
}

void keyboard(unsigned char key, int x, int y) {
    if (currentState == STATE_MENU) {
        if (key == '1') {
            currentDifficulty = EASY;
            resetGame();
            currentState = STATE_PLAYING;
        } else if (key == '2') {
            currentDifficulty = MEDIUM;
            resetGame();
            currentState = STATE_PLAYING;
        } else if (key == '3') {
            currentDifficulty = HARD;
            resetGame();
            currentState = STATE_PLAYING;
        } else if (key == 27) { // ESC
            exit(0);
        }
    }
    else if (currentState == STATE_PLAYING) {
        bool hit = false;

        for (int i = 0; i < MAX_TARGETS; i++) {
            if (targets[i].active && targets[i].symbol == key) {
                targets[i].active = false;
                hit = true;

                combo++;
                score += 10 * combo;

                addParticles(targets[i].x, targets[i].y, targets[i].r, targets[i].g, targets[i].b);
                break;
            }
        }
        if (!hit) {
            combo = 0;
        }
    }
    else if (currentState == STATE_GAMEOVER) {
        if (key == 'r' || key == 'R') {
            resetGame();
            currentState = STATE_PLAYING;
        } else if (key == 'm' || key == 'M') {
            currentState = STATE_MENU;
        }
    }
}

void init() {
    glOrtho(-250.0, 250.0, -250.0, 250.0, -250.0, 250.0);
    srand((unsigned int)time(0));
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(800, 700);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutCreateWindow("Professional Speed Typing Game");

    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutTimerFunc(0, timer, 0);
    glutMainLoop();

    return 0;
}
