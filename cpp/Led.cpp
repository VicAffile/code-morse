class Led
{
    bool etat;
    uint8_t pin;

public:
    Led() : pin(PIN_INVALIDE), etat(false) {}
    Led(uint8_t pin) : pin(pin), etat(false)
    {
        pinMode(pin, OUTPUT);
    }

    void allumer_eteindre(bool bouton_etat)
    {
        if (this->pin == PIN_INVALIDE)
        {
            return;
        }
        this->etat = bouton_etat;
        digitalWrite(pin, this->etat ? HIGH : LOW);
        Serial.println(this->etat);
    }
};