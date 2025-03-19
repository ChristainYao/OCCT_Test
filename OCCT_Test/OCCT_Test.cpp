#include "OCCT_Test.h"
#include <QMdiArea>
#include "MakeBottle.h"
OCCT_Test::OCCT_Test(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    this->myDocument3d = new DocumentCommon(this);
    this->myDocument2d = new DocumentCommon(this);
    myGeomWidget = new GeomWidget(myDocument3d, myDocument2d, this->ui.widget_3d);
    ui.horizontalLayout_3d->addWidget(myGeomWidget);
    this->AppendBottle();
    this->myDocument3d->SetObjects(myObject3d);
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