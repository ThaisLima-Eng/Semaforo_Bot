#include "btdoglab.h"
#include "led_button_control.h"

// Variáveis para controlar os estados dos LEDs e do temporizador
int led_state = 0; // 0: todos os LEDs ligados, 1: dois LEDs ligados, 2: um LED ligado
int timer_started = 0; // Flag para garantir que o temporizador não reinicie durante a execução

// Função de callback para desligar os LEDs
void turn_off_callback(void *ptr) {
    if (led_state == 0) {
        // Desliga o LED azul e verde, deixando apenas o vermelho aceso
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_B, LOW);
        led_state = 1;
    } else if (led_state == 1) {
        // Desliga o LED vermelho, deixando o LED verde aceso
        digitalWrite(LED_R, LOW);
        led_state = 2;
    } else if (led_state == 2) {
        // Desliga todos os LEDs
        digitalWrite(LED_G, LOW);
        digitalWrite(LED_B, LOW);
        digitalWrite(LED_R, LOW);
        led_state = 0; // Retorna ao estado inicial
        timer_started = 0; // Permite que o botão seja pressionado novamente
    }
}

// Função para iniciar o ciclo de LEDs (chamada quando o botão for pressionado)
void start_led_cycle() {
    if (timer_started == 0) {
        // Se o temporizador não estiver rodando, inicia o ciclo dos LEDs
        digitalWrite(LED_R, HIGH); // Liga todos os LEDs inicialmente
        digitalWrite(LED_G, HIGH);
        digitalWrite(LED_B, HIGH);
        led_state = 0; // Inicia no estado com todos os LEDs acesos
        TimerStart(); // Inicia o temporizador
        timer_started = 1; // Marca que o temporizador foi iniciado
    }
}

// Função para verificar o estado do botão
void check_button() {
    if (digitalRead(BUTTON) == LOW) {
        start_led_cycle(); // Chama a função para iniciar o ciclo de LEDs
    }
}

// Função de inicialização da biblioteca
void led_button_init() {
    // Configura os pinos dos LEDs e do botão
    pinMode(LED_R, OUTPUT);
    pinMode(LED_G, OUTPUT);
    pinMode(LED_B, OUTPUT);
    pinMode(BUTTON, INPUT_PULLUP); // Botão configurado como entrada com pull-up

    // Inicializa os LEDs apagados
    digitalWrite(LED_R, LOW);
    digitalWrite(LED_G, LOW);
    digitalWrite(LED_B, LOW);

    // Configura o temporizador para 3 segundos (3000 ms)
    TimerInit(3000, turn_off_callback);
}
