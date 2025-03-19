#pragma once

#include <QtWidgets/QMainWindow>
#include <AIS_ViewController.hxx>
#include <AIS_Shape.hxx>
#include <AIS_ViewCube.hxx>
#include <V3d_Viewer.hxx>
#include <AIS_InteractiveContext.hxx>
#include <V3d_View.hxx>
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
};
