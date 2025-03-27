#pragma once

#include <QtWidgets/QMainWindow>
#include <AIS_ViewController.hxx>
#include <AIS_Shape.hxx>
#include <AIS_ViewCube.hxx>
#include <V3d_Viewer.hxx>
#include <AIS_InteractiveContext.hxx>
#include <V3d_View.hxx>
#include <BRepBuilderAPI_MakeVertex.hxx>
#include <BRepBuilderAPI_MakeEdge.hxx>
#include <BRepBuilderAPI_MakeFace.hxx>
#include <BRepPrimAPI_MakeBox.hxx>
#include <BRepPrimAPI_MakeSphere.hxx>
#include <TopoDS_Vertex.hxx>
#include <TopoDS_Edge.hxx>
#include <TopoDS_Face.hxx>
#include <TopoDS_Solid.hxx>
#include <Geom_BezierCurve.hxx>
#include <gp_Circ.hxx>
#include "GeomWidget.h"
#include "DocumentCommon.h"
#include "ui_OCCT_Test.h"

class OCCT_Test : public QMainWindow, protected AIS_ViewController
{
    Q_OBJECT

public:
    OCCT_Test(QWidget *parent = nullptr);
    ~OCCT_Test();
    void AppendBottle();
private:
    Ui::OCCT_TestClass ui;

    GeomWidget* myGeomWidget;
    DocumentCommon* myDocument3d;
    DocumentCommon* myDocument2d;
    NCollection_Vector<Handle(AIS_InteractiveObject)> myObject3d;
    TopoDS_Shape myShape;
    // 定义拓扑图形集合
private:
    // 创建并显示顶点
    void MakeAndShowPoint();
    // 创建并显示线段
    void MakeAndShowLine();
    // 创建并显示平面
    void MakeAndShowPlane();
    // 创建并显示长方体
    void MakeAndShowBox();
    // 创建并显示曲线
    void MakeAndShowCurve();
    // 创建并显示圆
    void MakeAndShowCircle();
    // 创建并显示球体
    void MakeAndShowSphere();
    // 创建并显示圆锥体
    void MakeAndShowCone();
    // 创建并显示圆柱体
    void MakeAndShowCylinder();
    // 创建并显示圆环
    void MakeAndShowTorus();

protected slots:
    // 保存为STEP文件
    void on_save_to_step();
    // 打开STEP文件
    void on_open_step();
};
