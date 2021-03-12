// Constants
const int LED_WIRED           = D6; // Wired to the red LED
const int LED_BUILTIN         = D7; // Builtin Argon LED
const unsigned long UNIT_TIME = 300; // Milliseconds

/**
 * Initial setup.
 * Sets relevant pins to output.
 */
void setup() {
    pinMode(LED_WIRED, OUTPUT);
    pinMode(LED_BUILTIN, OUTPUT);
}


/**
 * Repeatedly display first and last name.
 * First name is displayed on the builtin LED.
 * Last name is displayed on the wired LED.
 */
void loop() {

    // First name on builtin LED
    blink_word(LED_BUILTIN, "Alex");

    // First name on wired LED
    blink_word(LED_WIRED, "Hocking");
}


/**
 * Blink the morse code for a whole word.
 *
 * @param led the pin to blink the word on.
 * @param word the word to blink
 */
void blink_word(int led, String word) {

    // Convert to lowercase
    String lower_word = word.toLowerCase();

    // Blink each char
    int len = lower_word.length();
    for (int i = 0; i < len; i++) {

        // Blink morse code for the char
        blink_char(led, lower_word[i]);
    }

    // Delay at the end of the word (7 units - 3 for the end of a char)
    delay(4 * UNIT_TIME);
}


/**
 * Blink the morse code for a single character.
 *
 * @param led the pin to blink the character on.
 * @param c the character to blink
 */
void blink_char(int led, char c) {

    // Convert char to morse code
    String code = to_morse(c);

    // Blink the morse code
    blink_code(led, code);

    // Delay at the end of a character (3 units - 1 for the end of a code piece)
    delay(2 * UNIT_TIME);
}


/**
 * Blink a single morse code element.
 * Blinks either a dash, dot or nothing (nothing if the code is not . or -)
 *
 * @param led the pin to blink the morse code element on.
 * @param code the morse code element to blink.
 */
void blink_code(int led, String code) {

    // Blink each piece of morse code
    int len = code.length();
    for (int i = 0; i < len; i++) {

        if (code[i] == '.') {
            // Blink a dot
            blink(led, UNIT_TIME);
        } else if (code[i] == '-') {
            // Blink a dash
            blink(led, 3 * UNIT_TIME);
        }
    }
}


/**
 * Performs the blink on the particle argon.
 * Turns the LED on, then delays, then turns it off and delays again
 *
 * @param led the pin used to perform the blink
 * @param duration how long to keep the LED on for
 */
void blink(int led, unsigned long duration) {

    // Turn LED on
    digitalWrite(led, HIGH);

    // Leave on for a set duration
    delay(duration);

    // Turn LED off
    digitalWrite(led, LOW);

    // Delay before next blink
    delay(UNIT_TIME);
}


/**
 * Returns the morse code string for a character.
 *
 * @param c the character to convert.
 * @return the morse code sequence as a string.
 */
String to_morse(char c) {

    // Convert a character to morse code
    switch (c) {
        case 'a': return ".-";
        case 'b': return "-...";
        case 'c': return "-.-.";
        case 'd': return "-..";
        case 'e': return ".";
        case 'f': return "..-.";
        case 'g': return "--.";
        case 'h': return "....";
        case 'i': return "..";
        case 'j': return ".---";
        case 'k': return "-.-";
        case 'l': return ".-..";
        case 'm': return "--";
        case 'n': return "-.";
        case 'o': return "---";
        case 'p': return ".--.";
        case 'q': return "--.-";
        case 'r': return ".-.";
        case 's': return "...";
        case 't': return "-";
        case 'u': return "..-";
        case 'v': return "...-";
        case 'w': return ".--";
        case 'x': return "-..-";
        case 'y': return "-.--";
        case 'z': return "--..";
        case '0': return "-----";
        case '1': return ".----";
        case '2': return "..---";
        case '3': return "...--";
        case '4': return "....-";
        case '5': return ".....";
        case '6': return "-....";
        case '7': return "--...";
        case '8': return "---..";
        case '9': return "----.";
        default: return "";
    }
}