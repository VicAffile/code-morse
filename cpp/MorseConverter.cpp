
const String lettres_morse[26] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.."};

class MorseConverter
{
  /*   char Caracteres[taille]; */
  String morse;
  String message;
  char c;
  uint8_t step;

public:
  MorseConverter() : message(""), morse(""), c(""), step(0){};

  String get_message()
  {
    return message;
  }
  int get_step()
  {
    return this->step;
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
      Serial.println("write your message");
      if (Serial.available() > 0)
      {
        c = Serial.read();
        message += c;

        morse += CarAsciiToMorse(Serial.read());
      }
      if (!message.equals(""))
      {
        Serial.println(message);
      }
    }
  }
  String CarAsciiToMorse(int c)
  { // methode qui tradui un caracter Asci en Morse
    return lettres_morse[c % 65];
  }
  char CarMorseToAscii(String car)
  { // methode qui tradui un caracter Morse en Asci
    for (uint8_t i; i < 26; i++)
    {
      if (c == lettres_morse[i])
      {
        return i + 65;
      }
    }
  }

  void lecture_bouton(char type_appuye)
  {
    if (type_appuye != '0')
    {
      this->caractere += type_appuye;
    }
  }
};