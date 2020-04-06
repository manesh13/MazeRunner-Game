#include <simplecpp>
#include<conio.h>

class DINO{
    Rectangle dino;
public:
    DINO()
    {
        dino.reset(52, 628, 20,20);
        dino.setColor(GREEN);
        dino.setFill();
    }

    void move(char command)
    {
        static int dx = 0, dy = 0;

        if(command == 'w')      { dx = 0; dy = -3;}
        else if (command == 's'){ dx = 0; dy = 3;}
        else if (command == 'a'){ dx = -3; dy = 0;}
        else if (command == 'd'){ dx = 3; dy = 0;}
        else if (command == '\0'){ dx = 0; dy = 0;}

        dino.move(dx, dy);
    }
    double getX()
    {
        return dino.getX();
    }
    double getY()
    {
        return dino.getY();
    }

};

class Obstacle{
    Rectangle obstacle;
   public:
    Obstacle(double dx, double dy, double lt, double bt)
    {
        obstacle.reset(dx, dy, lt, bt);
        obstacle.setColor(BLACK);
        obstacle.setFill();
    }
    double getX()
    {
        return obstacle.getX();
    }
    double getY()
    {
        return obstacle.getY();
    }
};

int main(){
    initCanvas("MAZE RUNNER", 600, 700);

    XEvent event;
    char c = '\0';
    // Borders
    Obstacle top_border(300, 16, 630, 50);
    Obstacle border_bottom(300, 684, 650, 50);
    Obstacle border_left(16, 300, 50, 600);
    Obstacle border_right(584, 400, 50, 600);

    // Walls
    Obstacle wall1(90, 450, 208, 28);
    Obstacle wall2(130, 590, 28, 140);
    Obstacle wall3(208, 460, 28 ,250);
    Obstacle wall4(451, 630, 28, 53);
    Obstacle wall5(385, 592, 160, 28);
    Obstacle wall6(350, 505, 280, 28);
    Obstacle wall7(470, 330, 200, 28);
    Obstacle wall8(490, 200, 380, 28);
    Obstacle wall9(300, 270, 28 ,300);
    Obstacle wall10(400, 450, 28, 90);
    Obstacle wall11(520, 420, 80, 28);
    Obstacle wall12(250, 270, 100, 28);
    Obstacle wall13(480, 240, 28, 53);
    Obstacle wall14(384, 290, 28, 53);
    Obstacle wall15(214, 120, 200, 28);
    Obstacle wall16(180, 200, 70, 28);
    Obstacle wall17(131, 286, 28 ,200);
    Obstacle wall18(170, 160, 28, 50);
    Obstacle wall119(480, 150, 28, 90);
    Obstacle wall1120(390, 84, 28, 85);

    DINO p;
    cout<<"\n"<<p.getX()<<"\n"<<p.getY();
  int clickPos;

 // initCanvas();
  /*repeat(20)
  {
  clickPos = getClick();

  cout << "Click position: ("<< clickPos/65536 <<", "
       << clickPos % 65536 <<")\n";
    }*/
    while(true)
    {
        //borders out of scope
        if (p.getX() <= border_left.getX()+37)      {c = '\0';}
        else if (p.getX() >= border_right.getX()-37 && p.getY() >=border_right.getY()-299)    {c=  '\0';}
        else if (p.getY() <= top_border.getY()+37)  {c=  '\0';}
        else if(p.getY() >= border_bottom.getY()-37){c = '\0';}


        //wall through
        if (p.getX() >= wall1.getX()+12 && p.getY() >=wall1.getY()+60 && p.getX()<= wall1.getX()+68)      {c = '\0';}
        if (p.getY() <=wall2.getY()-114 && p.getY() >=wall2.getY()-167 && p.getX() <= wall2.getX()+80)      {c = '\0';}
       // if (p.getX() >= wall3.getX()+15 && p.getY() >=wall3.getY()-70 && p.getX()<= wall3.getX()+70)      {c = '\0';}

        if (p.getX() >=427 && p.getX() <= 478  && p.getY() >= 580){c = '\0';}
        //if (p.getX() <=wall5.getX()+300 && p.getY() >= wall5.getY()-10 && p.getY() <= wall5.getY()){c = '\0';}

        if(checkEvent(event) && keyPressEvent(event))
            c = charFromEvent(event);

        p.move(c);
    }

 getch();
}



