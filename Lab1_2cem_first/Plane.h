//---------------------------------------------------------------------------

#ifndef PlaneH
#define PlaneH
//---------------------------------------------------------------------------
#endif
#include<vcl.h>
class plane
{
  public:

  plane(int x1,int y1,int x2,int y2)
  {
  this-> x1=x1;
  this-> y1=y1;
  this-> x2=x2;
  this-> y2=y2;
  }

  void show(TCanvas *Canvas);

  void hide(TCanvas *Canvas);

  void move(TCanvas *Canvas,int lr);

  void moveDown(TCanvas *Canvas);

  protected:
  int x1;
  int x2;
  int y1;
  int y2;
  int learningRate=5;
};


class planeAndChassis:public plane
{
public:

  planeAndChassis(int x1,int y1,int x2,int y2):plane(x1,y1,x2,y2){}

  void move(TCanvas *Canvas);

  void hideChassisFly(TCanvas *Canvas);

  void moveChassisFly(TCanvas *Canvas);

  void hideChassisDown(TCanvas *Canvas);

  void moveFinal(TCanvas *Canvas);

  void moveChassisDown(TCanvas *Canvas);

  void moveDown(TCanvas *Canvas);

   private:
   int i=0;
   int kof=5;
};

