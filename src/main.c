#include "btdoglab.h"
#include "led_button_control.h"

// Função principal
void setup() {
    // Inicializa a biblioteca de controle do botão e LEDs
    led_button_init();
}

void loop() {
    // Verifica se o botão foi pressionado e chama a função correspondente
    check_button();
}
