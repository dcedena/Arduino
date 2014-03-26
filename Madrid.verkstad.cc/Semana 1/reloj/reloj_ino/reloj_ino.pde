
int widthImage = 128;
int heightImage = 128;
int numImages = 10;

int numDigits = 2;

PImage images[] = new PImage[numImages];
// String files[] = { "0.png", "1.png", "2.png", "3.png" };

void setup() {

    size(widthImage * 8, heightImage);
    
    for(int i=0;i<10;i++) {
      images[i] = loadImage(i+".png");
    }
}

void draw() {
  background(255);
  
  int h = hour();
  int h_dec = int(h / 10);
  int h_uni = h - h_dec * 10;
  
  int m = minute();
  int m_dec = int(m / 10);
  int m_uni = m - m_dec * 10;
  
  int s = second();
  int s_dec = int(s / 10);
  int s_uni = s - s_dec * 10;
  
  image(images[h_dec], 0, 0);
  image(images[h_uni], widthImage * 1, 0); 
  
  image(images[m_dec], widthImage * 3, 0);
  image(images[m_uni], widthImage * 4, 0); 
  
  image(images[s_dec], widthImage * 6, 0);
  image(images[s_uni], widthImage * 7, 0); 
  
}
