#include "lostinjingantemple.h"

LostInJingAnTemple::LostInJingAnTemple(QWidget *parent, Qt::WFlags flags)
	: QMainWindow(parent, flags)
{
	ui.setupUi(this);

	glWidget = new GLWidget;

	setCentralWidget(glWidget);

	resize(800, 600);
}

LostInJingAnTemple::~LostInJingAnTemple()
{

}

// Import data
void LostInJingAnTemple::on_actionImportData_triggered() {
	// Clear building list
	glWidget->buildings.clear();

	// Read the data file
	QFile file("Lost.txt");
	if(!file.open(QIODevice::ReadOnly|QIODevice::Text))
		QMessageBox::about(this, "Open File Error", "Open File Error");

	QTextStream inStream(&file);
	int lineCount = 0;
	while(!inStream.atEnd()) {
		lineCount++;
		QString line = inStream.readLine();
		if(lineCount >= 3) {
			// New building
			Building building;

			QStringList fields = line.split(", ");

			for(int i=0; i<fields.count(); i=i+2) {
				// New point
				Point point;
				QString fieldX = fields.at(i);
				QString fieldY = fields.at(i + 1);
				QString fieldXValue = fieldX.mid(1);
				QString fieldYValue = fieldY.mid(0, fieldY.length() - 1);
				point.x = fieldXValue.toInt();
				point.y = fieldYValue.toInt();

				// Add point to building
				building.points.push_back(point);

				// Add point to point list
				glWidget->points.push_back(point);
			}

			// Add building
			glWidget->buildings.push_back(building);
		}
	}

	// Close file
	file.close();

	// Repaint map
	glWidget->repaint();
}

// Convert to weighted graph
void LostInJingAnTemple::on_actionConvert_To_Weighted_Graph_triggered() {
	// Compute distance between two points
	for(int i=0; i<glWidget->points.size(); i++) {
		for(int j=i+1; j<glWidget->points.size(); j++) {
			// Check if the line between the two points crosses all the buildings
			if(crossTheBuildings(glWidget->buildings, glWidget->points[i], glWidget->points[j]) == false) {
				glWidget->distance[i][j] = distanceBetweenTwoPoints(glWidget->points[i], glWidget->points[j]);
				glWidget->distance[j][i] = glWidget->distance[i][j];
			}
		}
	}

	// Repaint map
	glWidget->repaint();
}

// Find shortest path
// Floyd algorithm
void LostInJingAnTemple::on_actionFindShortestPath_triggered() {
	for(int i=0; i<glWidget->points.size(); i++) {
		for(int j=0; j<glWidget->points.size(); j++) {
			glWidget->weight[i][j] = glWidget->distance[i][j];

			if(glWidget->distance[i][j] < MAX_DISTANCE)
				glWidget->path[i][j] = i + 1;
			else
				glWidget->path[i][j] = 0;
		}
	}

	for(int k=0; k<glWidget->points.size(); k++) {
		for(int i=0; i<glWidget->points.size(); i++) {
			for(int j=0; j<glWidget->points.size(); j++) {			
				if(i != j && i != k && j != k) {
					if(glWidget->weight[i][j] > (glWidget->weight[i][k] + glWidget->weight[k][j])) {
						glWidget->weight[i][j] = (glWidget->weight[i][k] + glWidget->weight[k][j]);
						glWidget->path[i][j] = glWidget->path[k][j];
					}
				}
			}
		}
	}

	int start = 0;
	int end = 2;
	
	glWidget->pathPoints.push_back(glWidget->points[end]);
	while(glWidget->path[start][end] != start + 1) {
		end = glWidget->path[start][end] - 1;
		glWidget->pathPoints.push_back(glWidget->points[end]);
	}
	glWidget->pathPoints.push_back(glWidget->points[start]);

	// Repaint map
	glWidget->repaint();
}

// Export data
void LostInJingAnTemple::on_actionExportData_triggered() {
	int start = 0;
	int end = 2;

	QString message = "Shortest Length: " + QString::number((int)glWidget->weight[start][end]);
	
	for(int i=glWidget->pathPoints.size()-1; i>=0; i--) {
		Point point = glWidget->pathPoints[i];
		message = message + "\n(" + QString::number(point.x) + ", " + QString::number(point.y) + ")";
	}
	QMessageBox::about(this, "Shortest Path", message);
}

// About
void LostInJingAnTemple::on_actionAbout_triggered() {
	QMessageBox::about(this, "About This Porgram", "This program is developed by Xiang Chen\nTsinghua University\nEmail: chenxiangcyr@sina.com\nMobile: 13810306735");
}

// Compute distance between two points
float LostInJingAnTemple::distanceBetweenTwoPoints(Point point1, Point point2) {
	return sqrt(pow((float)(point1.x - point2.x), 2) + pow((float)(point1.y - point2.y), 2));
}

// Check if the two points is on the edge of the building
bool LostInJingAnTemple::onTheBuildingEdge(Building building, Point point1, Point point2) {
	int count = 0;
	for(int i=0; i<building.points.size(); i++) {
		Point point = building.points[i];
		if(point.x == point1.x && point.y == point1.y)
			count++;
		if(point.x == point2.x && point.y == point2.y)
			count++;
	}
	return (count == 2);
}

// Check if line<point1, point2> is the edge of the building
bool LostInJingAnTemple::isTheBuildingEdge(Building building, Point point1, Point point2) {
	for(int i=0; i<building.points.size(); i++) {
		Point point = building.points[i];
		Point nextPoint = building.points[(i + 1)%building.points.size()];
		
		if(((samePosition(point, point1)) && (samePosition(nextPoint, point2))) 
			|| ((samePosition(point, point2)) && (samePosition(nextPoint, point1)))) {
				return true;
		}
	}
	return false;
}

// Check if the line<point1, point2> crosses the building
bool LostInJingAnTemple::crossTheBuilding(Building building, Point point1, Point point2) {
	for(int i=0; i<building.points.size(); i++) {
		for(int j=i+1; j<building.points.size(); j++) {
			if(isLineFullInsideBuilding(building, building.points[i], building.points[j]) == true
				|| isTheBuildingEdge(building, building.points[i], building.points[j]) == true) {
					if(crossLines(building.points[i], building.points[j], point1, point2) == true) 						
						return true;
					
					if(isOnLine(point1, point2, building.points[i]) == true 
						&& isOnLine(point1, point2, building.points[j]) == true)
							return true;
			}
		}
	}
	return false;
}

// Check if the line<point1, point2> crosses any building of the building list
bool LostInJingAnTemple::crossTheBuildings(vector<Building> buildings, Point point1, Point point2) {
	for(int i=0; i<buildings.size(); i++) {
		Building building = buildings[i];

		// Line<point1, point2> is the edge of the building
		if(isTheBuildingEdge(building, point1, point2))
			return false;

		// The two points is on the edge of the building
		else if(onTheBuildingEdge(building, point1, point2) == true) {
			if(isLineInsideBuilding(building, point1, point2) == true)
				return true;
			else
				return false;
		}
		else {
			if(crossTheBuilding(building, point1, point2) == true)
				return true;
		}
	}
	return false;
}

// Check if the line<point1, point2> crosses with line<point3, point4>
bool LostInJingAnTemple::crossLines(Point point1, Point point2, Point point3, Point point4) {
	int value1 = (point3.x - point1.x)*(point4.y - point1.y) - (point3.y - point1.y)*(point4.x - point1.x);
	int value2 = (point3.x - point2.x)*(point4.y - point2.y) - (point3.y - point2.y)*(point4.x - point2.x);

	int value3 = (point1.x - point3.x)*(point2.y - point3.y) - (point1.y - point3.y)*(point2.x - point3.x);
	int value4 = (point1.x - point4.x)*(point2.y - point4.y) - (point1.y - point4.y)*(point2.x - point4.x);

	if(value1 * value2 * value3 * value4 == 0)
		return false;
	else{
		if((((value1>0)&&(value2<0)) || ((value1<0)&&(value2>0)))
			&&
			(((value3>0)&&(value4<0)) || ((value3<0)&&(value4>0)))) {
			return true;
		}
		return false;
	}
}

// Check if the two points represent the same position
bool LostInJingAnTemple::samePosition(Point point1, Point point2) {
	if(point1.x == point2.x && point1.y == point2.y)
		return true;
	return false;
}

// Check if the point is inside the building
bool LostInJingAnTemple::isPointInsideBuilding(Building building, Point point) {
	Point rightPoint;
	rightPoint.x = point.x + 1000;
	rightPoint.y = point.y;

	Point topPoint;
	topPoint.x = point.x;
	topPoint.y = point.y + 1000;

	int rightCrossingPointsCount = 0;
	int topCrossingPointsCount = 0;

	for(int i=0; i<building.points.size(); i++) {
		if(crossLines(building.points[i], building.points[(i+1)%building.points.size()], point, rightPoint) == true)
			rightCrossingPointsCount++;

		if(crossLines(building.points[i], building.points[(i+1)%building.points.size()], point, topPoint) == true)
			topCrossingPointsCount++;
	}
	if(rightCrossingPointsCount%2 == 0 && topCrossingPointsCount%2 == 0)
		return false;
	return true;
}

// Check if the line<point1, point2> is inside the building
bool LostInJingAnTemple::isLineInsideBuilding(Building building, Point point1, Point point2) {
	for(int i=1; i<10; i++) {
		Point point;
		point.x = point1.x*i/10 + point2.x*(10-i)/10;
		point.y = point1.y*i/10 + point2.y*(10-i)/10;
		if(isPointInsideBuilding(building, point) == true)
			return true;
	}
	return false;
}

// Check if the line<point1, point2> is fully inside the building
bool LostInJingAnTemple::isLineFullInsideBuilding(Building building, Point point1, Point point2) {
	for(int i=1; i<10; i++) {
		Point point;
		point.x = point1.x*i/10 + point2.x*(10-i)/10;
		point.y = point1.y*i/10 + point2.y*(10-i)/10;
		if(isPointInsideBuilding(building, point) == false)
			return false;
	}
	return true;
}

// Check if the line<point1, point2> parallels with the line< point3, point4>
bool LostInJingAnTemple::isTwoLinesParalleled(Point point1, Point point2, Point point3, Point point4) {
	return ((point2.y - point1.y) * (point4.x - point3.x) == (point4.y - point3.y) * (point2.x - point1.x));
}

// Check if the point3 is on the line<point1, point2>
bool LostInJingAnTemple::isOnLine(Point point1, Point point2, Point point3) {
	if(isTwoLinesParalleled(point1, point2, point3, point2)) {
		if((point3.x < point1.x && point3.x > point2.x)
			|| (point3.x < point2.x && point3.x > point1.x))
			return true;
	}
	else
		return false;
}