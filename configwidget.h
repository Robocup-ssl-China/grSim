#ifndef CONFIGWIDGET_H
#define CONFIGWIDGET_H

#include <QWidget>
#include <QtGui>
#include <QSplitter>
#include <QStringList>
#include <QMainWindow>


#include <stdint.h>
#include <stdio.h>

#include "VarTypes/gui/VarTreeModel.h"
#include "VarTypes/gui/VarItem.h"
#include "VarTypes/gui/VarTreeView.h"
#include "VarTypes/VarXML.h"
#include "VarTypes/primitives/VarList.h"
#include "VarTypes/primitives/VarDouble.h"
#include "VarTypes/primitives/VarBool.h"
#include "VarTypes/primitives/VarInt.h"
#include "VarXML.h"
#include "VarTypes.h"

using namespace VarTypes;

#define DEF_VALUE(type,Type,name)  \
            VarTypes::Var##Type* v_##name; \
            inline type name() {return v_##name->get##Type();}

class ConfigWidget : public VarTreeView
{
  Q_OBJECT

protected:
  vector<VarType *> world;
  VarTreeModel * tmodel;  
  void closeEvent(QCloseEvent* event);
public:
  VarList * geo_vars;
  ConfigWidget();
  virtual ~ConfigWidget();
  DEF_VALUE(double,Double,_SSL_FIELD_LENGTH)
  DEF_VALUE(double,Double,_SSL_FIELD_WIDTH)
  DEF_VALUE(double,Double,_SSL_FIELD_RAD)
  DEF_VALUE(double,Double,_SSL_FIELD_PENALTY)
  DEF_VALUE(double,Double,_SSL_FIELD_MARGIN)
  DEF_VALUE(double,Double,_SSL_WALL_THICKNESS)
  DEF_VALUE(double,Double,KICKFACTOR)
  DEF_VALUE(double,Double,CHIPFACTOR)
  DEF_VALUE(double,Double,ROLLERTORQUEFACTOR)
  DEF_VALUE(double,Double,CHASSISLENGTH)
  DEF_VALUE(double,Double,CHASSISWIDTH)
  DEF_VALUE(double,Double,CHASSISHEIGHT)
  DEF_VALUE(double,Double,BOTTOMHEIGHT)
  DEF_VALUE(double,Double,KICKERHEIGHT)
  DEF_VALUE(double,Double,KLENGTH)
  DEF_VALUE(double,Double,KWIDTH)
  DEF_VALUE(double,Double,KHEIGHT)
  DEF_VALUE(double,Double,WHEELRADIUS)
  DEF_VALUE(double,Double,WHEELLENGTH)
  DEF_VALUE(double,Double,CHASSISMASS)
  DEF_VALUE(double,Double,WHEELMASS)
  DEF_VALUE(double,Double,BALLMASS)
  DEF_VALUE(double,Double,KICKERMASS)
  DEF_VALUE(double,Double,BALLRADIUS)
  DEF_VALUE(double,Double,motorfactor)
  DEF_VALUE(double,Double,shootfactor)
  DEF_VALUE(double,Double,wheeltangentfriction)
  DEF_VALUE(double,Double,wheelperpendicularfriction)
  DEF_VALUE(double,Double,ballfriction)
  DEF_VALUE(double,Double,ballslip)
  DEF_VALUE(double,Double,ballbounce)
  DEF_VALUE(double,Double,ballbouncevel)
  DEF_VALUE(double,Double,balllineardamp)
  DEF_VALUE(double,Double,ballangulardamp)
  DEF_VALUE(bool,Bool,SyncWithGL)
  DEF_VALUE(double,Double,DeltaTime)
  DEF_VALUE(double,Double,Gravity)
  DEF_VALUE(std::string,String,VisionMulticastAddr)  
  DEF_VALUE(int,Int,VisionMulticastPort)  
  DEF_VALUE(int,Int,CommandListenPort)
};


#endif // CONFIGWIDGET_H
