#include "OCCT_Test.h"
#include <QMdiArea>
#include "MakeBottle.h"
#include <TColgp_Array1OfPnt.hxx>
#include <BRepPrimAPI_MakeCone.hxx>
#include <BRepPrimAPI_MakeCylinder.hxx>
#include <BRepPrimAPI_MakeTorus.hxx>
#include <QFileDialog>
#include <StlAPI_Writer.hxx>
#include <StlAPI_Reader.hxx>
#include <QMessageBox>
#include <TDocStd_Document.hxx>
#include <XCAFDoc_DocumentTool.hxx>
#include <STEPCAFControl_Reader.hxx>
#include <XCAFDoc_ShapeTool.hxx>
#include <STEPCAFControl_Writer.hxx>
OCCT_Test::OCCT_Test(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
    connect(ui.pushButton_save_to_step, &QPushButton::clicked, this, &OCCT_Test::on_save_to_step);
    connect(ui.pushButton_open_step, &QPushButton::clicked, this, &OCCT_Test::on_open_step);

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
    //MakeAndShowCurve();
    //MakeAndShowCircle();
    //MakeAndShowSphere();
    //MakeAndShowCone();
    //MakeAndShowCylinder();
    //MakeAndShowTorus();
}

OCCT_Test::~OCCT_Test()
{}

void OCCT_Test::AppendBottle()
{
    myShape = MakeBottle(50, 70, 30);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(myShape);
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

void OCCT_Test::MakeAndShowCircle()
{
    gp_Ax2 ax = gp_Ax2(gp_Pnt(0, 0, 0), gp_Dir(0, 0, 1));
    gp_Circ circle(ax, 100);
    TopoDS_Edge edge = BRepBuilderAPI_MakeEdge(circle);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(edge);
    myObject3d.Append(aShape);
    Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
    myObject3d.Append(aViewCube);
    myDocument3d->SetObjects(myObject3d);

}

void OCCT_Test::MakeAndShowSphere()
{
    gp_Pnt center(0, 0, 0);
    TopoDS_Shape sphere = BRepPrimAPI_MakeSphere(center, 100);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(sphere);
    myObject3d.Append(aShape);
    Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
    myObject3d.Append(aViewCube);
    myDocument3d->SetObjects(myObject3d);

}

void OCCT_Test::MakeAndShowCone()
{
    Standard_Real R1 = 100, R2 = 0, H = 100;
    TopoDS_Solid S = BRepPrimAPI_MakeCone(R1, R2, H);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(S);
    myObject3d.Append(aShape);
    Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
    myObject3d.Append(aViewCube);
    myDocument3d->SetObjects(myObject3d);
}

void OCCT_Test::MakeAndShowCylinder()
{
    Standard_Real R = 100, H = 200;
    TopoDS_Solid S = BRepPrimAPI_MakeCylinder(R, H);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(S);
    myObject3d.Append(aShape);
    Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
    myObject3d.Append(aViewCube);
    myDocument3d->SetObjects(myObject3d);
}

void OCCT_Test::MakeAndShowTorus()
{
    Standard_Real R1 = 100, R2 = 50;
    TopoDS_Solid S = BRepPrimAPI_MakeTorus(R1, R2);
    Handle(AIS_InteractiveObject) aShape = new AIS_Shape(S);
    myObject3d.Append(aShape);
    Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
    myObject3d.Append(aViewCube);
    myDocument3d->SetObjects(myObject3d);
}

void OCCT_Test::on_save_to_step()
{
    // myObject3d图形集合保存为step格式文件
    if (myObject3d.Size() > 0)
    {
        QString fileName = QFileDialog::getSaveFileName(this, tr("保存模型"), ".", tr("STEP Files (*.stp *.step)"));
        if (!fileName.isEmpty())
        {
            Handle(TDocStd_Document) doc = new TDocStd_Document("test");
            Handle(XCAFDoc_ShapeTool) shapeTool = XCAFDoc_DocumentTool::ShapeTool(doc->Main());
            Handle(XCAFDoc_ColorTool) colorTool = XCAFDoc_DocumentTool::ColorTool(doc->Main());
            shapeTool->AddShape(myShape);
            STEPCAFControl_Writer writer;
            writer.Transfer(doc);
            IFSelect_ReturnStatus stat = writer.Write(fileName.toStdString().c_str());
            if (IFSelect_RetDone != stat) {
                QMessageBox::warning(this, tr("保存STEP文件"), tr("保存STEP文件失败"));
            }
            else {
                QMessageBox::information(this, tr("保存STEP文件"), tr("保存STEP文件成功"));
            }
        }
    }
}


void OCCT_Test::on_open_step() {
    QString fileName = QFileDialog::getOpenFileName(this, tr("打开STEP文件"), ".", tr("STEP Files (*.stp *.step)"));
    if (!fileName.isEmpty())
    {
        Handle(TDocStd_Document) doc = new TDocStd_Document("test");
        Handle(XCAFDoc_ShapeTool) shapeTool = XCAFDoc_DocumentTool::ShapeTool(doc->Main());
        Handle(XCAFDoc_ColorTool) colorTool = XCAFDoc_DocumentTool::ColorTool(doc->Main());
        STEPCAFControl_Reader reader;
        reader.SetColorMode(true);
        reader.SetLayerMode(true);
        reader.SetMatMode(true);
        reader.SetGDTMode(true);
        reader.SetNameMode(true);
        IFSelect_ReturnStatus stat = reader.ReadFile(fileName.toStdString().c_str());
        if (IFSelect_RetDone != stat) {
            QMessageBox::warning(this, tr("打开STEP文件"), tr("打开STEP文件失败"));
        }
        Standard_Boolean is_ok = reader.Transfer(doc);
        if (!is_ok) {
            QMessageBox::warning(this, tr("打开STEP文件"), tr("文件转换失败"));
        }
        myShape = shapeTool->GetOneShape();
        Handle(AIS_InteractiveObject) aShape = new AIS_Shape(myShape);
        myObject3d.Append(aShape);
        Handle(AIS_ViewCube) aViewCube = new AIS_ViewCube();
        myObject3d.Append(aViewCube);
        myDocument3d->SetObjects(myObject3d);
    }
}


