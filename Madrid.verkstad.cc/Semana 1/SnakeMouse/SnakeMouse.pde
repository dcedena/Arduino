


void setup() {

  size(600, 600);
  frame.setResizable(true);

}

int diameter = 50;
int rojo = 255;
int tiempo = 0;

void draw() {
//  background(255);
 // frameRate = 25;
 tiempo = tiempo + 1;
 rojo = int(128 * (1 + sin(tiempo * 2 * PI / frameRate / 20)));
  
  diameter = int(50 * (1 + sin(tiempo * 2 * PI / frameRate / 5)));
   
  noStroke();
  fill(rojo, 0, 0, 50);
  ellipse(mouseX, mouseY, diameter, diameter);
  
}
