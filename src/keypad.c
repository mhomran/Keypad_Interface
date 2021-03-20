/**
 * @file keypad.c
 * @author Mohamed Hassanin
 * @brief Keypad interface pattern that is commonly used in 
 * embedded systems projects 
 * @version 0.1
 * @date 2021-03-19
 */
/******************************************************************************
* Includes
******************************************************************************/
#include <inttypes.h>
#include "keypad.h"
#include "dio.h"
#include "circ_buffer.h" 
/******************************************************************************
* Definitions
******************************************************************************/
#define KEYPAD_SW_PRESSED DIO_STATE_LOW
#define KEYPAD_SW_RELEASED DIO_STATE_HIGH
/******************************************************************************
* Prototypes
******************************************************************************/
static void Keypad_Scan(Keypad_t Keypad, uint8_t* ScannedChar);
/******************************************************************************
* Module Variable Definitions
******************************************************************************/
/**
 * @brief A pointer to the configuration table.
 */
static KeypadConfig_t * gConfig; 

/**
 * brief the keypad receive data buffers
 */
static uint8_t KeypadData[KEYPAD_MAX][KEYPAD_RCV_BUFF_SIZE];

/**
 * brief the keypad receive buffers structures
 */
static CircBuff_t KeypadBuff[KEYPAD_MAX];

/**
 * @brief Last char in pressed state
 */
static uint8_t LastChar[KEYPAD_MAX];

/**
 * @brief Last valid char put in the receive buffer
 */
static uint8_t LastValidChar[KEYPAD_MAX];

/**
 * @brief The keypad characters
 * //TODO: add the characters of your keypad set.
 */
static const uint8_t KeypadSet[KEYPAD_3_X_3] =
{
  '0', '1', '2',
  '3', '4', '5',
  '6', '7', '8'
};

/******************************************************************************
* Functions definitions
******************************************************************************/
/******************************************************************************
* Function : Keypad_Init()
*//**
* \b Description: Initialization function for the Keypad module<br/>
* \b PRE-CONDITION: Configuration table is populated<br/>
* @param Config a pointer to the configuration table of the keypads.
* @return void 
******************************************************************************/
extern void 
Keypad_Init(KeypadConfig_t* const Config)
{
  if(Config == 0x0)
    {
      //TODO: choose your error handling method
      return;
    }

  uint8_t Col;
  uint8_t Keypad;

  gConfig = Config;

  for(Keypad = 0; Keypad < KEYPAD_MAX; Keypad++)
    {
      KeypadBuff[Keypad] = CircBuff_Create(KeypadData[Keypad],
       KEYPAD_RCV_BUFF_SIZE);

      LastChar[Keypad] = '\0';
    }
}


/******************************************************************************
* Function : Keypad_Update()
*//**
* \b Description:
* This function is used to read the state of the keypad switches and fills
* the receive buffer according to what's pressed.
* data buffers. <br>
* PRE-CONDITION: Keypad_Init called properly <br>
* POST-CONDITION: The next byte (if existed) in the keypad data buffers is sent <br>
* @param keypad the keypad Id 
* @return void
*
* @see keypad_Init
*******************************************************************************/
extern void 
Keypad_Update(void)
{
  uint8_t CurrChar = '\0';
  Keypad_t Keypad;
  uint8_t EnqueueRes;

  for(Keypad = KEYPAD_0; Keypad < KEYPAD_MAX; Keypad++)
    {
      //scan all rows line by line
      Keypad_Scan(Keypad, &CurrChar);

      //A char is pressed ?
      if(CurrChar != '\0')
        {
          //A key has been pressed: debounce by checking twice
          if (CurrChar == LastChar[Keypad])
            {
              // A valid (debounced) key press has been detected
              // Must be a new key to be valid - no 'auto repeat'
              if(CurrChar != LastValidChar[Keypad])
                {
                  LastValidChar[Keypad] = CurrChar;

                  //add to the receive buffer
                  EnqueueRes = CircBuff_Enqueue(&KeypadBuff[Keypad], CurrChar);
                  if(EnqueueRes != 0)
                    {
                      //TODO: handle the error.
                      return;
                    }
                }
            }
        }
      else
        {
          LastValidChar[Keypad] = '\0';
        }

      LastChar[Keypad] = CurrChar;
    }
}

/******************************************************************************
* Function : Keypad_Scan()
*//**
* \b Description:
* Utility function used to scan the keypad <br>
* PRE-CONDITION: Keypad_Init called properly <br>
* @param Keypad the keypad Id 
* @param ScannedChar the scanned keypad character 
* @return void
*
* @see keypad_Scan
*******************************************************************************/
static void 
Keypad_Scan(Keypad_t Keypad, uint8_t* ScannedChar)
{
  DioState_t CurrState;
  uint8_t Col;
  uint8_t Row;
  uint8_t exit = 0;
  uint8_t CurrChar = '\0';
  uint8_t CurrCharIndex;

  //Make a row LOW at a time.
  for(Row = 0; Row < gConfig[Keypad].RowsSize; Row++)
    {
      Dio_ChannelWrite(gConfig[Keypad].Rows[Row], DIO_STATE_LOW);

      for(Col = 0; Col < gConfig[Keypad].ColsSize; Col++)
        {
          CurrState = Dio_ChannelRead(gConfig[Keypad].Cols[Col]);
          if (CurrState == KEYPAD_SW_PRESSED)
            {
              //Found the key pressed!
              CurrCharIndex = (Row * gConfig[Keypad].ColsSize) + Col;
              CurrChar = KeypadSet[CurrState];
            
              //Stop scanning the rows
              exit = 1;
              break;
            }
        }

      //Pull this row high again
      Dio_ChannelWrite(gConfig[Keypad].Rows[Row], DIO_STATE_HIGH);
    
      if (exit == 1) break;
    }
}
/***************************** END OF FILE ***********************************/
