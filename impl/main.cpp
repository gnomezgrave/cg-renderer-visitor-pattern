using namespace std;

#include <cstdio>
#include <stdio.h>
#include <iostream>
#include <vr/AC3DLoader.h>
#include <vr/PNGReader.h>
#include <vr/Vec3.h>
#include <vr/Vec4.h>
#include <GL/glut.h>
#include <cstdlib>
#include "../headers/transform.h"
#include "../headers/color.h"

float angle=30.0f;
float xAng = -0.1f;
float yAng = -0.1f;
float zAng = 0.0f;

const float RADIUS = 4.0f; //The radius of the sphere

//Called when a key is pressed
void handleKeypress(unsigned char key, //The key that was pressed
					int x, int y) {    //The current mouse coordinates
	switch (key) {
		case 27: //Escape key
			exit(0); //Exit the program
		/*
		case 'w':
		case 'W':
			angle+=2.0f;
			if(angle>360)
				angle-=360;
			xAng+=0.1f;
			glutPostRedisplay();
			break;
		case 's':
		case 'S':
			angle-=2.0f;
			if(angle>360)
				angle-=360;
			xAng-=0.1f;

			glutPostRedisplay();
			break;
		case 'a':
		case 'A':
			angle+=2.0f;
			if(angle>360)
				angle-=360;
			yAng+=0.1f;
			glutPostRedisplay();
			break;
		case 'd':
		case 'D':
			angle-=2.0f;
			if(angle>360)
				angle-=360;
			yAng-=0.1f;

			glutPostRedisplay();
			break;
		*/
	}
}

//Initializes 3D rendering
void initRendering() {
	//Makes 3D drawing work when something is in front of something else
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_LIGHTING);
	glEnable(GL_LIGHT0);
	glEnable(GL_NORMALIZE);
	glShadeModel(GL_SMOOTH);
	//Disable color materials, so that glMaterial calls work
	glDisable(GL_COLOR_MATERIAL);
}

//Called when the window is resized
void handleResize(int w, int h) {
	//Tell OpenGL how to convert from coordinates to pixel values
	glViewport(0, 0, w, h);
	
	glMatrixMode(GL_PROJECTION); //Switch to setting the camera perspective
	
	//Set the camera perspective
	glLoadIdentity(); //Reset the camera
	gluPerspective(45.0,                  //The camera angle
				   (double)w / (double)h, //The width-to-height ratio
				   1.0f,                   //The near z clipping coordinate
				   200.0f);                //The far z clipping coordinate
}
void update(int value){
	angle+=2.0f;
	if(angle>360){
		angle-=360;
	}
	glutPostRedisplay();
	//glutTimerFunc(25,update,0);
}
//Draws the 3D scene
void drawScene() {
	//Clear information from last draw
	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	
	glMatrixMode(GL_MODELVIEW); //Switch to the drawing perspective
	glLoadIdentity(); //Reset the drawing perspective
	glTranslatef(0.0f,0.0f,-5.0f);
	glRotatef(-angle,xAng,yAng,zAng);
	vr::AC3DLoader ac;
	
	if(ac.load("../racecar.ac")){
		
		vr::AC3DLoader::MaterialArray mats =   ac.getMaterials();
		vr::AC3DLoader::GeometryArray geos = ac.getGeometries();
		
		GLfloat ambientLight[] = {0.2f, 0.2f, 0.2f, 1.0f};
		glLightModelfv(GL_LIGHT_MODEL_AMBIENT, ambientLight);
		
		GLfloat lightColor[] = {0.6f, 0.6f, 0.6f, 1.0f};
		GLfloat lightPos[] = {2 * RADIUS, 2 * RADIUS, 2 * RADIUS, 1.0f};
		//Diffuse (non-shiny) light component
		glLightfv(GL_LIGHT0, GL_DIFFUSE, lightColor);
		//Specular (shiny) light component
		glLightfv(GL_LIGHT0, GL_SPECULAR, lightColor);
		glLightfv(GL_LIGHT0, GL_POSITION, lightPos);
		
		cout<<mats.size()<<endl;
		
		size_t geoC = ac.getNumGeometries();
		
		for(size_t j=0;j<geoC;j++){
			
			vr::AC3DLoader::Geometry g = geos[j];
			
			size_t verC = g.getNumVertices();
			
			vr::Vec3 trans = g.getTranslation();

			glBegin(GL_TRIANGLES);
			
			for(size_t i=0;i<verC;i++){
				
				vr::Vec3 v=g.getVertex(i);
				
				vr::AC3DLoader::Material m = mats[g.getMaterial(i)];
				
				vr::Vec4 dif = m.diffuse;
				vr::Vec4 amb = m.ambient;
				vr::Vec4 emi = m.emission;
				vr::Vec4 spc = m.specular;
				float shn = m.shine;
				
				vr::Vec3 nrm = g.getNormal(j);
				
				GLfloat difF[]={dif.x(),dif.y(),dif.z(),dif.w()};
				float ambF[]={amb.x(),amb.y(),amb.z(),amb.w()};
				GLfloat emiF[]={emi.x(),emi.y(),emi.z(),emi.w()};
				GLfloat spcF[]={spc.x(),spc.y(),spc.z(),spc.w()};
				
				glMaterialfv(GL_FRONT, GL_AMBIENT_AND_DIFFUSE, difF);
				glMaterialfv(GL_FRONT, GL_SPECULAR, spcF);
				glMaterialfv(GL_FRONT, GL_EMISSION, emiF);
				glMaterialf(GL_FRONT, GL_SHININESS, shn); //The shininess parameter
				
				glNormal3f(nrm.x(),nrm.y(),nrm.z());
				glVertex3f((float)v.x()+trans.x(),(float)v.y()+trans.y(),(float)v.z()+trans.z());				
				
				//cout<<v.x()<<(char)9<<v.y()<<(char)9<<v.z()<<(char)9<<endl;
			}
			glEnd();
			
		}
		glPopMatrix();
	}
	glutSwapBuffers(); //Send the 3D scene to the screen
}
/*
int main(int argc, char **argv){
	
  //Initialize GLUT
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(600, 600); //Set the window size

	//Create the window
	glutCreateWindow("Basic Shapes - videotutorialsrock.com");
	initRendering(); //Initialize rendering

	//Set handler functions for drawing, keypresses, and window resizes
	glutDisplayFunc(drawScene);
	glutKeyboardFunc(handleKeypress);
	glutReshapeFunc(handleResize);
	//glutTimerFunc(25,update,0);
	glutMainLoop(); //Start the main loop.  glutMainLoop doesn't return.

    
  return 0;
}
*/