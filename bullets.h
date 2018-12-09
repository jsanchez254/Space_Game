class bullets{
    public:
        static float y;
        static float positionY1;
        static float positionY2;
        static float positionX1;
        static float positionX2;

    public: 
        bullets(float positionY1x ,  float positionY2x , float positionX1x , float positionX2x ){
            y = 0.0f;
            positionY1 = positionY1x;
            positionY2 = positionY2x;
            positionX1 = positionX1x;
            positionX2 = positionX2x;
        }

        bullets(){

        }

    static void upbullet(){
        y += 0.03f;
        glutPostRedisplay();
    }
    

    void draw(){
        glColor3f(1, 0.6, 0.2);
        glBegin(GL_POLYGON);
        
       
        glVertex3f(positionX1/2, positionY1/2 + y, 0.15);
        glVertex3f(positionX2/2, positionY1/2 + y, 0.15);
        glVertex3f(positionX2/2, positionY2/2 + y, 0.15);
        glVertex3f(positionX1/2, positionY2/2 + y, 0.15);
        
        glEnd();
    }
};

float bullets::y = 0.0f;
float bullets::positionY1;
float bullets::positionY2;
float bullets::positionX1;
float bullets::positionX2;