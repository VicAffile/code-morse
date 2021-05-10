char lettres[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

class Bouton {
  bool appuye;
  uint8_t pin;
  
  public:
  Bouton() : pin(PIN_INVALIDE), appuye(false) {}
  Bouton(uint8_t pin) : pin(pin) {
    pinMode(pin,INPUT_PULLUP);
    appuye = digitalRead(pin);
  }
}

class Led {
  bool allumee;
  uint8_t pin;

  
  public :
  Led() : pin(PIN_INVALIDE), allumee(false) {}
  Led(uint8_t pin) : pin(pin), allumee(false){
    pinMode(pin,OUTPUT);
  }
}

void setup()
{
  Serial.begin(9600);
  Serial.println("Port série ouvert ----------");

  Bouton bouton = Bouton(12);
}

void loop()
{
  
}
