#ifndef LOSTINJINGANTEMPLE_H
#define LOSTINJINGANTEMPLE_H

#include <QtGui/QMainWindow>
#include <QtGui/QWidget>
#include <QMessageBox>
#include "ui_lostinjingantemple.h"
#include "glwidget.h"

class LostInJingAnTemple : public QMainWindow
{
	Q_OBJECT

public:
	LostInJingAnTemple(QWidget *parent = 0, Qt::WFlags flags = 0);
	~LostInJingAnTemple();

private slots:
	// Import data
	void on_actionImportData_triggered() ;

	// Convert to weighted graph
	void on_actionConvert_To_Weighted_Graph_triggered() ;

	// Find shortest path
	void on_actionFindShortestPath_triggered() ;

	// Export data
	void on_actionExportData_triggered() ;

	// About
	void on_actionAbout_triggered() ;

	// Compute distance between two points
	float distanceBetweenTwoPoints(Point point1, Point point2);

	// Check if the two points is on the edge of the building
	bool onTheBuildingEdge(Building building, Point point1, Point point2);

	// Check if line<point1, point2> is the edge of the building
	bool isTheBuildingEdge(Building building, Point point1, Point point2);

	// Check if the line<point1, point2> crosses the building
	bool crossTheBuilding(Building building, Point point1, Point point2);

	// Check if the line<point1, point2> crosses any building of the building list
	bool crossTheBuildings(vector<Building> buildings, Point point1, Point point2);

	// Check if the line<point1, point2> crosses with line<point3, point4>
	bool crossLines(Point point1, Point point2, Point point3, Point point4);

	// Check if the two points represent the same position
	bool samePosition(Point point1, Point point2);

	// Check if the point is inside the building
	bool isPointInsideBuilding(Building building, Point point);

	// Check if the line<point1, point2> is inside the building
	bool isLineInsideBuilding(Building building, Point point1, Point point2);

	// Check if the line<point1, point2> is fully inside the building
	bool isLineFullInsideBuilding(Building building, Point point1, Point point2);

	// Check if the line<point1, point2> parallels with the line< point3, point4>
	bool isTwoLinesParalleled(Point point1, Point point2, Point point3, Point point4);

	// Check if the point3 is on the line<point1, point2>
	bool isOnLine(Point point1, Point point2, Point point3);
private:
	Ui::LostInJingAnTempleClass ui;

	// OpenGL Widget UI
	GLWidget *glWidget;
};

#endif // LOSTINJINGANTEMPLE_H