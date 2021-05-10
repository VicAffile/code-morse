uint8_t PIN_INVALIDE = 255;

#include "./cpp/Bouton.cpp"
#include "./cpp/Led.cpp"
#include "./cpp/MorseConverter.cpp"

const char lettres[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};

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
