#include "OCCT_Test.h"
#include <QMdiArea>
#include "MakeBottle.h"
#include <TColgp_Array1OfPnt.hxx>
OCCT_Test::OCCT_Test(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->myDocument3d = new DocumentCommon(this);
    this->myDocument2d = new DocumentCommon(this);
    myGeomWidget = new GeomWidget(myDocument3d, myDocument2d, this->ui.widget_3d);
    ui.horizontalLayout_3d->addWidget(myGeomWidget);
    /*this->AppendBottle();
    this->myDocument3d->SetObjects(myObject3d);*/
    //MakeAndShowVertices();
    //MakeAndShowLine();
    //MakeAndShowPlane();
    //MakeAndShowBox();
    MakeAndShowCurve();
}

OCCT_Test::~OCCT_Test()
{}

void OCCT_Test::AppendBottle()
{
    TopoDS_Shape aBottle = MakeBottle(50, 70, 30);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(aBottle);
    myObject3d.Append(aShape);
    Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
    myObject3d.Append(aViewCube);
}

void OCCT_Test::MakeAndShowPoint()
{
    gp_Pnt aPnt(100, 1, 1);
    TopoDS_Vertex aVertex = BRepBuilderAPI_MakeVertex(aPnt);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(aVertex);
    myObject3d.Append(aShape);
    Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
    myObject3d.Append(aViewCube);
    myDocument3d->SetObjects(myObject3d);
}

void OCCT_Test::MakeAndShowLine()
{
    gp_Pnt aPnt(0, 0, 0);
    gp_Pnt aPnt2(100, 100, 100);
    TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(aPnt,aPnt2);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(edge);
    myObject3d.Append(aShape);
    Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
    myObject3d.Append(aViewCube);
    myDocument3d->SetObjects(myObject3d);
}

void OCCT_Test::MakeAndShowPlane()
{
    gp_Pnt aPnt(0, 0, 0);
    gp_Dir aDir(0, 0, 1);
    gp_Pln aPln(aPnt, aDir);
    Standard_Real umin=0, umax=100, vmin=0, vmax=100;
    TopoDS_Face face = BRepBuilderAPI_MakeFace(aPln,umin,umax,vmin,vmax);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(face);
    myObject3d.Append(aShape);
    Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
    myObject3d.Append(aViewCube);
    myDocument3d->SetObjects(myObject3d);
}

void OCCT_Test::MakeAndShowBox()
{
    Standard_Real x = 50, y = 100, z = 200;
    TopoDS_Solid aBox = BRepPrimAPI_MakeBox(x, y, z);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(aBox);
    myObject3d.Append(aShape);
    Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
    myObject3d.Append(aViewCube);
    myDocument3d->SetObjects(myObject3d);
}

void OCCT_Test::MakeAndShowCurve()
{
    TColgp_Array1OfPnt* aPnts = new TColgp_Array1OfPnt(1, 4);
    aPnts->SetValue(1, gp_Pnt(0, 0, 0));
    aPnts->SetValue(2, gp_Pnt(100, 0, 0));
    aPnts->SetValue(3, gp_Pnt(300, 500, 0));
    TColStd_Array1OfReal* aWights = new TColStd_Array1OfReal(1, 4);
    aWights->SetValue(1, 1);
    aWights->SetValue(2, 3);
    aWights->SetValue(3, 4);
    Handle(Geom_BezierCurve) aCurve = new Geom_BezierCurve(*aPnts, *aWights);
    TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(aCurve);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(edge);
    myObject3d.Append(aShape);
    Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
    myObject3d.Append(aViewCube);
    myDocument3d->SetObjects(myObject3d);
}


