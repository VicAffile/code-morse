class Bouton
{
    bool etat;
    uint8_t pin;
    unsigned long debut_appuye;
    unsigned long fin_appuye;

public:
    Bouton() : pin(PIN_INVALIDE), etat(false) {}
    Bouton(uint8_t pin) : pin(pin)
    {
        pinMode(pin, INPUT_PULLUP);
        this->etat = digitalRead(pin);
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
                    Serial.println("Appuye court");
                }
                else
                {
                    Serial.println("Appuye long");
                }
            }
        }
        this->etat = !etat;
        return this->etat;
    }
};