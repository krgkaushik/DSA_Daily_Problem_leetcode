#include <Keypad.h>
#include <LiquidCrystal.h>

// ---------- LCD CONNECTIONS ----------
// RS  -> D12
// E   -> D11
// DB4 -> D10
// DB5 -> A0
// DB6 -> A1
// DB7 -> A2

LiquidCrystal lcd(12, 11, 10, A0, A1, A2);


// ---------- KEYPAD CONNECTIONS ----------
const byte ROWS = 4;
const byte COLS = 4;

char keys[ROWS][COLS] = {
  {'1', '2', '3', 'A'},
  {'4', '5', '6', 'B'},
  {'7', '8', '9', 'C'},
  {'*', '0', '#', 'D'}
};

byte rowPins[ROWS] = {2, 3, 4, 5};
byte colPins[COLS] = {6, 7, 8, 9};

Keypad keypad = Keypad(
  makeKeymap(keys),
  rowPins,
  colPins,
  ROWS,
  COLS
);


// ---------- RFID ID ----------
String inputID = "";
String authorizedID = "1234";


void setup() {

  lcd.begin(16, 2);

  Serial.begin(9600);

  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("RFID SYSTEM");

  lcd.setCursor(0, 1);
  lcd.print("Scan Tag...");

  delay(2000);

  lcd.clear();
  lcd.print("Enter RFID ID:");
}


void loop() {

  char key = keypad.getKey();

  if (key) {

    // # = Submit RFID ID
    if (key == '#') {

      lcd.clear();

      lcd.setCursor(0, 0);
      lcd.print("RFID ID:");

      lcd.setCursor(0, 1);
      lcd.print(inputID);

      Serial.print("RFID ID: ");
      Serial.println(inputID);

      delay(1500);

      lcd.clear();

      // Check authorized ID
      if (inputID == authorizedID) {

        lcd.setCursor(0, 0);
        lcd.print("ACCESS GRANTED");

        Serial.println("ACCESS GRANTED");

      } 
      else {

        lcd.setCursor(0, 0);
        lcd.print("ACCESS DENIED");

        Serial.println("ACCESS DENIED");
      }

      delay(2000);

      // Reset
      inputID = "";

      lcd.clear();
      lcd.print("Enter RFID ID:");
    }


    // * = Clear ID
    else if (key == '*') {

      inputID = "";

      lcd.clear();
      lcd.print("Enter RFID ID:");

      Serial.println("ID Cleared");
    }


    // Add pressed key to ID
    else {

      // Maximum 8 characters
      if (inputID.length() < 8) {

        inputID += key;

        lcd.setCursor(0, 1);
        lcd.print(inputID);
      }
    }
  }
}
