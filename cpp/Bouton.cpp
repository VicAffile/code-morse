const uint8_t PIN_INVALIDE = 255;
class Bouton
{
    bool etat;
    uint8_t pin;

public:
    Bouton() : pin(PIN_INVALIDE), etat(false) {}
    Bouton(uint8_t pin) : pin(pin)
    {
        pinMode(pin, INPUT_PULLUP);
        this->etat = digitalRead(pin);
    }

    bool appuye()
    {
        this->etat = !digitalRead(pin);
        return this->etat;
    }
};