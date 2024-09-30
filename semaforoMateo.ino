const int redLED = 2;
const int yellowLED = 3;
const int greenLED = 4;
const int buttonPin = 5;

int state = 0; // Variable para controlar el estado del semáforo
bool lastButtonState = LOW; // Estado previo del botón
bool buttonState; // Estado actual del botón

void setup() {
  pinMode(redLED, OUTPUT);
  pinMode(yellowLED, OUTPUT);
  pinMode(greenLED, OUTPUT);
  pinMode(buttonPin, INPUT);
  
  // Inicializamos en el estado Rojo
  digitalWrite(redLED, HIGH);
  digitalWrite(yellowLED, LOW);
  digitalWrite(greenLED, LOW);
}

void loop() {
  buttonState = digitalRead(buttonPin);

  // Detectamos el cambio de estado del botón
  if (buttonState == HIGH && lastButtonState == LOW) {
    // Cambiamos el estado del semáforo
    state = (state + 1) % 5;

    // Actualizamos los LEDs según el estado
    if (state == 0) { // Rojo
      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, LOW);
    } else if (state == 1) { // Amarillo
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(greenLED, LOW);
    } else if (state == 2) { // Verde
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, HIGH);
    } else if (state == 3) { // Amarillo
      digitalWrite(redLED, LOW);
      digitalWrite(yellowLED, HIGH);
      digitalWrite(greenLED, LOW);
    } else if (state == 4) { // Rojo
      digitalWrite(redLED, HIGH);
      digitalWrite(yellowLED, LOW);
      digitalWrite(greenLED, LOW);
    }

    // Actualizamos el estado previo del botón
    lastButtonState = buttonState;
  } else {
    lastButtonState = buttonState;
  }
}