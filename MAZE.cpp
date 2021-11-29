#include<iostream>
#include <FL/Fl.H> // needed in every fltk program
#include <FL/Fl_Window.H> // needed to use the Fl_Window class
#include <FL/Fl_Box.H>
#include <FL/fl_draw.H>
using namespace std;

class Shape : public Fl_Widget  {
  	protected:
	int x, y, w, h;
	public:
		Shape (int x, int y, int w, int h) : Fl_Widget (x,y,w,h){
			this->x=x; this->y=y;
			this->w=w; this->h=h;
		}
		virtual void wipe()=0;
		virtual void refreshr(int dx, int dy)=0;
		virtual void refreshl(int dx, int dy)=0;
		virtual void refreshu(int dx, int dy)=0;
		virtual void refreshd(int dx, int dy)=0;
		
		virtual int handle(int e) {

			if (e==FL_KEYDOWN) {
			if(Fl::get_key(FL_Right)){
		
				wipe();
				refreshr(5,5);
			}
			if(Fl::get_key(FL_Left)){
		
				wipe();
				refreshl(5,5);
			}
			if(Fl::get_key(FL_Up)){
		
				wipe();
				refreshu(5,5);
			}
			if(Fl::get_key(FL_Down)){
		
				wipe();
				refreshd(5,5);
			}
			}

			
				
			return 1;
		}; 
};

class MyCircle : public Shape {
 public:
   MyCircle (int x,int y,int w) : Shape (x,y,w,w) { }
    virtual void draw() {
	fl_color(FL_RED);
	fl_pie (x,y,w,h,0,360);
   }
   virtual void wipe() {
	fl_color(FL_WHITE);
	fl_pie (x,y,w,h,0,360);

   }
   virtual void refreshr(int dx, int dy) {
     
	x=x+dx;
        if(y==5 && 201<x && x<249){ cout<<"WON"; exit(0);}
	if( (y==50 && 0<=x && x<=100) || (y==50 && 150<=x && x<=250) || (y==50 && 350<=x && x<=450)  ||  
                 (y==200 && 50<=x && x<=100) || (y==200 && 200<=x && x<=250) || (y==200 && 300<=x && x<=400)  ||
                 (y==250 && 50<=x && x<=150) || (y==250 && 200<=x && x<=300) || (y==250 && 350<=x && x<=450)  ||
                 (y==100 && 150<=x && x<=200) || (y==100 && 300<=x && x<=350)  ||
                 (y==150 && 100<=x && x<=200) || (y==150 && 250<=x && x<=300)  ||
                 (y==300 && 0<=x && x<=100) || (y==300 && 150<=x && x<=400)  ||
                 (y==350 && 400<=x && x<=450) || (y==350 && 50<=x && x<=250)  ||
                 (y==400 && 150<=x && x<=350)  ||             
                 (x==150 && 0<=y && y<=50) || (x==150 && 200<=y && y<=300) || (x==150 && 350<=y && y<=400) ||
                 (x==300 && 0<=y && y<=100) || (x==300 && 150<=y && y<=250) || (x==300 && 300<=y && y<=400) ||
                 (x==100 && 50<=y && y<=150) || (x==100 && 400<=y && y<=450) ||
                 (x==50 && 100<=y && y<=250) || (x==50 && 350<=y && y<=400) ||
                 (x==250 && 50<=y && y<=100) || (x==250 && 400<=y && y<=450) ||
                 (x==350 && 100<=y && y<=150) || (x==350 && 350<=y && y<=400) ||
                 (x==400 && 100<=y && y<=200) || (x==400 && 350<=y && y<=400) ||
                 (x==200 && 100<=y && y<=250) ||
                 (x ==0) || (y ==0) || (x==450) ||(y == 450)
           ) {x=x-dx;} 

	resize(x,y,w,h);
		fl_color(FL_RED);
	fl_pie (x,y,w,h,0,360);
   }
   
  virtual void refreshl(int dx, int dy) {
	x=x-dx;
        if(y==5 && 201<x && x<249){cout<<"WON"; exit(0);}
	if( (y==50 && 0<=x && x<=100) || (y==50 && 150<=x && x<=250) || (y==50 && 350<=x && x<=450)  ||  
                 (y==200 && 50<=x && x<=100) || (y==200 && 200<=x && x<=250) || (y==200 && 300<=x && x<=400)  ||
                 (y==250 && 50<=x && x<=150) || (y==250 && 200<=x && x<=300) || (y==250 && 350<=x && x<=450)  ||
                 (y==100 && 150<=x && x<=200) || (y==100 && 300<=x && x<=350)  ||
                 (y==150 && 100<=x && x<=200) || (y==150 && 250<=x && x<=300)  ||
                 (y==300 && 0<=x && x<=100) || (y==300 && 150<=x && x<=400)  ||
                 (y==350 && 400<=x && x<=450) || (y==350 && 50<=x && x<=250)  ||
                 (y==400 && 150<=x && x<=350)  ||             
                 (x==150 && 0<=y && y<=50) || (x==150 && 200<=y && y<=300) || (x==150 && 350<=y && y<=400) ||
                 (x==300 && 0<=y && y<=100) || (x==300 && 150<=y && y<=250) || (x==300 && 300<=y && y<=400) ||
                 (x==100 && 50<=y && y<=150) || (x==100 && 400<=y && y<=450) ||
                 (x==50 && 100<=y && y<=250) || (x==50 && 350<=y && y<=400) ||
                 (x==250 && 50<=y && y<=100) || (x==250 && 400<=y && y<=450) ||
                 (x==350 && 100<=y && y<=150) || (x==350 && 350<=y && y<=400) ||
                 (x==400 && 100<=y && y<=200) || (x==400 && 350<=y && y<=400) ||
                 (x==200 && 100<=y && y<=250) ||
                 (x ==0) || (y ==0) || (x==450) ||(y == 450)
           ) {x=x+dx;}

	resize(x,y,w,h);
		fl_color(FL_RED);
	fl_pie (x,y,w,h,0,360);
   }
      
  virtual void refreshu(int dx, int dy) {
	y=y - dx;
        if(y==5 && 201<x && x<249){cout<<"WON"; exit(0);}
	if( (y==50 && 0<=x && x<=100) || (y==50 && 150<=x && x<=250) || (y==50 && 350<=x && x<=450)  ||  
                 (y==200 && 50<=x && x<=100) || (y==200 && 200<=x && x<=250) || (y==200 && 300<=x && x<=400)  ||
                 (y==250 && 50<=x && x<=150) || (y==250 && 200<=x && x<=300) || (y==250 && 350<=x && x<=450)  ||
                 (y==100 && 150<=x && x<=200) || (y==100 && 300<=x && x<=350)  ||
                 (y==150 && 100<=x && x<=200) || (y==150 && 250<=x && x<=300)  ||
                 (y==300 && 0<=x && x<=100) || (y==300 && 150<=x && x<=400)  ||
                 (y==350 && 400<=x && x<=450) || (y==350 && 50<=x && x<=250)  ||
                 (y==400 && 150<=x && x<=350)  ||             
                 (x==150 && 0<=y && y<=50) || (x==150 && 200<=y && y<=300) || (x==150 && 350<=y && y<=400) ||
                 (x==300 && 0<=y && y<=100) || (x==300 && 150<=y && y<=250) || (x==300 && 300<=y && y<=400) ||
                 (x==100 && 50<=y && y<=150) || (x==100 && 400<=y && y<=450) ||
                 (x==50 && 100<=y && y<=250) || (x==50 && 350<=y && y<=400) ||
                 (x==250 && 50<=y && y<=100) || (x==250 && 400<=y && y<=450) ||
                 (x==350 && 100<=y && y<=150) || (x==350 && 350<=y && y<=400) ||
                 (x==400 && 100<=y && y<=200) || (x==400 && 350<=y && y<=400) ||
                 (x==200 && 100<=y && y<=250) ||
                 (x ==0) || (y ==0) || (x==450) ||(y == 450)
           ){y=y+dx;}
 
	resize(x,y,w,h);
		fl_color(FL_RED);
	fl_pie (x,y,w,h,0,360);
   }
      
  virtual void refreshd(int dx, int dy) {
	y = y+dx;
	if(y==5 && 201<x && x<249){cout<<"WON"; exit(0);}
	if( (y==50 && 0<=x && x<=100) || (y==50 && 150<=x && x<=250) || (y==50 && 350<=x && x<=450)  ||  
                 (y==200 && 50<=x && x<=100) || (y==200 && 200<=x && x<=250) || (y==200 && 300<=x && x<=400)  ||
                 (y==250 && 50<=x && x<=150) || (y==250 && 200<=x && x<=300) || (y==250 && 350<=x && x<=450)  ||
                 (y==100 && 150<=x && x<=200) || (y==100 && 300<=x && x<=350)  ||
                 (y==150 && 100<=x && x<=200) || (y==150 && 250<=x && x<=300)  ||
                 (y==300 && 0<=x && x<=100) || (y==300 && 150<=x && x<=400)  ||
                 (y==350 && 400<=x && x<=450) || (y==350 && 50<=x && x<=250)  ||
                 (y==400 && 150<=x && x<=350)  ||             
                 (x==150 && 0<=y && y<=50) || (x==150 && 200<=y && y<=300) || (x==150 && 350<=y && y<=400) ||
                 (x==300 && 0<=y && y<=100) || (x==300 && 150<=y && y<=250) || (x==300 && 300<=y && y<=400) ||
                 (x==100 && 50<=y && y<=150) || (x==100 && 400<=y && y<=450) ||
                 (x==50 && 100<=y && y<=250) || (x==50 && 350<=y && y<=400) ||
                 (x==250 && 50<=y && y<=100) || (x==250 && 400<=y && y<=450) ||
                 (x==350 && 100<=y && y<=150) || (x==350 && 350<=y && y<=400) ||
                 (x==400 && 100<=y && y<=200) || (x==400 && 350<=y && y<=400) ||
                 (x==200 && 100<=y && y<=250) ||
                 (x ==0) || (y ==0) || (x==450) ||(y == 450)
           ){y=y-dx;}
     
	resize(x,y,w,h);
		fl_color(FL_RED);
	fl_pie (x,y,w,h,0,360);
   }

};

class MyRectangle : public Shape {
 public:
   MyRectangle (int x,int y,int w, int h) : Shape (x,y,w,h) { }
   virtual void draw() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,FL_GREEN);
   }

   virtual void wipe() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,FL_WHITE);
   }

   virtual void refreshr(int dx, int dy) {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,50);
   }
   
  virtual void refreshl(int dx, int dy) {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,50);
   }
      
  virtual void refreshu(int dx, int dy) {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,50);
   }
      
  virtual void refreshd(int dx, int dy) {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,50);
   }

};



class MyLine : public Shape {
 public:
   MyLine (int x,int y,int w, int h) : Shape (x,y,w,h) { }
   virtual void draw() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,FL_BLUE);
   }

   virtual void wipe() {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,FL_WHITE);
   }

   virtual void refreshr(int dx, int dy) {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,130);
   }
   
  virtual void refreshl(int dx, int dy) {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,130);
   }
      
  virtual void refreshu(int dx, int dy) {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,130);
   }
      
  virtual void refreshd(int dx, int dy) {
	fl_draw_box (FL_FLAT_BOX,x,y,w,h,130);
   }

};


int main(int argc, char *argv[]) {
Fl_Window *window;
window = new Fl_Window (450,450,"MAZE"); // outer window

           new MyCircle(225,425,5);
           
           
           new MyLine(0,50,100,1);
           new MyLine(150,50,100,1);
           new MyLine(350,50,100,1);
           new MyLine(50,250,100,1);
           new MyLine(200,250,100,1);
           new MyLine(350,250,100,1);
           new MyLine(0,300,100,1);
           new MyLine(150,300,250,1);
           new MyLine(50,350,200,1);
           new MyLine(400,350,50,1);
           new MyLine(150,400,200,1);
           new MyLine(50,200,50,1);  
           new MyLine(200,200,50,1);
           new MyLine(300,200,100,1);
           new MyLine(150,100,50,1);
           new MyLine(300,100,50,1);
           new MyLine(100,150,100,1);  
           new MyLine(250,150,50,1);       
             
           new MyLine(100,50,1,100);
           new MyLine(250,50,1,50);
           new MyLine(50,100,1,150);
           new MyLine(200,100,1,150);
           new MyLine(350,100,1,50);
           new MyLine(400,100,1,100);
           new MyLine(300,150,1,100);
           new MyLine(150,200,1,100);
           new MyLine(300,300,1,100);
           new MyLine(50,350,1,50);           
           new MyLine(150,350,1,50);
           new MyLine(350,350,1,50);      
           new MyLine(400,350,1,50);
           new MyLine(100,400,1,50);
           new MyLine(250,400,1,50);
           new MyLine(300,0,1,100);
           new MyLine(150,0,1,50);
           
           new MyRectangle(200,0,50,10);
           

	window->color(FL_WHITE);
    	window->end();
    	window->show();
    	return(Fl::run());  // the process waits from here on for events
}
