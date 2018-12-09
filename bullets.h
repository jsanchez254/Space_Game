class bullets{
    public:
        static float y;
        static float positionY1;
        static float positionY2;
        static float positionX1;
        static float positionX2;
    bullets(){
        y = 0.0f;
    }

    static void upbullet(){
        y += 0.03f;
        glutPostRedisplay();
    }
    

    void draw(){
        glColor3f(1, 0.6, 0.2);
        glBegin(GL_POLYGON);
        
        glVertex2f(positionX1/2, positionY1/2 + y);
        glVertex2f(positionX2/2, positionY1/2 + y);
        glVertex2f(positionX2/2, positionY2/2 + y);
        glVertex2f(positionX1/2, positionY2/2 + y);
        
        glEnd();
    }
};

float bullets::y = 0.0f;
float bullets::positionY1 = -0.6f;
float bullets::positionY2 = -0.8f;
float bullets::positionX1 = -0.1f;
float bullets::positionX2 = 0.1f;