class bullets{
    public:
        float y = 0.0f;
    bullets(){

    }

    void upbullet(){
        y += 0.001f;
    }
    

    void draw(){
        glColor3f(1, 0.6, 0.2);
        glBegin(GL_POLYGON);
        
        glVertex2f(-0.1f , -0.6f +y );
        glVertex2f(0.1f , -0.6f + y);
        glVertex2f(0.1f , -0.8f + y);
        glVertex2f(-0.1f, -0.8f + y );
        
        glEnd();
    }
};