// Disparador / intervalometro Canon - Wemos D1 mini (ESP8266)
// As chaves sao lidas uma vez no boot. Para mudar o tempo: troque a chave e aperte RESET.
// Chaves 2, 3 e 4 do DIP = 2 s, 7 s, 20 s. Todas desligadas = 45 s.
// A chave 1 (GPIO16) nao e usada. Se mais de uma estiver ligada, vale a de menor numero.

#include <ESP8266WiFi.h>

const uint8_t PIN_METER   = 4;   // opto do meter (foco/fotometria)
const uint8_t PIN_SHUTTER = 5;   // opto do shutter

const uint8_t  N_CHAVES = 3;
const uint8_t  DIP_PINS[N_CHAVES]  = {14, 12, 13};
const uint32_t TEMPOS_MS[N_CHAVES] = {2000, 7000, 20000};
const uint32_t TEMPO_PADRAO_MS     = 45000;  // nenhuma chave ligada

const uint32_t PRE_FOCO_MS = 300;  // meter ativo antes do shutter
const uint32_t PULSO_MS    = 200;  // duracao do pulso de shutter

uint32_t intervalo = TEMPO_PADRAO_MS;

void disparar() {
  digitalWrite(PIN_METER, HIGH);
  delay(PRE_FOCO_MS);
  digitalWrite(PIN_SHUTTER, HIGH);
  delay(PULSO_MS);
  digitalWrite(PIN_SHUTTER, LOW);
  digitalWrite(PIN_METER, LOW);
}

void setup() {
  WiFi.mode(WIFI_OFF);

  pinMode(PIN_METER, OUTPUT);
  pinMode(PIN_SHUTTER, OUTPUT);
  digitalWrite(PIN_METER, LOW);
  digitalWrite(PIN_SHUTTER, LOW);

  for (uint8_t i = 0; i < N_CHAVES; i++) pinMode(DIP_PINS[i], INPUT_PULLUP);
  delay(50);

  for (uint8_t i = 0; i < N_CHAVES; i++) {
    if (digitalRead(DIP_PINS[i]) == LOW) {  // chave ligada = LOW
      intervalo = TEMPOS_MS[i];
      break;
    }
  }
}

void loop() {
  disparar();
  delay(intervalo - PRE_FOCO_MS - PULSO_MS);  // intervalo total de disparo a disparo
}
