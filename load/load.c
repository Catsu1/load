#include <stddef.h>
#include "load.h"

#define LOAD_TRIGGERS	2U

typedef struct
{
	load_hw_t hw;
	const load_hal_t *hal;
	load_trigger_t trigger;
} load_instance_t;

static load_instance_t load_instances[LOAD_MAX];

static const load_state_t state_for_trigger[][LOAD_TRIGGERS] =
{
	{LOAD_ON, LOAD_OFF},
	{LOAD_OFF, LOAD_ON}
};