const char lettres_ascii[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const String lettres_morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

class MorseConverter
{
  /*   char Caracteres[taille]; */
  String message;
  String caractere;

public:
  MorseConverter() : message(""), caractere(""){};

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

    //conversion du caractere
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

  void lecture_bouton(char type_appuye)
  {
    if (type_appuye != '0')
    {
      this->caractere += type_appuye;
    }
  }
};