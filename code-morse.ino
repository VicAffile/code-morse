const char lettres[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

const uint8_t PIN_INVALIDE = 255;

class Bouton {
  bool etat;
  uint8_t pin;
  
  public:
  Bouton() : pin(PIN_INVALIDE), etat(false) {}
  Bouton(uint8_t pin) : pin(pin) {
    pinMode(pin,INPUT_PULLUP);
    this->etat = digitalRead(pin);
  }

  bool appuye(){
    this->etat = !digitalRead(pin);
    return this->etat;  
  }
};

class Led {
  bool etat;
  uint8_t pin;

  public :
  Led() : pin(PIN_INVALIDE), etat(false) {}
  Led(uint8_t pin) : pin(pin), etat(false){
    pinMode(pin,OUTPUT);
  }

  void allumer_eteindre(bool bouton_etat) {
    if(this->pin == PIN_INVALIDE){
      return;
    }
    this->etat = bouton_etat;
    digitalWrite(pin, this->etat ? HIGH : LOW);
    Serial.println(this->etat);
  }
};

Bouton bouton;
Led led;

void setup()
{
  Serial.begin(9600);
  Serial.println("Port série ouvert ----------");

  bouton = Bouton(12);
  led = Led(13);
}

void loop()
{
  led.allumer_eteindre(bouton.appuye());
}
