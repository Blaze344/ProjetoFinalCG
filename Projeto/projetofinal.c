#include "projeto.h"

// Initialization routine.
void setup(void) 
{
   glClearColor(0.0, 0.0, 0.0, 0.0);
   font = (long)GLUT_BITMAP_8_BY_13; // inicializacao das fontes
   fontRoman = (long)GLUT_STROKE_ROMAN;

   inicializarMenu();
}

// OpenGL window reshape routine.
void resize(int w, int h){
   if(menu){resizeMenu(w,h);}
   else resizeSimulacao(w,h); //resize para a simulacao, que usa projecao em perspectiva
}

void drawScene(void){
   if(menu){drawMenu();} 
   else simulacao();       //se estiver no menu, desenha o menu, se nao, desenha a simulacao
}

// Keyboard input processing routine.
void keyInput(unsigned char key, int x, int y)
{
   if(menu){ keyMenu(key, x, y);}
   else keySimulacao(key, x, y);
}

void specialInput(int key, int x, int y){
   if(menu){} //specialMenu(key, x, y);
   else specialKeySimulacao(key, x, y);
}

void mouseInput(int button, int state, int x, int y){
   if(menu){mouseMenu(button, state, x, y);}
   // else //mouseSimulacao(key, x, y, state);
}

// Main routine.
int main(int argc, char **argv) {
   srand(time(NULL));
   menu = 1; //inicializando variavel de estado

   glutInit(&argc, argv);

   glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGBA | GLUT_DEPTH); 
   glutInitWindowSize(500, 500);
   glutInitWindowPosition(100, 100); 
   glutCreateWindow("Projeto final de CG.c");
   glutDisplayFunc(drawScene); 
   glutReshapeFunc(resize);  
   glutKeyboardFunc(keyInput);
   glutSpecialFunc(specialInput);
   glutMouseFunc(mouseInput);

   setup();

   glutMainLoop(); 
}
