#ifndef BLT_CONF_H
#define BLT_CONF_H

/****************************************************************************************
*   C P U   D R I V E R   C O N F I G U R A T I O N
****************************************************************************************/
/* To properly initialize the baudrate clocks of the communication interface, typically
 * the speed of the crystal oscillator and/or the speed at which the system runs is
 * needed. Set these through configurables BOOT_CPU_XTAL_SPEED_KHZ and
 * BOOT_CPU_SYSTEM_SPEED_KHZ, respectively. To enable data exchange with the host that is
 * not dependent on the targets architecture, the byte ordering needs to be known.
 * Setting BOOT_CPU_BYTE_ORDER_MOTOROLA to 1 selects big endian mode and 0 selects
 * little endian mode.
 *
 * Set BOOT_CPU_USER_PROGRAM_START_HOOK to 1 if you would like a hook function to be
 * called the moment the user program is about to be started. This could be used to
 * de-initialize application specific parts, for example to stop blinking an LED, etc.
 */
/** \brief Frequency of the external crystal oscillator. */
#define BOOT_CPU_XTAL_SPEED_KHZ          (8000)
/** \brief Desired system speed. */
#define BOOT_CPU_SYSTEM_SPEED_KHZ        (48000)
/** \brief Motorola or Intel style byte ordering. */
#define BOOT_CPU_BYTE_ORDER_MOTOROLA     (0)
/** \brief Enable/disable hook function call right before user program start. */
#define BOOT_CPU_USER_PROGRAM_START_HOOK (0)


/****************************************************************************************
*   C O M M U N I C A T I O N   I N T E R F A C E   C O N F I G U R A T I O N
****************************************************************************************/
/* The CAN communication interface is selected by setting the BOOT_COM_CAN_ENABLE
 * configurable to 1. Configurable BOOT_COM_CAN_BAUDRATE selects the communication speed
 * in bits/second. Two CAN messages are reserved for communication with the host. The
 * message identifier for sending data from the target to the host is configured with
 * BOOT_COM_CAN_TXMSG_ID. The one for receiving data from the host is configured with
 * BOOT_COM_CAN_RXMSG_ID. Note that an extended 29-bit CAN identifier is configured by
 * OR-ing with mask 0x80000000. The maximum amount of data bytes in a message for data
 * transmission and reception is set through BOOT_COM_CAN_TX_MAX_DATA and
 * BOOT_COM_CAN_RX_MAX_DATA, respectively. It is common for a microcontroller to have more
 * than 1 CAN controller on board. The zero-based BOOT_COM_CAN_CHANNEL_INDEX selects the
 * CAN controller channel.
 *
 */
/** \brief Enable/disable CAN transport layer. */
#define BOOT_COM_CAN_ENABLE             (1)
/** \brief Configure the desired CAN baudrate. */
#define BOOT_COM_CAN_BAUDRATE           (500000)
/** \brief Configure CAN message ID target->host. */
#define BOOT_COM_CAN_TX_MSG_ID          (0x7E1 /*| 0x80000000*/)
/** \brief Configure number of bytes in the target->host CAN message. */
#define BOOT_COM_CAN_TX_MAX_DATA        (8)
/** \brief Configure CAN message ID host->target. */
#define BOOT_COM_CAN_RX_MSG_ID          (0x667 /*| 0x80000000*/)
/** \brief Configure number of bytes in the host->target CAN message. */
#define BOOT_COM_CAN_RX_MAX_DATA        (8)
/** \brief Select the desired CAN peripheral as a zero based index. */
#define BOOT_COM_CAN_CHANNEL_INDEX      (0)

/* The RS232 communication interface is selected by setting the BOOT_COM_RS232_ENABLE
 * configurable to 1. Configurable BOOT_COM_RS232_BAUDRATE selects the communication speed
 * in bits/second. The maximum amount of data bytes in a message for data transmission
 * and reception is set through BOOT_COM_RS232_TX_MAX_DATA and BOOT_COM_RS232_RX_MAX_DATA,
 * respectively. It is common for a microcontroller to have more than 1 UART interface
 * on board. The zero-based BOOT_COM_RS232_CHANNEL_INDEX selects the UART interface.
 *
 */
/** \brief Enable/disable UART transport layer. */
#define BOOT_COM_RS232_ENABLE            (1)
/** \brief Configure the desired communication speed. */
#define BOOT_COM_RS232_BAUDRATE          (115200)
/** \brief Configure number of bytes in the target->host data packet. */
#define BOOT_COM_RS232_TX_MAX_DATA       (64)
/** \brief Configure number of bytes in the host->target data packet. */
#define BOOT_COM_RS232_RX_MAX_DATA       (64)
/** \brief Select the desired UART peripheral as a zero based index. */
#define BOOT_COM_RS232_CHANNEL_INDEX     (0)


/****************************************************************************************
*   B A C K D O O R   E N T R Y   C O N F I G U R A T I O N
****************************************************************************************/
/* It is possible to implement an application specific method to force the bootloader to
 * stay active after a reset. Such a backdoor entry into the bootloader is desired in
 * situations where the user program does not run properly and therefore cannot
 * reactivate the bootloader. By enabling these hook functions, the application can
 * implement the backdoor, which overrides the default backdoor entry that is programmed
 * into the bootloader. When desired for security purposes, these hook functions can
 * also be implemented in a way that disables the backdoor entry altogether.
 */
/** \brief Enable/disable the backdoor override hook functions. */
#define BOOT_BACKDOOR_HOOKS_ENABLE      (1)


/****************************************************************************************
*   N O N - V O L A T I L E   M E M O R Y   D R I V E R   C O N F I G U R A T I O N
****************************************************************************************/
/* The NVM driver typically supports erase and program operations of the internal memory
 * present on the microcontroller. Through these hook functions the NVM driver can be
 * extended to support additional memory types such as external flash memory and serial
 * eeproms. The size of the internal memory in kilobytes is specified with configurable
 * BOOT_NVM_SIZE_KB. If desired the internal checksum writing and verification method can
 * be overridden with a application specific method by enabling configuration switch
 * BOOT_NVM_CHECKSUM_HOOKS_ENABLE.
 */
/** \brief Enable/disable the NVM hook function for supporting additional memory devices. */
#define BOOT_NVM_HOOKS_ENABLE           (0)
/** \brief Configure the size of the default memory device (typically flash EEPROM). */
#define BOOT_NVM_SIZE_KB                (256)
/** \brief Enable/disable hooks functions to override the user program checksum handling. */
#define BOOT_NVM_CHECKSUM_HOOKS_ENABLE  (0)


/****************************************************************************************
*   F L A S H   M E M O R Y   D R I V E R   C O N F I G U R A T I O N
****************************************************************************************/
/** \brief This microcontroller has a smaller vector table then the default STM32F1xx
 *         project as assumed in the bootloader's core. This means the user program has
 *         a different checksum location, because this one is added at the end of the
 *         user program's vector table.
 */
#define BOOT_FLASH_VECTOR_TABLE_CS_OFFSET (0x1c)
/** \brief Enable support for a custom flash layout table. It is located in
 *         flash_layout.c. This was done because the default flashLayout[] table
 *         in the bootloader's core has more flash memory reserved for the bootloader
 *         than is needed for this demo.
 */
#define BOOT_FLASH_CUSTOM_LAYOUT_ENABLE (1)


/****************************************************************************************
*   W A T C H D O G   D R I V E R   C O N F I G U R A T I O N
****************************************************************************************/
/* The COP driver cannot be configured internally in the bootloader, because its use
 * and configuration is application specific. The bootloader does need to service the
 * watchdog in case it is used. When the application requires the use of a watchdog,
 * set BOOT_COP_HOOKS_ENABLE to be able to initialize and service the watchdog through
 * hook functions.
 */
/** \brief Enable/disable the hook functions for controlling the watchdog. */
#define BOOT_COP_HOOKS_ENABLE           (1)


/****************************************************************************************
*   S E E D / K E Y   S E C U R I T Y   C O N F I G U R A T I O N
****************************************************************************************/
/* A security mechanism can be enabled in the bootloader's XCP module by setting configu-
 * rable BOOT_XCP_SEED_KEY_ENABLE to 1. Before any memory erase or programming
 * operations can be performed, access to this resource need to be unlocked.
 * In the Microboot settings on tab "XCP Protection" you need to specify a DLL that
 * implements the unlocking algorithm. The demo programs are configured for the (simple)
 * algorithm in "libseednkey.dll". The source code for this DLL is available so it can be
 * customized to your needs.
 * During the unlock sequence, Microboot requests a seed from the bootloader, which is in
 * the format of a byte array. Using this seed the unlock algorithm in the DLL computes
 * a key, which is also a byte array, and sends this back to the bootloader. The
 * bootloader then verifies this key to determine if programming and erase operations are
 * permitted.
 * After enabling this feature the hook functions XcpGetSeedHook() and XcpVerifyKeyHook()
 * are called by the bootloader to obtain the seed and to verify the key, respectively.
 */
#define BOOT_XCP_SEED_KEY_ENABLE        (0)


#endif /* BLT_CONF_H */
/*********************************** end of blt_conf.h *********************************/
