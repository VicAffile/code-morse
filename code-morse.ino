uint8_t PIN_INVALIDE = 255;

#include "./cpp/Bouton.cpp"
#include "./cpp/Led.cpp"
#include "./cpp/MorseConverter.cpp"

Bouton bouton;
Led led;
MorseConverter converter;

void setup()
{
  Serial.begin(9600);
  Serial.println("Port série ouvert ----------");

  bouton = Bouton(12);
  led = Led(13);
}

void loop()
{
  converter.lecture_bouton(bouton.appuye());
  //converter.couper_caractere(bouton.pause());
  led.allumer_eteindre(bouton.get_etat());
}
