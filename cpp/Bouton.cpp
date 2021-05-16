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

    bool appuye()
    {
        bool etat = digitalRead(this->pin);
        if (this->etat == etat)
        {
            if (etat == 0)
            {
                this->debut_appuye = millis();
            }
            else
            {
                this->fin_appuye = millis();
                if (this->fin_appuye - this->debut_appuye <= 500)
                {
                    Serial.println(".");
                }
                else
                {
                    Serial.println("-");
                }
            }
        }
        this->etat = !etat;
        return this->etat;
    }
    void pause()
    {
        if (this->fin_appuye != 0)
        {
            if (millis() - this->fin_appuye < 5 * this->appuye_court)
            {
            }
            else
            {
            }
        }
    }
};