class MorseConverter
{
  /*   char Caracteres[taille]; */
  String message;
  uint8_t serial;

public:
  MorseConverter() : message(""), serial(){

                                  };

  String get_message()
  {
    return message;
  }

  void afficherMorse()
  {
    Serial.println(conversionToASCII(message));
  };
  String conversionToASCII(String message)
  {
    String result = "";
    String car = "";
    for (uint8_t i; i < message.length(); i++)
    {
      if (message[i] != ' ')
      {
        car += message[i];
      }
      else
      {
      }
    }
  };
  void lireChar(){};

  void fin_message(unsigned long dernier_appuye)
  {
    if (millis() - dernier_appuye > 2000 && this->message != "")
    {
      Serial.println("Message fini");
    }
  }
};