#ifndef LED_BUTTON_CONTROL_H
#define LED_BUTTON_CONTROL_H

// Definindo os pinos para os LEDs e o botão
#define LED_R   11
#define LED_G   12
#define LED_B   13
#define BUTTON  5

// Função de inicialização da biblioteca
void led_button_init();

// Função que verifica o estado do botão e controla os LEDs
void check_button();

// Função de callback para controle dos LEDs
void turn_off_callback(void *ptr);

#endif // LED_BUTTON_CONTROL_H
