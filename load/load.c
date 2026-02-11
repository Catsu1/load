#include <stddef.h>
#include "load.h"

typedef struct
{
	load_hw_t hw;
	const load_hal_t *hal;
	load_trigger_t trigger;
} load_instance_t;