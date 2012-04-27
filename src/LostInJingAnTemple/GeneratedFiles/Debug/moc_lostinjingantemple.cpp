/****************************************************************************
** Meta object code from reading C++ file 'lostinjingantemple.h'
**
** Created: Sat Apr 28 00:44:19 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../lostinjingantemple.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lostinjingantemple.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_LostInJingAnTemple[] = {

 // content:
       4,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      20,   19,   19,   19, 0x08,
      52,   19,   19,   19, 0x08,
      99,   19,   19,   19, 0x08,
     137,   19,   19,   19, 0x08,
     169,   19,   19,   19, 0x08,
     216,  202,  196,   19, 0x08,
     282,  259,  254,   19, 0x08,
     322,  259,  254,   19, 0x08,
     362,  259,  254,   19, 0x08,
     425,  401,  254,   19, 0x08,
     501,  473,  254,   19, 0x08,
     537,  202,  254,   19, 0x08,
     578,  563,  254,   19, 0x08,
     616,  259,  254,   19, 0x08,
     659,  259,  254,   19, 0x08,
     706,  473,  254,   19, 0x08,
     773,  752,  254,   19, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_LostInJingAnTemple[] = {
    "LostInJingAnTemple\0\0on_actionImportData_triggered()\0"
    "on_actionConvert_To_Weighted_Graph_triggered()\0"
    "on_actionFindShortestPath_triggered()\0"
    "on_actionExportData_triggered()\0"
    "on_actionAbout_triggered()\0float\0"
    "point1,point2\0distanceBetweenTwoPoints(Point,Point)\0"
    "bool\0building,point1,point2\0"
    "onTheBuildingEdge(Building,Point,Point)\0"
    "isTheBuildingEdge(Building,Point,Point)\0"
    "crossTheBuilding(Building,Point,Point)\0"
    "buildings,point1,point2\0"
    "crossTheBuildings(vector<Building>,Point,Point)\0"
    "point1,point2,point3,point4\0"
    "crossLines(Point,Point,Point,Point)\0"
    "samePosition(Point,Point)\0building,point\0"
    "isPointInsideBuilding(Building,Point)\0"
    "isLineInsideBuilding(Building,Point,Point)\0"
    "isLineFullInsideBuilding(Building,Point,Point)\0"
    "isTwoLinesParalleled(Point,Point,Point,Point)\0"
    "point1,point2,point3\0isOnLine(Point,Point,Point)\0"
};

const QMetaObject LostInJingAnTemple::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_LostInJingAnTemple,
      qt_meta_data_LostInJingAnTemple, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &LostInJingAnTemple::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *LostInJingAnTemple::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *LostInJingAnTemple::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_LostInJingAnTemple))
        return static_cast<void*>(const_cast< LostInJingAnTemple*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int LostInJingAnTemple::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: on_actionImportData_triggered(); break;
        case 1: on_actionConvert_To_Weighted_Graph_triggered(); break;
        case 2: on_actionFindShortestPath_triggered(); break;
        case 3: on_actionExportData_triggered(); break;
        case 4: on_actionAbout_triggered(); break;
        case 5: { float _r = distanceBetweenTwoPoints((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< float*>(_a[0]) = _r; }  break;
        case 6: { bool _r = onTheBuildingEdge((*reinterpret_cast< Building(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 7: { bool _r = isTheBuildingEdge((*reinterpret_cast< Building(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 8: { bool _r = crossTheBuilding((*reinterpret_cast< Building(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 9: { bool _r = crossTheBuildings((*reinterpret_cast< vector<Building>(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 10: { bool _r = crossLines((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])),(*reinterpret_cast< Point(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 11: { bool _r = samePosition((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 12: { bool _r = isPointInsideBuilding((*reinterpret_cast< Building(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 13: { bool _r = isLineInsideBuilding((*reinterpret_cast< Building(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 14: { bool _r = isLineFullInsideBuilding((*reinterpret_cast< Building(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 15: { bool _r = isTwoLinesParalleled((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])),(*reinterpret_cast< Point(*)>(_a[4])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 16: { bool _r = isOnLine((*reinterpret_cast< Point(*)>(_a[1])),(*reinterpret_cast< Point(*)>(_a[2])),(*reinterpret_cast< Point(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
        _id -= 17;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
