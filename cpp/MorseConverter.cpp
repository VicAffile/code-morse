const char lettres_ascii[26] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
const String lettres_morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

class MorseConverter
{
  /*   char Caracteres[taille]; */
  String message;
  String caractere;
  uint8_t step;

public:
  MorseConverter() : message(""), caractere(""), step(0){};

  String get_message()
  {
    return message;
  }
  void menu()
  {
    String choice = "";
    if (step == 0)
    { //etape 0 choix du sens de la translation
      choice = Serial.readString();
      if (choice == "1")
      {
        Serial.println(" morse to asci on monitor");
        step++;
      }
      else if (choice == "2")
      {
        Serial.println("You choose  asci on monitor to morse ");
        step++;
      }
    }
    //etape 1pour la translation morse to ascii
    if (step == 1 && choice == "1")
    {
      choice = "t";
      Serial.println("Press the button for translate message in morse");

      Serial.println("Your sentense in morse :" + choice);

      /* Serial.println("Your sentense in ascii :"+choice);*/
    }
    if (step == 1 && choice == "2")
    { //etape 1 pour la translation ascii to morse
      choice = "";
      Serial.println("write your message");
      choice = Serial.readString();

      if (choice != "")
      {
        Serial.println("Your sentense is :" + choice);
      }
    }
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