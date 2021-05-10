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
};