/**
 * Projekt do předmětu IMP
 * Název projektu: Dekodér Morseovy abecedy
 * Autor: Matěj Hlávka
 * Login: xhlavk08
 * Email: xhlavk08@stud.fit.vutbr.cz
 */

#include <fitkitlib.h>
#include <keyboard/keyboard.h>
#include <lcd/display.h>
#include <string.h>

/**
 * Konstanty pro retezce znaku Morseova kodu reprezentujici znaky normalni abecedy
 */
#define MORSE_A ".-"
#define MORSE_B "-..."
#define MORSE_C "-.-."
#define MORSE_D "-.."
#define MORSE_E "."
#define MORSE_F "..-."
#define MORSE_G "--."
#define MORSE_H "...."
#define MORSE_CH "----"
#define MORSE_I ".."
#define MORSE_J ".---"
#define MORSE_K "-.-"
#define MORSE_L ".-.."
#define MORSE_M "--"
#define MORSE_N "-."
#define MORSE_O "---"
#define MORSE_P ".--."
#define MORSE_Q "--.-"
#define MORSE_R ".-."
#define MORSE_S "..."
#define MORSE_T "-"
#define MORSE_U "..-"
#define MORSE_V "...-"
#define MORSE_W ".--"
#define MORSE_X "-..-"
#define MORSE_Y "-.--"
#define MORSE_Z "--.."
#define MORSE_0 "-----"
#define MORSE_1 ".----"
#define MORSE_2 "..---"
#define MORSE_3 "...--"
#define MORSE_4 "....-"
#define MORSE_5 "....."
#define MORSE_6 "-...."
#define MORSE_7 "--..."
#define MORSE_8 "---.."
#define MORSE_9 "----."

/**
 * Konstanty pro navratove hodnoty funkce dekodujici Morseuv kod
 */
#define VALID_MORSE_CODE 1
#define NOT_VALID_MORSE_CODE 0

/**
 * Konstanty pro casove citace
 */
#define MORSE_CODE_DOT_TIME 5000
#define NEW_LETTER_TIME 20000
#define NEW_WORD_TIME 50000


/**
 * Vypis uzivatelske napovedy (funkce se vola pri vykonavani prikazu "help") 
 */
void print_user_help(void)
{
	term_send_str_crlf("Pomoci klavesy * na klavesnici kitu lze zadavat jednotlive znaky morseeovy abecedy");
	term_send_str_crlf("Klavesa # provede smazani znaku z displeje");
}


/**
 * Dekodovani a vykonani uzivatelskych prikazu
 */
unsigned char decode_user_cmd(char *cmd_ucase, char *cmd)
{
	if (strcmp5(cmd_ucase, "CLEAR")) {
		LCD_clear();
		return USER_COMMAND;
	}

	return (CMD_UNKNOWN);
}


/**
 * Inicializace periferii/komponent po naprogramovani FPGA
 */
void fpga_initialized()
{
  	LCD_init();
	keyboard_init();
}


/**
 * Funkce pro dekodovani Morseova kodu
 */
int resolveInput(char* inputCombination)
{ 
	if (strcmp(inputCombination, MORSE_A) == 0) {
		LCD_append_char('A');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_B) == 0) {
		LCD_append_char('B');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_C) == 0) {
		LCD_append_char('C');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_D) == 0) {
		LCD_append_char('D');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_E) == 0) {
		LCD_append_char('E');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_F) == 0) {
		LCD_append_char('F');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_G) == 0) {
		LCD_append_char('G');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_H) == 0) {
		LCD_append_char('H');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_CH) == 0) {
		LCD_append_char('CH');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_I) == 0) {
		LCD_append_char('I');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_J) == 0) {
		LCD_append_char('J');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_K) == 0) {
		LCD_append_char('K');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_L) == 0) {
		LCD_append_char('L');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_M) == 0) {
		LCD_append_char('M');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_N) == 0) {
		LCD_append_char('N');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_O) == 0) {
		LCD_append_char('O');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_P) == 0) {
		LCD_append_char('P');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_Q) == 0) {
		LCD_append_char('Q');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_R) == 0) {
		LCD_append_char('R');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_S) == 0) {
		LCD_append_char('S');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_T) == 0) {
		LCD_append_char('T');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_U) == 0) {
		LCD_append_char('U');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_V) == 0) {
		LCD_append_char('V');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_W) == 0) {
		LCD_append_char('W');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_X) == 0) {
		LCD_append_char('X');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_Y) == 0) {
		LCD_append_char('Y');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_Z) == 0) {
		LCD_append_char('Z');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_0) == 0) {
		LCD_append_char('0');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_1) == 0) {
		LCD_append_char('1');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_2) == 0) {
		LCD_append_char('2');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_3) == 0) {
		LCD_append_char('3');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_4) == 0) {
		LCD_append_char('4');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_5) == 0) {
		LCD_append_char('5');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_6) == 0) {
		LCD_append_char('6');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_7) == 0) {
		LCD_append_char('7');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_8) == 0) {
		LCD_append_char('8');
		return VALID_MORSE_CODE;
	} else if (strcmp(inputCombination, MORSE_9) == 0) {
		LCD_append_char('9');
		return VALID_MORSE_CODE;
	}
	
	return NOT_VALID_MORSE_CODE;
}


/**
 * Hlavni funkce programu, provede zakladni konfiguraci a inicializaci potrebnych promennych
 * Pote se v cyklu kontroluje, zda nebyla stistknuta klavesa pro zaregistrovani znaku morseeovy kodu
 * Po urcite dobe nestistknuti znaku probehne kontrola, zda je v poli pro znaky morseeova kodu nejaky znak,
 * pokud ano, probehne pokus o jeho vypsani na LCD displej, pokud je znak nevalidni, je vypsana informativni hlaska na terminal
 */
int main(void) 
{      
	char pressedKey;
	char morseCode[255];
	memset(morseCode, 0, sizeof morseCode);
	unsigned long long morseCodeCounter = 0;
	unsigned long long idleCounter = 0;
	int morseCodeIndex = 0;
	int recievedChar = 0;

	initialize_hardware();
	keyboard_init();
	LCD_init();
		
	while (1) {
		pressedKey = key_decode(read_word_keyboard_4x4());
		// Pokud je zmacknuta klavesa pro Morseuv znak, zvysuje se counter doby zmacknuti a rozsviti se LED
		if (pressedKey == '*') {
			recievedChar = 1;
			morseCodeCounter++;
			idleCounter = 0;
			set_led_d6(1);
		// Smazani znaku z displeje a vynulovani promennych
		} else if (pressedKey == '#') {
			LCD_clear();
			recievedChar = 0;
		// Nebyl zmacknut zadny znak nebo je zmacknuty znak, ktery nas nezajima
		} else {
			/** 
			 * Zhasnuti LED a kontrola, zda se ma zaregistrovat dlouhy ci kratky znak Morseova kodu
			 * Inkrementace indexu pole znaku Morseova kodu a vynulovani citace delky zmacknuti klavesy pro registraci znaku
			 */
			set_led_d6(0);
			if (morseCodeCounter > 0 && morseCodeCounter < MORSE_CODE_DOT_TIME) {
				morseCodeCounter = 0;
				morseCode[morseCodeIndex] = '.';
				morseCodeIndex++;
			} else if (morseCodeCounter >= MORSE_CODE_DOT_TIME) {
				morseCodeCounter = 0;
				morseCode[morseCodeIndex] = '-';
				morseCodeIndex++;
			}
			/**
			 * Inkrementace citace necinnosti, po urcite dobe necinnosti a za predpokladu, ze neni pole znaku Morseova kodu prazdne
			 * probehne prevedeni kodu do normalni abecedy a vypsani na LCD displej, pote se vynuluje index pole znaku Morseova kodu
			 * a pole se nastavi na prazdny retezec
			 */
			idleCounter++;
			if (idleCounter == NEW_WORD_TIME && recievedChar == 1) {
				LCD_append_char(' ');
			}
			if (idleCounter > NEW_LETTER_TIME) {
				if (strcmp(morseCode, "") != 0) {
					if (resolveInput(morseCode) == NOT_VALID_MORSE_CODE) {
						term_send_str_crlf("Byl zadan neplatny znak Morseova kodu");
					}
					morseCodeIndex = 0;
					memset(morseCode, 0, sizeof morseCode);
				}
			}
		}
		terminal_idle();
	}
}