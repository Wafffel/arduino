#include <FastLED.h>
#define NUM_LEDS 256
#define DATA_PIN 8
CRGB leds[NUM_LEDS];

#define MATRIX_WIDTH 32
#define MATRIX_HEIGHT 8

//tablice zawierajace bitmapy 8x8 liter alfabetu
uint8_t A[] = {0b00110000, 0b01111000, 0b11001100, 0b11001100, 0b11111100, 0b11001100, 0b11001100, 0b00000000};
uint8_t B[] = {0b11111100, 0b01100110, 0b01100110, 0b01111100, 0b01100110, 0b01100110, 0b11111100, 0b00000000};
uint8_t C[] = {0b00111100, 0b01100110, 0b11000000, 0b11000000, 0b11000000, 0b01100110, 0b00111100, 0b00000000};
uint8_t D[] = {0b11111000, 0b01101100, 0b01100110, 0b01100110, 0b01100110, 0b01101100, 0b11111000, 0b00000000};
uint8_t E[] = {0b11111110, 0b01100010, 0b01101000, 0b01111000, 0b01101000, 0b01100010, 0b11111110, 0b00000000};
uint8_t F[] = {0b11111110, 0b01100010, 0b01101000, 0b01111000, 0b01101000, 0b01100000, 0b11110000, 0b00000000};
uint8_t G[] = {0b00111100, 0b01100110, 0b11000000, 0b11000000, 0b11001110, 0b01100110, 0b00111110, 0b00000000};
uint8_t H[] = {0b11001100, 0b11001100, 0b11001100, 0b11111100, 0b11001100, 0b11001100, 0b11001100, 0b00000000};
uint8_t I[] = {0b01111000, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b01111000, 0b00000000};
uint8_t J[] = {0b00011110, 0b00001100, 0b00001100, 0b00001100, 0b11001100, 0b11001100, 0b01111000, 0b00000000};
uint8_t K[] = {0b11100110, 0b01100110, 0b01101100, 0b01111000, 0b01101100, 0b01100110, 0b11100110, 0b00000000};
uint8_t L[] = {0b11110000, 0b01100000, 0b01100000, 0b01100000, 0b01100010, 0b01100110, 0b11111110, 0b00000000};
uint8_t M[] = {0b11000110, 0b11101110, 0b11111110, 0b11111110, 0b11010110, 0b11000110, 0b11000110, 0b00000000};
uint8_t N[] = {0b11000110, 0b11100110, 0b11110110, 0b11011110, 0b11001110, 0b11000110, 0b11000110, 0b00000000};
uint8_t O[] = {0b00111000, 0b01101100, 0b11000110, 0b11000110, 0b11000110, 0b01101100, 0b00111000, 0b00000000};
uint8_t P[] = {0b11111100, 0b01100110, 0b01100110, 0b01111100, 0b01100000, 0b01100000, 0b11110000, 0b00000000};
uint8_t Q[] = {0b01111000, 0b11001100, 0b11001100, 0b11001100, 0b11011100, 0b01111000, 0b00011100, 0b00000000};
uint8_t R[] = {0b11111100, 0b01100110, 0b01100110, 0b01111100, 0b01101100, 0b01100110, 0b11100110, 0b00000000};
uint8_t S[] = {0b01111000, 0b11001100, 0b11100000, 0b01110000, 0b00011100, 0b11001100, 0b01111000, 0b00000000};
uint8_t T[] = {0b11111100, 0b10110100, 0b00110000, 0b00110000, 0b00110000, 0b00110000, 0b01111000, 0b00000000};
uint8_t U[] = {0b11001100, 0b11001100, 0b11001100, 0b11001100, 0b11001100, 0b11001100, 0b11111100, 0b00000000};
uint8_t V[] = {0b11001100, 0b11001100, 0b11001100, 0b11001100, 0b11001100, 0b01111000, 0b00110000, 0b00000000};
uint8_t W[] = {0b11000110, 0b11000110, 0b11000110, 0b11010110, 0b11111110, 0b11101110, 0b11000110, 0b00000000};
uint8_t X[] = {0b11000110, 0b11000110, 0b01101100, 0b00111000, 0b00111000, 0b01101100, 0b11000110, 0b00000000};
uint8_t Y[] = {0b11001100, 0b11001100, 0b11001100, 0b01111000, 0b00110000, 0b00110000, 0b01111000, 0b00000000};
uint8_t Z[] = {0b11111110, 0b11000110, 0b10001100, 0b00011000, 0b00110010, 0b01100110, 0b11111110, 0b00000000};
uint8_t empty[] = {0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000, 0b00000000};

//funkcja ktora dla chara zawierajacego litere zwraca bitmape 8x8 tej litery
uint8_t* getLetterByChar(char letter) {
    switch (letter) {
      case 'A': case 'a': return A;
      case 'B': case 'b': return B;
      case 'C': case 'c': return C;
      case 'D': case 'd': return D;
      case 'E': case 'e': return E;
      case 'F': case 'f': return F;
      case 'G': case 'g': return G;
      case 'H': case 'h': return H;
      case 'I': case 'i': return I;
      case 'J': case 'j': return J;
      case 'K': case 'k': return K;
      case 'L': case 'l': return L;
      case 'M': case 'm': return M;
      case 'N': case 'n': return N;
      case 'O': case 'o': return O;
      case 'P': case 'p': return P;
      case 'Q': case 'q': return Q;
      case 'R': case 'r': return R;
      case 'S': case 's': return S;
      case 'T': case 't': return T;
      case 'U': case 'u': return U;
      case 'V': case 'v': return V;
      case 'W': case 'w': return W;
      case 'X': case 'x': return X;
      case 'Y': case 'y': return Y;
      case 'Z': case 'z': return Z;
      default: return empty;
    }
}

//funkcja zwracajaca indeks diody w tablicy leds po podaniu wspolzednych na matrycy
int getPosition(int x, int y) {
  if (x % 2 == 0){
    return x*MATRIX_HEIGHT+y;
  } else {
    return x*MATRIX_HEIGHT+(MATRIX_HEIGHT-1-y);
  }
}

//funckja ktora po podaniu bitmapy 8x8, przesuniecia liczonego od lewej strony i koloru wyswietla litere na matrycy
void drawLetter(uint8_t letter[8], int offset, CRGB color) {
  for (int x=0; x<8; x++) {
    for (int y=0; y<8; y++) {
      if (getPosition(x+offset,y) >= 0 && getPosition(x+offset,y) <= 255) {
        if (letter[y] & (1 << (7 - x))) {
        leds[getPosition(x+offset,y)]=color;               
        } else {
          leds[getPosition(x+offset,y)]=CRGB::Black;
        } 
      }      
    }
  }
}

//funckja ktora po tablicy charow, przesuniecia liczonego od lewej strony i koloru wyswietla napis na matrycy
void drawText(const char* text, int offset, CRGB color) {
  int length = strlen(text);
  for (int i = 0; i < length; i++) {
    drawLetter(getLetterByChar(text[i]), i * 8 + offset, color);
  }
}

void setup() {
  FastLED.addLeds<WS2812, DATA_PIN, RGB>(leds, NUM_LEDS);
  FastLED.setBrightness(10);
}

//tekst ktory ma zostac wyswietlony
const char* text = "AB CDEFGHIJKLMNOP";

void loop() {
  static int position = MATRIX_WIDTH+1;

//  zmiana koloru z kazdym ponownym wywolaniem
  uint8_t red = random(256);   // 0 to 255
  uint8_t green = random(256); // 0 to 255
  uint8_t blue = random(256);  // 0 to 255
  CRGB color = CRGB(red, green, blue); 
  
  fill_solid(leds, NUM_LEDS, CRGB::Black);

  drawText(text, position, color);
  int nLenght = strlen(text)*(-8);

//  napis przesuwa sie w lewo i po dotarciu do konca wraca na poczatek
  position--;
  if (position < nLenght) {
    position = MATRIX_WIDTH+1;
  }

  FastLED.show();
  delay(100);
}
