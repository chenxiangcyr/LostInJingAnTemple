#include <QtGui>
#include <QtOpenGL>
#include <QMessageBox>
#include <math.h>

#include "glwidget.h"

GLWidget::GLWidget(QWidget *parent)
	: QGLWidget(parent)
{
	leftMargin = 100;
	topMargin = 10;

	// Start point1
	startPoint1.x = 60;
	startPoint1.y = 0;

	// Start point2
	startPoint2.x = -60;
	startPoint2.y = 330;

	// End point
	endPoint.x = 300;
	endPoint.y = 200;

	points.push_back(startPoint1);
	points.push_back(startPoint2);
	points.push_back(endPoint);

	// Initialize distance matrix
	for(int i=0; i<POINTS_SIZE; i++) {
		for(int j=0; j<POINTS_SIZE; j++) {
			distance[i][j] = MAX_DISTANCE;
		}
	}
}

GLWidget::~GLWidget()
{

}

// Initialize OpenGL
void GLWidget::initializeGL()
{
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

// Resize OpenGL
void GLWidget::resizeGL(int width, int height)
{
	this->width = width;
	this->height = height;

	glViewport(0, 0, width, height);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glOrtho(.0, width, height, .0, -1000, 1000);
	glMatrixMode(GL_MODELVIEW);
}

// Paint map
void GLWidget::paintGL()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	
	// Set line width
	glLineWidth(1.0);

	// Set color to black
	glColor3f (0.0f, 0.0f, 0.0f);

	// Draw x coordinate
	glBegin(GL_LINE_STRIP);
	glVertex3f(0, topMargin, 0.0);
	glVertex3f(this->width, topMargin, 0.0);
	glEnd();

	// Draw y coordinate
	glBegin(GL_LINE_STRIP);
	glVertex3f(leftMargin, topMargin, 0.0);
	glVertex3f(leftMargin, this->height, 0.0);
	glEnd();

	// Set point size
	glPointSize(3.0);
	glEnable (GL_POINT_SMOOTH);
	glHint (GL_POINT_SMOOTH, GL_NICEST);

	// Set color to red
	glColor3f (1.0f, 0.0f, 0.0f);

	glBegin(GL_POINTS);
	// Draw start point: Bus Stop West Beijing Road, (60, 0)
	glVertex3f(startPoint1.x + leftMargin, startPoint1.y + topMargin, 0.0);

	// Draw start point: Metro YuYuan Road, (-60, 330)
	glVertex3f(startPoint2.x + leftMargin, startPoint2.y + topMargin, 0.0);

	// Draw end point: EF Labs, (300, 200)
	glVertex3f(endPoint.x + leftMargin, endPoint.y + topMargin, 0.0);
	glEnd();
	
	// Draw building edges
	glColor3f (0.0f, 0.0f, 1.0f);
	for(int i=0; i<buildings.size(); i++) {
		Building building = buildings[i];
		glBegin(GL_LINE_LOOP);
		for(int j=0; j<building.points.size(); j++) {
			Point point = building.points[j];
			glVertex3f(point.x + leftMargin, point.y + topMargin, 0.0);
		}
		glEnd();
	}
	
	// Draw building points
	glColor3f (1.0f, 0.0f, 0.0f);
	glBegin(GL_POINTS);
	for(int i=0; i<buildings.size(); i++) {
		Building building = buildings[i];
		for(int j=0; j<building.points.size(); j++) {
			Point point = building.points[j];
			glVertex3f(point.x + leftMargin, point.y + topMargin, 0.0);
		}
	}
	glEnd();

	// Set color to green
	glColor3f (0.0f, 1.0f, 0.0f);
	
	// Draw weighted graph
	for(int i=0; i<points.size(); i++) {
		for(int j=i+1; j<points.size(); j++) {
			if(distance[i][j] < MAX_DISTANCE) {
				// Draw line
				glBegin(GL_LINE_STRIP);
				glVertex3f(points[i].x + leftMargin, points[i].y + topMargin, 1.0);
				glVertex3f(points[j].x + leftMargin, points[j].y + topMargin, 1.0);
				glEnd();
			}
		}
	}

	// Set color to red
	glColor3f (1.0f, 0.0f, 0.0f);

	glBegin(GL_LINE_STRIP);
	// Draw weighted graph
	for(int i=0; i<pathPoints.size(); i++)
		glVertex3f(pathPoints[i].x + leftMargin, pathPoints[i].y + topMargin, 2.0);
	glEnd();
}