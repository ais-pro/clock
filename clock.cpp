#include<stdio.h>
#include<graphics.h>
#include<math.h>
#include<time.h>

int generate_clock(int x, int y, int r){

//circle(x,y,r+5); //outliner
circle(x,y,r+35); //border

//put text
double x1, xx1, y1, yy1, PI=3.14159265, a;
char Str[2];
settextstyle(1,0,2);
for(int i=0,j=30;i<=360;i+=6){
	a=i*(PI/180);	



	if(i>0 && j==i){
		// five second text
		x1=x+((r+5)*(sin(a))); // take the first x
		y1=y-((r+5)*(cos(a))); // take the first y
		xx1=x1+(30*(sin(a))); //take the second x1
		yy1=y1-(30*(cos(a))); //take the second y1
		line(x1,y1,xx1,yy1);	
		
		
		x1=x+((r-5)*(sin(a))); // take the first x
		y1=y-((r-5)*(cos(a))); // take the first y
		sprintf(Str, "%d", j/30);
		if(j/30==12) // 12 digit adjustment
			outtextxy(x1-15,y1-6,Str);
		else
			outtextxy(x1-6,y1-8,Str);
		j+=30; // increment for next cycle
		
	}else{
		//second circle
		x1=x+((r+25)*(sin(a))); // take the first x
		y1=y-((r+25)*(cos(a))); // take the first y
		xx1=x1+(10*(sin(a))); //take the second x1
		yy1=y1-(10*(cos(a))); //take the second y1
		line(x1,y1,xx1,yy1);
	}
}

//center
circle(x,y,20);
return 0;
}

int main(){
int gd = DETECT, gm;
double i, x=300, y=300, r=250, x1, y1, PI=3.14159265, a, xx1, yy1;
int ii,mm,hh;
initwindow(600, 600, "Clock");

	time_t timer;
    char sec[2],mini[2],hour[2];
    struct tm* tm_info;





generate_clock(x,y,r); //init clock	


while(i<1){
	Sleep(1000); // wait 1 sec
	cleardevice(); //clear window
	
	time(&timer);
    tm_info = localtime(&timer);
    strftime(sec, 26, "%S", tm_info);
	ii=atoi(sec);
	
	generate_clock(x,y,r); //regenrate clock
	
	
//	generate second
	a=ii*6*(PI/180);		
	x1=x+((20)*(sin(a))); // take the first x
	y1=y-((20)*(cos(a))); // take the first y
	xx1=x1+((r-40)*(sin(a))); //take the second x1
	yy1=y1-((r-40)*(cos(a))); //take the second y1	
	line(x1,y1,xx1,yy1); //generate new secend
	
//	generate minute
    strftime(mini, 26, "%M", tm_info);
	mm=atoi(mini);
	a=mm*6*(PI/180);		
	x1=x+((20)*(sin(a))); // take the first x
	y1=y-((20)*(cos(a))); // take the first y
	xx1=x1+((r-80)*(sin(a))); //take the second x1
	yy1=y1-((r-80)*(cos(a))); //take the second y1	
	line(x1,y1,xx1,yy1); //generate new secend	
	
//	generate hour
    strftime(hour, 26, "%H", tm_info);
	hh=atoi(hour);
	puts(hour);
	a=hh*30*(PI/180);		
	x1=x+((20)*(sin(a))); // take the first x
	y1=y-((20)*(cos(a))); // take the first y
	xx1=x1+((r-120)*(sin(a))); //take the second x1
	yy1=y1-((r-120)*(cos(a))); //take the second y1	
	line(x1,y1,xx1,yy1); //generate new secend
}

getch();
closegraph();

	return 0;
}
