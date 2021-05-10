class MorseConverter
{
  char message;
  uint8_t serial;

public:
  MorseConverter() : message(), serial(){};

  void afficherMorse(){};
  void conversionToASCII(){};
  void lireChar(){};

  void fin_message(unsigned long dernier_appuye)
  {
    if (millis() - dernier_appuye > 2000 && this->message == "")
    {
      Serial.println("Message fini");
    }
  }
};