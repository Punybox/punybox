/**
 * main.c
 *
 * Created on: June 20, 2025
 *     Author: Dmitry Murashov
 */

/****************************************************************************
 * Pre-processor Definitions
 ****************************************************************************/

/****************************************************************************
 * Included files
 ****************************************************************************/

/****************************************************************************
 * Private Types
 ****************************************************************************/

/****************************************************************************
 * Private Function Prototypes
 ****************************************************************************/

static void initializeBss();
data section from flash memory
static void initializeData();
void memoryInitialize();

/****************************************************************************
 * Private Data
 ****************************************************************************/

/****************************************************************************
 * Public Data
 ****************************************************************************/

/****************************************************************************
 * Private Functions
 ****************************************************************************/

/// @brief Sets the entire .bss section w/ NULL
static void initializeBss(void)
{
	// See the linker script where those symbols are defined
	extern unsigned long int gBssStart;
	extern unsigned long int gBssEnd;

	for (volatile register unsigned long int *bssIt = &gBssStart; bssIt < &gBssEnd; ++bssIt)
	{
		*bssIt = 0;
	}
}

/// @brief Copies default values for .data section from flash memory
static void initializeData(void)
{
	// See the linker script where those symbols are defined
	extern int gRamDataStart;
	extern int gRamDataEnd;
	extern int gFlashDataStart;

	for (volatile register int *flashDataIt = &gFlashDataStart, *ramDataIt = &gRamDataStart;
		ramDataIt < &gRamDataEnd;
		++flashDataIt, ++ramDataIt
	) {
		*ramDataIt = *flashDataIt;
	}
}

/****************************************************************************
 * Public Functions
 ****************************************************************************/

void main()
{
	kStartScheduler();

	/* Will only get here if there was insufficient memory to create the idle
	 * task.  The idle task is created within vTaskStartScheduler(). */
	for( ; ; )
	{
	}
}

