class Bouton
{
    bool etat;
    uint8_t pin;
    unsigned long debut_appuye;
    unsigned long fin_appuye;
    int appuye_court;

public:
    Bouton() : pin(PIN_INVALIDE), etat(false), fin_appuye(0), appuye_court(500) {}
    Bouton(uint8_t pin) : pin(pin), fin_appuye(0), appuye_court(500)
    {
        pinMode(pin, INPUT_PULLUP);
        this->etat = digitalRead(pin);
    }

    bool get_etat()
    {
        return this->etat;
    }

    unsigned long get_fin_appuye()
    {
        return this->fin_appuye;
    }

    char appuye()
    {
        bool etat = digitalRead(this->pin);
        if (this->etat == etat)
        {
            if (etat == 0)
            {
                this->debut_appuye = millis();
                Serial.println("debut appuye");
            }
            else
            {
                this->fin_appuye = millis();
                this->etat = !etat;
                if (this->fin_appuye - this->debut_appuye <= 500)
                {
                    Serial.println(".");
                    return '.';
                }
                else
                {
                    Serial.println("-");
                    return '-';
                }
            }
        }
        this->etat = !etat;
        return '0';
    }
    int pause()
    {
        if (this->fin_appuye != 0)
        {
            int temps = millis() - this->fin_appuye;
            if (temps >= 3 * this->appuye_court && temps < 6 * this->appuye_court)
            {
                Serial.println("caractère suivant");
                return 0;
            }
            else if (temps >= 6 * this->appuye_court && temps < 9 * this->appuye_court)
            {
                Serial.println("espace");
                return 1;
            }
            else if (temps >= 9 * this->appuye_court)
            {
                Serial.println("fin du message ");
                return 2;
            }
        }
    }
};