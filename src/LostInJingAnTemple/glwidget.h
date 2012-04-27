#ifndef GLWIDGET_H
#define GLWIDGET_H

#include <QGLWidget>
#include <QPoint>
#include <QPainter>
#include <QFile>
#include <QTextStream>
#include <QIODevice>
#include <vector>
#include <math.h>

#define MAX_DISTANCE 10000
#define POINTS_SIZE 200

using namespace std;

// Structure which represents a point
struct Point {
	int x;
	int y;
};

// Structure which represents a building
struct Building {
	// Point list
	vector<Point> points;
};

// GLWidget
class GLWidget : public QGLWidget
{
	Q_OBJECT

public:
	GLWidget(QWidget *parent = 0);
	~GLWidget();

public:
	void initializeGL();
	void paintGL();
	void resizeGL(int width, int height);

public:
	// Start point1
	Point startPoint1;

	// Start point2
	Point startPoint2;

	// End point
	Point endPoint;

	// Building list
	vector<Building> buildings;

	// Point list
	vector<Point> points;

	// Distance matrix
	float distance[POINTS_SIZE][POINTS_SIZE];

	// Weight matrix
	float weight[POINTS_SIZE][POINTS_SIZE];

	// Path
	int path[POINTS_SIZE][POINTS_SIZE];

	// Path points
	vector<Point> pathPoints;

	// Paint area width
	int width;

	// Paint area height
	int height;

	// Paint area left margin
	int leftMargin;

	// Paint area top margin
	int topMargin;
};

#endif // GLWIDGET_H
